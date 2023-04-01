
#ifndef RPN_HPP
# define RPN_HPP

# include	<stack>
#include	<string>

class RPN{
private:
	std::stack<int>	_num_stack;

	bool	isStrOperator( std::string const &str ) const;
	bool	isStrDigit( std::string const &str ) const;
	int		strToInt( std::string const &str ) const;
	void	clearStack( void );
	int		getTopAndPop( void );

	bool	calculate( std::string const &str );
	int		printResult( void );

public:
	RPN( void );
	RPN( std::string &str );
	RPN( RPN const &origin );
	~RPN( void );

	RPN	&operator=( RPN const &origin );

	int	readRPN( std::string str );
};

# endif
