// Peter Hughes
// CISC - 2000 L01
// HW #6
// 10/14/19
// Professor Vincent Mierlak



#include <iostream>
#include <cstdlib>

using namespace std;



// CLASS DECLARATION

class Rational
{

// MEMBER FUNCTIONS

public:

    Rational( );
    Rational(int num1, int num2);
    Rational(int num1);

    friend Rational operator -(const Rational& num1, const Rational& num2);
    friend Rational operator -(const Rational& fraction);
    friend Rational operator *(const Rational& num1, const Rational& num2);
    friend Rational operator /(const Rational& num1, const Rational& num2);
   
    friend bool operator ==(const Rational& num1, const Rational& num2);
    friend bool operator <(const Rational& num1, const Rational& num2);
    friend bool operator >(const Rational& num1, const Rational& num2);
    friend bool operator <=(const Rational& num1, const Rational& num2);
    friend bool operator >=(const Rational& num1, const Rational& num2);
    friend bool operator !=(const Rational& num1, const Rational& num2);
    
    friend istream& operator >>(istream& instream, const Rational& fraction);
    friend ostream& operator <<(ostream& outstream, const Rational& fraction);

    friend Rational normalize(Rational& num);

    bool input( );
    void output( );
    int getNumerator( );
    int getDenominator( );
    void sum(const Rational& a, const Rational& b);



// MEMBER VARIABLES

private:

    int numerator;

    int denominator;

};


// MAIN FUNCTION

int main(int argc, char *argv[])
{
    
    using namespace std;
    Rational a(1,2);
    cout << "The rational number a(1,2):\n";
    a.output();
    Rational b(2);
    cout << "The rational number b(2):\n";
    b.output();
    Rational c;
    cout << "The default rational number:\n";
    c.output();
/*    if (!c.input())
    {
        cout << "Invalid rational number." << endl;
        exit(1);
    }
    c.output();
*/
    cout << "The sum of 1/2 + 2/1 = 5/2:\n";
    c.sum(a,b);
    c.output();
    cout << "_______________HW7 test__________________" << endl;
    Rational d(-3,9);
    cout << "Normalize -3/9 = -1/3" << endl;
    cout << normalize(d) << endl;
    cout << "1/2 - 2/1 = -3/2" << endl;
    cout << a-b << endl;
    cout << "- 2/1 = -2/1" << endl;
    cout << -b << endl;
    cout << "1/2 * 2/1 = 2/2 = 1/1(normalized)" << endl;
    Rational x = a*b;
    cout << normalize(x) << endl;
    if(a<b)
      cout << "Print this if 1/2 < 2/1" << endl;
    if(a>b)
      cout << "Print if 1/2 > 2/1"; //won't be printed
    if(a <= b)
      cout << "Print this if 1/2 <= 2/1" << endl;
    if(a>=b)
      cout << "Print if 1/2 >= 2/1"; //wont be printed
    if(c==c)
      cout << "Print this if 0/1 == 0/1" << endl;
    if(c!=b)
      cout << "Print this if 0/1 != 2/1" << endl;
    cout << "(4 statements will be printed)" << endl;

    Rational e;
    cout << endl << "enter a number to be printed: (will be normalized)";
    cin >> e;
    cout << normalize(e);



    return 0;
}


int gcd(int m, int n)
{
	int t;
	m = abs(m);
	n = abs(n);
	
	if (n<m)
	{
		t = m;
		m = n;
		n = t;
	}

	int r;
	r = m % n;

	while (r!=0)
	{
		r = m % n;
		m = n;
		n = r;
	}

	return m;
}


// Constructor for rational objects without arguments
// Sets numerator to 0 and denominator to 1

Rational::Rational( )
{
    numerator = 0;
    denominator = 1;
}


// Constructor for rational arguments with single int value
// Sets numerator to given parameter and denominator to 1

Rational::Rational(int num1)
{
    numerator = num1;
    denominator = 1;
}


// Constructor for rational arguments with two int values
// Sets first value to numerator and second value to denominator

Rational::Rational(int num1, int num2)
{
    if (num2)
    {
        numerator = num1;
        denominator = num2;
    }

    else
    {
        cout << "Illegal rational number: cannot have 0 in denominator."<< endl;
        exit(1);
    }
}


// the current object

bool Rational::input()    
{
    char op;
    cout << "Enter a value in the form n/m:";
    cin >> numerator;
    cin >> op;
    cin >> denominator;

    if (op!= '/' || denominator == 0)
        return false;
    
    return true;
}


// Member function to display values of current object

void Rational::output()
{   
    cout << numerator << "/" << denominator << endl;
    return;
}


// Member function that sets current rational object to sum of the
// two given rational numbers


Rational operator -(const Rational& num1, const Rational& num2)
{
    Rational t1, t2;
    Rational temp;

    if (num1.denominator == num2.denominator)
    {
        temp.denominator = num1.denominator;
        temp.numerator = num1.numerator - num2.numerator;
        return temp;
    }

        else
        {
            t1.numerator = num1.numerator * num2.denominator;
            t1.denominator = num1.denominator * num2.denominator;
            t2.numerator = num2.numerator * num1.denominator;
            t2.denominator = num2.denominator * num1.denominator;
            temp.numerator = t1.numerator - t2.numerator;
            temp.denominator = t1.denominator;
        }

        return temp;
}


Rational operator -(const Rational& fraction)
{
    Rational temp;
    temp.numerator = -fraction.numerator;
    temp.denominator = fraction.denominator;
    return temp;
}

void Rational::sum(const Rational &a, const Rational &b)
{
    numerator = a.numerator * b.denominator + a.denominator * b.numerator;
    denominator = a.denominator * b.denominator;
    return;
}

Rational operator *(const Rational& num1, const Rational& num2)
{
    Rational temp;
    temp.numerator = num1.numerator * num2.numerator;
    temp.denominator = num1.denominator * num2.denominator;
    return temp;
}


bool operator ==(const Rational& num1, const Rational& num2)
{
    if( (num1.numerator == num2.numerator) && (num1.denominator == num2.denominator) )
        return true;
    return false;
}

bool operator !=(const Rational& num1, const Rational& num2)
{
    if( !(num1 == num2) )
        return true;
    return false;
}

bool operator >(const Rational& num1, const Rational& num2)
{
    if( (num1.numerator * num2.denominator) > (num1.denominator * num2.numerator) )
        return true;
    return false;
}

bool operator <(const Rational& num1, const Rational& num2)
{
    if( (num1.numerator * num2.denominator) < (num1.denominator * num2.numerator) )
        return true;
    return false;
}

bool operator <=(const Rational& num1, const Rational& num2)
{
    if( (num1.numerator * num2.denominator) <= (num1.denominator * num2.numerator) )
        return true;
    return false;
}

bool operator >=(const Rational& num1, const Rational& num2)
{
    if((num1.numerator * num2.denominator) >= (num1.denominator * num2.numerator))
        return true;
    return false;
}


istream& operator >>(istream& instream, const Rational& fraction)
{
    char op;
    cout << "Enter a rational number in the integer form n/m: ";
    cin >> fraction.numerator;
    cin >> op;
    cin >> fraction.denominator;

    return instream;
}

ostream& operator <<(ostream& outstream, const Rational& fraction)
{
    cout << fraction.numerator << '/' << fraction.denominator << endl;
    return outstream;
}


Rational normalize(Rational& num)
{
    using namespace std;

    Rational temp;

    if ((num.denominator<0||num.numerator<0)&&!(num.denominator<0 && num.numerator<0))
    {

        temp.numerator = num.numerator;
        temp.denominator = num.denominator;
        int divisor = gcd(temp.numerator, temp.denominator);
        temp.numerator = -(temp.numerator/divisor);
        temp.denominator = -(temp.denominator/divisor);
    }
    else
    {
        temp.numerator = num.numerator;
        temp.denominator = num.denominator;
        int divisor = gcd(temp.numerator, temp.denominator);
        temp.numerator = (temp.numerator/divisor);
        temp.denominator = (temp.denominator/divisor);
    }

    return temp;
	

}


// Member function to return int value of numerator in current object

int Rational::getNumerator( )
{
    return (numerator);
}


// Member function to return int value of denominator in current object

int Rational::getDenominator( )
{
    return (denominator);
}



