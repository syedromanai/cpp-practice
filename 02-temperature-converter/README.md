# Temperature Converter

Converts a temperature between Celsius and Fahrenheit. Enter a value, say which
unit it is in, and the program prints the equivalent in the other unit to one
decimal place.

## Build and run

```bash
g++ temperature-converter.cpp -o temperature-converter
./temperature-converter
```

## Example

```
Enter temperature: 98.6

Enter unit (C or F): F

98.6F = 37.0C
```

## Behaviour

| Input | Output |
|---|---|
| 100 C | 212.0 F |
| 32 F | 0.0 C |
| 98.6 F | 37.0 C |
| 36.5 C | 97.7 F |
| -40 C | -40.0 F |
| any other unit | `Enter valid unit` |

Accepts upper or lower case for the unit. `-40` is the point where both scales
meet, which makes it a useful sanity check.

## How it works

Two conversion functions do the arithmetic, and `main` picks which one to call
based on the unit character.

```
C to F:  (C * 9 / 5) + 32
F to C:  (F - 32) * 5 / 9
```

The value is stored as a `double`, not an `int` - an `int` cannot hold `98.6`,
and reading one leaves the `.6` in the input stream, which then gets picked up
as the unit character and breaks the program.

Output formatting is set once at the top of `main`:

```cpp
std::cout << std::fixed << std::setprecision(1);
```

`std::setprecision(1)` alone would mean one *significant* digit, printing 212 as
`2e+02`. `std::fixed` changes it to mean digits after the decimal point. Both
are sticky, so one line covers every print that follows.

## Concepts used

- `double` vs `int`, and why the type of an input variable matters
- `char` comparison for the unit, with upper and lower case accepted
- Functions with return values
- Output formatting with `<iomanip>`
- `if` / `else if` / `else`
