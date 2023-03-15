

#include	"BitcoinExchange.hpp"

#include	<iostream>

int	main(int argc, char *argv[])
{
	//BitcoinExchange	b;
	if (argc == 2)
	{
		BitcoinExchange	b;

		b.evaluateDatabaseFile(argv[1]);

	}
	else
		std::cout << "Error: could not oopen file." << std::endl;


	return 0;
}
