#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
File input as follows:
no of states
no of symbols
initial state
transition table
table containing output of mealy machine with state in row and symbol in column

*/
int main()
{
	ifstream f1;
	f1.open("mealy.txt");
	int n_states,n_alpha,q_init,q;
	vector <int> out[10],v[10];
	int i,j;
	f1>>n_states;
	f1>>n_alpha;
	f1>>q_init;
	int a;
	for(i=0;i<n_states;i++)
	{
		for(j=0;j<n_alpha;j++)
		{
			f1>>a;
			v[i].push_back(a);
		}
	}
	for(i=0;i<n_states;i++)
	{
		for(j=0;j<n_alpha;j++)
		{
			f1>>a;
			out[i].push_back(a);
		}
	}

	f1.close();
	q=q_init;
	string s;
	cout<<"Enter the input: ";
	cin>>s;
	cout<<"Output: ";
	for(i=0;i<s.size();i++)
	{
		cout<<out[q][s[i]-'a']<<" ";
		q=v[q][s[i]-'a'];
	}

	return 0;
}