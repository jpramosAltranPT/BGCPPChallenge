#include <iostream>
using namespace std;

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