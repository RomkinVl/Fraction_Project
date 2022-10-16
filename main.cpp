#include <iostream>
using namespace std;

class Fraction
{
	int numerator;
	int denominator;
	int whole;
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

	void set_whole(int whole)
	{
		this->whole = whole;
	}

	int get_numerator() const
	{
		return numerator;
	}

	int get_denominator() const
	{
		return denominator;
	}

	int get_whole() const
	{
		return whole;
	}

	Fraction(int wh = 0, int num = 0, int den = 1)
	{
		whole = wh;
		numerator = num;
		set_denominator(den);
	}

	Fraction(const Fraction& other)
	{
		this->whole = other.whole;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}

	Fraction ImpFraction(Fraction& f)
	{
		Fraction F;
		F.whole = 0;
		F.numerator = f.whole * f.numerator;
		F.denominator = f.denominator;
		return F;
	}

	Fraction Add(Fraction& f1, Fraction& f2)
	{
		Fraction f1_n;
		Fraction f2_n;
		if (f1.whole > 0) f1_n = f1.ImpFraction(f1);
		if (f2.whole > 0) f2_n = f2.ImpFraction(f2);
		//f1_n.Print();
		/*cout << "\t";
		f2_n.Print();
		cout << endl;*/
		Fraction f3;
		f3.numerator = f1_n.numerator * f2_n.denominator + f2_n.numerator * f1_n.denominator;
		f3.denominator = f1_n.denominator * f2_n.denominator;
		/*f3.Print();
		cout << endl;*/
		f3 = f3.Reduction(f3);
		f3 = f3.WholeSelection(f3);
		return f3;
	}

	Fraction Sub(Fraction& f1, Fraction& f2)
	{
		Fraction f1_n;
		Fraction f2_n;
		if (f1.whole > 0) f1_n = f1.ImpFraction(f1);
		if (f2.whole > 0) f2_n = f2.ImpFraction(f2);
		/*f1_n.Print();
		cout << "\t";
		f2_n.Print();
		cout << endl;*/
		Fraction f3;
		f3.numerator = f1_n.numerator * f2_n.denominator - f2_n.numerator * f1_n.denominator;
		f3.denominator = f1_n.denominator * f2_n.denominator;
		f3 = f3.Reduction(f3);
		f3 = f3.WholeSelection(f3);
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

	//Сравнения
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

	bool EqualsOrMore(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
		return f1.numerator >= f2.numerator;
	}

	bool EqualsOrLess(Fraction f1, Fraction f2)
	{
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.denominator;
		f2.numerator *= f1.denominator;
		f2.denominator *= f1.denominator;
		return f1.numerator <= f2.numerator;
	}
	//Конец блока сравнений

	Fraction Square(Fraction& f)
	{
		f.numerator = sqrt(f.numerator);
		f.denominator = sqrt(f.denominator);
		return f;
	}

	double Decimal(Fraction f)
	{
		return ((double)whole * (double)f.numerator) / (double)f.denominator;
	}

	void Print()
	{
		if (this->whole == 0)
			cout << this->numerator << "/" << this->denominator;
		else cout << this->whole << "-" << this->numerator << "/" << this->denominator;
	}

	Fraction Reduction(Fraction& f)
	{
		Fraction result(0, f.numerator, f.denominator);
		for (int i = 2; i < 100 ; i++)
		{
			if ((f.numerator % i == 0) && (f.denominator % i == 0))
			{
				result.numerator = f.numerator / i;
				result.denominator = f.denominator / i;
				return result;
			}
		}

		return result;
	}

	Fraction WholeSelection(Fraction& f)
	{
		if (f.numerator < f.denominator)
			return f;					//Возвращаем ту же дробь, потому как она является правильной, выделять целую часть не нужно
		Fraction F;
		if (f.numerator % f.denominator == 0)
		{
			F.whole = f.numerator / f.denominator;
			F.numerator = 0;
			F.denominator = 0;
			return F;
		}//Возвращаем результат от деления, т.к.к числитель нацело делится на знаменатель

		
		F.whole = f.numerator / f.denominator;
		F.numerator = f.numerator - F.whole * f.denominator;
		F.denominator = f.denominator;
		return F;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	//Fraction f1(1, 1, 3);//Создаем f1
	//f1.Print();
	//cout << endl;
	//Fraction f2(1, 8, 9);//Создаем f2
	//f2.Print();
	//cout << endl;
	//Fraction f3;//Создаем f3
	//f3 = f1.Add(f1, f2); //Проверка Add()
	//f3.Print();
	//cout << endl;
	//Fraction f4; //Создаем f4
	//f4 = f1.Sub(f1, f2); //Проверка Sub()
	//f4.Print();
	//cout << endl;
	//Fraction f5; //Создаем f5
	//f5 = f1.Mult(f1, f2); //Проверка Mult()
	//f5.Print();
	//cout << endl;
	//Fraction f6; //Создаем f6
	//f6 = f1.Div(f1, f2); //Проверка Div()
	//f6.Print();
	//cout << endl;
	//Fraction f7; // Создаем f7
	//f7 = f2.Pow(f2, 3); //Проверяем Pow()
	//f7.Print();
	//cout << endl;
	//bool temp;
	//temp = f1.Equals(f1, f2);
	//cout << temp << endl;
	//cout << f1.NotEquals(f1, f2) << endl;
	//cout << f1.Less(f1, f2) << endl;
	//cout << f1.More(f1, f2) << endl;
	//Fraction f8;
	//f8 = f2.Square(f2);
	//f8.Print();
	//cout << endl;
	//double f9;
	//f9 = f2.Decimal(f2);
	//cout << f9 << endl;
	//Fraction f10;
	//f10 = f6.Reduction(f6);
	//f10.Print();
	//cout << endl;

	Fraction F1(2, 3, 4);
	Fraction F2(5, 4, 8);
	Fraction add_result = F1.Add(F1, F2);
	add_result.Print();
	cout << endl;
	Fraction sub_result = F1.Sub(F1, F2);
	sub_result.Print();
	cout << endl;
	return 0;
}