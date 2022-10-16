#include <iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;
public:
	void set_numerator(int num)
	{
		numerator = num;
	}

	void set_denominator(int den)
	{
		if (den != 0)
			denominator = den;
		else
			cout << "Знаменатель не может быть равен нулю!" << endl;
	}

	int get_numerator()
	{
		return numerator;
	}

	int get_denominator()
	{
		return denominator;
	}

	Fraction(int num = 0, int den = 1)
	{
		numerator = num;
		set_denominator(den);
	}

	Fraction(const Fraction& other) 
	{
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}

	Fraction Add(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}

	Fraction Sub(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}

	Fraction Mult(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.numerator;
		f3.denominator = f1.denominator * f2.denominator;
		return f3;
	}

	Fraction Div(Fraction f1, Fraction f2)
	{
		Fraction f3;
		f3.numerator = f1.numerator * f2.denominator;
		f3.denominator = f1.denominator * f2.numerator;
		return f3;
	}

	Fraction Pow(Fraction f, int n)
	{
		Fraction f2(f.numerator, f.denominator);
		for (int i = 0; i < n; i++)
		{
			f2.numerator *= f.numerator;
			f2.denominator *= f.denominator;
		}

		return f2;

	}

	bool Equals(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
		return f1.numerator == f2.numerator;
	}

	bool NotEquals(Fraction f1, Fraction f2)
	{
		return !Equals(f1, f2);
	}

	bool Less(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
		return f1.numerator < f2.numerator;
	}

	bool More(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
		return f1.numerator > f2.numerator;
	}

	Fraction Square(Fraction &f)
	{
		f.numerator = sqrt(f.numerator);
		f.denominator = sqrt(f.denominator);
	}

	double Decimal(Fraction f)
	{
		return f.numerator / f.denominator;
	}
};

int main()
{

	return 0;
}