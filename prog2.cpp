#include<bits/stdc++.h>
using namespace std;


bool iskeyword(string arr)
{
	string s[]={"auto","break","while","void","int","char","float","enum","struct","if","else if",
				"else","main","double","do","continue","default","goto","sizeof","return","short","unsigned",
				"long","extern","typedef","switch","signed"};
	int n=sizeof(s)/sizeof(s[0]);
	for(int i=0;i<n;i++)
	{
		if(arr==s[i])
		{
			return true;
		}
	}
	return false;
}

struct terminal
{
	int index;
	char t;
	int cnt;
};

struct used_reserved_keyword
{
	int index;
	string s;
	int cnt;
};

struct identifiers
{
	int index;
	string s;
	int cnt;
};

struct operators_used
{
	int index;
	char o;
	int cnt;
};


int main()
{
	FILE* fp;

	struct operators_used op[6];	//for storing used operators
	int i=0;						//counter for operator table
	struct used_reserved_keyword key[10];
	int j=0;
	struct identifiers iden[10];
	int z=0;
	struct terminal ter[20];
	int x=0;
	char oper[]="+-/*%=";
	char ch;
	string arr;
	int l=0,c=0;
	fp=fopen("program.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{
		
		//Checking operators
		for(int k=0;k<6;k++)
		{
			if(ch==oper[k])
			{
				c=c+1;
				cout<<c<<"\t"<<ch<<"\t:"<<"operator"<<endl;
				op[i].o=ch;
				op[i].index=i+1;
				op[i].cnt=c;
				i++;
			}
		}
		//Checking alpha-numeric characters
		if(isalnum(ch))
		{
			arr.insert(l,&ch);	
			l=l+1;
		}
		else if((ch==' ' || ch=='\n' || ch==',' || ch==';')&&(l!=0))
		{		
			//Checking for reserved keywords
			arr.resize(l);
			if(iskeyword(arr))
			{
				c=c+1;
				cout<<c<<"\t"<<arr<<"\t:"<<"Keyword"<<endl;
				key[j].s=arr;
				key[j].index=j+1;
				key[j].cnt=c;
				j++;
			}
			else if(!iskeyword(arr))
			{
				c=c+1;
				cout<<c<<"\t"<<arr<<"\t:"<<"Identifier"<<endl;
				iden[z].s=arr;
				iden[z].index=z+1;
				iden[z].cnt=c;
				z++;
			}
			if((ch=='{' || ch=='}' || ch=='(' || ch==')' || ch==';' || ch==':' || ch==',') && (l!=0))
			{
				c=c+1;
				cout<<c<<"\t"<<ch<<"\t:"<<"Terminal"<<endl;
				ter[x].t=ch;
				ter[x].index=x+1;
				ter[x].cnt=c;
				x++;
			}
			arr.erase();
			l=0;
		}
		else
		{
			if((ch=='{' || ch=='}' || ch=='(' || ch==')' || ch==';' || ch==':' || ch==',') && (l==0))
			{
				c=c+1;
				cout<<c<<"\t"<<ch<<"\t:"<<"Terminal"<<endl;
				ter[x].t=ch;
				ter[x].index=x+1;
				ter[x].cnt=c;
				x++;
			}
		}
	}
	cout<<endl;
	//Operator table
	cout<<"Index\t"<<"Operator_Used\t"<<"Counter"<<endl;
	for(int q=0;q<i;q++)
	{
		cout<<op[q].index<<"\t"<<op[q].o<<"\t\t"<<op[q].cnt<<endl;
	}
	cout<<endl;

	cout<<"Index\t"<<"Identifier_Used\t"<<"Counter"<<endl;
	for(int q=0;q<z;q++)
	{
		cout<<iden[q].index<<"\t"<<iden[q].s<<"\t\t"<<iden[q].cnt<<endl;
	}
	cout<<endl;

	cout<<"Index\t"<<"Keyword_Used\t"<<"Counter"<<endl;
	for(int q=0;q<j;q++)
	{
		cout<<key[q].index<<"\t"<<key[q].s<<"\t\t"<<key[q].cnt<<endl;
	}
	cout<<endl;

	cout<<"Index\t"<<"Terminal\t"<<"Counter"<<endl;
	for(int q=0;q<x;q++)
	{
		cout<<ter[q].index<<"\t"<<ter[q].t<<"\t\t"<<ter[q].cnt<<endl;
	}

	fclose(fp);
	return 0;
}