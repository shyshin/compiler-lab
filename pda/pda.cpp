#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
/*
no states
init
final
alpha
transition table
stack table
*/
char stack[20];
int top;
void push(char a)
{
	top++;
	stack[top]=a;
}
char pop()
{
	if(top==-1)
	{
		return '-';
	}
	char a=stack[top];
	top--;
	return a;
}
int main()
{
	top=-1;push('z');
	int states,init,final,alpha;
	vector<int> v[10];vector<string> st[10];
	ifstream f1;
	f1.open("pda.txt");
	f1>>states;
	f1>>init;
	f1>>final;
	f1>>alpha;
	int i,j,k;string ch;
	for(i=0;i<states;i++)
	{

		for(j=0;j<=alpha;j++)
		{
			f1>>k;
			v[i].push_back(k);
		}
	}
	for(i=0;i<=alpha;i++)
	{
		for(j=0;j<=alpha;j++)
		{
			f1>>ch;
			st[i].push_back(ch);
		//	cout<<ch<<" ";
		}
		//cout<<endl;
	}
	f1.close();
	string s;
	cout<<"Enter the string  ";
	int q=init,c=1;char l;
	cin>>s;
	s.append("$");
	
	for(i=0;i<s.size();i++)
	{
		j=s[i]-'a';
		
		if(s[i]=='$')
		{
			j=alpha;
		}
		q=v[q][j];
		if(q==-1)
		{
			c=0;break;
		}
		l=pop();
		if(l=='-')
		{
			c=0;break;
		}
		else if(l=='z')
		{
			ch=st[j][alpha];
		}
		else
		{
			ch=st[j][l-'a'];
		}
		if(ch=="-1")
		{
			
		}
		else if(ch!="E")
		{
			for(k=0;k<ch.size();k++)
			{
				push(ch[k]);
			}
		}
	//	cout<<q<<" "<<j<<" "<<l-'a'<<" "<<ch<<endl;
	}
	if(q!=final or stack[top]!='z')
	{
		c=0;
	}
	if(c==1)
	{
		cout<<"Accepted";
	}
	else
	{
		cout<<"Rejected";
	}

	return 0;
}