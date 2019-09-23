//Name : Alphonsa George
//Assignment: PROG1003 HW7- Sales

#include <fstream>
#include <iomanip>
#include <iostream>
#include <locale>
#include <string>

#include "sales.h"

int main()
{
	double sales[12];

	nwacc::load_array("monthly_sales.txt", sales);
	
	std::cout << "COMMAND MENU \n"
		<< "view -View sales for specified month\n"
		<< "edit -Edit sales for specified month\n"
		<< "totals - View sales summary for year\n"
		<< "quarter - View sales summary for each quarter\n"
		<< "exit - Exit program\n";

	std::string option;
	option = nwacc::get_option();

		std::cout.imbue(std::locale("ENGLISH_US"));
		std::cout << std::fixed << std::showpoint << std::setprecision(2);

		while (option != "exit")
		{
			if (option == "view")
			{
				nwacc::view_sales(sales, "Three-letter month: ");
			}
			else if (option == "edit")
			{
				nwacc::edit_sales(sales, "Three-letter month: ");
			}
			else if (option == "totals")
			{
				nwacc::display_yearly_summary(sales, 12);
			}
			else 
			{
				nwacc::display_quarterly_summary(sales);
			}

			option=nwacc::get_option();
		}
		std::cout << "Bye !" << std::endl;

	return 0;
}

