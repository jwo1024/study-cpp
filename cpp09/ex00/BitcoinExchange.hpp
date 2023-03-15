
#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include	<map> // >?
# include	<string> // ?

# include	<sstream>
# include	<time.h>
// time_t

// <typename key = std::string, typename value = double >
class BitcoinExchange{
private:
	std::map< std::string, double >	_csv_data; // template ?

	void	readCsvFile( std::string file_name );
	void	insertCsvData( std::string line );

	double	strToDouble( std::string str );
	int		isValidDate( std::string date );


	void	showExchangeRate( std::string line );
	double	multipleWithExchangeRate( std::string date, double value );

public:
	BitcoinExchange( void );
	BitcoinExchange( size_t n );
	BitcoinExchange( BitcoinExchange const &origin );
	~BitcoinExchange( void );

	BitcoinExchange &operator=( BitcoinExchange const &origin );


	
	void	evaluateDatabaseFile( std::string string);


/*
private:
	std::vector<int> _vect;
	size_t _max;
public:
	Span( void );
	Span( size_t n );
	Span( Span const &origin );
	~Span( void );

	Span &operator=( Span const &origin );

	void	addNumber( int value );

	template <typename C>
	void	addRange( typename C::iterator begin, typename C::iterator end ){
		if (this->_max - this->_vect.size() < static_cast<unsigned long>(std::distance(begin, end)))
			throw Span::CanNotAddNumbersException();
		this->_vect.insert(this->_vect.end(), begin, end);
	};

	int		shortestSpan( void ); 
	int		longestSpan( void ) const;

	void	printAll( void ) const;

	class CanNotAddNumbersException : public std::exception{
		public:
			const char *what() const throw();
	};
	class LackOfNumbersException : public std::exception{
		public:
			const char *what() const throw();
	};
*/

};


#endif
