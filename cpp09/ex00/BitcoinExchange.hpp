
#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include	<map> // >?
# include	<string> // ?

# include	<sstream>
# include	<time.h>
// time_t

class BitcoinExchange{
private:
	std::map< std::string, float >	_csv_data; // template ?

	void	readCsvFile( std::string file_name );
	void	insertCsvData( std::string line );
	float	strToFloat( std::string str );


public:
	BitcoinExchange( void );
	BitcoinExchange( size_t n );
	BitcoinExchange( BitcoinExchange const &origin );
	~BitcoinExchange( void );

	BitcoinExchange &operator=( BitcoinExchange const &origin );



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
