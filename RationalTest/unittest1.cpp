#include "stdafx.h"
#include "CppUnitTest.h"
#include "Rational.h"
#include <typeinfo>
#include <sstream>
#include <limits.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RationalTest
{	
  typedef Rational<short> Rshort;
  typedef Rational<int> Rint;
  typedef Rational<long long> RLL;

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

      Rational<short> r_sh_1small = Rational<short>(1, SHRT_MAX);
      Rational<short> r_sh_2small = Rational<short>(2, SHRT_MAX);
      Assert::IsTrue(r_sh_1small + r_sh_1small == r_sh_2small);
      r_sh_1small += r_sh_1small;
      Assert::IsTrue(r_sh_1small == r_sh_2small);
		}

    TEST_METHOD(Subtract)
		{
			Rational<int> r1 = Rational<int>(2,4), r2 = Rational<int>(2,16);
      int int1 = 3;
      Assert::IsTrue(r1-r2==-r2+r1);
      Assert::IsTrue(r1-r2==Rational<int>(3, 8));
      Assert::IsTrue((r1 -= r2) == Rational<int>(3, 8));
      r1 = Rational<int>(2,4);
      Assert::IsTrue((r1 - (Rational<int>) int1) == Rational<int>(-5, 2));
      Assert::IsTrue((int1 - r1) == Rational<int>(5, 2));
      Rational<short> r3 = Rational<short>(8,16);
      Assert::IsTrue((r3 - r1) == Rational<int>(0, 1));

      Rational<short> r_sh_1small = Rational<short>(1, SHRT_MAX);
      Assert::IsTrue(r_sh_1small - r_sh_1small == Rational<short>(0, 1));
      r_sh_1small -= r_sh_1small;
      Assert::IsTrue(r_sh_1small == Rational<short>(0, 1));
		}

    TEST_METHOD(Multiply)
		{
			Rational<int> r1 = Rational<int>(2,4), r2 = Rational<int>(2,16);
      int int1 = 3;
      Assert::IsTrue(r1*r2==r2*r1);
      Assert::IsTrue(r1*r2==Rational<int>(4, 4*16));
      Assert::IsTrue((r1 *= r2) == Rational<int>(4, 4*16));
      r1 = Rational<int>(2,4);
      Assert::IsTrue((r1 * (Rational<int>) int1) == Rational<int>(6, 4));
      Assert::IsTrue((int1 * r1) == Rational<int>(6, 4));
      Rational<short> r3 = Rational<short>(8,16);
      Assert::IsTrue((r3 * r1) == Rational<int>(16, 64));
		}

    TEST_METHOD(Divide)
		{
			Rational<int> r1 = Rational<int>(2,4), r2 = Rational<int>(2,16);
      int int1 = 3;
      Assert::IsTrue(r1/r2==Rational<int>(1,1)/(r2/r1));
      Assert::IsTrue(r1/r2==Rational<int>(16*2, 8));
      Assert::IsTrue((r1 /= r2) == Rational<int>(16*2, 8));
      r1 = Rational<int>(2,4);
      Assert::IsTrue((r1 / (Rational<int>) int1) == Rational<int>(2, 12));
      Assert::IsTrue((int1 / r1) == Rational<int>(6, 1));
      Rational<short> r3 = Rational<short>(8,16);
      Assert::IsTrue((r3 / r1) == Rational<int>(1, 1));
		}

    TEST_METHOD(IncrDecr)
    {
      Rational<int> r1 = Rational<int>(1,2);
      ++r1;
      Assert::IsTrue(r1 == Rational<int>(3,2));
      --r1;
      Assert::IsTrue(r1 == Rational<int>(1,2));
      --r1;
      Assert::IsTrue(r1 == Rational<int>(-1,2));

      Rational<int> r2 = r1++;
      Rational<int> r3 = r1++;
      Assert::IsTrue(r1 == Rational<int>(3,2));
      Assert::IsTrue(r2 == Rational<int>(-1,2));
      Assert::IsTrue(r3 == Rational<int>(1,2));
    }

    TEST_METHOD(G)
		{
    Rational<short> rs0, rs1(1), rs2(2,1), rs3(3);
	  Rational<int> ri0;
	  Rational<long long> rll0, rll1(1), rll2(2,1), rll3(3);


    //Konstrueras från ”Tal” dvs. Rtal rtal(tal);
	  RLL   rllx(1);
	  RLL   rlly(rs0);

    //Jämföras med == dvs. if (rtal == tal) …
	  Assert::IsTrue(rs1==rs1);
	  Assert::IsTrue(rs2==2);
	  Assert::IsTrue(rs1==rll1);

    //Tilldelas (=) från ”Tal” dvs. rtal=tal;
	  rs3=Rint(13,3);
	  Assert::IsTrue(rs3==Rshort(13,3));
	  rs3=rll3=-17;
	  Assert::IsTrue(rs3==Rshort(-17));

    //+= med ”Tal” dvs. rtal += tal;
	  Assert::IsTrue((rs3 += 4) == Rshort(-13));

    //+  dvs. (rtal + tal)
	  rs3=Rshort(13,3);
	  Assert::IsTrue(rs3+rll2==Rshort(19,3));
	  Assert::IsTrue(rs3+2==Rshort(19,3));

    //unärt ”–” dvs. rtal1 = -rtal2;
	  Assert::IsTrue( (rs0=-rs1)==Rshort(-1));

    //båda ++ operatorerna, dvs. ++rtal; rtal++;
	  rll3 = RLL(1,6);
	  Assert::IsTrue(++rll3==RLL(7,6));
	  Assert::IsTrue(rll3++==RLL(7,6));
	  Assert::IsTrue(rll3==RLL(13,6));

    // explicit konvertering till Tal. (Kräver VS2012 och kompilator CTP november 12.
	  int i = static_cast<int>(rll3);
	  Assert::IsTrue(i==2);

    // Overloading av << och >> (ut och in matning)
	  std::cout << "Utmatning>" << rs3 << "< skriv in texten mellan > och < + retur\n";
	  std::cin >> rs2;
	  Assert::IsTrue(rs3==rs2);
	 }

    TEST_METHOD(VG)
    {
	  Rational<short> as0, as1(1), as2(2,1), as3(3);
	  Rational<long long> all0, all1(1), all2(2,1), all3(3);
	  Assert::IsTrue(1000000+Rshort(1,2) == Rint(2000001,2));	//blir bara rätt om man man räknar med int
	  Assert::IsTrue(Rshort(1,2)+1000000 == Rint(2000001,2));	//blir bara rätt om man man räknar med int
	  Assert::IsTrue(RLL(10000000LL)+Rshort(1,2) == RLL(20000001,2));	//blir bara rätt om man man räknar med int

	  Assert::IsTrue(Rshort(10000, 81)+Rshort(10000, 81) == Rshort(20000, 81));	//blir bara rätt om man man räknar med int

	  Assert::IsTrue((Rshort(1)+(short)SHRT_MAX)==SHRT_MIN);
	  Assert::IsTrue((Rshort(1)+(int)INT_MAX)==INT_MIN);
    }
    
	};
}