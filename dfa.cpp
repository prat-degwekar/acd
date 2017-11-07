#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

int getint( char ch )
{
	if( ch == '.' )
		return 1;
	else if( isdigit( ch ) )
		return 0;
	else
		return 2;
}

bool checkfloat( string str )
{
	char ch;
	int i=0;

	int dfa[3][3] = {{2}};

	dfa[0][0] = 0;
	dfa[0][1] = 1;
	dfa[0][2] = 2;
	dfa[1][0] = 1;
	dfa[1][1] = 3;
	dfa[1][2] = 2;
	dfa[2][0] = 2;
	dfa[2][1] = 2;
	dfa[3][2] = 2;

	int cur = 0 , next;

	while( i < str.length() )
	{
		cout<<"ch = "<<ch<<endl;

		ch = str.at(i);
		int k = getint( ch );
		
		if( k > 2 )
		{
			cout<<"not float"<<endl;
			return false;
		}

		cur = dfa[cur][k];

		i++;

	}

	if( cur == 1 || cur == 0 )
		return true;

	return false;
}

int main()
{
	cout<<"1.23 : "<<checkfloat( "1.23" )<<endl;
	cout<<"hello : "<<checkfloat( "hello" )<<endl;

	return 0;
}