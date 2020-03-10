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

int main()
{
	FILE* fp;
	char oper[]="+-/*%=";
	char ch;
	string arr;
	int l=0;
	fp=fopen("program.txt","r");
	while((ch=fgetc(fp))!=EOF)
	{
		//Checking operators
		for(int k=0;k<6;k++)
		{
			if(ch==oper[k])
			{
				cout<<ch<<"\t:"<<"operator"<<endl;
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
				cout<<arr<<"\t:"<<"Keyword"<<endl;
			}
			else if(!iskeyword(arr))
			{
				cout<<arr<<"\t:"<<"Identifier"<<endl;
			}
			if((ch=='{' || ch=='}' || ch=='(' || ch==')' || ch==';' || ch==':' || ch==',') && (l!=0))
			{
				cout<<ch<<"\t:"<<"Terminal"<<endl;
			}
			arr.erase();
			l=0;
		}
		else
		{
			if((ch=='{' || ch=='}' || ch=='(' || ch==')' || ch==';' || ch==':' || ch==',') && (l==0))
			{
				cout<<ch<<"\t:"<<"Terminal"<<endl;
			}
		}
	}
	fclose(fp);
	return 0;
}