
#include	"RPN.hpp"


#include	<iostream>

int	main(int argc, char *argv[])
{
	if (argc == 2)
	{
		RPN	rpn;

		rpn.calculateRPN(argv[1]);
	}
	else
		std::cout << "Error: no input." << std::endl;
	return 0;
}
