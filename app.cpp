
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm> 
#include <cstdlib> 


using namespace std;

////////////////LAST STUFFF
bool control = true;

int Num_of_complex = 0;
////////////////LAST STUFFF
int Num_Tabs = 0;

string random_string(size_t length)
{
	auto randchar = []() -> char
	{
		const char charset[] =
			"0123456789"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz";
		const size_t max_index = (sizeof(charset) - 1);
		return charset[rand() % max_index];
	};
	string str(length, 0);
	generate_n(str.begin(), length, randchar);
	return str;
}

void make_Complex_Xml(bool start, string name) {



	fstream outfile;
	outfile.open("teste.xml", fstream::app);

	if (start && control) 
	{

		cout << name << endl;
		for (int j = 0; j < Num_Tabs; j++)
			outfile << "	";
		outfile << "<" << name << ">" << endl;
		Num_Tabs++;
		control = false;
	}
	else if(!start && control)
	{
		cout << name << endl;
		for (int j = 0; j < Num_Tabs; j++)
			outfile << "	";
		outfile << "</" << name << ">" << endl;
		control = true;
	}

	outfile.close();

}

void found_Complex(string name_Complex, bool begin) 
{
	string s;
	ifstream f1("template.xsd");
	string aux("<xsd:element");
	string aux2("name=");
	string aux3("type=");
	getline(f1, s);
	size_t  found, found2, found3;

	if (f1.is_open())
	{
			while (!f1.eof() || s.length() != 0)
			{
				found = s.find(aux);
				if (found != string::npos)
				{
					//	cout << s << endl;
					//	cout << found << endl;

					found2 = s.find(aux2);

					if (found2 != string::npos)
					{
						char a = '"';
						found3 = s.find(" type");
						//		cout << found3 << endl;
						string variable_name_complex = s.substr(found2 + 6, found3 - found2 - 7);
					//	cout << variable_name_complex << endl;


						found2 = s.find(aux3);
						if (found2 != string::npos)
						{
							found3 = s.find(">");
							//	cout << found3 << endl;
							// 
							if (found3 != string::npos) {
								string c_name = s.substr(found2 + 10, found3 - found2 - 12);
								if (c_name == name_Complex) {
									Num_of_complex++;
									cout << "Num_of_complex:    " << Num_of_complex << endl;
									make_Complex_Xml(begin, variable_name_complex);
								}
							}


						}
					}
				}
				getline(f1, s);
			}
		}
		

	}



void create_xml()
{
	ofstream outfile("teste.xml");
	char a = 34;
	outfile << "<?xml version= "<< a <<"1.0" << a << " encoding= "<< a << "UTF-8" << a << "?>" << endl;
	Num_Tabs++;
	outfile.close();
}

void writing_map(string variable_name, string variable_type) {

	fstream outfile;
	outfile.open("teste.xml", fstream::app);
//	cout << "Opening File XML" << endl;
	char a = 34; // make the "
	string compare1("int");
	string compare3 = compare1 + a;
	string compare2("string");
	string compare4 = compare2 + a;

	if( variable_type == "int" || variable_type == compare3)
	{
		int i = rand() % 100;
		for (int j = 0; j < Num_Tabs; j++)
			outfile << "	";
		outfile << "<"  <<variable_name << ">" << i << "</" << variable_name << ">" << endl;
	}
	else if (variable_type == "string" || variable_type == compare4){
		string gen = random_string(5);
		for (int j = 0; j < Num_Tabs; j++)
			outfile << "	";
		outfile << "<" << variable_name << ">" << gen << "</" << variable_name << ">" << endl;
	}
		
	outfile.close();
}

void ficheiro_method() {


	string s,name_complex;
	string aux("<xsd:element");
	string aux2("name=");
	string aux3("type=");
	string find_end_complex("</xsd:complexType>");
	string found_ComplexType("<xsd:complexType");

	ifstream f1("template.xsd");
	size_t complex, complex_end_num , found_complex, found, found2, found3;

	if (f1.is_open())
	{
		s = "";
	//	cout << "Opening File" << endl;
		getline(f1, s);


		//Parser
		while (!f1.eof() || s.length() != 0)
		{
			cout << s << endl;
			complex = s.find(found_ComplexType);

			if (complex != string::npos) {
				found_complex = s.find(aux2);
				if (found_complex != string::npos)
				{
				//	cout << found_complex << endl;
					found3 = s.find(">");
				//	cout << found3 << endl;
					// 
					if (found3 != string::npos) {
						name_complex = s.substr(found_complex + 6, found3 - found_complex - 7);
						cout << "line149" << name_complex << endl;
						found_Complex(name_complex,true);
					}

				}
			}

			complex_end_num = s.find(find_end_complex);
			if (complex_end_num != string::npos)
			{
				Num_Tabs--;
				control = true;
				found_Complex(name_complex, false);
			}
			found = s.find(aux);
			if (found != string::npos)
			{
				//	cout << s << endl;
				//	cout << found << endl;

				found2 = s.find(aux2);
				if (found2 != string::npos)
				{
					found3 = s.find(" type");
					//		cout << found3 << endl;
					string variable_name = s.substr(found2 + 6, found3 - found2 - 7);
				//	cout << variable_name << endl;

					found2 = s.find(aux3);
					if (found2 != string::npos)
					{
						char a = '"';
						//		cout << found2 << endl;
						found3 = s.find("/>");
						//	cout << found3 << endl;
						// 
						if (found3 != string::npos) {
							string variable_type = s.substr(found2 + 10, found3 - found2 - 11);
						//	cout << variable_type << endl;
							writing_map(variable_name, variable_type);
						}

					}
				}
			}
			getline(f1, s);

		}
	}
	else {
		cout << "Error opening File" << endl;
	}
}


int main() {

	int option = 0;

	do {
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
	} while (option != 1 && option != 2 && option != 3);

	switch (option) {
	case 1:
		cout << "Case1" << endl;
		create_xml();
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