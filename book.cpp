#include<bits/stdc++.h>
using namespace std;
class book
{
    char *title,*author,*publisher;
    float price;
    int stock;
    public:
    static int s_trans,us_trans;
    book(char a[],char b[],char c[],float p,int s)
    {
            title=new char(strlen(a)+1);
            strcpy(title,a);
            author=new char(strlen(b)+1);
            strcpy(author,b);
            publisher=new char(strlen(c)+1);
            strcpy(publisher,c);
            price=p;
            stock=s;
    }
    void display()
    {
            cout<<"\nAuthor Name: "<<author;
            cout<<"\nTitle Name: "<<title;
            cout<<"\nPublisher Name: "<<publisher;
            cout<<"\nPrice: "<<price;
            cout<<"\nStock Position: "<<stock;
    }
    int search(char tbuy[20],char abuy[20])
    {
            if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
            return 1;
            else
            return 0;
    }
    void buy_book()
    {
            int count;
            cout<<"\nEnter Number Of Books to buy: ";
            cin>>count;
            if(count<=stock)
            {
                stock=stock-count;
                cout<<"\nBooks Bought Sucessfully";
                cout<<"\nAmount: Rs. "<<price*count;
                s_trans++;
            }
            else
            {
               cout<<"\nRequired Copies not in Stock";
               us_trans++;
             }
    }
    void update()
    {
          int ch;
          char a[100],b[100],c[100];
          int p,s;
          cout<<"\nEnter the detail you want to update: \n";
          cout<<"1. Title\n";
          cout<<"2. Author name\n";
          cout<<"3. publisher\n";
          cout<<"4. price\n";
          cout<<"5. stock\n";
          cout<<"\nEnter your choice: ";
          cin>>ch;
          switch(ch)
          {
                case 1: delete[] title;
                        cout<<"enter the new title : ";
                        cin>>a;
                        title=new char(strlen(a)+1);
                        strcpy(title,a);
                break;
                case 2: delete[] author;
                        cout<<"enter the new author name : ";
                        cin>>b;
                        author=new char(strlen(b)+1);
                        strcpy(author,b);
                break;
                case 3: delete[] publisher;
                        cout<<"enter the new publisher : ";
                        cin>>c;
                        publisher=new char(strlen(c)+1);
                        strcpy(publisher,c);
                break;
                case 4: cout<<"enter the new price : ";
                        cin>>p;
                        price=p;
                break;
                case 5: cout<<"enter the new stock : ";
                        cin>>s;
                        stock=s;
                break;
          }
     }
};
int book:: s_trans;
int book:: us_trans;

int main()
{
	int n,i=0,s,choice,t;
    float p;
    char a[100],b[100],c[100],ch;
    char titlebuy[20],authorbuy[20];
    book *q[30];
    while(1)
    {
        cout<<"\n\n\t\tMENU";
        cout<<"\n1. Entry of New Book";
        cout<<"\n2. Buy a book";
        cout<<"\n3. Search For Book";
        cout<<"\n4. Update Details Of Book";
        cout<<"\n5. Record of successfull/unsuccessfull transaction";
        cout<<"\n6. Exit";
        cout<<"\n\nEnter your Choice: ";
        cin>>choice;
        switch(choice)
		{
            case 1:
                do
                {
                    cout<<"\nenter title of book: ";
                    cin>>a;
                    cout<<"\nenter author of book: ";
                    cin>>b;
                    cout<<"\nenter publisher of book: ";
                    cin>>c;
                    cout<<"\nenter price of one book: ";
                    cin>>p;
                    cout<<"\nenter number of books in stock: ";
                    cin>>s;
                    q[i]=new book(a,b,c,p,s);
                    i++;
                    cout<<"\nDo you want to enter new record for books(y/n): ";
                    cin>>ch;
                }
                while(ch=='Y'||ch=='y');
                break;

            case 2:
                    cout<<"\nEnter the book you want to buy: ";
                    cin>>titlebuy;
                    cout<<"\nEnter the name of author: ";
                    cin>>authorbuy;
                    for(t=0;t<i;t++)
                    {
                        if(q[t]->search(titlebuy,authorbuy))
			            {
                            cout<<"\nBook Found Successfully";
                            q[t]->buy_book();
                            break;
                        }
                    }
                    if(t==i)
                    cout<<"\nThis Book is Not in Stock";
                    break;

		    case 3:
                    cout<<"\nEnter the book title you want to search for: ";
                    cin>>titlebuy;
                    cout<<"\nEnter the name of author: ";
                    cin>>authorbuy;
                    for(t=0;t<i;t++)
                    {
                        if(q[t]->search(titlebuy,authorbuy))
                        {
                            cout<<"\nBook Found Successfully";
                            q[t]->display();
                            break;
                        }
                    }
                    if(t==i)
                    cout<<"\nThis Book is Not in Stock";
                    break;

            case 4:
                    cout<<"\nEnter the book title you want to search for: ";
                    cin>>titlebuy;
                    cout<<"\nEnter the name of author: ";
                    cin>>authorbuy;
                    for(t=0;t<i;t++)
                    {
                        if(q[t]->search(titlebuy,authorbuy))
                        {
                            cout<<"\nBook Found Successfully";
                            q[t]->update();
                            break;
                        }
                    }
                    if(t==i)
                    cout<<"\nThis Book is Not in Stock";
                    break;

            case 5:
                    cout<<"\nNumber of successfull transaction: ";
                    cout<<book::s_trans;
                    cout<<"\nNumber of unsucessfull transaction: ";
                    cout<<book::us_trans;
                    break;

            case 6:
                    exit(0);
                    break;
        }
    }
}
