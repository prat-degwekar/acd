#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream ifile;
	ifile.open("ckeys");
	string word;
	ifstream checkfile;
	checkfile.open("try.c");

	ofstream ofile;
	ofile.open("converted.txt" , ios::out);

	while(!checkfile.eof())
	{
		string tope;
		//checkfile>>tope;
		getline( checkfile , tope );
		istringstream iss ( tope );

		string chk;
		string fin;
		string newl;
		bool d=0;

		while(!iss.eof() )
		{
			d=0;

			iss>>fin;

			while(!ifile.eof())
			{


				ifile>>chk;
				//cout<<chk<<endl;
				if( chk.compare(fin) == 0 )
				{
					cout<<fin<<" : is a keyword"<<endl;
					newl+="kwd ";
					d=1;
					break;
				}

			}

			if(!d)
				newl+=fin+" ";


			ifile.close();
			ifile.open("ckeys");

		}

		newl+="\n";

		cout<<newl<<endl;
		ofile << newl;
		newl = "";
	}

	string newl="\0";
	ofile<<newl;
	ofile.close();
	ifile.close();

	return 0;
}