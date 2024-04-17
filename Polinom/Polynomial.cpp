#include "Polynomial.h"

Polynomial::Polynomial(vector < pair <int, double> > p) {
	for (int i = 0; i < p.size(); ++i) {
		Monomial mono(p[i]);
		vec.push_back(mono);
	}
}
Polynomial::Polynomial(vector<double> v) {
	Monomial mono;
	for (int i = 0; i < v.size(); ++i) {
		mono.SetKoef(v[i]);
		mono.SetStep(v.size() - 1 - i);
		vec.push_back(mono);
	}
}

ostream& operator<<(ostream& out, Polynomial poly) {
	for (int i = 0; i < poly.vec.size(); ++i) {
		out << poly.vec[i];
	}
	out << "\n";
	return out;
}

Polynomial operator*(double A, Polynomial poly) { // двусторонн€€
	Polynomial tmp = poly;
	for (int i = 0; i < tmp.vec.size(); ++i) {
		tmp.vec[i].SetKoef(A * tmp.vec[i].GetKoef());
	}
	return tmp;
}
Polynomial operator*(Polynomial poly, double A) { // обратна предыдущей
	return (A*poly);
}

Polynomial operator*(Monomial& mono, Polynomial& poly) { // двусторонн€€
	Polynomial tmp = poly;
	for (int i = 0; i < tmp.vec.size(); ++i) {
		tmp.vec[i] = tmp.vec[i] * mono;
	}
	return tmp;
}
Polynomial operator*(Polynomial& poly, Monomial& mono) { // обратна предыдущей
	return (mono*poly);
}

bool comp(Monomial a, Monomial b) { // компаратор дл€ сортировки одночленов по убыванию
	return a.GetStep() > b.GetStep();
}
void Sort_and_Plus(Polynomial& poly) {
	sort(poly.vec.begin(), poly.vec.end(), comp);
	for (int i = 0; i < poly.vec.size() - 1; ++i) {
		if (!poly.vec[i].GetKoef()) {
			poly.vec.erase(poly.vec.begin() + i);
			--i;
		}
		else 
			if (poly.vec[i].GetStep() == poly.vec[i+1].GetStep()) {
				poly.vec[i].SetKoef(poly.vec[i].GetKoef() + poly.vec[i+1].GetKoef());
				poly.vec.erase(poly.vec.begin() + i + 1);
				--i;
			}
	}
}
Polynomial operator*(Polynomial& left, Polynomial& right) {
	Polynomial poly;
	Monomial mono;
	for (int i = 0; i < left.vec.size(); ++i) {
		for (int j = 0; j < right.vec.size(); ++j) {
			mono = left.vec[i] * right.vec[j];
			poly.vec.push_back(mono);
		}
	}
	Sort_and_Plus(poly);
	return poly;
}

Polynomial operator+(Polynomial& left, Polynomial& right) {
	Polynomial tmp = left;
	for (int i = 0; i < right.vec.size(); ++i) {
		tmp.vec.push_back(right.vec[i]);
	}
	Sort_and_Plus(tmp);
	return tmp;
}
Polynomial operator-(Polynomial& left, Polynomial& right) {
	Polynomial tmp = -1 * right;
	return (left + tmp);
}

bool operator==(const Polynomial& left, const Polynomial& right) {
	if (left.vec.size() != right.vec.size()) return false;
	for (int i = 0; i < left.vec.size(); ++i) {
		if ( !(left.vec[i] == right.vec[i]) ) return false;
	}
	return true;
}