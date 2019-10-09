#include<bits/stdc++.h>
using namespace std;
class student
{
  int roll;
  float marks;
  string name;
public:
  void getdata();
  void modif(ofstream &,int);
};
void student::getdata()
{
  ofstream f;
  f.open("anand.txt",ios::app);
  cout<<"\nEnter roll no\n";
  cin>>roll;
  cout<<"\nEnter name\n";
  cin>>name;
  cout<<"\nEnter marks\n";
  cin>>marks;
  f<<roll<<" "<<name<<" "<<marks<<"\n";

  f.close();
}
void student::modif(ofstream &f3,int roll1)
{
  cout<<"enter new name\n";
  cin>>name;
  cout<<"enter new marks\n";
  cin>>marks;
  roll=roll1;
  f3<<roll<<" "<<name<<" "<<marks<<"\n";
}

int main()
{
  int i=0,n,r1,roll,ch;
  string name;
  float marks;
  student *s1;
  s1=new student;
  ifstream f1,f2;
  ofstream f3,f4;
  do
  {
      cout<<"\n1-enter new record\n2-modify\n3-insert\n4-delete\n5-display\n";
      cin>>ch;
      switch(ch)
      {
        case 1:n=0;i=0;
              cout<<"\nentering records\n";
              do
              {
                s1->getdata();
                n++;
                cout<<"\n1-continue to enter data\n";
                cin>>ch;
              }while(ch==1);
              break;
        case 2:cout<<"\nenter roll no. to modify\n";
              cin>>r1;
              f1.open("anand.txt",ios::in);
              f3.open("temp.txt",ios::out);
              for(i=0;i<n;i++)
                {
                  f1>>roll>>name>>marks;
                  if(roll!=r1)
                  {
                    f3<<roll<<" "<<name<<" "<<marks<<"\n";
                  }
                  else
                  {
                    s1->modif(f3,roll);
                  }
                }
                f1.close();
                f3.close();
                f1.open("temp.txt",ios::in);
                f3.open("anand.txt",ios::out);
                for(i=0;i<n;i++)
                  {
                    f1>>roll>>name>>marks;
                    f3<<roll<<" "<<name<<" "<<marks<<"\n";
                  }
                  f1.close();
                  f3.close();
                  break;
        case 3:cout<<"enter the pos u want to insert at\n";
                cin>>r1;
                f1.open("anand.txt",ios::in);
                f3.open("temp.txt",ios::out);
                for(i=0;i<n;i++)
                  {
                    if(i+1==r1)
                    {
                      cout<<"enter roll no.\n";
                      cin>>roll;
                      cout<<"enter name.\n";
                      cin>>name;
                      cout<<"enter marks.\n";
                      cin>>marks;
                      f3<<roll<<" "<<name<<" "<<marks<<"\n";
                    }

                    f1>>roll>>name>>marks;
                    f3<<roll<<" "<<name<<" "<<marks<<"\n";

                  }
                  n++;
                  f1.close();
                  f3.close();
                  f1.open("temp.txt",ios::in);
                  f3.open("anand.txt",ios::out);
                  for(i=0;i<n;i++)
                    {
                      f1>>roll>>name>>marks;
                      f3<<roll<<" "<<name<<" "<<marks<<"\n";
                    }
                    f1.close();
                    f3.close();
                    break;
        case 4:cout<<"enter the roll no. u want to delte \n";
                cin>>r1;
                f1.open("anand.txt",ios::in);
                f3.open("temp.txt",ios::out);
                for(i=0;i<n;i++)
                  {
                    f1>>roll>>name>>marks;
                    if(roll!=r1)
                    {
                    f3<<roll<<" "<<name<<" "<<marks<<"\n";
                    }

                  }
                  n--;
                  f1.close();
                  f3.close();
                  f1.open("temp.txt",ios::in);
                  f3.open("anand.txt",ios::out);
                  for(i=0;i<n;i++)
                    {
                      f1>>roll>>name>>marks;
                      f3<<roll<<" "<<name<<" "<<marks<<"\n";
                    }
                    f1.close();
                    f3.close();
          case 5:f1.open("anand.txt",ios::in);
                  cout<<"\nroll\tname\tmarks\n";
                  while (f1>>roll>>name>>marks)
                    {
                      cout<<roll<<"\t"<<name<<"\t"<<marks<<"\n";
                    }
                    f1.close();
                    break;
                  }
                  cout<<"\n1-continue\n";
                  cin>>ch;
        }while(ch==1);
return 0;
}
