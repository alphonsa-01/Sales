//Name : Alphonsa George
//Assignment: PROG1003 HW7- Sales

#include "sales.h"

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
	\brief This loads the array with the values from the file.
	This loads the array with the double values from the passed to it.

	\param file_name file from which the data being read.
	\param sales[] array which needs to be loaded.
	*/
	void load_array(const std::string& file_name,double sales[])
	{
		std::ifstream fin;
		
		fin.open(file_name);
		if (fin)
		{
			while (!fin.eof())
			{
				std::string months;
				fin >> months;
				fin >> sales[3];
				fin >> months;
				fin >> sales[7];
				fin >> months;
				fin >> sales[11];
				fin >> months;
				fin >> sales[1];
				fin >> months;
				fin >> sales[0];
				fin >> months;
				fin >> sales[6];
				fin >> months;
				fin >> sales[5];
				fin >> months;
				fin >> sales[2];
				fin >> months;
				fin >> sales[4];
				fin >> months;
				fin >> sales[10];
				fin >> months;
				fin >> sales[9];
				fin >> months;
				fin >> sales[8];
			}
			fin.close();
		}
		else
		{
			std::cout << "File failed to open !" << std::endl;
		}
	}

	/*!
	\brief Returns the valid option selected by the user.
	Checks the option entered by the user is valid or not and gets the right option.

	\return returns the valid option.
	*/
	std::string get_option()
	{
		std::cout << "Command:";
		std::string option;
		std::cin >> option;

		while (std::cin.fail() || option != "view" && option != "edit" && option != "totals" &&
			option != "quarter" && option != "exit")
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), k_newline);
			std::cout << "Invalid option, try again!: ";
			std::cin >> option;
		}
		return option;
	}

	/*!
	\brief Gets the valid entry for the month.
	checks the option entered by the user for the month and validates it

	\param prompt prompts the user for the input

	\return returns the valid entry for month.
	*/
	std::string get_month(std::string prompt)
	{
		std::cout << prompt;
		std::string month;
		std::cin >> month;

		while (std::cin.fail() || month != "jan" && month != "feb" && month != "mar" && month != "apr" && month != "may" &&
			month != "jun" && month != "jul" && month != "aug" && month != "sep" && month != "oct" && month != "nov" && month != "dec")
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), k_newline);
			std::cout << "Invalid three-letter month, try again!: ";
			std::cin >> month;
		}

		return month;
	}

	/*!
	\brief displays the sales amount for the month selected.

	\param sales[] array which holds the sales value.
	\param prompt prompts the user for the month

	*/
	void view_sales(const double sales[], std::string prompt)
	{
		std::string month = get_month(prompt);

		if (month =="jan")
		{
			std::cout << "Sales amount for Jan is " << sales[0] << std::endl;
		}
		else if (month == "feb")
		{
			std::cout << "Sales amount for Feb is " << sales[1] << std::endl;
		}
		else if (month == "mar")
		{
			std::cout << "Sales amount for Mar is " << sales[2] << std::endl;
		}
		else if (month == "apr")
		{
			std::cout << "Sales amount for Apr is " << sales[3] << std::endl;
		}
		else if (month == "may")
		{
			std::cout << "Sales amount for May is " << sales[4] << std::endl;
		}
		else if (month == "jun")
		{
			std::cout << "Sales amount for Jun is " << sales[5] << std::endl;
		}
		else if (month == "jul")
		{
			std::cout << "Sales amount for Jul is " << sales[6] << std::endl;
		}
		else if (month == "aug")
		{
			std::cout << "Sales amount for Aug is " << sales[7] << std::endl;
		}
		else if (month == "sep")
		{
			std::cout << "Sales amount for Sep is " << sales[8] << std::endl;
		}
		else if (month == "oct")
		{
			std::cout << "Sales amount for Oct is " << sales[9] << std::endl;
		}
		else if (month == "nov")
		{
			std::cout << "Sales amount for Nov is " << sales[10] << std::endl;
		}
		else
		{
			std::cout << "Sales amount for Dec is " << sales[11] << std::endl;
		}
	}

	/*!
	\brief Calculates the total of sales for the year
	finds the sum of all sales values in the array

	\param sales[] array which holds the sales values for 12 months
	\param size size of the array.
	\return returns the total of sales for 12 months.
	*/
	double total(const double sales[], int size)
	{
		auto sum = 0.0;

		for (auto index = 0; index < size; index++)
		{
			sum += sales[index];
		}

		return sum;
	}

	/*!
	\brief Calculates the monthly average
	calculates the average of sales from the array of sales values for an year.

	\param sales[] array which holds the sales values for 12 months
	\param size size of the array.

	\return returns the monthly average
	*/
	double average(const double sales[], int size)
	{
		return total(sales, size) / static_cast<double>(size);
	}

	/*!
	\brief displays the summary of yearly sales
	displays total and average of 12 months sales

	\param sales[] array which holds the sales values for 12 months
	\param size size of the array.
	*/
	void display_yearly_summary(const double sales[], int size)
	{
		std::cout << "Yearly total:" << k_tab_line<<k_tab_line << total(sales, size) << std::endl;
		std::cout << "Monthly average:"<< k_tab_line<<average(sales, size) << std::endl;
	}

	/*!
	\brief Calculates the total of sales for a quarter(3 months)
	finds the sum sales values for certain quarter

	\param sales[] array which holds the sales values for 12 months
	\param start_of_quarter index number of the start of the quarter we choose
	\param end_of_quarter index number for the end of the quarter we choose

	\return returns the total of sales for specific 3 months.
	*/
	double total_quarter(const double sales[], int start_of_quarter, int end_of_quarter)
	{
		auto sum = 0.0;

		for (auto index = start_of_quarter; index <= end_of_quarter; index++)
		{
			sum += sales[index];
		}

		return sum;
	}

	/*!
	\brief calculates the quarterly average
	calculates the average of sales from the array of sales values for a quarter.

	\param start_of_quarter index number of the start of the quarter we choose
	\param end_of_quarter index number for the end of the quarter we choose

	\return returns the quarterly average.
	*/
	double average_quarter(const double sales[], int start_of_quarter, int end_of_quarter)
	{
		return total_quarter(sales, start_of_quarter, end_of_quarter) / static_cast<double>(k_number_of_months_in_quarter);

	}

	/*!
	\brief displays the summary of quarterly sales
	displays total and average for all 4 quarters

	\param sales[] array which holds the sales values for 12 months

	*/
	void display_quarterly_summary(const double sales[])
	{
		std::cout << "Total for First quarter:" << k_tab_line << total_quarter(sales, 0, 2) << std::endl;
		std::cout << "Average for first quarter:" << k_tab_line << average_quarter(sales, 0, 2) << std::endl;

		std::cout << "Total for Second quarter:" << k_tab_line << total_quarter(sales, 3, 5) << std::endl;
		std::cout << "Average for Second quarter:" << k_tab_line << average_quarter(sales, 3, 5) << std::endl;

		std::cout << "Total for Third quarter:" << k_tab_line << total_quarter(sales, 6, 8) << std::endl;
		std::cout << "Average for Third quarter:" << k_tab_line << average_quarter(sales, 6, 8) << std::endl;

		std::cout << "Total for Forth quarter:" << k_tab_line << total_quarter(sales, 9, 11) << std::endl;
		std::cout << "Average for Forth quarter:" << k_tab_line << average_quarter(sales, 9, 11) << std::endl;

	}

	/*!
	\brief Gets the valid sales amount from the user
	checks the input entered by the user for sales amount and validates it

	\param prompt prompts the user for the input

	\return returns the valid entry for sales amount.

	*/
	double get_sales_amount(std::string prompt)
	{
		std::cout << prompt;
		auto amount = 0.0;
		std::cin >> amount;

		while (std::cin.fail() || amount <= 0)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), k_newline);
			std::cout << "Invalid sales amount value, try again!: ";
			std::cin >> amount;
		}

		return amount;
	}

	/*!
	\brief Displays the edited sales data for the specific month
	Changes the sales amount for the month chosen by the
	user for the sales amount eneterd by the user and writes all the values to a new file

	\param sales[] array which holds the sales values for 12 months
	\param prompt prompts the user for the inputs
	*/
	void edit_sales(const double sales[], std::string prompt)
	{
		std::string month = get_month(prompt);

		auto amount = get_sales_amount("Sales Amount: ");

		std::ofstream fout;
		fout.open("monthly_sales_new.txt");

		if (month == "jan")
		{
			fout.imbue(std::locale("ENGLISH_US"));
			fout<< std::fixed << std::showpoint << std::setprecision(2);
			std::cout << "Sales amount for Jan is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << amount << std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else if (month == "feb")
		{
			std::cout << "Sales amount for Feb is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0] << std::endl;
			fout << "Feb" <<  k_tab_line << amount << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;

		}
		else if (month == "mar")
		{
			std::cout << "Sales amount for Mar is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0] << std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << amount << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else if (month == "apr")
		{
			std::cout << "Sales amount for Apr is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0] << std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << amount << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else if (month == "may")
		{
			std::cout << "Sales amount for May is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0] << std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << amount << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else if (month == "jun")
		{
			std::cout << "Sales amount for Jun is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0]<< std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << amount << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else if (month == "jul")
		{
			std::cout << "Sales amount for Jul is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0] << std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << amount << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else if (month == "aug")
		{
			std::cout << "Sales amount for Aug is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0]<< std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << amount << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else if (month == "sep")
		{
			std::cout << "Sales amount for Sep is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0] << std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << amount << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else if (month == "oct")
		{
			std::cout << "Sales amount for Oct is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0] << std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << amount << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else if (month == "nov")
		{
			std::cout << "Sales amount for Nov is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0]<< std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << amount << std::endl;
			fout << "Dec" <<  k_tab_line << sales[11] << std::endl;
		}
		else
		{
			std::cout << "Sales amount for Dec is " << amount << std::endl;
			fout << "Jan" <<  k_tab_line << sales[0]<< std::endl;
			fout << "Feb" <<  k_tab_line << sales[1] << std::endl;
			fout << "Mar" <<  k_tab_line << sales[2] << std::endl;
			fout << "Apr" <<  k_tab_line << sales[3] << std::endl;
			fout << "May" <<  k_tab_line << sales[4] << std::endl;
			fout << "Jun" <<  k_tab_line << sales[5] << std::endl;
			fout << "Jul" <<  k_tab_line << sales[6] << std::endl;
			fout << "Aug" <<  k_tab_line << sales[7] << std::endl;
			fout << "Sep" <<  k_tab_line << sales[8] << std::endl;
			fout << "Oct" <<  k_tab_line << sales[9] << std::endl;
			fout << "Nov" <<  k_tab_line << sales[10] << std::endl;
			fout << "Dec" <<  k_tab_line << amount << std::endl;
		}

		fout.close();
	}
}