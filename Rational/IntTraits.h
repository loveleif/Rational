#pragma once
#include <limits>
using namespace std;
//#include <climits>

namespace IntTraits {

/* NextType trait, used to get a larger int type */
template <typename intT>
struct NextType {
  static bool HasNextType() { return false; }
};

template <>
struct NextType<short> {
  typedef int Type;
  static bool HasNextType() { return true; }
};

template <>
struct NextType<int> {
  typedef long Type;
  static bool HasNextType() { return true; }
};

template <>
struct NextType<long> {
  typedef long long Type;
  static bool HasNextType() { return true; }
};

/* LargestType trait, used to get the larger of two types */
// TODO: Handle unsigned types
template <typename T, typename U>
struct LargestType {
  typedef typename conditional<sizeof(U) <= sizeof(T), T, U>::type Type;
};

}