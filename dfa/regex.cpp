#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
/*
Input as follows in file
no of states
no of symbols
initial state
no of final states
array of final state nos
transition table

*/
int main()
{
	ifstream f1;
	f1.open("regex.txt");
	string s;
	int no_states,q,q_init,no_final,no_alpha;
	vector <int> final;
	f1>>no_states;
	f1>>no_alpha;
	f1>>q_init;
	f1>>no_final;
	vector<int> v[10];
	int a;
	int i,j;
	for(i=0;i<no_final;i++)
	{
		f1>>a;
		final.push_back(a);
	}
	for(i=0;i<no_states;i++)
	{
		for(j=0;j<no_alpha;j++)
		{
			f1>>a;
			v[i].push_back(a);
		}
	}
	f1.close();

	q=q_init;
	//string s;
	cout<<"Enter the input: ";
	cin>>s;
	int k;int c=0;
	for(i=0;i<s.size();i++)
	{
		if(v[q][s[i]-'a']==-1)
		{
			q=-1;
			break;
		}
		else
		{
			q=v[q][s[i]-'a'];
		}
	}
	for(i=0;i<final.size();i++)
	{
		if(final[i]==q)
		{
			c=1;break;
		}
	}
	if(c==1)
	{
		cout<<"Accepted\n";
	}
	else
	{
		cout<<"Rejected\n";
	}

	return 0;
}