/*Develop an object oriented program in C++ to create a database of the personnel
information system containing the following information: Name, Date of Birth, Blood
group, Height, Weight, Insurance Policy, number, Contact address, telephone number,
driving license no. etc Construct the database with suitable member functions for
initializing and destroying the data viz constructor, default constructor, copy, constructor,
destructor, static member functions, friend class, this pointer, inline code and dynamic
memory allocation operators-new and delete.*/

#include<iostream>
#include<string>
using namespace std;

class database
{
	private:
	static int count;
	string name, blood_grp, dob, license, address;
	float height, weight;
	long insurance_num, phone_num;

	public:
	void input();
	void output();
	void display_msg();
	static void calc_obj();
	friend void validate_phone(database &);
	database(database &);
	~database();
	database()
	{
		name = "XYZ";
		blood_grp="O";
		dob="01-01-01";
		address="ABC";
		insurance_num=123;
		phone_num=123;
		height=0;
		weight=0;
	}
};

database::~database()
{
	cout<<"\nDestructor called!";
}

int database::count = 0;

inline void database::display_msg()
{
	cout<<"\n-----------------------------Personal Information Database------------------------\n";
}

void database::calc_obj()
{
	count+=1;
	cout<<"\nEntry "<<count<<": \n";
}

void database::input()
{
	cin.ignore();
	cout<<"\nEnter name: ";
	getline(cin, name);
	cout<<"\nEnter date of birth: ";
	getline(cin, dob);
	cout<<"\nEnter address: ";
	getline(cin, address);
	cout<<"\nEnter phone number: ";
	cin>>phone_num;
	cin.ignore();
	cout<<"\nEnter license number: ";
	getline(cin, license);
	cout<<"\nEnter insurance policy number: ";
	cin>>insurance_num;
	cout<<"\nEnter height: ";
	cin>>height;
	cout<<"\nEnter weight: ";
	cin>>weight;
	cin.ignore();
	cout<<"\nEnter blood group: ";
	getline(cin, blood_grp);
}

void validate_phone(database &obj1)
{
	long temp,temp1;
	temp = obj1.phone_num;
	int digit;
	do {
		digit = 0;
		temp = obj1.phone_num;
		temp1 = temp;
		while(temp != 0) {
			temp = temp/10;
			digit++;
		}
		if(digit != 10) {
			cout<<"\nInvalid phone number!";
			cout<<"\nEnter valid phone number(10 digits): ";
			cin>>obj1.phone_num;
		}
	}while(digit != 10);
	obj1.phone_num = temp1;
}

void database::output()
{
	cout<<"\nName: "<<name;
	cout<<"\nDate of Birth: "<<dob;
	cout<<"\nAddress: "<<address;
	cout<<"\nPhone number: "<<phone_num;
	cout<<"\nLicense number: "<<license;
	cout<<"\nInsurance Policy number: "<<insurance_num;
	cout<<"\nHeight: "<<height;
	cout<<"\nWeight: "<<weight;
	cout<<"\nBlood Group: "<<blood_grp;
}

database::database(database &obj2)
{
	cout<<"\nCopy Constructor called!";
	name = obj2.name;
	dob = obj2.dob;
	address = obj2.address;
	phone_num = obj2.phone_num;
	license = obj2.license;
	insurance_num = obj2.insurance_num;
	height = obj2.height;
	weight = obj2.weight;
	blood_grp = obj2.blood_grp;
}

int main()
{
	int entries;
	cout<<"\nHow many entries? ";
	cin>>entries;
	database *obj[entries];
	database d;
	d.display_msg();
	for(int i=0; i<entries; i++) {
		obj[i] = new database;
		database::calc_obj();
		obj[i]->input();
		validate_phone(*obj[i]);
		obj[i]->output();
	}
	database *d1;
	d1 = new database;
	{
		database d2;
		d2.input();
		{
			database d3 = d2;
		}
	}
	delete d1;	
	return 0;
}









































