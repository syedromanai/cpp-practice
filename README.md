# C++ Practice

Working through C++ from the ground up, one project per folder. Each has its own
README with what it does, how to build it, and what it taught me.

Studying toward embedded systems and edge AI - C++ is the language of that work,
so this repo is where the fundamentals get built before they get useful.

## Projects

| | Project | Concepts | Course stage |
|---|---|---|---|
| 01 | [Password Checker](01-password-checker) | strings, loops, bool flags, ASCII comparison, conditionals | Chapters 1-4 checkpoint |
| 02 | [Temperature Converter](02-temperature-converter) | doubles vs ints, functions with return values, char input, output formatting | Post-course practice |
| 03 | [Sensor Stats](03-sensor-stats) | vectors, range-based for, passing by const reference, guarding empty input | Post-course practice |

## Build anything here

Each project is a single translation unit, so no build system is needed:

```bash
cd 01-password-checker
g++ password_checker.cpp -o password_checker
./password_checker
```

## Course

[Codédex C++](https://www.codedex.io/cpp) - 10 chapters, ending with pointers
and references. Projects land here as I reach them.

**Progress:** course complete, 10 of 10 chapters. Practice projects continue here.
