#include <bits/stdc++.h>
using namespace std;

const int From=1000;
const int To=6297;

int main()
{
	for (int id=4991;id<=To;id++)
	{
		cout<<"------------------"<<id<<"------------------"<<endl<<flush;
		
		ofstream out("input");
		out<<id<<endl;
		out.close();
		
		cout<<"clawer "<<flush;
		system("python3 main.py <input");
		cout<<"down"<<endl<<flush;
		
		system("./match");

		cout<<"sleep"<<flush;system("sleep 1");cout<<"."<<endl;
	}

	cout<<"create index"<<endl;
	ofstream index("index.html");

	ifstream in("index_head.html");
	string head;
	getline(in,head,(char)EOF);
	in.close();
	index<<head<<endl;
	for (int id=From;id<=To;id++)
	{
		stringstream tostring;tostring<<id;
		in.open(("./html/HDU"+tostring.str()+"-title.txt").c_str());
		string name;
		getline(in,name,(char)EOF);
		in.close();
		index<<"<tr><td><a href=\"./"<<id<<".html\">"<<id<<"</a></td><td>"<<name<<"</td></tr>"<<endl;
	}

	in.open("index_foot.html");
	getline(in,head,(char)EOF);
	in.close();
	index<<head<<endl;
	index.close();
	
	return 0;
}
