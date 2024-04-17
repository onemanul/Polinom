#include "Monomial.h"

Monomial::Monomial(double a, int n) {
	SetKoef(a);
	SetStep(n);
}

Monomial operator* (double& A, Monomial& mono) {
	return Monomial(mono.GetKoef() * A, mono.GetStep());
}
Monomial operator*(Monomial& mono, double& A) {
	return (A*mono);
}

Monomial operator*(Monomial& left, Monomial& right) {
	return Monomial(left.GetKoef() * right.GetKoef(), left.GetStep() + right.GetStep());
}

ostream& operator<<(ostream& out, Monomial mono) {
	if (mono.GetKoef()) {
		if ((mono.GetStep()) && (mono.GetKoef() != 1) && (mono.GetKoef() != -1)) {
			if (mono.GetStep() == 1) out << mono.GetKoef() << "x ";
			else out << mono.GetKoef() << "x^" << mono.GetStep() << " ";
		}
		if ((mono.GetStep()) && (mono.GetKoef() == 1)) {
			if (mono.GetStep() == 1) out << "x ";
			else out << "x^" << mono.GetStep() << " ";
		}
		if ((mono.GetStep()) && (mono.GetKoef() == -1)) {
			if (mono.GetStep() == 1) out << "-x ";
			else out << "-x^" << mono.GetStep() << " ";
		}
		if (!mono.GetStep()) out << mono.GetKoef() << " ";
	}
	return out;
}

bool operator==(const Monomial& left, const Monomial& right) {
	return ( (left.m.first == right.m.first) && (left.m.second == right.m.second) );
}