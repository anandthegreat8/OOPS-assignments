#include<bits/stdc++.h>
using namespace std;

class basic                                                        //class basic
{
    char name[100];
    char dob[11];
    char bg[3];
public:
    void input()
    {   cout<<"ENTER YOUR NAME :";
        cin>>name;
        while((getchar()!='\n'));
        cout<<"ENTER YOUR DATE OF BIRTH(DD/MM/YYYY):";
        cin>>dob;
        while((getchar()!='\n'));
        cout<<"ENTER YOUR BLOOD GROUP:";
        cin>>bg;
    }
    void output()
    {   cout<<"------------------------DETAILS--------------------\n";
        cout<<"NAME :"<<name<<endl;
        cout<<"DATE OF BIRTH :"<<dob<<endl;
        cout<<"BLOOD GROUP :"<<bg<<endl;
    }
    basic()
    {
        strcpy(name,"ANAND");
        strcpy(dob,"10/07/2000");
        strcpy(bg,"AB+");
    }
    basic(const char a[], const char b[],const char c[])
    {   strcpy(name,a);
        strcpy(dob,b);
        strcpy(bg,c);
    }
};
class phy                                                            //class phy
{
    float weight,height;
public:
    void input()
    {   cout<<"ENTER WEIGHT(in KG):";
        cin>>weight;
        cout<<"ENTER HEIGHT(in m):";
        cin>>height;
    }
    void output()
    {
        cout<<"WEIGHT:"<<weight<<" KG"<<endl;
        cout<<"HEIGHT:"<<height<<" m"<<endl;
    }
    phy()
    {
        weight=52.6;
        height=1.78;
    }
    phy(float d, float e)
    {
        weight=d;
        height=e;
    }

};
class insurance                                                //class insurance
{
    long int policy_no;
    char address[1000];
public:
    void input()
    {   cout<<"ENTER POLICY NUMBER:";
        cin>>policy_no;
        cout<<"ENTER CONTACT ADDRESS:";
        cin>>address;
        while((getchar()!='\n'));
    }
    void output()
    {
        cout<<"POLICY NUMBER :"<<policy_no<<endl;
        cout<<"CONTACT ADDRESS :"<<address<<endl;
    }
    insurance()
    {
        policy_no=562354768;
        strcpy(address,"AIT, PUNE (411015)");
    }
    insurance(long int f, const char g[])
    {   strcpy(address,g);
        policy_no=f;
    }
    int search(long int p)
    {
        if(p==policy_no)
            return 0;
        else
            return -1;
    }
};
class contact:public phy,public insurance,public basic          //class contact
{
    long long int mobile_no;
    char driving_lic[20];
public:
    void input()
    {
        cout<<"ENTER MOBILE NUMBER:";
        cin>>mobile_no;
        cout<<"ENTER DRIVING LICENCE NUMBER :";
        cin>>driving_lic;
    }
    void output()
    {
        cout<<"MOBILE NUMBER :"<<mobile_no<<endl;
        cout<<"DRIVING lICENCE:"<<driving_lic<<endl;
    }
    contact()
    {
        mobile_no=7733816710;
        strcpy(driving_lic,"7645DKL967J");
    }
    contact(const char a[],const char b[],const char c[],float d,float e,long int f,const char g[],long int h, const char i[]):basic(a,b,c),phy(d,e),insurance(f,g)
    {   strcpy(driving_lic,i);
        mobile_no=h;
    }
}b;
int main()                                                       //MAIN FUNCTION
{
    int n,m=0,k=0,j=0,i,count=0,flag=2,temp=0;
    long int p;
    contact *a=new contact[20];
    do
    {
        cout<<"\nEnter Your Choice:\n1.Dispaly Master Table\n2.Insert new Entry\n3.Delete an Entry\n4.Display\n5.Search For An Entry\n6.Append\n7.Exit\n";
        cin>>n;
        switch(n)
        {
            case 1:
            {
                b.basic::output();
                b.phy::output();
                b.insurance::output();
                b.output();

                break ;
            }
            case 2:
            {
                cout<<"To continue press 1 or to exit press 0:";
                cin>>m;
                while(m==1)
                {
                      (a+k)->basic::input();
                      (a+k)->phy::input();
                      (a+k)->insurance::input();
                      (a+k)->input();
                      k++;
                      cout<<"To continue press 1 or to exit press 0:";
                      cin>>m;

                }

                break ;
            }
            case 3:
            {
                cout<<"Which Policy_no you want to Delete:";
                cin>>p;
                for(i=0;i<k;i++)
                {
                    flag=(a+i)->insurance::search(p);

                    if(flag==0)
                    {
                        break;
                    }
                }
                if(flag==0)
                {
                    for(j=i+1;j<k;j++)
                    {
                        a[j-1]=a[j];
                    }
                k--;
                cout<<"Entry Deleted Successfully\n";
                }
                else
                    cout<<"\nNO SUCH ENTRY\n";

                break;
            }
            case 4:
            {
                  for(i=0;i<k;i++)
                {
                    (a+i)->basic::output();
                    (a+i)->phy::output();
                    (a+i)->insurance::output();
                    (a+i)->output();
                }
                if(i==0)
                  cout<<"\nNO DATA TO DISPLAY\n";

                break;

            }
            case 5:
            {
                cout<<"\nEnter policy number:";
                cin>>m;
                for(i=0;i<k;i++)
                {
                    flag=(a+i)->insurance::search(m);
                    if(flag==0)
                    {   j=i;
                        break;
                    }
                }
                if(flag==0)
                {   (a+j)->basic::output();
                    (a+j)->phy::output();
                    (a+j)->insurance::output();
                    (a+j)->output();
                }
                else
                    cout<<"\nNOT FOUND\n";
                break ;
            }
            case 6:
            {
              cout<<"ENTER THE POLICY NUMBER YOU WANT TO APPEND :";
              cin>>m;
              for(i=0;i<k;i++)
              {
                  flag=(a+i)->insurance::search(m);
                  if(flag==0)
                  {   j=i;
                      break;
                  }
              }
              if(flag==0)
              {   (a+j)->basic::input();
                  (a+j)->phy::input();
                  (a+j)->insurance::input();
                  (a+j)->input();
                  cout<<"\nAPPENDED Successfully\n";
              }
              else
              {
                cout<<"\nNO SUCH POLICY NUMBER\n";
              }

            }
            case 7:
            {
                break;
            }
        }
    }while(n!=7);
    delete [] a;
return 0;
}
