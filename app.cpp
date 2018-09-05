#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

void writing_map (string variable_name, string variable_type){
	
	ofstream outfile("teste.xml");
		cout << "Opening File XML"<< endl;
	outfile << variable_name << " " << variable_type << endl;

	outfile.close();
}

void ficheiro_method(){
	
	string s;
	string aux  ("<xsd:element");
	string aux2 ("name=");
	string aux3 ("type=");
	
	ifstream f1("template.xsd");
	size_t found,found2, found3;
	
	if(f1.is_open())
	{
		s="";
		cout << "Opening File"<< endl;
		getline(f1,s);

		
		//Parser
		while (!f1.eof() || s.length()!=0)
		{
			
			found = s.find(aux);
			if (found!=string::npos)
			{
			//	cout << s << endl;
			//	cout << found << endl;
			
				found2 = s.find(aux2);
				if (found2!=string::npos)
				{
					char a = '"';
			//		cout << found2 << endl;
					found3 = s.find(" type");
			//		cout << found3 << endl;
					string variable_name = s.substr (found2+6,found3-found2-7);
					cout << variable_name << endl;
				
					found2 = s.find(aux3);
					if (found2!=string::npos)
					{
						char a = '"';
				//		cout << found2 << endl;
						found3 = s.find(" />");
					//	cout << found3 << endl;
						if (found3!=string::npos){
							string variable_type = s.substr (found2+10,found3-found2-11);
							cout << variable_type << endl;
							writing_map(variable_name,variable_type);
						}
						
					}
				}				
			}
			getline(f1,s);
			
		}
	}
	else{
		cout << "Error opening File"<< endl;
	}
}


int main(){
	
	int option=0;

		do{
			cout << "Menu" << endl;
			cout << "1-XML generation" << endl;
			cout << "2-JSON export" << endl;
			cout << "3-Exit the program" << endl;
			cout << "Choose your option" << endl;
			cin >> option;
			if (option != 1 && option != 2 && option != 3)
			{
				cout << "Invalid option, please repeat" << endl;
			}
		}while(option != 1 && option != 2 && option != 3);
	
	switch(option){
			case 1:
				cout << "Case1" << endl;
				ficheiro_method();
				break;
			case 2:
				cout << "Case2" << endl;
				break;
			case 3:
				cout << "Case3" << endl;
				break;
			default:
				break;
	};

	return (0);
}