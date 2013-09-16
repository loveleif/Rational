#pragma once
#include <limits>
using namespace std;

namespace IntTraits {

/* NextType trait, used to get a larger int type */
// TODO: Handle unsigned and check if type really is larger.
template <typename intT>
struct NextType {
  typedef intT Type;
};
template <>
struct NextType<short> {
  typedef int Type;
};
template <>
struct NextType<int> {
  typedef long Type;
};
template <>
struct NextType<long> {
  typedef long long Type;
};

/* LargestType trait, used to get the larger of two types */
// TODO: Handle unsigned types
template <typename T, typename U>
struct LargestType {
  typedef typename conditional<sizeof(U) <= sizeof(T), T, U>::type Type;
};

}