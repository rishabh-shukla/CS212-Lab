using namespace std;
Fraction::Fraction(int a,int b){			// Constructor
	iNumerator = a;
	uiDenominator = b;
}
Fraction ::Fraction(const Fraction &F){   			// Copy Constructor
	iNumerator = F.iNumerator;
	uiDenominator = F.uiDenominator;
}
Fraction& Fraction::operator =(const Fraction& F){				// Assignment Overloaded
	if(this==&F){
		return *this;
	}
	iNumerator = F.iNumerator;
	uiDenominator = F.uiDenominator;
	return *this;
}

Fraction Fraction::operator -(){						// Unary - operator
	return Fraction((-1)*iNumerator,uiDenominator);
}
Fraction Fraction:: operator +(){				// Unary + operator
	return *this;
}
Fraction & Fraction::operator --(){				// Pre-decrement operator
	iNumerator -= uiDenominator;
	return *this;
}
Fraction & Fraction::operator ++(){				// Pre-increment operator
	iNumerator += uiDenominator;
	return *this;
}
int gcd(int a,int b){				// gcd function
	int min,max=1;
	min = (a>b)?b:a;
	for(int i=1;i<=min;i++){
		if(a%i==0 && b%i==0)
			max=i;
	}
	return max;
}
Fraction operator +(const Fraction& F1, const Fraction& F2){			// + operator
	int num,denom;
	num = F1.iNumerator*F2.uiDenominator+F1.uiDenominator*F2.iNumerator;
	denom = F1.uiDenominator*F2.uiDenominator;
	int div = gcd(num,denom);
	return Fraction(num/div,denom/div);
}
Fraction:: ~Fraction(){}
Fraction operator/(const Fraction& F1, const Fraction& F2){			// Division / operator
	int num,denom;
	num =  F1.iNumerator*F2.uiDenominator;
	denom = F1.uiDenominator*F2.iNumerator;
	int div = gcd(num,denom);
	return Fraction(num/div,denom/div);
}

bool Fraction:: operator ==(const Fraction &F){							//  == operator
	if((F.iNumerator==iNumerator)&&(F.uiDenominator==uiDenominator))
		return true;
	return false;
}
bool Fraction:: operator !=(const Fraction &F){								//   != operator
	if((F.iNumerator!=iNumerator)||(F.uiDenominator!=uiDenominator))
		return true;
	return false;
}
bool Fraction:: operator <(const Fraction &F){							//    < operator
	float lhs,rhs;
	lhs = (1.0*iNumerator)/(1.0*uiDenominator);
	rhs = (1.0*F.iNumerator)/(1.0*F.uiDenominator);
	if(lhs<rhs) return true;
	else return false;
}
bool Fraction:: operator <=(const Fraction &F){							//   <= operator
	float lhs,rhs;
	lhs = (1.0*iNumerator)/(1.0*uiDenominator);
	rhs = (1.0*F.iNumerator)/(1.0*F.uiDenominator);
	if(lhs<=rhs) return true;
	else return false;
}
bool Fraction:: operator >(const Fraction &F){								//  > operator
	float lhs,rhs;
	lhs = (1.0*iNumerator)/(1.0*uiDenominator);
	rhs = (1.0*F.iNumerator)/(1.0*F.uiDenominator);
	if(lhs>rhs) return true;
	else return false;
}
bool Fraction:: operator >=(const Fraction &F){								//  >= operator
	float lhs,rhs;
	lhs = (1.0*iNumerator)/(1.0*uiDenominator);
	rhs = (1.0*F.iNumerator)/(1.0*F.uiDenominator);
	if(lhs>=rhs) return true;
	else return false;
}
ostream& operator<<(ostream& out, const Fraction& F){							//    << operator
	return out<<F.iNumerator<<"/"<<F.uiDenominator;
}
istream& operator>>(istream& in, Fraction& F){									//    >> operator
	char c;
	in>>F.iNumerator;
	in>>c;
	in>>F.uiDenominator;
}

