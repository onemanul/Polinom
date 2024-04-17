#include "pch.h"
#include "CppUnitTest.h"
#include "..\Polinom\Monomial.cpp"

namespace Microsoft {
	namespace VisualStudio {
		namespace CppUnitTestFramework {
			template <> static std::wstring ToString(const Monomial& mono) {
				wstringstream s;
				Monomial m = mono;
				s.precision(4);       // можно указать сколько знаков выводить в поток
				s << m.GetKoef() << "x^" << m.GetStep() << ' ';
				return s.str();
			}
		}
	}
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestMono
{
	TEST_CLASS(TestMono)
	{
	public:
		
		TEST_METHOD(UmnDouble1)
		{
			Monomial a(3, 2), b(15,2), c;
			double d = 5;
			c = a * d;
			Assert::AreEqual(b, c);
		}
		TEST_METHOD(UmnDouble2)
		{
			Monomial a(3, 2), b(15, 2), c;
			double d = 5;
			c = d * a;
			Assert::AreEqual(b, c);
		}
		TEST_METHOD(UmnMono1)
		{
			Monomial a(3, 2), b(4, 3), c(12,5), d;
			d = a*b;
			Assert::AreEqual(c,d);
		}
		TEST_METHOD(UmnMono2)
		{
			Monomial a(3, 2), b(4, 3), c(12, 5), d;
			d = a * b;
			Assert::AreEqual(c, d);
		}
	};
}
