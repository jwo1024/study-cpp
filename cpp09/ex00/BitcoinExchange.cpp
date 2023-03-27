
#include	"BitcoinExchange.hpp"

#include	<fstream>
#include	<iostream>
#include	<sstream>
#include	<string>

BitcoinExchange::BitcoinExchange( void )
{
	;
}

BitcoinExchange::BitcoinExchange( std::string &csv_file )
{
	BitcoinExchange::readCsvFile(csv_file);
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &origin )
{
	*this = origin;
}

BitcoinExchange::~BitcoinExchange( void )
{
	;
}

BitcoinExchange	&BitcoinExchange::operator=( BitcoinExchange const &origin )
{
	this->_csv_data = origin._csv_data;
	return *this;
}


/* ===== READ CSV FILE ===== */

void	BitcoinExchange::readCsvFile( std::string file_name )
{
	std::string	line;
	std::ifstream scv_file;

	if(!this->_csv_data.empty())
		this->_csv_data.clear();
	scv_file.open(file_name.c_str());
	if (scv_file.is_open())
	{
		getline(scv_file, line);
		if (line == "date,exchange_rate") // space
		{
			while (getline(scv_file, line))
			{
				if (!BitcoinExchange::insertCsvData(line))
				{
					this->_csv_data.clear();
					break ;
				}
			}
		}
		else
			std::cout << "Error: is not valid data format csv" << std::endl;
		scv_file.close();
	}
	else
		std::cout << "Error: could not open csv file" << std::endl;
}

bool	BitcoinExchange::insertCsvData( std::string line ) // insertCsvFileLine
{
	std::string	date, str_exchange_rate;
	double		exchange_rate;
	size_t		pos;

	if (line.empty())
		return true;
	pos = line.find(",");
	if (pos != std::string::npos || pos + 1 != line.size())
	{
		date = line.substr(0, pos);
		str_exchange_rate = line.substr(pos + 1, line.length());
		exchange_rate = BitcoinExchange::strToDouble(str_exchange_rate);
		if (BitcoinExchange::isValidDate(date) && (exchange_rate != 0 || \
			(exchange_rate == 0 && str_exchange_rate.find_first_not_of("0.") == std::string::npos)))
		{
			this->_csv_data.insert( std::pair<std::string, double>(date, exchange_rate));
			return true;
		}
		else
			std::cout << "Error: bad input of csv database => " << line << std::endl;
	}
	else
		std::cout << "Error: wrong format of csv database" << std::endl;
	return false;
}


/* ===== READ INPUT DATA BASE ===== */

void	BitcoinExchange::readInputDatabaseFile( std::string file_name ) // readDatabaseFile
{
	std::string	line;
	std::ifstream database;

	if (this->_csv_data.empty())
	{
		std::cout << "Error: no csv data" << std::endl;
		return ;
	}
	database.open(file_name.c_str());
	if (database.is_open())
	{
		getline(database, line);
		if (line == "date | value")
		{
			while (getline(database, line))
				BitcoinExchange::readDatabaseLine(line);
		}
		else
			std::cout << "Error: is not valid data format" << std::endl;
		database.close();
	}
	else
		std::cout << "Error: could not open file" << std::endl;
}

void	BitcoinExchange::readDatabaseLine( std::string line )
{
	size_t		pos;
	std::string	date, value_str;
	double		value;

	pos = line.find(" | ");
	date = line.substr(0, pos);
	if (line.empty())
		;
	else if (!BitcoinExchange::isValidDate(date))
		std::cout << "Error: bad input => " << date << std::endl;
	else if (line.length() < 14)
		std::cout << "Error: bad input => " << line << std::endl;
	else
	{
		value_str = line.substr(pos + 3, line.length());
		value = BitcoinExchange::strToDouble(value_str);
	
		if (value < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (value > 1000)
			std::cout << "Error: too large a number." << std::endl;
		else if (value == 0 && value_str.find_first_not_of("0.") != std::string::npos)
			std::cout << "Error: bad input : value => " << value_str << std::endl;
		else
			BitcoinExchange::showExchangeRate(date, value);
	}
}

void	BitcoinExchange::showExchangeRate( std::string date, double value ) // show calculate
{
	double	multipled;

	multipled = BitcoinExchange::multipleWithExchangeRate(date, value);
	std::cout << date << " => " << value << " = " << multipled << std::endl;
}

double	BitcoinExchange::multipleWithExchangeRate( std::string date, double value )
{
	typedef std::map< std::string, double >::iterator iter;
	std::pair< iter, iter > pair;
	double					rtn;

	pair = this->_csv_data.equal_range(date); // not const ..
	if (pair.first == this->_csv_data.begin() && pair.first == pair.second)
		return 0;
	if (pair.first == pair.second)
		pair.first--;
	rtn = pair.first->second * value;
	return rtn;
}



/* ===== UTILS ===== */

double BitcoinExchange::strToDouble( std::string str ) const
{
	double				value;
	std::stringstream	stream;

	if (str.empty())
		return 0;
	stream.str(str);
	stream >> value;
	return value;
}

int BitcoinExchange::strToInt( std::string str ) const
{
	int					value;
	std::stringstream	stream;

	if (str.empty())
		return 0;
	stream.str(str);
	stream >> value;
	return value;
}

bool	BitcoinExchange::isValidDate( std::string date ) const // YYYY-MM-DD
{
	size_t	pos1, pos2;
	int		month, day;

	if (date.empty() || !BitcoinExchange::isStrDateFormat(date))
		return false;
	pos1 = date.find("-") + 1;
	pos2 = date.find("-", pos1) + 1;
	month = BitcoinExchange::strToInt(date.substr(pos1, 2));
	day = BitcoinExchange::strToInt(date.substr(pos2, 2));
	if ((month == 1|| month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		&& day <= 31)
		return true;
	else if ((month == 4 || month == 6 || month == 9 || month == 11)
		&& day <= 30)
		return true;
	else if (month == 2 && day <= 28)
		return true;
	return false;
}

// YYYY-MM-DD
bool	BitcoinExchange::isStrDateFormat( std::string const &str ) const
{
	size_t	pos;


	pos = str.find_first_not_of("0123456789");
	if (pos == std::string::npos || str[pos] != '-' || pos != 4)
		return false;
	pos = str.find_first_not_of("0123456789", pos + 1);
	if (pos == std::string::npos || str[pos] != '-' || pos != 7)
		return false;
	pos = str.find_first_not_of("0123456789", pos + 1);
	if (pos != std::string::npos || str.length() != 10)
		return false;
	return true;
}
