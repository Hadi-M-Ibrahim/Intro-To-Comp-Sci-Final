#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const float tax = .0775;
string NameReceipt;
float TotalPrice;


void recipt(string Name, int quantity, float Price, int i ){
	ofstream Output;

	Output.open("Output.txt", ios_base::app);



	if (i == -1) {
		cout << fixed << showpoint << setprecision(2);
		cout << "You selected the books: " << NameReceipt << endl << " Your total is $" << TotalPrice;
	}
	else {
		NameReceipt = NameReceipt + Name;
		TotalPrice = TotalPrice + Price;
		
		Output << fixed << showpoint << setprecision(2);
		Output << Name << quantity << endl; 
	
	}


}

int Menu(int i, int quantity) {
	ifstream Input;
	string Book1_Title;
	string Book1_Price;
	float Book1_Pricef;
	string Book2_Title;
	string Book2_Price;
	float Book2_Pricef;
	string Book3_Title;
	string Book3_Price;
	float Book3_Pricef;
	string Book4_Title;
	string Book4_Price;
	float Book4_Pricef;
	string Book5_Title;
	string Book5_Price;
	float Book5_Pricef;

	float SubTotal;
	float taxtotal;
	float total;


	Input.open("Input.txt");

	if (!Input)
		cout << "Could not open Input.txt check for file in system";

	getline(Input, Book1_Title);
	getline(Input, Book1_Price);
	getline(Input, Book2_Title);
	getline(Input, Book2_Price);
	getline(Input, Book3_Title);
	getline(Input, Book3_Price);
	getline(Input, Book4_Title);
	getline(Input, Book4_Price);
	getline(Input, Book5_Title);
	getline(Input, Book5_Price);

	Book1_Pricef = stof(Book1_Price);
	Book2_Pricef = stof(Book2_Price);
	Book3_Pricef = stof(Book3_Price);
	Book4_Pricef = stof(Book4_Price);
	Book5_Pricef = stof(Book5_Price);

	cout << fixed << showpoint << setprecision(2);
	cout << "Option 1: " << Book1_Title << " $" << Book1_Price << endl;
	cout << "Option 2: " << Book2_Title << " $" << Book2_Price << endl;
	cout << "Option 3: " << Book3_Title << " $" << Book3_Price << endl;
	cout << "Option 4: " << Book4_Title << " $" << Book4_Price << endl;
	cout << "Option 5: " << Book5_Title << " $" << Book5_Price << endl;
	cout << "Option -1: Checkout Selected Books" << endl;
	
	switch (i)
	{
	case 0: 
		break;
	case 1:
		SubTotal = quantity * Book1_Pricef;
		taxtotal = SubTotal * tax;
		total = taxtotal + SubTotal;

		recipt(Book1_Title, quantity, total, 0);
		break;
	case 2:
		SubTotal = quantity * Book2_Pricef;
		taxtotal = SubTotal * tax;
		total = taxtotal + SubTotal;

		recipt(Book2_Title, quantity, total, 0);
		break;
	case 3:
		SubTotal = quantity * Book3_Pricef;
		taxtotal = SubTotal * tax;
		total = taxtotal + SubTotal;

		recipt(Book3_Title, quantity, total, 0);
		break;
	case 4:
		SubTotal = quantity * Book4_Pricef;
		taxtotal = SubTotal * tax;
		total = taxtotal + SubTotal;

		recipt(Book4_Title, quantity, total, 0);
		break;
	case 5:
		SubTotal = quantity * Book5_Pricef;
		taxtotal = SubTotal * tax;
		total = taxtotal + SubTotal;

		recipt(Book5_Title, quantity, total, 0);
		break;
	default:
		cout << "Sorry thats not a vaild choice. Try again!" << endl;
		break;
	}
	
return 0;
}


int main()
{
	int MenuChoice = 0;
	int Quantity = 0; 

	cout << "Welcome to the book shop!" << endl;
	

	do
	{
	Menu(MenuChoice, Quantity);
	cout << "Which option would you like: ";
	cin >> MenuChoice;
	if (MenuChoice != -1)
	{
		cout << "And how many would you like : ";
		cin >> Quantity;
	}
	
	} 
	while (MenuChoice != -1);
	
	recipt("", 0, 0, -1);
	

}
