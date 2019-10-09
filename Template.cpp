#include<bits/stdc++.h>
using namespace std;
template<class T>
class matrix
{
	int h,m,n;
	T **a,**b,**c;
public:
	void addition(T **a,T **b,T **c,int,int );
	void subtraction(T** a,T** b,T **c,int,int );
	void transpose(T **a,T **b,int,int);
	matrix();
	matrix(int M,int N)
	{	a=new T*[M];
		for(int i=0;i<M;i++)
		{
				a[i]=new T[N];
		}
		b=new T*[M];
		for(int i=0;i<M;i++)
		{
				b[i]=new T[N];
		}
		c=new T*[M];
		for(int i=0;i<M;i++)
		{
				c[i]=new T[N];
		}
		m=M;
		n=N;
		h=0;
	}
	void input ()
	{
		cout<<"ENTER THE ELEMENTS OF YOUR MATRIX:\n";
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>a[i][j];
			}
		}
		cout<<"ENTER THE ELEMENTS OF YOUR SECOND MATRIX:\n";
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<n;j++)
				{
					cin>>b[i][j];
				}
			}


	}


	void multiply(T **a,T **b,int m,int n)
{  	T d[n][m];
    for (int i=0;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            d[i][j] = 0;
            for (int k=0;k<n;k++)
                d[i][j]+=a[i][k]*b[k][j];
			cout<<d[i][j]<<"\t";
        }
		cout<<"\n";
    }
}

	void display()
	{
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<c[i][j]<<"\t";
			}
			cout<<"\n";
		}
	}
	void menu()
	{	input();
		while(h!=5)
		{	cout<<"ENTER YOUR CHOICE :\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Transpose\n5.Exit\n";
			cin>>h;

			if(h==1)
			{
				addition(a,b,c,m,n);
				display();
			}
			else if(h==2)
			{
				subtraction(a,b,c,m,n);
				display();
			}
			else if(h==3)
			{
				multiply(a,b,m,n);
			}
			else if(h==4)
			{	transpose(a,c,m,n);
				display();
			}
			else if(h==5)
			{
				break;
			}
			else
				cout<<"\nENTER CORRECT CHOICE\n";
		}
		delete a;
		delete b;
		delete c;

	}

};
template<class T>
void matrix<T>::addition(T **a, T **b, T **c,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i][j]=a[i][j]+b[i][j];
		}
	}
}
template<class T>
void matrix<T>::subtraction(T **a, T **b, T **c,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i][j]=a[i][j]-b[i][j];
		}
	}
}
template<class T>
void matrix<T>::transpose(T **a,T **c,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			c[i][j]=a[j][i];
		}
	}
}
int main()
{	int m,n;
	cout<<"ENTER THE SIZE OF MATRIX:\n";
		cin>>m;
		cin>>n;
		matrix<int> a(m,n);
		a.menu();
	return 0;
}
