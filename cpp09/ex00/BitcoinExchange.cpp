
#include	"BitcoinExchange.hpp"

#include	<fstream>
#include	<iostream>

BitcoinExchange::BitcoinExchange( void )
{
	BitcoinExchange::readCsvFile("data.csv");
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

bool	BitcoinExchange::insertCsvData( std::string line )
{
	std::string	date;
	double		exchange_rate;
	size_t		pos;

	if (line.empty())
		return true;
	pos = line.find(",");
	if (pos != std::string::npos || pos + 1 != line.size())
	{
		date = line.substr(0, pos);
		exchange_rate = BitcoinExchange::strToDouble(line.substr(pos + 1, line.length()));
		if (BitcoinExchange::isValidDate(date))
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

void	BitcoinExchange::readInputDatabaseFile( std::string file_name )  // readDatafile
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
				BitcoinExchange::showExchangeRate(line);
		}
		else
			std::cout << "Error: is not valid data format" << std::endl;
		database.close();
	}
	else
		std::cout << "Error: could not open file" << std::endl; // no data.scv file error or exception
}

void	BitcoinExchange::showExchangeRate( std::string line )
{
	std::string date, str_value;
	double		value, multipled;
	size_t		pos;
	
	pos = line.find("|");
	if (pos == std::string::npos)
		return ;
	date = line.substr(0, pos - 1);
	value = BitcoinExchange::strToDouble(line.substr(pos + 2, line.length()));

	if (!BitcoinExchange::isValidDate(date))
		std::cout << "Error: bad input => " << date << std::endl;
	else if (value == 0 && !BitcoinExchange::isStrDouble(line.substr(pos + 2, line.length())))
		std::cout << "Error: bad input value => " << line << std::endl;
	else if (value < 0)
		std::cout << "Error: not a positive number." << std::endl;
	else if (value > 1000)
		std::cout << "Error: too large a number." << std::endl;
	else
	{
		multipled = BitcoinExchange::multipleWithExchangeRate(date, value);
		std::cout << date << " => " << value << " = " << multipled <<std::endl;
	}
}

double	BitcoinExchange::multipleWithExchangeRate( std::string date, double value )  // const? 
{
	typedef std::map< std::string, double >::iterator iter; // typedef typename
	std::pair< iter, iter > pair;
	double					rtn;

	pair = this->_csv_data.equal_range(date);
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

	stream.str(str);
	stream >> value;
	return value;
}

int BitcoinExchange::strToInt( std::string str ) const
{
	int					value;
	std::stringstream	stream;

	stream.str(str);
	stream >> value;
	return value;
}


bool	BitcoinExchange::isValidDate( std::string date ) const // YYYY-MM-DD
{
	size_t	pos1, pos2;
	int		month, day;

	if (!BitcoinExchange::isStrDate(date))
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

bool	BitcoinExchange::isStrDigit( std::string const &str ) const
{
	if (str.empty() && str.find_first_not_of("0123456789") == std::string::npos)
		return false;
	return true;
}

bool	BitcoinExchange::isStrDouble( std::string const &str ) const
{
	size_t	pos;

	pos = str.find_first_not_of("0123456789");
	if (pos != std::string::npos && str[pos] != '.')
		return false;
	pos = str.find_first_not_of("0123456789", pos + 1);
	if (pos != std::string::npos)
		return false;
	return true;
}

bool	BitcoinExchange::isStrDate( std::string const &str ) const // YYYY-MM-DD
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
