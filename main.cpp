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
		for (int i = 1; i < n; i++)
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

	Fraction Square(Fraction& f)
	{
		f.numerator = sqrt(f.numerator);
		f.denominator = sqrt(f.denominator);
		return f;
	}

	double Decimal(Fraction f)
	{
		return (double)f.numerator / (double)f.denominator;
	}

	void Print()
	{
		cout << this->numerator << "/" << this->denominator;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	Fraction f1(1, 3);//Создаем f1
	f1.Print();
	cout << endl;
	Fraction f2(8, 9);//Создаем f2
	f2.Print();
	cout << endl;
	Fraction f3;//Создаем f3
	f3 = f1.Add(f1, f2); //Проверка Add()
	f3.Print();
	cout << endl;
	Fraction f4; //Создаем f4
	f4 = f1.Sub(f1, f2); //Проверка Sub()
	f4.Print();
	cout << endl;
	Fraction f5; //Создаем f5
	f5 = f1.Mult(f1, f2); //Проверка Mult()
	f5.Print();
	cout << endl;
	Fraction f6; //Создаем f6
	f6 = f1.Div(f1, f2); //Проверка Div()
	f6.Print();
	cout << endl;
	Fraction f7; // Создаем f7
	f7 = f2.Pow(f2, 3); //Проверяем Pow()
	f7.Print();
	cout << endl;
	cout << f1.Equals(f1, f2) << endl;
	cout << f1.NotEquals(f1, f2) << endl;
	cout << f1.Less(f1, f2) << endl;
	cout << f1.More(f1, f2) << endl;
	Fraction f8;
	f8 = f2.Square(f2);
	f8.Print();
	cout << endl;
	double f9;
	f9 = f2.Decimal(f2);
	cout << f9 << endl;
	return 0;
}