// This program calculates the number of different cups needed

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;
int main()
{
// Cup sizes
	const int SHOT = 1;
	const int REGULAR = SHOT * 8; 
	const int GRANDE = REGULAR * 2;
	const int VENTI = REGULAR * 3;
	const double PLAINCOFFEE = 0.13;
	const double LATTE = 0.23;
	const double MACCHIATO = 0.25;
	const double FRAPPUCCINO = 0.28; 
	const double taxrate = 0.07;
	double priceOfcoffee, salesTax, total;
	
	int ouncesInput =0, Venti =0, Grande =0, Regular =0, Shot =0, remainingOunces = 0, choice = 0, numberOforders = 0;
	string name, PlainCoffee, Latte, Macchiato, Frappuccino, order, price, tax, amountOwed, newline, blankline;
	
// Ask customer to enter the amount of coffee and his/her name
	cout << "Welcome to the World's Best Coffee Shop \n\n";
	cout << "Enter the number of orders: ";
	cin >> numberOforders;
	while(numberOforders == 0 || numberOforders < 0)
	{
		cout << "Invalid number entered. Please enter the whole number greater than 0: ";
		cin >> numberOforders;
	}
	
	cin.ignore();
		
	if(numberOforders > 3)
	{
		// create the ifstream object and open file for reading
		ifstream input;
		input.open("CoffeeOrders.txt");
		
		// read the info from the file using a while loop
		
			while(getline(input, name)) // if we can read a name, then process the rest
		{
			// read the next line into the order string
						
			getline(input, order);
			getline(input, price);
			getline(input, tax);
			getline(input, amountOwed);
			getline(input, newline);
			getline(input, blankline);
			
				
			// display the data
			cout << name << endl;
			cout << order << endl;
			cout << price << endl;
			cout << tax << endl;
			cout << amountOwed << endl << endl;
			
		
		}
			input.close();
			
					
	}	
	else if(numberOforders <= 3)
	{
		for ( int i = 0; i < numberOforders; i++ )
		{
		
			cout << "1 - Plain Coffee \n";
			cout << "2 - Latte \n";
			cout << "3 - Macchiato \n";
			cout << "4 - Frappuccino \n\n";
			cout << "Enter your choice ";
			cin >> choice;
		
		 // Validation of choices	
			while(choice < 1 || choice > 4)
			{
				cout << choice << " is an invalid choice. Enter the number 1-4: ";
				cin >> choice;
			}
			if(choice >=1 & choice <=4) 
			{
			cout << "\n";
			cout << "Enter the number of ounces ordered: ";
			cin >> ouncesInput;
		    }
				while(ouncesInput <=0)
			{
				cout << "Invalid amount entered. Please enter amount more than 0: ";
				cin >> ouncesInput;
			}
			if(ouncesInput > 0) 
			{
			cin.get(); 
			cout << "Enter the name of the customer:  ";
			getline(cin, name);
			
		 // Price Calculations
			if(choice == 1)
			{
				
				priceOfcoffee = ouncesInput * PLAINCOFFEE;
				salesTax = priceOfcoffee * taxrate;
				total = priceOfcoffee + salesTax;
				cout << "\n";
				cout << name << endl;
				cout << "Order: " << "Plain Coffee " << ouncesInput << " oz" << endl;
				
			}
			
			else if(choice == 2)
			{
			
				priceOfcoffee = ouncesInput * LATTE;
				salesTax = priceOfcoffee * taxrate;
				total = priceOfcoffee + salesTax;
				cout << "\n";
				cout << name << endl;
				cout << "Order: " << "Latte " << ouncesInput << " oz" << endl;
				
			}
			 else if(choice == 3)
			 {
				
				priceOfcoffee = ouncesInput * MACCHIATO;
				salesTax = priceOfcoffee * taxrate;
				total = priceOfcoffee + salesTax;
				cout << "\n";
				cout << name << endl;
				cout << "Order: " << "Macchiato " << ouncesInput << " oz" << endl;
				
			 }
			 else if(choice == 4)
			 {
				priceOfcoffee = ouncesInput * FRAPPUCCINO;
				salesTax = priceOfcoffee * taxrate;
				total = priceOfcoffee + salesTax;
				cout << "\n";
				cout << name << endl;
				cout << "Order: " << "Frappuccino " << ouncesInput << " oz" << endl;
								
			 }
		
			
		 // Calculates the amount of cups needed			
			Venti = ouncesInput/VENTI;
			remainingOunces = ouncesInput % VENTI; 
			
			Grande = remainingOunces / GRANDE; 
			remainingOunces = remainingOunces % GRANDE; 
			
			Regular = remainingOunces / REGULAR;
			remainingOunces = remainingOunces % REGULAR;
			
			if(remainingOunces > 3)
			{
				Regular = remainingOunces / REGULAR + 1;	
				Shot = 0;
			}
			else
			{
				Regular = remainingOunces / REGULAR;
				Shot = remainingOunces / SHOT;
			} 
			
		 // Results	
			
			cout << setprecision(2) << showpoint << fixed;
			cout << "Price of Coffee: $" << priceOfcoffee << endl;
			cout << "Sales Tax: $" << salesTax << endl;
			cout << "Total Amount Owed: $" << total << endl;
			cout << "\n\n";
			
			
			cout << "Cups size \t Number needed" << endl;
			
			cout << "----------  \t --------------" << endl;
			
			cout << "Venti: \t\t\t" << Venti << endl;
			cout << "Grande: \t\t" << Grande << endl;
			cout << "Regular: \t\t" << Regular << endl;
			cout << "Shot: \t\t\t" << Shot << endl;

			// create the ofstrem object
				ofstream output;
				// open or create a file called CoffeeBills.txt
				output.open("CoffeeBills.txt");
				
				// write bill to the file
				output << name << endl;
				output << "Price of Coffee: $" << priceOfcoffee << endl;
				output << "Sales Tax: $" << salesTax << endl;
				output << "Total Amount Owed: $" << total << endl;
				output << newline << endl;
				output << blankline << endl;
				output.close();		
		 }
		
	}
	
	
	return 0;
}
}


