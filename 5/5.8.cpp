/*
5.8
*/
#include<cstdio>
#include<iostream>
using namespace std;

int main()
{	int x1,x2;
	cin>>x1>>x2;
	typedef char bytes;
	bytes arr[100]={0};
	// x1, x2 are bits NOT array index
	int start_offset=x1%8;
	int end_offset=x2%8;
	int start=x1/8;
	int end=x2/8;
	if ( start_offset != 0 )
		start++;
	if ( end_offset != 7 )
		end--;
	for ( int i=start; i<=end; i++ )
	{	arr[i] |= 0xff;
		//cout<<(int)arr[i]<<endl;
		/*
		1 - 00000001
		-1  11111110
			  +1
		    11111111	2's compliment
		*/
	}
	//cout<<0b00111111<<endl;
	bytes start_mask=( 1<<(8-start_offset))-1;	// mask need to be for 1 byte only
	cout<<(int)start_mask<<endl;	// will translate the 1 byte value to integer
	/*
	start_mask >>= start_offset;
	cout<<(int)start_mask<<endl;
	Bit shift method fails becaose of bit shifting for 2's compliment notation
	e.g. a = 11111111
		 |
		MSB is 1 -> negative number representation
	    so a>>2 != 00111111
		BUT == 11111111
		       ||
		     1's are added
		     NOT 0's
		so a>>X is stil a
	*/
	bytes end_mask = ( 1<<(8-end_offset-1))-1;
	end_mask = ~end_mask;
	cout<<(int)end_mask<<endl;
	/*
	11110000
	
	16- 00010000
	    11101111
		  +1
	    11110000	-16 2's compliment
	*/
	//end_mask <<= (end_offset+1);
	if ( x1/8 == x2/8 )		// if in same index
		arr[x1/8] |= ( start_mask & end_mask);
	else
	{	arr[x1/8] |= start_mask;
		arr[x2/8] |= end_mask;
	}
	//cout<<start<<" "<<start_offset<<" "<<(int)start_mask<<endl;
	//cout<<end<<" "<<end_offset<<" "<<(int)end_mask<<endl;
	for ( int i=0; i<=x2/8; i++ )
		cout<<(int)arr[i]<<" ";
	cout<<endl;
	return 0;
}
