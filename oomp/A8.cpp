/*Design a C++ base class consisting of the data members such as name of the student, roll
number and subject. The derived class consists of the data members subject code,
internal assessment and university examination marks. Construct a virtual base class for
the item name of the student and roll number. The program should have the facilities.
i) Build a master table ii) List a table iii) Insert a new entry
iv) Delete old entry v) Edit an entry vi) Search for a record*/

#include<iostream>
#include<string>
using namespace std;   
#define max 50   

class database
{
	protected:
	string student_name, subject_name;
	int roll;

	public:
	void get_database();
	void print_database();
	int get_roll()
	{
		return roll;
	}
};

void database::get_database()
{
	cin.ignore();
	cout<<"\n\nEnter student name: ";
	getline(cin, student_name);
	//cin.ignore();
	cout<<"\nEnter subject name: ";
	getline(cin, subject_name);
	cout<<"\nEnter roll number: ";
	cin>>roll;
}                 

void database::print_database()
{
	cout<<"\n\nName: "<<student_name;
	cout<<"\nSubject: "<<subject_name;
	cout<<"\nRoll number: "<<roll;
}

class college:public virtual database
{
	protected:
	string subject_code;
	int internal_marks;
	
	public:
	void get_college();
	void print_college();
};

void college::get_college()
{
	cout<<"\nEnter subject code: ";
	cin>>subject_code;
	cout<<"\nEnter internal marks: ";
	cin>>internal_marks;
}

void college::print_college()
{
	cout<<"\nSubject code: "<<subject_code;
	cout<<"\nInternal marks: "<<internal_marks;
}

class uni:public virtual database
{
	protected:
	int uni_marks;

	public:
	void get_uni();
	void print_uni();
};

void uni::get_uni()
{
	cout<<"\nEnter university marks: ";
	cin>>uni_marks;
}

void uni::print_uni()
{
	cout<<"\nUniversity marks: "<<uni_marks;
}

class student:public college, public uni
{
	public:
	void build();
	void list();
	void insert();
	int search();
	void modify();
	int del();
	int mod();
};

void student::build()
{
	get_database();	
	get_college();
	get_uni();
}

void student::list()
{
	print_database();
	print_college();
	print_uni();
}

void student::insert()
{
	build();
}

int student::search()
{
	int temp_roll;
	cout<<"\nEnter the roll number you wish to search: ";
	cin>>temp_roll;
	return temp_roll;
}

void student::modify()
{
	int ch;
	char ans1;
	do {
		cout<<"\n\nWhat field do you wish to modify? ";
		cout<<"\n\n1)Student name";
		cout<<"\n2)Subject name";
		cout<<"\n3)Roll number";
		cout<<"\n4)Subject code";
		cout<<"\n5)Internal marks";
		cout<<"\n6)University marks\n";
		cout<<"\nEnter choice: ";	
		cin>>ch;
		switch(ch) {
				case 1:
				cin.ignore();
				cout<<"\n\nEnter new name: ";
				getline(cin, student_name);
				break;
		
				case 2:
				cin.ignore();
				cout<<"\n\nEnter new subject: ";
				getline(cin, subject_name);
				break;

				case 3:
				cout<<"\n\nEnter new roll number: ";
				cin>>roll;
				break;

				case 4:
				cout<<"\n\nEnter new subject code: ";
				cin>>subject_code;
				break;
	
				case 5:
				cout<<"\n\nEnter new internal marks: ";
				cin>>internal_marks;
				break;

				case 6:
				cout<<"\n\nEnter new university marks: ";
				cin>>uni_marks;
				break;
			}
		cout<<"\n\nDo you wish to modify more data?(y/n): ";
		cin>>ans1;
	}while(ans1 == 'y' || ans1 == 'Y');
}

int student::del()
{
	int temp_roll2;
	cout<<"\nEnter the roll number of the student whose record you wish to delete: ";
	cin>>temp_roll2;
	return temp_roll2;
}

int student::mod()
{
	int temp_roll3;
	cout<<"\nEnter the roll number of the student whose details you wish to modify: ";
	cin>>temp_roll3;
	return temp_roll3;
}

int main()
{
	student s;
	student st[max];
	int count = 0, flag = 0;
	int choice,i,temp,k;
	char ans;
	do {	
		cout<<"\n\n1)Build database";
		cout<<"\n2)List database";
		cout<<"\n3)Insert";
		cout<<"\n4)Search";
		cout<<"\n5)Modify";
		cout<<"\n6)Delete";
		cout<<"\n7)Exit\n";
		cout<<"\nEnter your choice: ";
		cin>>choice; 
		switch(choice) {
			case 1:
			do {
				st[count].build();
				count++;
				cout<<"\n\nDo you wish to add more data?(y/n): ";
				cin>>ans; 
			}while(ans == 'Y' || ans == 'y');
			break;

			case 2:
			for(i = 0; i<count; i++) {
				st[i].list();
				cout<<endl<<endl;
			}
			break;

			case 3:
			st[count].insert();
			count++;
			break;

			case 4:
			flag = 0;
			temp = s.search();
			for(i = 0; i<count; i++) {
				if(temp == st[i].get_roll()) {
					cout<<"\n\nRoll number found!\n";
					st[i].list();
					flag = 1; 
					break;
				}
			}
			if(flag != 1)
				cout<<"\n\nRoll number not found!\n";
			break;

			case 5:
			flag = 0;
			temp = s.mod();
			for(i = 0; i<count; i++) {
				if(temp == st[i].get_roll()) {
					cout<<"\n\nRoll number found!\n";
					flag = 1;
					st[i].list();
					st[i].modify();
					break;
				}
			}
			if(flag != 1) 
				cout<<"\n\nRoll number not found!\n";
			break;

			case 6:
			flag = 0;
			temp = s.del();
			for(i = 0; i<count; i++) {
				if(temp == st[i].get_roll()) {
					flag = 1;
					k = i;
					for(k = i; k<count; k++)
						st[k] = st[k+1];
					count--;
					cout<<"\n\nRecord deleted!\n";
					break;
				}
			}
			if(flag != 1)
				cout<<"\n\nRoll number not found!\n";
			break;
		}
	}while(choice != 7);

	return 0;

}






























