/*Write a program in C++ using function template to read two matrices of different data
types such as integers and floating point values and perform simple arithmetic operations
on these matrices separately and display it.*/

#include<iostream>
using namespace std;

template <class T>

class matrix
{
	private:
	T a[3][3], b[3][3], c[3][3];
	
	public:
	void input();
	void output();
	void add();
	void sub();
	void mul();
	void transpose();
};

template <class T>
void matrix<T>::input()
{
	cout<<"\nMatrix A: \n";
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			cout<<"\n["<<i<<"]["<<j<<"] = ";
			cin>>a[i][j];
		}
	}

	cout<<"\nMatrix B: \n";
	for(int k = 1; k<=3; k++) {
		for(int l = 1; l<=3; l++) {
			cout<<"\n["<<k<<"]["<<l<<"] = ";
			cin>>b[k][l];
		}
	}
}

template <class T>
void matrix<T>::output()
{
	cout<<"\n\nMatrix A is: \n\n";
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			cout<<a[i][j]<<"\t";
		}
		cout<<endl;
	}

	cout<<"\n\nMatrix B is: \n\n";
	for(int k = 1; k<=3; k++) {
		for(int l = 1; l<=3; l++) {
			cout<<b[k][l]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

template <class T>
void matrix<T>::add()
{
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	cout<<"\nThe addition is: \n\n";
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

template <class T>
void matrix<T>::sub()
{
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}
	cout<<"\nThe subtraction is: \n\n";
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

template <class T>
void matrix<T>::mul()
{
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++)
			c[i][j] = 0;
	}

	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			for(int k = 1; k<=3; k++) 
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
		}
	}

	cout<<"\nThe multiplication is: \n\n";
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

template <class T>
void matrix<T>::transpose()
{
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++)
			c[i][j] = a[j][i];
	}

	cout<<"\nThe transpose is: \n\n";
	for(int i = 1; i<=3; i++) {
		for(int j = 1; j<=3; j++) {
			cout<<c[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
	int choice,ch;
	matrix<int> m1;
	matrix<float> m2;
	matrix<double> m3;
	do {
		cout<<"\n1)Integer\n2)Float\n3)Double\n4)Exit\n";
		cout<<"\nEnter your choice of data type: ";
		cin>>ch;
	switch(ch) {
	
	case 1: 
          cout<<"\nEnter your choice of operation: \n1)Addition \n2)Subtraction \n3)Multiplication\n4)Transpose  \n\n"; 
          cin>>choice; 
          switch(choice) 
          { 
           case 1: 
             m1.input();           //calling functions using object of Matrix having datatype int 
             m1.output(); 
             m1.add(); 
                  break; 
           case 2: 
             m1.input(); 
             m1.output(); 
             m1.sub(); 
                  break; 
           case 3: 
             m1.input(); 
             m1.output(); 
             m1.mul(); 
                  break; 
	   case 4:
		m1.input();
		m1.output();
		m1.transpose();
		break;	             
          } 
          break; 
   case 2: 
           cout<<"\nEnter your choice of operation: \n1)Addition \n2)Subtraction \n3)\nMultiplication\n\n"; 
          cin>>choice; 
          switch(choice) 
          { 
           case 1:                                                           
                   
                   m2.input();              //calling functions using object of Matrix having datatype float 
                   m2.output(); 
                   m2.add(); 
                  break; 
           case 2: 
                   m2.input(); 
                   m2.output(); 
                   m2.sub(); 
                  break; 
           case 3: 
                   m2.input(); 
                   m2.output(); 
                   m2.mul(); 
                  break;              
          } 
          break; 
          
   case 3: 
           cout<<"\nEnter your choice of operation: \n1)Addition \n2)Subtraction \n3)Multiplication\n\n"; 
          cin>>choice; 
          switch(choice) 
          { 
           case 1: 
                 m3.input();           //calling functions using object of Matrix having datatype double 
                 m3.output(); 
                 m3.add(); 
                  break; 
           case 2: 
                 m3.input(); 
                 m3.output(); 
                 m3.sub(); 
                  break; 
           case 3: 
                m3.input(); 
                m3.output(); 
                m3.mul();           
                   break;              
          } 
          break;   
          
			
		}
	}while(ch != 5);

	return 0;
}




























