#include<bits/stdc++.h>
using namespace std;

class basic                                                             //class basic
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
class phy                                                                           //calss phy
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
class insurance                                                                 //class insurance
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
int main()                                                                          //MAIN FUNCTION
{
    int n,m=0,k=0,j=0,i,count=0,flag=2,temp=0;
    long int p;
    contact *a=new contact[20];
    do
    {
        cout<<"\nEnter Your Choice:\n1.Dispaly Master Table\n2.Insert new Entry\n3.Delete an Entry\n4.Display\n5.Search For An Entry\n6.Exit\n";
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
                cout<<"How many entries you want to do:";
                cin>>m;
                for(i=k;i<m+k;i++)
                {
                    (a+i)->basic::input();
                    (a+i)->phy::input();
                    (a+i)->insurance::input();
                    (a+i)->input();
                }
                k=k+m;

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
                }
                else
                    cout<<"NO SUCH ENTRY";

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

                break;

            }
            case 5:
            {
                cout<<"Enter policy number:";
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
                    cout<<"NOT FOUND\n";
                break ;
            }
            case 6:
            {
                break;
            }
        }
    }while(n!=6);
    delete [] a;
return 0;
}
