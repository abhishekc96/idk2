/*Write a C++ program to perform String operations
i. = Equality
ii. == String Copy
iii. + Concatenation
iv. << To display a string
v. >> To reverse a string
vi. Function to determine whether a string is a palindrome
To find occurrence of a sub-string. Use Operator Overloading*/

#include<iostream>
#include<string>
using namespace std;

class strng
{
	public:
	char str[40];
	void operator+(strng);
	void operator=(strng);
	void operator==(strng);
	void operator<<(strng);
	void operator>>(strng);
	void palindrome();
	void substring(strng);	
	friend ostream& operator<<(ostream &out, strng &s);
	friend istream& operator>>(istream &in, strng &s);
};

void strng::operator+(strng s)
{
	int i = 0,j = 0;
	while(str[i] != '\0')
		i++;
	while(s.str[j] != '\0') {
		str[i] = s.str[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

void strng::operator=(strng s)
{
	int i = 0,j = 0;	
	while(s.str[j] != '\0') {
		str[i] = s.str[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

void strng::operator==(strng s)
{
	int i = 0, j = 0;
	int cmp;
	while(str[i] != '\0' || s.str[j] != '\0') {
		cmp = str[i] - s.str[j];
		if(cmp != 0) {
			cout<<"\nStrings are not equal!\n";
			break;
		}
		i++;
		j++;
	}
	if(cmp == 0) 
		cout<<"\nStrings are equal!\n";
}

ostream& operator<<(ostream &out, strng &s) 
{
	out<<s.str;	
	return out;
}

istream& operator>>(istream &in, strng &s)
{
	in>>s.str;
	return in;
}

void strng::operator<<(strng s)
{
	int i = 0,j = 0;
	while(s.str[j] != '\0') {
		str[i] = s.str[j];
		j++;
		i++;
	}
	str[i] = '\0';
}

void strng::operator>>(strng s)
{
	int i = 0,j = 0;
	while(s.str[j] != '\0')
		j++;
	while(j>0) {
		j--;
		str[i] = s.str[j];
		i++;
	}
	str[i] = '\0';
}

void strng::palindrome()
{
	int flag = 0,i = 0,j = 0;
	for(j=0; str[j] != '\0';j++);
	j--;
	for(i=0; i<=j/2; i++,j--) {
		if(str[i] != str[j]) {
			flag = 1;
			cout<<"\nEntered string is not a palindrome!\n";
			break;
		}
	}
	if(flag == 0)
		cout<<"\nEntered string is a palindrome!\n";
}

void strng::substring(strng s)
{
	int i = 0,j = 0,k = 0,count = 0;
	while(s.str[k] != '\0')
		k++;
	while(str[i] != '\0') {	
		if(str[i] == s.str[j]) {
			j++;
			if(j == k) {
				j = 0;
				count++;
			}
		}
		else 
			j = 0;
		i++;
	}
	if(count > 0)
		cout<<"\nSubstring found "<<count<<" time(s).\n";
	else
		cout<<"\nSubstring not found!\n";
}

int main()
{
	strng s1,s2;
	int choice;
	char ans;
	do{
	cout<<"\n1)Concatenate strings";
	cout<<"\n2)Copy string";
	cout<<"\n3)Compare strings";
	cout<<"\n4)Display string";
	cout<<"\n5)Reverse string";
	cout<<"\n6)Is palindrome?";
	cout<<"\n7)Find substring";
	cout<<"\n\nEnter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
		cout<<"\nEnter the first string: ";
		cin>>s1;
		cout<<"\nEnter the second string: ";
		cin>>s2;
		s1 + s2;
		cout<<"\nThe concatenated string is: "<<s1<<endl;
		break;

		case 2:
		cout<<"\nEnter the string to be copied into first string: ";
		cin>>s2;
		s1 = s2;
		cout<<"\nThe copied string is: "<<s1<<endl;
		break;

		case 3:
		cout<<"\nEnter the first string: ";
		cin>>s1;
		cout<<"\nEnter the second string: ";
		cin>>s2;
		s1 == s2;
		break;

		case 4:
		cout<<"\nEnter the string: ";
		cin>>s1;
		s2<<s1;
		cout<<"\nThe entered string is: "<<s1<<endl;
		break;
		
		case 5:
		cout<<"\nEnter the string: ";
		cin>>s1;
		s2>>s1;
		cout<<"\nThe reverse string is: "<<s2<<endl;
		break;

		case 6:
		cout<<"\nEnter the string: ";
		cin>>s1;
		s1.palindrome();
		break;
		
		case 7:
		cout<<"\nEnter the string: ";
		cin>>s1;
		cout<<"\nEnter the substring: ";
		cin>>s2;
		s1.substring(s2);
		break;
	}
	cout<<"\n\nDo you wish to continue?(y/n): ";
	cin>>ans;
	}while(ans == 'y' || ans == 'Y');

	return 0;
}
































