#include "stdafx.h"
#include "CppUnitTest.h"
#include "Rational.h"
#include <typeinfo>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RationalTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Set)
		{
			Rational<int> r;
      r.Set(0, 1);
      Assert::IsTrue(r==Rational<int>(0, 1));
      r.Set(0, 2);
      Assert::IsTrue(r==Rational<int>(0, 1));
      r.Set(1, 2);
      Assert::IsTrue(r==Rational<int>(1, 2));
      r.Set(2, 4);
      Assert::IsTrue(r==Rational<int>(1, 2));
      r.Set(-2, -4);
      Assert::IsTrue(r==Rational<int>(1, 2));
      r.Set(2, -4);
      Assert::IsTrue(r==Rational<int>(-1, 2));
		}

    TEST_METHOD(Add)
		{
			Rational<int> r1 = Rational<int>(2,4), r2 = Rational<int>(2,16);
      int int1 = 3;
      Assert::IsTrue(r1+r2==r2+r1);
      Assert::IsTrue(r1+r2==Rational<int>(5, 8));
      Assert::IsTrue((r1 + r2) == Rational<int>(5, 8));
      Assert::IsTrue((r1 += r2) == Rational<int>(5, 8));
      r1 = Rational<int>(2,4);
      Assert::IsTrue((r1 + (Rational<int>) int1) == Rational<int>(14, 4));
      Assert::IsTrue((int1 + r1) == Rational<int>(14, 4));
      Rational<short> r3 = Rational<short>(8,16);
      Assert::IsTrue((r3 + r1) == Rational<int>(1, 1));
		}

    TEST_METHOD(Subtract)
		{
			Rational<int> r1 = Rational<int>(2,4), r2 = Rational<int>(2,16);
      Assert::IsTrue(r1+r2==r2+r1);
      Assert::IsTrue(r1+r2==Rational<int>(5, 8));
      Assert::IsTrue((r1 += r2) == Rational<int>(5, 8));
		}

    TEST_METHOD(G)
		{
      // short, int, long long som parameter (Rational<short> etc.)
      short sh = 42;
      int in = 123;
      long long ll = 7000000000;
      Rational<short> Rsh = Rational<short>(3,13);
      Rational<int> Rin = Rational<int>(3,139);
      Rational<long long> Rll = Rational<long long>(8000001, 7000000000);

      Rational<int> a, a2;
      a = Rational<int>(sh);
      a = Rational<int>(in);
      #pragma warning(disable: 4244)
      a = Rational<int>(ll);
      a = Rational<int>(Rsh);
      a = Rational<int>(Rin);
      a = Rational<int>(Rll);

      a = in;
      a = sh;
      a = ll;

      a += in;
      a += sh;
      a += ll;

      a = a + in;
      a = in + a;
      a = a + sh;
      a = sh + a;
      a = a + ll;
      a = ll + a;

      a = -a2;

      a++;
      a--;
      ++a;
      a++;

      stringstream ss;
      ss << Rin;
      Rational<int> out;
      ss >> out;
      Assert::IsTrue(out == Rin);

      int aa = (int) Rational<short>(4,1);
      Rational<int> b = Rational<short>(4,9);
		}

    TEST_METHOD(VG)
    {
      short sh = 42;
      int in = 123;
      long long ll = 7000000000;
      Rational<short> Rsh = Rational<short>(3,13);
      Rational<int> Rin = Rational<int>(3,139);
      Rational<long long> Rll = Rational<long long>(8000001, 7000000000);

      Assert::IsTrue(std::is_same<Rational<long long>, decltype((Rll + in))>::value);
      Assert::IsTrue(std::is_same<Rational<long long>, decltype((in + Rll))>::value);

      Assert::IsTrue(std::is_same<Rational<int>, decltype((Rin + sh))>::value);
      Assert::IsTrue(std::is_same<Rational<int>, decltype((sh + Rin))>::value);

      Assert::IsTrue(std::is_same<Rational<long long>, decltype((Rin + ll))>::value);
      Assert::IsTrue(std::is_same<Rational<long long>, decltype((ll + Rin))>::value);

      Assert::IsTrue(std::is_same<Rational<int>, decltype((Rsh + in))>::value);
      Assert::IsTrue(std::is_same<Rational<int>, decltype((in + Rsh))>::value);

    }
    
	};
}