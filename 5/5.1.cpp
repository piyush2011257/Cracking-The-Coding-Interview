/*
5.1
*/
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{	unsigned int n, m ,i,j;
	cin>>n>>m>>i>>j;
	unsigned int N= (~( ((1<<j+1)-1) & (~((1<<i)-1)) )) & n;
	/*
	e.g. N=10000000000 M=10011 i=2 j=6
	((1<<j+1)-1) - 00001111111
	((1<<i)-1) - 00000000011
	( ((1<<j+1)-1) & (~((1<<i)-1)) ) - 00001111100
	~ ( ((1<<j+1)-1) & (~((1<<i)-1)) ) - 1110000011
	N - i to j bits cleared ( all 0 )
	m<<i - 1001100
	*/
	//cout<<((1<<j+1)-1)<<" "<<((1<<i)-1)<<" "<<(~((1<<i)-1))<<" "<<( ((1<<j+1)-1) & (~((1<<i)-1)) )<<endl;
	unsigned int M= m<<i;
	//cout<<N<<" "<<M<<endl;
	cout<<(N|M)<<endl;
	return 0;
}
