
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



/* private */

void	BitcoinExchange::readCsvFile( std::string file_name )
{
	std::string	line;
	std::ifstream scv_file(file_name);

	if (scv_file.is_open())
	{
		getline(scv_file, line); // 첫번째 줄 무시
		if (line != "date,exchange_rate")
			std::cout << "Error: is not valid data format csv" << std::endl;
		else
		{
			while (getline(scv_file, line))
			{
				BitcoinExchange::insertCsvData(line); // 여기서 실패하면은 ?
				break;
			}
		}
		scv_file.close();
	}
	else
		std::cout << "Error: could not open csv file" << std::endl;
}

void	BitcoinExchange::insertCsvData( std::string line ) // const
{
	std::string date;
	double		exchange_rate;
	size_t		pos;

	if (line.empty())
		return;
	pos = line.find(",");
	if (pos == std::string::npos || pos + 1 == line.size())
	{
		std::cout << "Error: wrong format of csv database" << std::endl;
		return ; // 잘못된 형식 "Error: wrong format of csv database"
	}

	date = line.substr(0, pos);
	exchange_rate = BitcoinExchange::strToDouble(line.substr(pos + 1, line.length())); //

	if (BitcoinExchange::isValidDate(date))
		this->_csv_data.insert( std::pair<std::string, double>(date, exchange_rate));
	else
		std::cout << "Error: bad input of csv database => " << date << std::endl;
}

double BitcoinExchange::strToDouble( std::string str )
{
	double				value;
	std::stringstream	stream;

	stream.str(str);
	stream >> value;
	return value;
}

int		BitcoinExchange::isValidDate( std::string date ) // YYYY-MM-DD
{
	std::stringstream	stream;
	size_t	pos1, pos2;
	int		month, day;

	pos1 = date.find("-") + 1;
	pos2 = date.find("-", pos1) + 1;
	stream.str(date.substr(pos1, 2));
	stream >> month;
	stream.clear();
	stream.str(date.substr(pos2, 2));
	stream >> day;
	if (0 < month && month <= 12 && 0 < day && day <= 31)
	{
		if ((month == 1|| month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			&& day <= 31)
			return 1;
		else if ((month == 4 || month == 6 || month == 9 || month == 11)
			&& day <= 30)
			return 1;
		else if (month == 2 && day <= 28)
			return 1;
	}
	return 0;
}

void	BitcoinExchange::showExchangeRate( std::string line )
{
	std::string date;
	double		value, multipled;
	size_t		pos;
	
	pos = line.find("|");
	if (pos == std::string::npos)
		return ;
	date = line.substr(0, pos - 1);
	value = BitcoinExchange::strToDouble(line.substr(pos + 2, line.length()));

	if (!BitcoinExchange::isValidDate(date))
		std::cout << "Error: bad input => " << date << std::endl;
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

double	BitcoinExchange::multipleWithExchangeRate( std::string date, double value )
{
	typedef std::map< std::string, double >::iterator iter; // typedef typename
	std::pair< iter, iter > pair;
	double					rtn;

	pair = this->_csv_data.equal_range(date);
	if (pair.first == pair.second)
		pair.first--; // 만약 맨 앞의 값일 경우에는 어떻게 처리 ? 0으로 처리 해야할듯 
	rtn = pair.first->second * value; //?
	return rtn;
}



// for

/* public func */

void	BitcoinExchange::evaluateDatabaseFile( std::string file_name)  // readDatafile
{
	std::string	line;
	std::ifstream database;

	if (this->_csv_data.empty())
	{
		std::cout << "Error: no csv data" << std::endl;
		return ;
	}
	database.open(file_name);
	if (database.is_open()){

		getline(database, line); // 첫번째 줄 무시 data | value 
		if (line != "date | value")
			std::cout << "Error: is not valid data format" << std::endl;
		else
		{
			while (getline(database, line))
				BitcoinExchange::showExchangeRate(line);
		}
		database.close();
	}
	else
		std::cout << "Error: could not open file" << std::endl; // no data.scv file error or exception
}


