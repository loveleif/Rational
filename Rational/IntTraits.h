#pragma once
#include <limits>
using namespace std;
//#include <climits>

namespace IntTraits {

template <typename intT>
struct IntTraits {
  static bool HasNextType() { return false; }
};

template <>
struct IntTraits<short> {
  typedef int NextType;
  static bool HasNextType() { return true; }
};

template <>
struct IntTraits<int> {
  typedef long NextType;
  static bool HasNextType() { return true; }
};

template <>
struct IntTraits<long> {
  typedef long long NextType;
  static bool HasNextType() { return true; }
};

template <typename T, typename U>
struct LargestType {
  typedef typename conditional<sizeof(U) <= sizeof(T), T, U>::type Type;
};

template <typename T, typename U>
void TestFunc(T a, U b) {
  cout << typeid(LargestType<T, U>::Type).name() << endl;
}


}