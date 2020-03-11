#include<bits/stdc++.h>
using namespace std;
//D->Type|List
//Type->int|float|char
//List->id List|id
int i=0;

void H(string a)
{
	if(a[i]==' ')
	{
		i++;
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
	}
}


void F(string a)
{
	if(a[i]==';')
	{
		i++;
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
	}
}


void C(string a)
{
	if(a[i]==',')
	{
		i++;
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
	}
}

void B(string a)
{
	if(a[i]=='g'&& a[i+1]==';')
	{
		i++;
		F(a);
	}
	if(a[i]=='g' && a[i+1]!=';')
	{
		i++;
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
		C(a);
		H(a);
		B(a);
	}
}

void A(string a)                                                                                                                     
{
	if(s1=="int")
	{
		i=i+s1.size();
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
		//A1(a);
	}
	else if(s1=="float")
	{
		i=i+s1.size();
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
	}
	else if(s1=="char")
	{
		i=i+s1.size();
		for(int j=i;j<a.length();j++)
		{
			cout<<a[j];
		}
		cout<<endl;
	}
}   

void D(string a)
{
	A(a);
	H(a);
	B(a);
	F(a);
}
                                                                                                          
int main()
{
	
	string s1;
	cout<<"Enter data_type(int,float,char):";
	cin>>s1;
	strring s2=" ";
	string s3;
	
	//char p;
	
	cout<<"\nEnter variable:";
	cin>>s3;
	
	string s4=";"; 
	
	string s5;
	s5=s1+s2+s3+s4;
	cout<<s5<<endl;
	string a="c g, g, g;#";
	cout<<a<<endl;
	D(a);
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

