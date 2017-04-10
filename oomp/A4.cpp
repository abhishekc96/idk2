/*Design a C++ Class ‘Complex ‘ with data members for real and imaginary part. Provide
default and parameterized constructors. Write a program to perform arithmetic operations
of two complex numbers using operator overloading (using either member functions or
friend functions).*/

#include<iostream>
using namespace std;

class complex
{
	private:
	float r,i;

	public:
	complex();
	complex operator+(complex);
	friend complex operator-(complex, complex);
	complex operator*(complex);
	complex operator/(complex);
	void input();
	void output();
	void displayop();
};

complex::complex()
{
	r = 0.0;
	i = 0.0;
}

void complex::input()
{
	cout<<"\nEnter the real part: ";
	cin>>r;
	cout<<"\nEnter the imaginary part: ";
	cin>>i;
}

void complex::output()
{
	cout<<"\nGiven number = "<<r<<" + "<<i<<"i"<<endl;
}

void complex::displayop()
{
	cout<<r<<" + "<<i<<"i"<<endl;
}

complex complex::operator+(complex a1)
{
	complex a;
	a.r = r + a1.r;
	a.i = i + a1.i;
	return a;
}

complex operator-(complex a1, complex a2)
{
	complex a;
	a.r = a1.r - a2.r;
	a.i = a1.i - a2.i;
	return a;
}

complex complex::operator*(complex a1)
{
	complex a;
	a.r = (r * a1.r) - (i * a1.i);
	a.i = (r * a1.i) + (i * a1.r);
	return a;
}

complex complex::operator/(complex a1)
{
	complex a;
	a.r = ((r * a1.r) + (i * a1.i)) / ((a1.r * a1.r) + (a1.i * a1.i));
	a.i = (-(r * a1.i) + (i * a1.r)) / ((a1.r * a1.r) + (a1.i * a1.i));
	return a;
}

int main()
{
	complex a,b,c;
	int choice;
	char ans;
	do {
	cout<<"\n1)Addition";
	cout<<"\n2)Subtraction";
	cout<<"\n3)Multiplication";
	cout<<"\n4)Division";
	cout<<"\n5)Exit\n";
	cout<<"\nEnter your choice of operation: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		cout<<"\nFirst complex number:";
		a.input();
		a.output();
		cout<<"\nSecond complex number:";	
		b.input();
		b.output();
		c = a+b;
		cout<<"\nAddition = ";
		c.displayop();
		break;

		case 2:
		cout<<"\nFirst complex number:";
		a.input();
		a.output();
		cout<<"\nSecond complex number:";	
		b.input();
		b.output();
		c = a-b;
		cout<<"\nSubtraction = ";
		c.displayop();
		break;

		case 3:
		cout<<"\nFirst complex number:";
		a.input();
		a.output();
		cout<<"\nSecond complex number:";	
		b.input();
		b.output();
		c = a*b;
		cout<<"\nMultiplication = ";
		c.displayop();
		break;

		case 4:
		cout<<"\nFirst complex number:\n";
		a.input();
		a.output();
		cout<<"\nSecond complex number:\n";	
		b.input();
		b.output();
		c = a/b;
		cout<<"\nDivision = ";
		c.displayop();
		break;

		case 5:
		break;
	}
	cout<<"\n\nDo you wish to continue?(y/n): ";
	cin>>ans;
	}while(ans == 'y' || ans == 'Y');
	
	return 0;
}














































