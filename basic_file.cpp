#include <bits/stdc++.h>
using namespace std;


class student
{
	int roll_no;
	char name[100];
	char grade;
public:
	void input()
	{	cout<<"ENTER STUDENT ROLL NUMBER:";
		cin>>roll_no;
		cout<<"ENTER STUDENT NAME :";
		getline(a,100);
		cout<<"ENTER STUDENT GRADE :";
		cin>>grade;
	}
	void display()
	{
		cout<<"STUDENT ROLL NUMBER:"<<roll_no<<endl<<"STUDENT NAME :"<<a<<endl<<"STUDENT GRADE :"<<grade<<endl;	
		
	}
	int search(int n)
	{
		for(int i=0;i<n;i++)
		{
			
		}
	}
}
int main ()
{
   FILE *fp;
   int ch;

   fp = fopen("file.txt", "w+");
   for( ch = 33 ; ch <= 100; ch++ )
   {
      fputc(ch, fp);
   }
   fclose(fp);

   return(0);
}
