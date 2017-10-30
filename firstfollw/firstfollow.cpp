#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <string> v[26];
int n;
vector <char> first[26];
void fir(int k)
{
	int i,j,l;
	if(first[k].size()!=0)
	{
		break;
	}
	for(i=0;i<v[k].size();i++)
	{
		for(j=0;j<v[k][i].size();j++)
		{
			if(v[k][i][j]>='a')
			{
				first[k].push_back(v[k][i][j]);
			}
			else
			{
				fir(v[k][i][j]-'A');
				for(l=0;l<first[v[k][i][j]].size();l++)
				{
					first[k].push_back(first[v[k][i][j]][l]);
				}
			}
		}
	}
}
void fol(int k)
{
	int i,j,l;
	if(fol[k].size()!=0)
	{
		break;
	}
	for(i=0;i<26;i++)	
	{
		for(j=0;j<v[i].size();j++)
		{
			if(v[i][j][v[i][j].size()-1]==k)
			{
				fol(i-'A');
				for(l=0;l<follow[i].size();l++)
				{
					follow[k].push_back(follow[i][l]);
				}
			}
			else
			{
				follow[k].push_back(v[i][j][v[i][j].size()-1]);
			}
		}
	}
}
int main()
{
	ifstream f1;int k;
	f1.open("firstfollow.txt");
	int a,i,j;
	string s;
	
	f1>>n;
	char ch;
	for(i=0;i<n;i++)
	{
		f1>>ch;
		f1>>s;
		v[ch-'A'].push_back(s);
	}
	f1.close();cout<<"First\n";
	for(i=0;i<26;i++)
	{
		if(v[i].size()!=0)
		{
			cout<<'A'+i<<"->";
			fir(i-'A');
			for(j=0;j<first[i].size();j++)
			{
				cout<<first[i][j]<<" ";
			}
		}
		cout<<"\n";
	}
	vector <char> follow[26];cout<<"Follow\n";
	follow[18].push_back('$');
	for(i=0;i<26;i++)
	{
		if(v[i].size()!=0)
		{
			cout<<'A'+i<<"->";
			fol(i);
			for(j=0;j<follow[i].size();j++)
			{
				cout<<follow[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	return 0;
}