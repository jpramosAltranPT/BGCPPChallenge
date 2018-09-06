#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <cstring>
#include <map>
#include <algorithm> 
#include <cstdlib> 

char* PATH;


using namespace std;


void found_Complex(string name_Complex, bool begin);

////////////////LAST STUFFF
bool control = true;

int Num_of_complex = 0;
////////////////LAST STUFFF
int Num_Tabs = 0;
int Num_Tabs_JSON = 0;

// ENTER FUNCTION

void removeCharsFromString( string str, char* charsToRemove ) {
   for ( unsigned int i = 0; i < strlen(charsToRemove); ++i ) {
      str.erase( remove(str.begin(), str.end(), charsToRemove[i]), str.end() );
   }
}

/////////////// XSD to XML
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

void writing_map(string variable_name, string variable_type) {

	fstream outfile;
	outfile.open("teste.xml", fstream::app);
	//	cout << "Opening File XML" << endl;
	char a = 34; // make the "
	string compare1("int");
	string compare3 = compare1 + a;
	string compare2("string");
	string compare4 = compare2 + a;

	if (variable_type == "int" || variable_type == compare3)
	{
		int i = rand() % 100;
		for (int j = 0; j < Num_Tabs; j++)
			outfile << "	";
		outfile << "<" << variable_name << ">" << i << "</" << variable_name << ">" << endl;
	}
	else if (variable_type == "string" || variable_type == compare4) {
		string gen = random_string(5);
		for (int j = 0; j < Num_Tabs; j++)
			outfile << "	";
		outfile << "<" << variable_name << ">" << gen << "</" << variable_name << ">" << endl;
	}

	outfile.close();
}

void make_Complex_Xml(bool start, string name) {



	fstream outfile;
	outfile.open("teste.xml", fstream::app);

	if (start)
	{

		cout << name << endl;
		for (int j = 0; j < Num_Tabs; j++)
			outfile << "	";
		outfile << "<" << name << ">" << endl;
		Num_Tabs++;

	}
	else if (!start)
	{
		cout << name << endl;
		for (int j = 0; j < Num_Tabs; j++)
			outfile << "	";
		outfile << "</" << name << ">" << endl;

	}

	outfile.close();

}

void getting_sequece(string variable_name_complex) {

	string aux("<xsd:element");
	string aux2("<xsd:sequence>");
	string aux3("</xsd:sequence>");
	string aux4("type=");

	fstream f1(PATH);
	size_t begin_of_sequece, end_of_sequece, found, found2, found3;

	f1.seekp(ios_base::beg);

	if (f1.is_open())
	{
		string s("");
		//	cout << "Opening File" << endl;
		getline(f1, s);

		while (!f1.eof() || s.length() != 0) {
			begin_of_sequece = s.find(aux2);
			cout << "KUNE 3123" <<begin_of_sequece << endl;
			if (begin_of_sequece != string::npos)
			{

				cout << "Hello" << begin_of_sequece << endl;
				do {
					cout << s << endl;
					found = s.find(aux);
					if (found != string::npos)
					{
						cout << s << endl;
						cout <<"LINE 90                 "<< found << endl;

						found2 = s.find(aux);
						if (found2 != string::npos)
						{
							found3 = s.find(" type");
							cout << "KINE 101       " << found3 << endl;
							string variable_name = s.substr(found2+19, found3 - found2-20);
							cout <<  found2 << "                        LINE 104                 " <<variable_name << endl;

							found2 = s.find(aux4);
							if (found2 != string::npos)
							{
								char a = '"';
								//		cout << found2 << endl;
								found3 = s.find("/>");
								//	cout << found3 << endl;
								cout << "KINE 112       " << found3 << endl;
								if (found3 != string::npos) {
									string variable_type = s.substr(found2 + 10, found3 - found2-12);
									//	cout << variable_type << endl;
									cout << found2 << "                        LINE 117                 " << variable_type << endl;
									
									writing_map(variable_name, variable_type);
								}

							}
						}
					}
					getline(f1, s);
					end_of_sequece = s.find(aux3);
					cout << "LEBVEFE124                             " <<end_of_sequece << "               "  << string::npos << endl;
				} while (end_of_sequece == string::npos);
			}
			getline(f1, s);
		}
		Num_Tabs--;
		make_Complex_Xml(false, variable_name_complex);
	}

}

void found_Complex(string name_Complex, bool begin) 
{
	string s;
	ifstream f1 (PATH);
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
									if (begin)
										getting_sequece(variable_name_complex);
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


void ficheiro_method() {


	string s,name_complex;
	string aux("<xsd:element");
	string aux2("name=");
	string aux3("type=");
	string find_end_complex("</xsd:complexType>");
	string found_ComplexType("<xsd:complexType");

	ifstream f1(PATH);
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
						//cout << "line149" << name_complex << endl;
						found_Complex(name_complex,true);

					}

				}
			}

			complex_end_num = s.find(find_end_complex);
			if (complex_end_num != string::npos)
			{
				Num_Tabs--;
				//found_Complex(name_complex, false);
			}

			getline(f1, s);

		}
		f1.close();
	}
	else {
		cout << "Error opening File" << endl;
	}
}


/////////// XML to JSON

void create_JSON()
{
	
	ofstream outJSON("Final.JSON");
	outJSON << "{" ;
	Num_Tabs_JSON++;
	outJSON.close();


}

void end_JSON()
{
	fstream outJSON;
	outJSON.open("Final.JSON", fstream::app);
	outJSON << "\n" << "}";
	outJSON.close();


}

void writing_JSON(string name, string value ,bool isValid, bool exception) {
	fstream outJSON;
	outJSON.open("Final.JSON", fstream::app);
	char a = 34;
	cout << "Line 270                        "  << endl;
	if (isValid) {
		outJSON << "," << "\n";
		for (int j = 0; j < Num_Tabs_JSON; j++)
			outJSON << "	";
		outJSON << a << name << a << ": " << a << value << a;
	}
	else if (!isValid && !exception)
	{
		outJSON << "\n";
		for (int j = 0; j < Num_Tabs_JSON; j++)
			outJSON << "	";
		outJSON << a << name << a << ": " << "{";
		Num_Tabs_JSON++;
	}
	else if (!isValid && exception)
	{
		Num_Tabs_JSON--;
		outJSON << "\n";
		for (int j = 0; j < Num_Tabs_JSON; j++)
			outJSON << "	";
		outJSON << "}";
	
	}
	outJSON.close();

}


void reading_XML() {

	ifstream f1("teste.xml");

	string s, value_string;
	string search_beginning("<");
	string search_end(">");
	string search_end_name("</");
	
	size_t name_number_b;
	size_t name_number_e, name_ending, difference;

	if (f1.is_open())
	{
		getline(f1, s);
		cout << "Opening File XML" << endl;
		getline(f1, s);
		cout << "XML 2 line" << endl;
		cout << s << endl;
		//Parser
		while (!f1.eof() || s.length() != 0)
		{
			name_number_b = s.find(search_beginning);
			name_number_e = s.find(search_end_name);
			difference = name_number_e - name_number_b;
			if (name_number_b != string::npos && difference>1)
			{
				name_number_e = s.find(search_end);
				if (name_number_e != string::npos)
				{
					string variable_name = s.substr(name_number_b + 1, name_number_e - name_number_b-1);
					cout << "Line 284                        " << variable_name << endl;
					name_ending = s.find(search_end_name); // now i know if its an element
					if (name_ending != string::npos)
					{
						value_string = s.substr(name_number_e + 1, name_ending - name_number_e - 1);
						writing_JSON(variable_name, value_string ,true, false);

					}
					else
					{
						value_string = "";
						writing_JSON(variable_name, value_string, false,false);
					}
					
				}
				
			}
			else
			{

				if (name_ending != string::npos)
				{
					string variable_name = "";
					value_string = "";
					writing_JSON(variable_name, value_string, false, true);
				}
			}
			getline(f1, s);
		}
		end_JSON();
	}
}

int main(int argc, char*argv[]) {

	char option = 0;

	if (argc > 1)
		PATH = argv[1];
	cout << PATH << endl;
	 //fill with your absolute path
	removeCharsFromString( PATH, "\"" );
	cout << PATH << endl;
	do {
		cout << "Menu" << endl;
		cout << "1-XML generation" << endl;
		cout << "2-JSON export" << endl;
		cout << "3-Exit the program" << endl;
		cout << "Choose your option" << endl;
		cin >> option;
		if (option != '1' && option != '2' && option != '3')
		{
			cout << "Invalid option, please repeat" << endl;
		}
	} while (option != '1' && option != '2' && option != '3');

	switch (option) {
	case '1':
		cout << "Case1" << endl;
		create_xml();
		ficheiro_method();
		break;
	case '2':
		cout << "Case2" << endl;
		create_JSON();
		reading_XML();
		break;
	case '3':
		cout << "Case3" << endl;
		break;
	default:
		break;
	};

	return (0);
}