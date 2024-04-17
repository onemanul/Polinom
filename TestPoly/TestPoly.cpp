#include "pch.h"
#include "CppUnitTest.h"
#include "..\Polinom\Monomial.cpp"
#include "..\Polinom\Polynomial.cpp"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const Polynomial& poly) {
				wstringstream s;
				Polynomial p = poly;
				s.precision(4);       // можно указать сколько знаков выводить в поток
				for (auto i = 0; i != p.vec.size(); ++i) {
					s << p.vec[i].GetKoef() << "x^" << p.vec[i].GetStep() << ' ';
				}
				return s.str();
			}
		}
	}
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPoly
{
	TEST_CLASS(TestPoly)
	{
	public:
		
		TEST_METHOD(UmnDouble1)
		{
			vector <double> v{ 2,4,3 }, w{ 10,20,15 };
			Polynomial p(v), t(w), s;
			double a = 5;
			s = a * p;
			Assert::AreEqual(t, s);
		}
		TEST_METHOD(UmnDouble2)
		{
			vector <double> v{ 2,4,3 }, w{ 10,20,15 };
			Polynomial p(v), t(w), s;
			double a = 5;
			s = p * a;
			Assert::AreEqual(t, s);
		}
		TEST_METHOD(UmnMono1)
		{
			vector <double> v{ 2,4,3 };
			vector < pair <int, double> > w{ {4,6}, {3,12}, {2,9} };
			Monomial a(3, 2);
			Polynomial p(v), t(w), s;
			s = a * p;
			Assert::AreEqual(t, s);
		}
		TEST_METHOD(UmnMono2)
		{
			vector <double> v{ 2,4,3 };
			vector < pair <int, double> > w{ {4,6}, {3,12}, {2,9} };
			Monomial a(3, 2);
			Polynomial p(v), t(w), s;
			s = p * a;;
			Assert::AreEqual(t, s);
		}
		TEST_METHOD(UmnPoly1)
		{
			vector <double> v{ 1,3,5 }, w{ 2,4,6 };
			vector < pair <int, double> > u{ {4,2}, {3,10}, {2,28}, {1,38}, {0,30} };
			Polynomial p(v), t(w), s(u), r;
			r = p * t;
			Assert::AreEqual(s, r);
		}
		TEST_METHOD(UmnPoly2)
		{
			vector <double> v{ 1,1 }, w{ 1,-1 };
			vector < pair <int, double> > u{ {2,1}, {0,-1} };
			Polynomial p(v), t(w), s(u), r;
			r = p * t;
			Assert::AreEqual(s,r);
		}
		TEST_METHOD(AddPoly1)
		{
			vector <double> v{ 1,3,5 }, w{ 2,4,6 };
			vector < pair <int, double> > u{ {2,3}, {1,7}, {0,11} };
			Polynomial p(v), t(w), s(u), r;
			r = p + t;
			Assert::AreEqual(s, r);
		}
		TEST_METHOD(AddPoly2)
		{
			vector <double> v{ 3,4 };
			vector < pair <int, double> > w{{3,5},{2,6}}, u{ {3,5}, {2,6}, {1,3}, {0,4} };
			Polynomial p(v), t(w), s(u), r;
			r = p + t;
			Assert::AreEqual(s, r);
		}
		TEST_METHOD(SubPoly1)
		{
			vector <double> v{ 1,3,5 }, w{ 3,7,10 };
			vector < pair <int, double> > u{ {2,-2}, {1,-4}, {0,-5} };
			Polynomial p(v), t(w), s(u), r;
			r = p - t;
			Assert::AreEqual(s, r);
		}
		TEST_METHOD(SubPoly2)
		{
			vector <double> v{ 3,4 };
			vector < pair <int, double> > w{{3,5},{2,6}}, u{ {3,-5}, {2,-6}, {1,3}, {0,4} };
			Polynomial p(v), t(w), s(u), r;
			r = p - t;
			Assert::AreEqual(s, r);
		}
	};
}