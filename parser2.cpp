#include<bits/stdc++.h>
using namespace std;
//A->Ab|B
//A->BA1
//A1->bA1|''
//B->d
//d,db,dbb
int i=0;
void B(string a)
{
	if(a[i]=='d')
	{
		i++;
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
	}
}

void A1(string a)
{
	if(a[i]=='b')
	{
		i++;
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
		A1(a);
	}
	else
	{
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
	}
}   

void A(string a)
{
	/*
	if(a[i]=='b')
	{
		i++;
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
		//cout<<a<<endl;
	}
	*/
	B(a);
	A1(a);
}
                                                                                                          
int main()
{
	string a="dbbb#";
	cout<<a<<endl;
	A(a);
	if(a[i]=='#')
	{
		cout<<"Possible string!!"<<endl;
	}
	else
	{
		cout<<"Not possible";
	}
	return 0;
}
