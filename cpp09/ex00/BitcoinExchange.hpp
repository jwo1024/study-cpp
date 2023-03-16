
#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include	<map> 

// template<typename Key = std::string, typename Value = double>
class BitcoinExchange{
private:
	std::map< std::string, double >	_csv_data; // template ?

	void	readCsvFile( std::string file_name );
	bool	insertCsvData( std::string line );
	void	showExchangeRate( std::string line ); // & 
	double	multipleWithExchangeRate( std::string date, double value ) ;

	double	strToDouble( std::string str ) const;
	int		strToInt( std::string str ) const;
	bool	isValidDate( std::string date ) const;
	bool	isStrDigit( std::string const &str ) const;
	bool	isStrDateFormat( std::string const &str ) const;
	bool	isStrDouble( std::string const &str ) const;

public:
	BitcoinExchange( void );
	BitcoinExchange( BitcoinExchange const &origin );
	~BitcoinExchange( void );

	BitcoinExchange &operator=( BitcoinExchange const &origin );

	void	readInputDatabaseFile( std::string string );
};


#endif
