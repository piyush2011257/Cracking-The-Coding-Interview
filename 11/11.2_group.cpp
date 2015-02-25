/*
11.2
*/

// The question does not describe the ordering of anagrams

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

int main()
{	int n;
	cin>>n;
	map<string,vector<string> > m;
	string a,tmp;
	for ( int i=0; i<n; i++ )
	{	cin>>a;
		tmp=a;
		sort(a.begin(), a.end());
		m[a].push_back(tmp);
	}
	for ( map<string,vector<string> >::iterator iter=m.begin(); iter != m.end(); iter++ )
	{	for ( int i=0; i< (iter->second).size(); i++ )
			cout<<(*iter).first<<" "<<(*iter).second[i]<<endl;
	}
	return 0;
}
