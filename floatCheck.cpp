#include <iostream>
#include <fstream>
#include <ctype.h>

using namespace std;

/*int lookupChar( char c )
{
    if(isdigit(c))
        return 1;
    if( c == '.' )
        return 2;

    return 3;
}

bool detectFloat( string s )
{

    int dfa[2][2] = {{0}};

    return 0;
}*/

int getint( char ch )
{
	if( ch == '.' )
		return 1;
	else if( isdigit( ch ) )
		return 0;
    else if( ch == 'e' )
        return 2;
    else if( ch == '+' || ch == '-' )
        return 3;
    else if( ch == ';' )
        return 4;
	else
		return 5;
}

bool checkFloat( string str )
{
	char ch;
	int i=0;

	int dfa[4][6] = {{2}};

	dfa[0][0] = 0;
	dfa[0][1] = 1;
	dfa[0][2] = 3;
	dfa[0][3] = 0;
	dfa[0][4] = 1;
	dfa[0][5] = 3;

	dfa[1][0] = 1;
	dfa[1][1] = 3;
	dfa[1][2] = 2;
	dfa[1][3] = 3;
	dfa[1][4] = 1;
	dfa[1][5] = 3;

	dfa[2][0] = 2;
	dfa[2][1] = 3;
	dfa[2][2] = 3;
	dfa[2][3] = 2;
	dfa[2][4] = 2;
	dfa[2][5] = 3;

	dfa[3][0] = 3;
	dfa[3][1] = 3;
	dfa[3][2] = 3;
	dfa[3][3] = 3;
	dfa[3][4] = 3;
	dfa[3][5] = 3;

	int cur = 0 , next;

	while( i < str.length() )
	{
		//cout<<"ch = "<<ch<<endl;

		ch = str.at(i);
		int k = getint( ch );

		if( k > 5 )
		{
			cout<<"not float"<<endl;
			return false;
		}

		cur = dfa[cur][k];

		i++;

	}

	if( cur == 1 || cur == 0 || cur == 2 )
		return true;

	return false;
}

int main()
{
    cout << "Hello world!" << endl;

    ifstream ifile;
    ofstream ofile;
    string inp;

    ifile.open("input.txt");

    while( !ifile.eof() )
    {
        ifile >> inp;

        if( checkFloat( inp ) )
        {

            cout<<"float detected and it is : "<<inp<<endl;

        }
        /*else
            cout<<"word that is not float is : " << inp <<endl;*/
    }

    return 0;
}
