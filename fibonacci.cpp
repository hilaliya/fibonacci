#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

double func(double x, int terms, double coef[], double deg[])
{
	double z=0;
	for(int i=0; i<terms; i++)
	{
		z= z + coef[i]*pow(x, deg[i]);	
	}	
	return z;	
}

double fibo(int a)
{
	double f[a];
	f[0]=1;
	f[1]=1;
	if(a==0 or a==1) return 1;
	else
	{
		for(int i=2; i<=a; i++)
		{
			f[i]=f[i-1]+f[i-2];
		}	
		return f[a];
	}	
}

double x1(double a, double b, double n, double k )
{
	return a + fibo(n-k-2)/fibo(n-k)*(b-a);
}

double x2(double a, double b, double n, double k )
{
	return a + fibo(n-1-k)/fibo(n-k)*(b-a);
}

int main(){
	
cout<<"\nEnter the number of terms in your function: ";
int terms;
cin>> terms;

double coef[terms];
for(int i=0; i<terms; i++)
{
	cout<<"\nEnter the coefficient of "<<i+1<<". term: ";	
	cin>>coef[i];
}

double deg[terms];
for(int i=0; i<terms; i++)
{
	cout<<"\nEnter the degree of "<<i+1<<". term: ";	
	cin>>deg[i];
}

cout<<"\n\nYour function is ";

cout<<"f(x)=";
for(int i=0; i<terms; i++)
{
	cout<<" "<<coef[i]<<"x^"<<deg[i];
}


cout<<"\n\n\nEnter the interval \n";
double a,b;
cout<<"\nMinimum value of x: ";
cin>>a;
cout<<"\nMaximum value of x: ";
cin>>b;		
cout<<"\nThe Interval is ["<<a<<","<<b<<"]\n"; 	

cout<<"\n\nEnter the number of iterations: ";
int n;
cin>>n;

cout<<"\nSearch method: Fibonacci \n";
			
double lamda=x1(a,b,n,0);		
double mu=x2(a,b,n,0);
		
for(int i=1; i<=n-2; i++)
	{
		if (func(lamda,terms,coef,deg)>func(mu,terms,coef,deg))
		{	//step 2
			a=lamda;	
			lamda=mu;
			mu=x2(a,b,n,i);
		}
		else
		{
			//step 3
			b=mu;
			mu=lamda;
			lamda=x1(a,b,n,i);
		} 
			
		if(i==n-2)
		{
			mu=lamda + 0.01;
			if (func(lamda,terms,coef,deg)>func(mu,terms,coef,deg))
			{
				a=lamda;	
			}
			else
			{
				b=lamda;
			}
				
			cout<<"\nOptimal solution lies in the interval ["<<a<<","<<b<<"].\n";
			cout<<"f("<<a<<")="<<func(a,terms,coef,deg)<<"\n";
			cout<<"f("<<b<<")="<<func(b,terms,coef,deg)<<"\n";
			break;
		}		
	}
}

