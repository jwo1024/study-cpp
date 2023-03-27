
#include	"RPN.hpp"

#include	<iostream>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		RPN	rpn;
		rpn.readRPN(argv[1]);
	}
	else
		std::cout << "Error: worng input argc." << std::endl;
	return 0;
}
