# Sensor Stats

Takes a run of temperature readings and reports on the whole set. Enter readings
one at a time in Celsius, `-999` to finish.

## Build and run

```bash
g++ -Wall -Wextra sensor-stats.cpp -o sensor-stats
./sensor-stats
```

## Example

```
Enter reading in Celsius, -999 to finish.
18
22
19
30
24
-999

5 reading
Average: 22.6 C
Lowest: 18.0 C
Highest: 30.0 C
```

## Behaviour

| Input | Output |
|---|---|
| `20 25 30` | 3 readings, average 25.0, low 20.0, high 30.0 |
| `-5 -10 -2` | 3 readings, average -5.7, low -10.0, high -2.0 |
| `21.5` | 1 reading, average 21.5, low 21.5, high 21.5 |
| nothing, just `-999` | `No reading entered.` |

## How it works

Readings collect into a `std::vector<double>`. Three functions do the maths and
`main` does the printing - the functions return numbers, they never print.

```cpp
double average(const std::vector<double>& reading);
double lowest(const std::vector<double>& reading);
double highest(const std::vector<double>& reading);
```

### Why the parameter is a const reference

`std::vector<double> reading` as a parameter would copy every element, every
call. Three calls, three full copies. `const std::vector<double>&` hands over
the address of the original instead, so nothing is copied, and `const` stops the
function modifying it by accident.

At five readings nobody notices. At fifty thousand on a board with 64KB of RAM,
the copy is the bug.

### Two things that look fine and are not

**Dividing by zero.** Enter `-999` immediately and there are no readings, so
`average` would divide by zero. The empty check runs in `main` *before* the
average is ever calculated.

**Starting lowest and highest at zero.** If `highest` began at `0.0` and every
reading were negative, it would report `0.0` - a temperature that was never
recorded. Both functions start from the first element of the vector instead.
The `-5 -10 -2` case in the table is what proves it.

## Concepts used

- `std::vector<double>` and range-based `for`
- Passing containers by const reference instead of by value
- Functions that return a value rather than printing
- Guarding an empty container before doing maths on it
- Output formatting with `<iomanip>`
