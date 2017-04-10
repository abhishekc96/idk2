/*Create a C++ class named Television that has data members to hold the model number
and the screen size in inches, and the price. Member functions include overloaded
insertion and extraction operators. If more than four digits are entered for the model, if
the screen size is smaller than 12 or greater than 70 inches, or if the price is negative or
over $5000 then throw an integer. Write a main() function that instantiates a television
object, allows user to enter data and displays the data members .If an exception is caught,
replace all the data member values with zero values.*/

#include<iostream>
using namespace std;
	
class television
{
	private:
	int model, screen, price;
	
	public:
	friend ostream& operator<<(ostream &, television &);
	friend istream& operator>>(istream &, television &);
};

istream& operator>>(istream &in, television &tv)
{
	cout<<"\nEnter the model number: ";
	in>>tv.model;
	cout<<"\nEnter the screen size(inches): ";
	in>>tv.screen;
	cout<<"\nEnter the price($): ";
	in>>tv.price;
	
	int digit = 0;
	int temp;
	int flag = 0;
	try {
		temp = tv.model;
		while(temp != 0) {
			temp = temp/10;
			digit++;
		}
		if(digit>4)
			throw 1;
	}
	
	catch(int) {
		cout<<"\nThe model number is not available!\n";
		flag = 1;
	}

	try {
		if(tv.screen<12 || tv.screen>70)
			throw 2;
	}

	catch(int) {
		cout<<"\nThe screen size is not available!\n";
		flag = 1;
	}

	try {
		if(tv.price<0 || tv.price>5000)
			throw 3;
	}

	catch(int) {
		cout<<"\nThe price is not available!\n";
		flag = 1;
	}

	if(flag == 1) {
		tv.model = 0;
		tv.screen = 0;
		tv.price = 0;
	}
}

ostream& operator<<(ostream &out, television &tv) 
{
	out<<"\nModel number: "<<tv.model;
	out<<"\nScreen size: "<<tv.screen<<" inches";
	out<<"\nPrice: "<<tv.price<<"$\n\n";
}

int main()
{
	television t1;
	cin>>t1;
	cout<<t1;
	return 0;
}



















