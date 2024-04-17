#pragma once
#ifndef MONOMIAL_H_INCLUDED
#define MONOMIAL_H_INCLUDED

#include <iostream>
using namespace std;

class Monomial {
	public:
		Monomial() {}
		Monomial(pair <int, double> M) : m(M) {}
		Monomial(double a, int n);
		int GetStep() { return m.first; }
		void SetStep(int val) { m.first = val; }
		double GetKoef() { return m.second; }
		void SetKoef(double val) { m.second = val; }
		friend Monomial operator*(double& A, Monomial& mono);
		friend Monomial operator*(Monomial& mono, double& A);
		friend Monomial operator*(Monomial& left, Monomial& right);
		friend bool operator==(const Monomial& left, const Monomial& right);
		friend ostream& operator<<(ostream& out, Monomial mono);
	private:
		pair <int, double> m;
};

#endif // MONOMIAL_H_INCLUDED