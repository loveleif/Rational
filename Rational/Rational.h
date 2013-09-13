#pragma once

#include <iostream>
#include "IntTraits.h"
using namespace std;

/*
 * Class representation of a rational number. This rational number will always 
 * be simplified as far as possible and will always indicate sign on the
 * numerator. For example 2/-8 will be represented as -1/4.
 */
template <typename T>
class Rational {
  /* Trying to be nice to our friends: */
  friend bool operator== <T>(const Rational<T>&, const Rational<T>&);
  friend bool operator!= <T>(const Rational<T>&, const Rational<T>&);
  friend bool operator< <T>(const Rational<T>&, const Rational<T>&);
  friend bool operator> <T>(const Rational<T>&, const Rational<T>&);
  friend bool operator<= <T>(const Rational<T>&, const Rational<T>&);
  friend bool operator>= <T>(const Rational<T>&, const Rational<T>&);
  friend ostream& operator<< <T>(ostream&, const Rational<T>&);
  friend istream& operator>> <T>(istream&, Rational<T>&);
  friend Rational<T> operator- <T>(const Rational<T>&);

private:
  T numerator, denominator;

  /* Divide by greatest common divisor and makes sure sign is indicated on 
   * numerator.
   */
  void Simplify();
public:
  /* Constructors. */
  Rational(T numerator = 0, T denominator = 1):
    numerator(numerator), denominator(denominator) { Simplify(); }

  //Rational(int numerator): Rational(numerator) { }

  template <typename U>
  Rational(const Rational<U>& r): 
    numerator(r.GetNumerator()), denominator(r.GetDenominator()) { }

  /* Sets the numerator and denominator of this Rational, will run Simplify. */
  Rational& Set(T numerator, T denominator);

  /* Overloaded compound-assignment operators */
  Rational& operator+=(const Rational& right) {
    return Set(right.denominator * numerator + denominator * right.numerator, 
               denominator * right.denominator);
  }
  Rational& operator-=(const Rational& right) {
    return Set(right.denominator * numerator - denominator * right.numerator,
               denominator * right.denominator);
  }
  Rational& operator*=(const Rational& right) {
    return Set(numerator * right.numerator, denominator * right.denominator);
  }
  Rational& operator/=(const Rational& right) {
    return Set(right.denominator * numerator, right.numerator * denominator);
  }
  
  Rational operator++() { 
    Rational<T> rval(*this);
    Set(numerator + denominator, denominator);
    return rval;
  }
  Rational& operator++(int a) { return Set(numerator + denominator, denominator); }
  Rational operator--() { 
    Rational<T> rval(*this);
    Set(numerator - denominator, denominator); 
    return rval;
  }
  Rational& operator--(int a) { return Set(numerator - denominator, denominator); }

  T GetNumerator() const { return numerator; }
  T GetDenominator() const { return denominator; }

  /* Arithmetic and relational operators are overloaded as non-members. */

  explicit operator int() const { return numerator / denominator; }
};

/*
 * Returns the greatest common devisor (Euclidean algorithm).
 */
template <typename T>
T Gcd(T numerator, T denominator) {
  T temp;
  while (denominator != 0) {
    temp = denominator;
    denominator = numerator % denominator;
    numerator = temp;
  }
  return numerator;
}

template <typename T>
void Rational<T>::Simplify() {
  if (numerator == 0) {
    denominator = 1;
    return;
  }

  // Divide by greatest common divisor
  T gcd = Gcd(numerator, denominator);
  numerator = numerator / gcd;
  denominator = denominator / gcd;

  // Indicate sign on numerator only
  if (denominator < 0) {
    numerator = -numerator;
    denominator = -denominator;
  }
}

template <typename T>
Rational<T>& Rational<T>::Set(T numerator, T denominator) {
  this->numerator = numerator;
  this->denominator = denominator;
  Simplify();
  return *this;
}

// Overloaded arithmetic operators
// ===============================

template <typename T, typename U>
Rational<typename IntTraits::LargestType<T, U>::Type>
operator+(const Rational<T>& left, const Rational<U>& right) {
  Rational<typename IntTraits::LargestType<T, U>::Type> sum = left;
  sum += right;
  return sum;
}

template <typename T, typename U>
Rational<typename IntTraits::LargestType<T, U>::Type>
operator+(const Rational<T>& left, const U& right) {
  Rational<IntTraits::LargestType<T, U>::Type> sum = left;
  return sum += right;
}

template <typename T, typename U>
Rational<typename IntTraits::LargestType<T, U>::Type>
operator+(const U& left, const Rational<T>& right) {
  return right + left;
}

template <typename T>
Rational<T> operator-(const Rational<T>& left, const Rational<T>& right) {
  Rational<T> sum = left;
  return sum -= right;
}

template <typename T>
Rational<T> operator-(const Rational<T>& in) {
  Rational<T> out = in;
  out.numerator = -out.numerator;
  return out;
}

template <typename T>
Rational<T> operator*(const Rational<T>& left, const Rational<T>& right) {
  Rational<T> product = left;
  return product *= right;
}

template <typename T>
Rational<T> operator/(const Rational<T>& left, const Rational<T>& right) {
  Rational<T> quotient = left;
  return quotient /= right;
}

// Overloaded relational operators
// ===============================

template <typename T>
bool operator==(const Rational<T>& left, const Rational<T>& right) {
  return left.numerator == right.numerator && left.denominator == right.denominator;
}

template <typename T>
bool operator!=(const Rational<T>& left, const Rational<T>& right) {
  return left.numerator != right.numerator || left.denominator != right.denominator;
}

template <typename T>
bool operator<(const Rational<T>& left, const Rational<T>& right) {
  return (right - left).numerator > 0;
}

template <typename T>
bool operator>(const Rational<T>& left, const Rational<T>& right) {
  return (left - right).numerator > 0;
}

template <typename T>
bool operator<=(const Rational<T>& left, const Rational<T>& right) {
  return (right - left).numerator >= 0;
}

template <typename T>
bool operator>=(const Rational<T>& left, const Rational<T>& right) {
  return (left - right).numerator >= 0;
}

// Overloaded stream operator
// ==========================

template <typename T>
ostream& operator<<(ostream& os, const Rational<T>& r) {
  return os << r.numerator << "/" << r.denominator;
}

template <typename T>
istream& operator>>(istream& is, Rational<T>& item) {
  is >> item.numerator;
  is.ignore(1);
  is >> item.denominator;
	
  if (!is)
    item = Rational<T>(); // Input failed: give the object the default state
	
  return is;
}