# Password Checker

A command-line password validator written in C++. Takes a password as input and
checks it against three rules, reporting the first rule it fails.

Built as the checkpoint project for the first four chapters of the Codédex C++
course — variables, control flow, and loops.

## Rules

A valid password must:

- Be at least **8 characters** long
- Contain at least **one number** (`0`–`9`)
- Contain at least **one special character** (`!` `@` `#` `%` `^`)

## Build and run

```bash
g++ password_checker.cpp -o password_checker
./password_checker
```

On Windows with MinGW:

```bash
g++ password_checker.cpp -o password_checker.exe
password_checker.exe
```

## Example

```
===================
Password Checker 🔐
===================

Enter a password: hello

❌ Password must be at least 8 characters.
```

```
===================
Password Checker 🔐
===================

Enter a password: hello123!

✅ Valid password!
```

## How it works

The program loops through the password once, character by character, setting two
flags: `hasNumber` and `hasSpecialCharacter`. Characters are compared directly
against their ASCII ranges — `password[i] >= '0' && password[i] <= '9'` catches
any digit without needing a library function.

After the loop, the three rules are checked in order of importance: length
first, then the number, then the special character. Only the first failure is
reported, so the user fixes one thing at a time rather than being handed a list.

## Concepts used

- `std::string` and indexing individual characters
- `for` loop with a counter
- `bool` flags to carry state out of a loop
- Character comparison using ASCII ordering
- `if` / `else if` / `else` chains
- Console I/O with `std::cin` and `std::cout`

## Notes

`std::cin >> password` reads up to the first whitespace, so passwords
containing spaces are truncated. Fine for this exercise; `std::getline` would be
the fix if spaces were allowed.
