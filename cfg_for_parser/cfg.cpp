#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	int no;
	vector<string> v[26];
	ifstream f1;
	f1.open("cfg.txt");
	f1>>no;
	int i,j;char ch;string a;
	for(i=0;i<no;i++)
	{
		f1>>ch;f1>>a;
		v[ch-'A'].push_back(a);
	}
	f1.close();
//	cout<<"Enter the string\n";
	int c1=0,c2=0;
	cout<<"Checking for left recursion\n";
	for(i=0;i<26;i++)
	{
		if(v[i].size()!=0)
		{
			for(j=0;j<v[i].size();j++)
			{
				if(v[i][j][0]-'A'==i)
				{
					c1=1;
				}
			}
		}
	}
	if(c1==1)
	{
		cout<<"Left recursion exists\n\n";
	}
	int k;
	cout<<"Checking left factoring\n";
	for(i=0;i<26;i++)
	{
		if(v[i].size()!=0)
		{	
			//cout<<(char)('A'+i)<<"->";

			for(j=0;j<v[i].size();j++)
			{
				for(k=j+1;k<v[i].size();k++)
				{
					//cout<<v[i][j]<<" "<<v[i][k]<<endl;
					if(v[i][j][0]==v[i][k][0] and v[i][j][0]>='a')
					{
						c2=1;
					}
				}
			}
		}
	}
	if(c2==1)
	{
		cout<<"Left factoring exists\n";
	}
	else
	{
		cout<<"No left factoring\n";
	}
	if(c1 or c2)
	{
		cout<<"Not suitable for LL(1)\n";
	}
	else 
	{
		cout<<"suitable\n";
	}
	return 0;
}