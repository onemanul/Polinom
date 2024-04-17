#pragma once
#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include "Monomial.h"
#include <vector>
#include <algorithm>
class Polynomial {
	public:
		Polynomial() {}
		Polynomial(vector <Monomial> v) : vec(v) {}
		Polynomial(vector < pair <int,double> > p);
		Polynomial(vector <double> v);
		vector <Monomial> vec;
		friend Polynomial operator*(double A, Polynomial poly);
		friend Polynomial operator*(Polynomial poly, double A);
		friend Polynomial operator*(Monomial& mono, Polynomial& poly);
		friend Polynomial operator*(Polynomial& poly, Monomial& mono);
		friend Polynomial operator*(Polynomial& left, Polynomial& right);
		friend Polynomial operator+(Polynomial& left, Polynomial& right);
		friend Polynomial operator-(Polynomial& left, Polynomial& right);
		friend bool operator==(const Polynomial& left, const Polynomial& right);
		friend ostream& operator<<(ostream& out, Polynomial poly);
};

#endif // POLYNOMIAL_H_INCLUDED