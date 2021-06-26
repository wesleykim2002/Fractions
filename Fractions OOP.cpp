/*
	Wesley Kim
	November 10, 2020
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <iomanip>

using namespace std;


class Fraction
{
	private:
		int numerator, denominator;
		
	public:
		Fraction()
		{
			numerator = 0;
			denominator = 1;
		}
		
		Fraction(int num, int den)
		{
			numerator = num;
			denominator = den;
		}
		
		//accessor
		int get_num() const
		{
			return numerator;
		}
		
		int get_den() const
		{
			return denominator;
		}
		
		//mutator
		void set_num(int num)
		{
			numerator = num;
		}
		
		void set_den(int den)
		{
			if (den < 0)
			{
				denominator = den*(-1);
				numerator *= -1;
			}
			else if (den > 0)
				denominator = den;
			else
				cout << "INVALID ENTRY";
		}
		
		//since |num| < |denom|, denom can never be 0
		double rounded(int decimals) const
		{
			return round(((double)numerator/denominator)*pow(10,decimals))/
				(double)(pow(10,decimals));
		}
		
		bool isExactlySame(Fraction const & other) const
		{
			if ((numerator==other.numerator)&&(denominator==other.denominator))
				return true;
			else
				return false;
		}
		
		void output() const
		{
			cout << numerator << "/" << denominator;
		}
};

int main()
{
	Fraction fracOne;
	cout << "Enter the numerator and denominator: " << endl;
	int num = 0, den = 0;
	cin >> num >> den;
	fracOne.set_num(num);
	fracOne.set_den(den);
	fracOne.output();
	cout << endl;
	
	cout << "How many decimal places should this fraction be rounded to? "
		<< endl;
	int decimals = 0;
	cin >> decimals;
	cout << "Rounded: " << fracOne.rounded(decimals) << endl;
	
	cout << "Enter the numerator and denominator: " << endl;
	int numer = 0, denom = 0;
	cin >> numer >> denom;
	Fraction fracTwo(numer,denom);
	fracTwo.output();
	cout << endl;
	
	cout << "How many decimal places should this fraction be rounded to? "
		<< endl;
	int decimalPlaces = 0;
	cin >> decimalPlaces;
	cout << "Rounded: " << fracTwo.rounded(decimalPlaces) << endl;
	
	cout << "The fractions are ";
	if (fracOne.isExactlySame(fracTwo))
		cout << "the same!" << endl;
	else
		cout << "different! " << endl;
	
	return 0;
}

/* Test Case
Enter the numerator and denominator:
3
7
3/7
How many decimal places should this fraction be rounded to?
4
Rounded: 0.4286
Enter the numerator and denominator:
-3
7
-3/7
How many decimal places should this fraction be rounded to?
3
Rounded: -0.429
The fractions are different!

--------------------------------
Process exited after 8.281 seconds with return value 0
Press any key to continue . . .
*/

/*
Enter the numerator and denominator:
3
-5
-3/5
How many decimal places should this fraction be rounded to?
1
Rounded: -0.6
Enter the numerator and denominator:
-3
5
-3/5
How many decimal places should this fraction be rounded to?
2
Rounded: -0.6
The fractions are the same!

--------------------------------
Process exited after 13.93 seconds with return value 0
Press any key to continue . . .
*/
