/*A book shop maintains the inventory of books that are being sold at the shop. The list
includes details such as author, title, price, publisher and stock position. Whenever a
customer wants a book, the sales person inputs the title and author and the system
searches the list and displays whether it is available or not. If it is not, an appropriate
message is displayed. If it is, then the system displays the book details and requests
for the number of copies required. If the requested copies book details and requests
for the number of copies required. If the requested copies are available, the total cost
of the requested copies is displayed; otherwise the message “Required copies not in
stock” is displayed.*/

#include<iostream>
#include<string>
using namespace std;

class books
{
	private:
	string title[5];
	string author[5];
	string publisher[5];
	float *price;
	int *stock;

	public:
	
	books()
	{
		price = new float[5];
		stock = new int[5];

			author[0]="Sir Alex Ferguson"; 
			title[0]="Leading"; 
			publisher[0]="Hodder & Stoughton"; 
			stock[0]=50; 
			price[0]=550; 

			author[1]="Steven Levitt"; 
			title[1]="Freakonomics"; 
			publisher[1]="Morrow"; 
			stock[1]=20; 
			price[1]=925; 

			author[2]="Jim Collins"; 
			title[2]="Built to Last"; 
			publisher[2]="Collins Business"; 
			stock[2]=30; 
			price[2]=700; 
			 
			author[3]="Gerald Durrell"; 
			title[3]="The Corfu Trilogy"; 
			publisher[3]="Penguin Books"; 
			stock[3]=40; 
			price[3]=750; 

			author[4]="Brian Greene"; 
			title[4]="The Fabric of the Cosmos"; 
			publisher[4]="Penguin Books"; 
			stock[4]=15; 
			price[4]=600; 	
	}
	string input_title, input_author;
	void search();
	void display();
};

void books::search()
{
	int flag,copies;
	float cost;
	cout<<"\nEnter the name of the book: ";
	//cin.ignore();
	getline(cin,input_title);
	cout<<"\nEnter the name of the author: ";
	getline(cin,input_author);
	for(int i = 0; i<=5; i++) {
		if(input_title == title[i] && input_author == author[i]) {
			flag = 1;
			cout<<"\nBook found!";
			cout<<"\nTitle: "<<title[i]<<"\nAuthor: "<<author[i]<<"\nPublisher: "<<publisher[i]<<"\nStock: "<<stock[i]<<"\nPrice: "<<price[i];
			cout<<"\nHow many copies do you wish to purchase? ";
			cin>>copies;
			if(copies<=stock[i]) {
				cost = price[i] * copies;
				stock[i] = stock[i] - copies;
				cout<<"The total price of "<<copies<<" copies will be "<<cost;
			}
			else 
				cout<<"\nRequired copies not in stock";
		}
	}
	if(flag != 1)
		cout<<"\nBook not available!";
}

void books::display()
{
	for(int i=0;i<5;i++) 
	{ 
		cout<<"\nTitle : "<<title[i]; 
		cout<<"\nAuthor : "<<author[i]; 
		cout<<"\nPublisher : "<<publisher[i]; 
		cout<<"\nStock : "<<stock[i]; 
		cout<<"\nPrice : "<<price[i]<<endl; 
	} 
}

int main() 
{ 
	books b1; 
	int ch; 
	string dump; 
	do 
	{ 
		cout<<"\n\t\t------------------Book Shop------------------"; 
		cout<<"\n1. Display Database"; 
		cout<<"\n2. Search and Purchase"; 
		cout<<"\n3. Exit"; 
		cout<<"\nEnter choice : "; 
		cin>>ch; 
		getline(cin,dump); 
		switch(ch) 
		{ 
			case 1 : 
				b1.display(); 
				break; 
			case 2 : 
				b1.search(); 
				break; 
			case 3: 
				break; 
			default: 
				cout<<"\nWrong choice!!!!"; 
				break; 
		} 
	}while(ch!=3); 
	return 0;	 
}































