#include "Status.hpp"
#include <iostream>
#include <string>
#include <vector>

int main (int ac, char **av)
{
	if (ac != 2)
		std::cerr << "argument error" << std::endl;
	Status	status;

	status.print();
	status.input_arg(av[1]);
	status.print();
}