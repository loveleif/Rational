Rational
========

A C++ implementation of a rational number. The template class `Rational`
represents one rational number. It will always be simplified as far as possible, 
will always indicate sign on the numerator and will always represent 0 as 0/1. 
For example 2/-8 will be represented as -1/4 and 0/-128 will be represented as 
0/1.

Some crude unit tests based on Visual Studios C++ unit test framework are 
supplied in the folder RationalTest.

Features:

- Construction and assignment from any integer type or `Rational<IntType>` type. 
- `+=`, `-=`, `*=`, `/=`, `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`, `<=`, `>=`, 
  `<<`, `>>` operators
- Postfix and prefix `++` and `--` operators
- `int + Rational<IntType>` will work as expected
- Unary operator, `r1 = -r2;`
- Explicit conversion to integer types
- Calculations are performed in a larger type than that of the Rational in use 
  (see IntTraits.h). For example, the operation `Rational<short> + 
  Rational<short>` will perform calculation steps with ints.

Build
-----
This project has been built with Microsoft Visual Studio 2012, compiler Nov 
2012 CTP, project files are included. It should however be easy to compile it 
using other C++11 compilers.