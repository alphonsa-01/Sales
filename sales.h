//Name : Alphonsa George
//Assignment: PROG1003 HW7- Sales

#ifndef SALES_H_
#define SALES_H_

#include<fstream>
#include <iomanip>
#include <locale>
#include<iostream>
#include<string>

/**
 * \brief The standard nwacc namespace.
 *
 * The namespace used for all nwacc application code.
 */
namespace nwacc
{
	/*!
	\brief The character literal for new line.
	*/
	const char k_newline = '\n';

	/*!
	\brief The character literal for giving tab in between words.
	*/
	const char k_tab_line = '\t';

	/*!
	This represents the number of months in a quarter which is equal to 3.
	*/
	const int k_number_of_months_in_quarter = 3;

	/*!
	\brief This loads the array with the values from the file.
	This loads the array with the double values from the passed to it. 

	\param file_name file from which the data being read.
	\param sales[] array which needs to be loaded.
	*/
	void load_array(const std::string& file_name, double sales[]);

	/*!
	\brief Returns the valid option selected by the user.
	Checks the option entered by the user is valid or not and gets the right option.

	\return returns the valid option.
	*/
	std::string get_option();

	/*!
	\brief Gets the valid entry for the month.
	checks the option entered by the user for the month and validates it

	\param prompt prompts the user for the input

	\return returns the valid entry for month.
	*/
	std::string get_month(std::string prompt);

	/*!
	\brief displays the sales amount for the month selected.

	\param sales[] array which holds the sales values for 12 months.
	\param prompt prompts the user for the month

	*/
	void view_sales(const double sales[], std::string prompt);

	/*!
	\brief Calculates the total of sales for the year
	finds the sum of all sales values in the array

	\param sales[] array which holds the sales values for 12 months
	\param size size of the array.
	\return returns the total of sales for 12 months.
	*/
	double total(const double sales[], int size);

	/*!
	\brief Calculates the monthly average
	calculates the average of sales from the array of sales values for an year.

	\param sales[] array which holds the sales values for 12 months
	\param size size of the array.

	\return returns the monthly average 
	*/
	double average(const double sales[], int size);

	/*!
	\brief displays the summary of yearly sales
	displays total and average of 12 months sales

	\param sales[] array which holds the sales values for 12 months
	\param size size of the array.
	*/
	void display_yearly_summary(const double sales[], int size);

	/*!
	\brief Calculates the total of sales for a quarter(3 months)
	finds the sum sales values for certain quarter

	\param sales[] array which holds the sales values for 12 months
	\param start_of_quarter index number of the start of the quarter we choose
	\param end_of_quarter index number for the end of the quarter we choose

	\return returns the total of sales for specific 3 months.
	*/
	double total_quarter(const double sales[], int start_of_quarter, int end_of_quarter);

	/*!
	\brief calculates the quarterly average
	calculates the average of sales from the array of sales values for a quarter.

	\param start_of_quarter index number of the start of the quarter we choose
	\param end_of_quarter index number for the end of the quarter we choose

	\return returns the quarterly average.
	*/
	double average_quarter(const double sales[], int start_of_quarter, int end_of_quarter);

	/*!
	\brief displays the summary of quarterly sales
	displays total and average for all 4 quarters

	\param sales[] array which holds the sales values for 12 months

	*/
	void display_quarterly_summary(const double sales[]);

	/*!
	\brief Gets the valid sales amount from the user
	checks the input entered by the user for sales amount and validates it

	\param prompt prompts the user for the input

	\return returns the valid entry for sales amount.
	
	*/
	double get_sales_amount(std::string prompt);

	/*!
	\brief Displays the edited sales data for the specific month
	Changes the sales amount for the month chosen by the
	user for the sales amount eneterd by the user and writes all the values to a new file

	\param sales[] array which holds the sales values for 12 months
	\param prompt prompts the user for the inputs
	*/
	void edit_sales(const double sales[], std::string prompt);

}
#endif