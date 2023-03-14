
#include	"BitcoinExchange.hpp"

#include	<fstream>
#include	<iostream>

BitcoinExchange::BitcoinExchange( void )
{
	BitcoinExchange::readCsvFile("data.csv");
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &origin )
{
	this->_csv_data = origin._csv_data;
//
}

BitcoinExchange::~BitcoinExchange( void )
{
	;
}

/*
BitcoinExchange	&BitcoinExchange::operator=( BitcoinExchange const &origin )
{
	;
	return *this;
}*/


/* private */

void	BitcoinExchange::readCsvFile( std::string file_name )
{
	// open file fd
	std::string	line;
	std::ifstream scv_file(file_name);


	if (scv_file.is_open()){

	getline(scv_file, line);


		while (getline(scv_file, line))
		{
		//	std::cout << line << std::endl;
			BitcoinExchange::insertCsvData(line);
			break;
		}
	}
	else
		; // no data.scv file error or exception
	scv_file.close();

	// string
	// 한줄씩 읽어서 insert 하기
	// close file fd
}

void	BitcoinExchange::insertCsvData( std::string line )
{
	std::string date;
//	float		value;

	size_t	pos = line.find(",");
	std::cout << "pos " << pos << std::endl;
	std::cout << line.substr(0, pos) << std::endl;
	std::cout << line.substr(pos + 1, line.length()) << std::endl;
	//date; // =
	// substr()
	// find, rfind

//	value = BitcoinExchange::strToFloat(line); //
//	this->_csv_data.insert( std::pair<std::string, float>(date, value) );
}

float BitcoinExchange::strToFloat( std::string str )
{
	float	value;
	std::stringstream	stream;

	stream.str(str);
	stream >> value;

	return value;
}





/* public func */



