#include<bits/stdc++.h>
using namespace std;
class personal
{
	char name[100];
	int age;
public:
	void input()
	{
		cin>>name;
		cin>>age;
	}
	void display()
	{
		cout<<"NAME :"<<name<<endl;
		cout<<"AGE :"<<age<<endl;
	}
	personal()
	{
		strcpy(name,"ANAND");
		age=21;
	}
	personal(const char g[],int h)
	{
		int i=0;
		strcpy(name,g);
		age=h;
	}

};
class academic:virtual public personal
{
	char col_name[100];
	int yop10,yop12;
	int mar10,mar12;
public:
	void input()
	{	cout<<"ENTER COLLEGE NAME :";
		cin>>col_name;
		cout<<"ENTER YEAR OF PASSING OF CLASS 10th :";
		cin>>yop10;
		cout<<"ENTER YEAR OF PASSING OF CLASS 12th :";
		cin>>yop12;
		cout<<"PERCENTAGE IN CLASS 10th :";
		cin>>mar10;
		cout<<"PERCENTAGE IN CLASS 12th :";
		cin>>mar12;
	}
	void display()
	{	cout<<"---------------------CV--------------------\n";
		cout<<"COLLEGE NAME :"<<col_name<<endl;
		cout<<"YEAR OF PASSING OF CLASS 10th :"<<yop10<<endl;
		cout<<"YEAR OF PASSING OF CLASS 12th :"<<yop12<<endl;
		cout<<"PERCENTAGE IN CLASS 10th :"<<mar10<<"%"<<endl;
		cout<<"PERCENTAGE IN CLASS 12th :"<<mar12<<"%"<<endl;;
	}
	academic()
	{
		strcpy(col_name,"AIT,PUNE");
		yop10=2015;
		yop12=2017;
		mar10=88;
		mar12=95;
	}
	academic(const char b[],int a,int o,int c,int d)
	{	int i=0;
		strcpy(col_name,b);
		yop10=a;
		yop12=o;
		mar10=c;
		mar12=d;
	}
};
class professional:virtual public personal, public academic
{
	int yoe;
	char post[100];
	int eop;
public :
	void display()
	{
		cout<<"POST :"<<post<<endl;
		cout<<"YEAR OF EXPERIENCE :"<<eop<<endl;
		cout<<"EMPLOYED SINCE :"<<yoe<<endl;
	}
	professional()
	{
		yoe=2022;
		strcpy(post,"CEO");
		eop=10;
	}
	professional(const char g[],int h,const char b[],int a,int o,int c,int d,int e,const char p[],int f):personal(g,h),academic(b,a,o,c,d)
	{
		yoe=e;
		strcpy(post,p);
		eop=f;
	}
};
int main()

{	char name[100],col_name[100],post[100];
	int age,yoe,eop,yop10,yop12,mar10,mar12;
	cout<<"ENTER YOUR NAME:";
	cin>>name;
	cout<<"ENTER AGE:";
	cin>>age;
	cout<<"IN WHIch YEAR YOU PASSED 10th:";
	cin>>yop10;
	cout<<"IN WHICH YEAR YOU PASSED 12th";
	cin>>yop12;
	cout<<"MARKS OBTAINED IN 10th:";
	cin>>mar10;
	cout<<"MARKS OBTAINED IN 12th:";
	cin>>mar12;
	cout<<"ENTER YOUR COLLEGE NAME :";
	cin>>col_name;
	cout<<"ENTER YOUR POST";
	cin>>post;
	while((getchar()!='\n'));
	cout<<"ENTER YOUR YEAR OF EMPLOYMENT :";
	cin>>yoe;
	cout<<"ENTER YOUR EXPERIENCE:";
	cin>>eop;
	professional obj(name,age,col_name,yop10,yop12,mar10,mar12,yoe,post,eop),obj2;
	cout<<"\nPARAMETERISED CONSTRUCTOR IS INVOKED:\n";
	obj.personal::display();
	obj.academic::display();
	obj.display();
	cout<<"\nDEFAULT CONSTRUCTOR IS INVOKED:\n";
	obj2.personal::display();
	obj2.academic::display();
	obj2.display();
 	cout<<"THIS IS THE EDITED FILE";
	return 0;
}
