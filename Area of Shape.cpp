#include <iostream>
using namespace std;

class shape
{
protected:
	double x,y;
public:
	void input()
	{
		cout<<"ENTER DIMENSIONS:\n"<<"Enter length:";
		cin>>x;
		cout<<"Enter height:";
		cin>>y;


	}
	virtual void area()=0;
};

class triangle:public shape
{
	int a;
public:
	void area()
	{
		input();
		a=(0.5*x*y);
		cout<<"\nArea of triangle:"<<a<<"\n";
	}
};

class rectangle:public shape
{
	int a;
public:
	void area()
	{
		input();
		a=(x*y);
		cout<<"\nArea of rectangle:"<<a<<"\n";
	}
};

int main()
{
	int n;
	shape *s;

	do{
	cout<<"\nENTER YOUR CHOICE\n1. Triangle\n"<<"2. Rectangle\n"<<"3. Exit\n";
	cin>>n;

		switch(n)
		{
			case 1:
				{
				triangle t;
				s=&t;
				s->area();
				break;
				}
			case 2:
				{
				rectangle r;
				s=&r;
				s->area();
				break;
				}
		}
	}while(n!=3);
	delete(s);
}
