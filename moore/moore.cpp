#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
/*
File input:
no of states
no of symbols
initial state
transition table
array containing output of each state


*/
int main()
{
	ifstream f1;
	f1.open("moore.txt");
	int n_states,n_alpha,q_init,q;
	vector<int> v[10],out;
	f1>>n_states;
	f1>>n_alpha;
	f1>>q_init;
	int i,j,a;
	for(i=0;i<n_states;i++)
	{
		for(j=0;j<n_alpha;j++)
		{
			f1>>a;
			v[i].push_back(a);
		}
	}
	for(i=0;i<n_alpha;i++)
	{
		f1>>a;
		out.push_back(a);
	}
	f1.close();

	q=q_init;
	cout<<"Enter the input: ";
	string s;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		cout<<out[q];
		q=v[q][s[i]-'a'];
	}
	cout<<out[q];
	return 0;
}



