
#include	"RPN.hpp"

# include	<stack>

#include	<sstream>
#include	<iostream>


RPN::RPN( void )
{
	;
}

RPN::RPN( std::string &str )
{
	RPN::calculateRPN( str );
}

RPN::RPN( RPN const &origin )
{
	*this = origin;
}

RPN::~RPN( void )
{
	;
}

RPN &RPN::operator=( RPN const &origin )
{
	this->_num_stack = origin._num_stack;
	return *this;
}


/* ====== RPN ====== */

int	RPN::calculateRPN( std::string str )
{
	size_t				pos = 0;
	std::string			token;
	int					result;

	str = str.substr(str.find_first_not_of(" "));
	while (pos != std::string::npos)
	{
		pos = str.find_first_not_of("0123456789+-/*");
		token = str.substr(0, pos);
		str = str.substr(pos + 1);

		if (RPN::isStrDigit(token))
			_num_stack.push(RPN::strToInt(token));
		else if (RPN::isStrOperator(token))
		{
			RPN::calculate(token);
		}
		else
		{
			// clear stack
			std::cout << "Error" << std::endl;
			return 0;
		}
	}

	// 숫자가 남았을 경우 error
	if (this->_num_stack.size() != 1)
	{
	//	clear stack
		std::cout << "Error" << std::endl;
		return 0;
	}

	result = RPN::getTopAndPop();

	std::cout << "result : " << result << std::endl;

	return result;
}

int	RPN::calculate( std::string const &str ) //bool
{
	int	num1, num2;

	if (this->_num_stack.size() < 2)
		return 0; // error; false

	num1 = RPN::getTopAndPop();
	num2 = RPN::getTopAndPop();
	if (str.compare("+") == 0)
		this->_num_stack.push(num2 + num1);
	else if (str.compare("-") == 0)
		this->_num_stack.push(num2 - num1);
	else if (str.compare("/") == 0)
		this->_num_stack.push(num2 / num1);
	else if (str.compare("*") == 0)
		this->_num_stack.push(num2 * num1);

	return this->_num_stack.top(); // true;
}


/* ====== UTILS ======*/

int		RPN::getTopAndPop( void )
{
	int num;
	
	num = this->_num_stack.top();
	this->_num_stack.pop();
	return num;
}

bool	RPN::isStrDigit( std::string const &str ) const
{
	// str 이 비어있거나 0123457
	if (str.empty() || str.find_first_not_of("0123456789") != std::string::npos)
		return false;
	return true;
}


bool	RPN::isStrOperator( std::string const &str ) const
{
	if (str.length() != 1 || str.find_first_not_of("+-/*") != std::string::npos)
		return false;
	return true;
}

int RPN::strToInt( std::string const &str ) const
{
	int					value;
	std::stringstream	stream;

	stream.str(str);
	stream >> value;
	return value;
}

