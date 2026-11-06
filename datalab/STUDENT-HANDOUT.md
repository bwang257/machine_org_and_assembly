# Data Lab: Manipulating Bits

**Course:** CS 2011  
**Due:** November 6, 2026. See this assignment in Canvas for the deadline time and time zone.  
**Download and submission:** This Data Lab assignment in Canvas.  
**Collaboration and AI-use policy:** Collaboration and AI use are permitted. You may not submit another student’s work.  
**Help:** Piazza, course office hours, and Wednesday lab help sessions. See Canvas for links and schedules.

## What you will learn

In this lab, you will implement 13 short C functions that manipulate integer and floating-point representations. You will practice two’s-complement arithmetic, Boolean operations, shifts, and IEEE 754 single-precision representation. The restrictions are part of the exercise: a function must produce the correct result and follow its coding rules.

Use the dedicated Ubuntu Linux VM supplied for this course. Read the instructions and each function’s specification in `bits.c` before starting. That file defines the required behavior, permitted operators, and operation limit for each puzzle.

## Get started

Download `datalab-handout.tar` from the course site and save it in a private working directory on your course VM. Extract it and build the tools:

```sh
tar -xf datalab-handout.tar
cd datalab-handout
make
```

Edit **only `bits.c`**. Add your name and user ID at the top of the file. Keep function names and parameter types unchanged.

The skeleton contains placeholder return values. Failing tests and a score of **0/62** before implementing any functions are expected. Work on one function at a time and save backup copies of your work.

| File or tool | Purpose |
|---|---|
| `bits.c` | Your working implementations; submit a copy as `username_bits.c` |
| `dlc` | Checks permitted language features and operator counts |
| `btest` | Tests functional correctness; built by `make` |
| `driver.pl` | Combines rule checking and correctness tests to report automated points |
| `ishow`, `fshow` | Display integer and floating-point representations; built by `make` |
| `README` | Additional tool documentation |
| `tests.c` | Reference behavior; these reference functions do not obey the student coding restrictions |

## The puzzles

“Correctness points” are the weights used by the grader. Every puzzle also offers two operator-budget points. Read the full specification in `bits.c`, especially its boundary-case requirements.

| Function | Required behavior | Correctness points | Maximum operators |
|---|---|---:|---:|
| `bitXor(x, y)` | Compute `x ^ y` using only `~` and `&` | 1 | 14 |
| `tmin()` | Return the minimum 32-bit two’s-complement integer | 1 | 4 |
| `isTmax(x)` | Return 1 exactly when `x` is the maximum two’s-complement integer | 1 | 10 |
| `allOddBits(x)` | Return 1 if every odd-numbered bit is set; bit 0 is the least significant bit | 2 | 12 |
| `negate(x)` | Return `-x` without using the `-` operator | 2 | 5 |
| `isAsciiDigit(x)` | Return 1 exactly when `0x30 <= x <= 0x39` | 3 | 15 |
| `conditional(x, y, z)` | Compute the result of `x ? y : z` using the permitted bit operations | 3 | 16 |
| `isLessOrEqual(x, y)` | Return 1 exactly when `x <= y` | 3 | 24 |
| `logicalNeg(x)` | Compute `!x` without using `!` | 4 | 12 |
| `howManyBits(x)` | Return the minimum number of bits needed to represent `x` in two’s complement, including the sign bit | 4 | 90 |
| `floatScale2(uf)` | Return the representation of twice the represented float; preserve NaN inputs | 4 | 30 |
| `floatFloat2Int(uf)` | Convert the represented float to `int`; return `0x80000000u` for out-of-range values, NaN, or infinity | 4 | 30 |
| `floatPower2(x)` | Return the representation of two raised to integer power `x`; return zero below the representable range and positive infinity above it | 4 | 30 |

In `floatScale2` and `floatFloat2Int`, `uf` is a bit pattern representing a single-precision float, not a numeric unsigned-to-float conversion. `floatPower2` takes an integer exponent. All floating-point results are returned as integer bit patterns; `floatFloat2Int` returns an `int`.

## Coding rules

### Integer puzzles

Use straight-line code: no conditionals, loops, or switch statements. The generally permitted operators are:

```text
! ~ & ^ | + << >>
```

Some functions allow fewer operators; use the list in that function’s comment. Integer constants must be between 0 and 255 inclusive. Use only `int` arguments and local variables. Do not use casts, function calls, extra functions, macros, global variables, arrays, structs, unions, or other data types. Operators such as `-`, `*`, `/`, `%`, `&&`, `||`, comparisons, and `?:` are not permitted in integer solutions.

Assume 32-bit two’s-complement integers and arithmetic right shifts. Keep shift counts between 0 and 31. Assignment itself does not count toward the operator limit.

### Floating-point puzzles

You may use conditionals, loops, integer comparisons and arithmetic, and arbitrary `int` or `unsigned` constants. Use only `int` and `unsigned` data. You may not use floating-point types, operations, or constants, casts, function calls, extra functions, macros, global variables, arrays, structs, or unions.

Put local variable declarations before other statements in each block. The `dlc` checker accepts an older C syntax and may reject declarations mixed with statements even when GCC accepts them. Do not add header includes to `bits.c`.

## Test your work

Run these commands from inside `datalab-handout`:

```sh
make
./dlc -e bits.c
./btest
./driver.pl
```

Rebuild with `make` after editing `bits.c` before running `btest`. The driver rebuilds its own test executables in a scratch directory.

Use `dlc` to check the rules and operator counts. Use `btest` to find incorrect results. Passing `btest` alone does not establish that a solution follows the coding rules. The tests cover many inputs and boundary cases, but are not an exhaustive proof for every possible input.

Test a single function, or a particular input:

```sh
./btest -f bitXor
./btest -f bitXor -1 4 -2 5
```

Explore representations with the helper tools:

```sh
./ishow 0x27
./fshow 0x3f800000
```

Run `./driver.pl` without the contest submission option `-u`. Your course submission is the `bits.c` file uploaded at the location specified above.

## Grading

This lab has **72 points**:

- **36 correctness points:** each function earns its listed weight if it obeys the coding rules and passes the correctness tests. An incorrect or rule-violating function receives no correctness points.
- **26 operator-budget points:** two points per function that is correct, follows the rules, and stays within its operation limit. Reducing the count below the limit earns no additional points.
- **10 explanation/documentation points:** assessed manually. Place well-formatted comments above each implemented function explaining your approach and the key bit manipulations. Explain the reasoning rather than restating the code line by line.

The automated driver reports a maximum of **62/62**. It does not award the ten explanation/documentation points. Official grading uses instructor-controlled copies of the tools and tests.

## Before submitting

1. Confirm that your username and email appear at the top of `bits.c`. Your username is your school email address without `@wpi.edu`.
2. Run `make`, `./dlc -e bits.c`, `./btest`, and `./driver.pl` on the course VM.
3. Remove temporary debugging code and check that all solutions follow their function-specific rules.
4. Keep your working file named `bits.c`. Submit an unarchived copy named `username_bits.c` to this assignment in Canvas, replacing `username` with your username. Do not submit the tar file or a zip file. Verify that the uploaded file is the version you intended to submit. Grading staff will rename it to `bits.c` for grading.

## If something goes wrong

- **Missing `bits/libc-header-start.h` or 32-bit libraries:** the VM’s 32-bit development environment needs attention. Contact course staff and include the command and complete error output.
- **Permission denied when running `dlc` or `driver.pl`:** check that you extracted the course archive inside the VM. Contact staff if its executable permissions were lost.
- **`dlc` rejects code GCC accepts:** check permitted operators, constants, variable types, and declaration placement. GCC compilation alone is not a legality check.
- **A test times out:** check for an infinite loop in a floating-point solution and make sure you are running on the course VM.

When requesting help, include the function name, exact command, and complete diagnostic. Follow the course policy above when sharing code.

*Adapted for this course from the CS:APP Data Lab by Randal E. Bryant and David R. O’Hallaron.*
