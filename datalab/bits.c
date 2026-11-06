/*
 * CS 2011 - Data Lab
 * Due: November 6, 2026. See the course site for the deadline time.
 * Collaboration and AI use are permitted. Do not submit another student's work.
 * Read STUDENT-HANDOUT.md for the assignment and submission checklist.
 * Work in bits.c; submit an unarchived copy as username_bits.c to Canvas.
 */

/* 
 * CS:APP Data Lab 
 * 
 * Brian Wang
 * username: bzwang
 * email: bzwang@wpi.edu
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * Do not add header includes. Function calls, including temporary printf
 * debugging calls, must be removed before legality checks or submission.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Run ./driver.pl to check your correctness and operator-budget scores.
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use btest to test your solutions and driver.pl to check your scores.
 */


#endif
/* Copyright (C) 1991-2022 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /*
  Create filters for bits that are set to 1 or 0 for both x,y
  and filter them out of the final answer. We set bits
  that correspond to pairs of bits in x and y that are not
  both 1 or 0.
  */
  int both_set_to_zero = ~x & ~y;
  int both_set_to_one = x & y;
  return ~both_set_to_zero & ~both_set_to_one;

}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  /* 
  Tmax = 2^31 - 1, and Tmax + 1 wraps around to Tmin, 
  so Tmin is equivalent to 1 << 31
  */
  return (1 << 31);
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  /*
  x+1 == ~x only if x = tmax or x = -1
  Check if this property is true and that x != -1, i.e. x+1 != 0
  */
  return !(((x+1) ^ (~x)) | !(x+1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  /*
  If x has all odd bits set to 1, setting every
  even bit should result in 0xFFFFFFFF and adding 1 gives 0.

  01010101 in binary = 85 in decimal
  */
  int even_set_x = x | 85 | (85 << 8) | (85 << 16) | (85 << 24);
  return !(even_set_x + 1);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  /*
  Apply two's complement directly 
  */
  return (~x + 1);
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  /*
  0x30 <= x <= 0x39 implies that x - 0x30 >= 0 and x - 0x3A < 0. 
  We check the sign bit across both operations to see if 0x30 <= x <= 0x39.

  Works even with wraparound.
  */
 int lb = 0x30, ub = 0x3A;
 int lb_check = ((x + (~lb + 1)) >> 31) & 1; // want 0
 int ub_check = ((x + (~ub + 1)) >> 31) & 1; // want 1
 return (!lb_check) & ub_check; 
}

/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /*
  We create a mask (~(!x) + 1) such that the mask is all ones
  if x =0, else 0. We can apply this mask such that it yields y on y when
  x != 0 (else 0) and z on z when x = 0 (else 0).
  */

  int y_or_zero = y & ~(~(!x) + 1);
  int z_or_zero = z & (~(!x) + 1);
  return y_or_zero | z_or_zero;
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  /*
  if x <= y and x < 0 and y >= 0, y - x could be negative (overflow)
  if x > y and x >= 0 and y < 0, y - x could be positive (underflow)
  if x <= y and x,y >= 0,  y - x will always be non negative
  if x <= y and x,y < 0, y - x will always be non negative

  So, if x and y are the same sign, then we compute whether y - x is nonnegative
  When the signs differ, we check the signs of x and y.
  */
  int x_sign_bit = x >> 31;
  int y_sign_bit = y >> 31;
  int sign_bits_different = (x_sign_bit) ^ (y_sign_bit);  // 0 if same 
  int diff_sign_bit = (y + (~x + 1)) >> 31;  // 0 if nonnegative
  int y_pos_x_neg = (!y_sign_bit) & x_sign_bit;
  return (y_pos_x_neg & sign_bits_different) | (!sign_bits_different & !diff_sign_bit);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  /*
  If x == 0, the sign bit should remain unset across negation. Thus, we 
  simply check if this property applies to x. 
  */
  int x_sign_bit = (x >> 31) & 1;
  int neg_x_sign_bit = ((~x + 1) >> 31) & 1;
  return (x_sign_bit ^ 1) & (neg_x_sign_bit ^ 1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /*
  We notice that if x >= 0, then number of bits needed is the size of
  the bit vector of x excluding leading 0's, plus 1 for the sign bit. 
  If x < 0, we notice  that the number of bits needed is the size 
  of the bit vector of ~x, plus 1 for the sign bit.

  To find the size of the bit vector of x excluding leading 0's, we use binary
  search to find the position (k) of the highest set bit through arithmetic right shifts.
  The size of the bit vector is k + 1 (if x =0, this is 0).
  */
 // use conditional logic to choose ~x when x < 0
  int x_sign_bit = (x >> 31) & 1;
  int mask = ~(x_sign_bit) + 1;
  int x_copy = (x & ~mask) | (~x & mask); 

  // binary search
  // arithmetic right shifts fill the bit vector with 0's
  // since we binary search on ~x if x < 0
  int check = 16;
  
  int bit_present = !!(x_copy >> check);
  mask = ~(bit_present) + 1;
  check = ((check + 8) & mask) | ((check + (~8 + 1)) & ~mask);

  bit_present = !!(x_copy >> check);
  mask = ~(bit_present) + 1;
  check = ((check + 4) & mask) | ((check + (~4 + 1)) & ~mask);

  bit_present = !!(x_copy >> check);
  mask = ~(bit_present) + 1;
  check = ((check + 2) & mask) | ((check + (~2 + 1)) & ~mask);

  bit_present = !!(x_copy >> check);
  mask = ~(bit_present) + 1;
  check = ((check + 1) & mask) | ((check + (~1 + 1)) & ~mask);

  bit_present = !!(x_copy >> check);
  mask = ~(bit_present) + 1;
  check = ((check) & mask) | ((check + (~1 + 1)) & ~mask);

  // bit length is check + 1, but should be 0 if x_copy == 0
  // thus, we can write bit length = check + !!x_copy
  return check + (!!x_copy) + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  /*
  uf is organized as [1 sign bit][8 bit exp][23 bit frac]

  If exp = 0xFF, uf = +/- infinity or NaN. In either case, we return uf.
  If exp = 0, then we know the float is denormalized, so we double the fraction
  by shifting it left once. Else, we know the float is normalized and we simply 
  add 1 to the exponent.
  */
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned sign_bit = uf & (1 << 31);
  unsigned frac = uf & 0x7FFFFF;

  // if uf = +/- infinity or NaN
  if (!(exp ^ 0xFF)) return uf;

  // denormalized 
  if (!exp) return sign_bit | (frac << 1); // set exp = 1

  // normalized
  return uf + (1u << 23); // won't carry over to sign bit since exp != 0xFF
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  /*
  uf is organized as [1 sign bit][8 bit exp][23 bit frac]

  If exp = 0xFF, uf = +/- infinity or NaN. In either case, we return 0x80000000u.
  If uf is normalized, then the float is (-1)^s * M * 2^E, where E= exp - bias and
  M = 1.frac. Overflow occurs when exp - bias > 30 and we return 0x80000000u. Otherwise,
  we construct M with leading 1 and the 23 bit frac. During this construction M is technically
  already shifted 23 to the left. So we shift left by E- 23 if E >= 23, else 23 - E right. 

  If E < 0 or uf is denormalized, uf is strictly less than 1, so we just return 0
  Right shifting allows truncation to 0 and we negate if necessary at the end.

  Note: ~x + 1 for some constant is replaced with the hex to reduce operator count
  */

  int exp = (uf >> 23) & 0xFF;
  int frac = uf & 0x7FFFFF;
  int E, M, abs_ans, E_minus_23_sign;

  // if uf = +/- infinity or NaN
  if (!(exp ^ 0xFF)) return 0x80000000u;

  // denormalized
  if (!exp) return 0;

  // normalized
  E = exp + 0xFFFFFF81; // -bias = -127 = 0xFFFFFF81
  if (E < 0) return 0; // strictly less than 1

  // if E > 30, i.e, E - 31 >= 0, there would be overflow
  // -31 = ~31 + 1 = 0xFFFFFFE1
  if (!(((E + 0xFFFFFFE1) >> 31) & 1)) return 0x80000000u;

  //  M is constructed already shifted 23 left
  // -23 = ~23+ 1 = 0xFFFFFFE9
  M = (1 << 23) | frac;
  E_minus_23_sign =  ((E + 0xFFFFFFE9) >> 31) & 1;
  if (!E_minus_23_sign){ // if E >= 23
    abs_ans = M << (E + 0xFFFFFFE9);
  } else {
    abs_ans = M >> (23 + (~E + 1));
  }

  // if float is negative
  if (((uf >> 31) & 1)) return ~abs_ans + 1;
  return abs_ans;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  /*
  Want to return an unsigned int of form [1 sign bit s][8 bit exp][23 bit frac]
  2^x for any int x is positive. The sign bit must be unset. 

  Normalized floats that hold 2^x have M = 1. (frac = 0) and exp = bias + E, where 
  E is set to x. A normalized float allows E between -126 and 127 so it is able to accommodate
  x between -126 and 127. Thus, if x is between -126 and 127, we return a float with frac = 0,
  s = 0, and exp = bias + x. If x > 127, then we have overflow and we return +INF.

  Denormalized floats can hold 2^x for x between -127 and -149, The minimum that can
  can be represented is 2^{-23} * 2^{1- bias} = 2^{-149} and 2^{-127} can be represented 
  with M = 0.100...000. The frac for x in this range is a single set bit shifted based on how 
  far x is from -149 (so that x = -127 gives frac of 1 << 22, x = -128 gives frac of 1 << 21, etc.).
  Thus, if x is between -127 and -149, we return a float with frac = 1 << (distance between x and -149), 
  s = 0, and exp = 0. If x < -149, we have underflow and we return 0. 

  Note that +INF = 0x7F800000 for single precision float
  */
  int x_neg = (x >> 31) & 1;
  if (!x_neg){
    // if x > 127, i.e. x - 128 >= 0 
    if (!(((x + (~128 + 1)) >> 31) & 1)) return 0x7F800000; // overflow
    return (x + 127) << 23;
  } else {
    // if -126 <= x, i.e., x + 126 >= 0
    if (!(((x + 126) >> 31) & 1)){
      return (x + 127) << 23;
    } else {
      // consider if 2^x can fit in a denormalized float
      // check if x >= -149, i.e, x + 149 >= 0
      if (!(((x + 149) >> 31) & 1)){
        return 1 << (x + 149);
      }
      return 0; // underflow
    }    
  }
}
