#include<bits/stdc++.h>
using namespace std;
class television
{
    int model_no;
    float price;
    float size;
public:
    void getdata()
    { int flag=0;
      do {
      cout<<"\nENTER THE 4 DIGIT MODEL NUMBER :";
      try
        { flag=0;
          cin>>model_no;
          if(model_no<1000 || model_no>=10000)
          {
            flag=1;
            throw model_no;
          }
        }
        catch(int x)
        {
          cout<<"WRONG DETAILS \n";
        }
        }while(flag!=0);
        do
        {
          cout<<"\nENTER SCREEN SIZE (in inches) :";
          try
        {
            flag=0;
            cin>>size;
            if(size<=11|| size>=18)
            {
              flag=1;
              throw model_no;
            }

        }
        catch(int x)
        {
          cout<<"WRONG DETAILS \n";
        }
      }while(flag!=0);
      do
      {
        cout<<"\nENTER PRICE:";
        try
      {
          flag=0;
          cin>>price;
          if(price>5000)
          {
            flag=1;
            throw model_no;
          }

      }
      catch(int x)
      {
        cout<<"WRONG DETAILS \n";
      }
    }while(flag!=0);
      }
      void display()
      {  cout<<"-------------------OUTPUT---------------------"<<endl;
        cout<<"MODEL No.- "<<model_no<<endl;
        cout<<"\nSCREEN SIZE (inches)- "<<size<<endl;
        cout<<"\nPRICE- "<<price<<endl;
      }
}a;
int main()
{
  a.getdata();
  a.display();
  return 0;
}
