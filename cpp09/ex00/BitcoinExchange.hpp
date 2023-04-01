
#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include	<map> 
# include	<string>

class BitcoinExchange{
private:
	std::map< std::string, double >	_csv_data;

	bool	insertCsvData( std::string line );
	
	void	showExchangeRate(  std::string date, double value  );
	double	multipleWithExchangeRate( std::string date, double value );
	void	readDatabaseLine( std::string line );


	double	strToDouble( std::string str ) const;
	int		strToInt( std::string str ) const;
	bool	isValidDate( std::string date ) const;
	bool	isStrDateFormat( std::string const &str ) const;

public:
	BitcoinExchange( void );
	BitcoinExchange( std::string &csv_file );
	BitcoinExchange( BitcoinExchange const &origin );
	~BitcoinExchange( void );

	BitcoinExchange &operator=( BitcoinExchange const &origin );

	void	readCsvFile( std::string file_name );
	void	readInputDatabaseFile( std::string string );
};

#endif
