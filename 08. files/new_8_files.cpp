 /*Write a C++ program that reads contents from two text files
 that are specified as command line arguments and create a file by name “merge.txt”.
 Read one line at a time from each input file in an alternate manner
 and write to the output file till you have reached the end.
 A Sample output is shown here:
 Input File1 		Input File2			 merge.txt
 Abcdeabc	        fghijfgh 		     abcdeabc
 67890123			12345678		     fghijfgh
                                         67890123
                                         12345678

*/

#include<iostream>
#include<fstream>
using namespace std;

int main(int argc,char *argv[])
{
	int flag=0;
	char data[100];

	ifstream ifile1,ifile2;
	fstream ofile;

	ifile1.open(argv[1]);
	ifile2.open(argv[2]);
	if(!ifile1)   //to check whether input file1 exist or not
	{
		cout<<"there is no file with name "<<argv[1]<<endl;
		flag=1;
	}


	if(!ifile2)   //to check whether input file2 exist or not
	{
		cout<<"there is no file with name "<<argv[2]<<endl;
		flag=1;
	}
	if(flag==1)
	{
		return 0;
	}

	ofile.open(argv[3],ios::out);
	do
	{
		ifile1.getline(data,100);
		if(!ifile1.eof())
		ofile<<data<<"\n";

		ifile2.getline(data,100);
		if(!ifile2.eof())
		ofile<<data<<"\n";

	}while(!ifile1.eof() || !ifile2.eof());

	ifile1.close();
	ifile2.close();
	ofile.close();

	ofile.open(argv[3],ios::in);
	do
	{
		ofile.getline(data,100);
		if(!ofile.eof())
		cout<<data<<"\n";
	}while( ! ofile.eof() );

	return 0;
}
