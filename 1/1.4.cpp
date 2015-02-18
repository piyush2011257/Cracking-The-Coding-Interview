/*
Careercup- 1.4
*/
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{	char ch[1000];
	scanf("%[^\n]s",ch);
	int n=strlen(ch);
	int ct=0;
	for ( int i=0; i<n; i++ )
		if ( ch[i] == ' ' )
			ct++;
	int N = n + ct*2;
	//cout<<n<<" "<<N<<endl;
	ch[N]='\0';
	for ( int i=N-1, j=n-1; j >= 0; j-- )
	{	if ( ch[j] != ' ' )
		{	ch[i]=ch[j];
			i--;
		}
		else
		{	ch[i]='0';
			ch[i-1]='2';
			ch[i-2]='%';
			i-=3;
		}
	}
	cout<<ch<<endl;
	return 0;
}
