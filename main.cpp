#include "rubic.hpp"
#include "Search.hpp"
// int main (int ac, char **av)
// {
	
// 	if (ac != 2)
// 		std::cerr << "argument error" << std::endl;
// 	Cp	co;

// 	// co.IndexToCp(0);
// 	// co.print();
// 	// co.IndexToCp(24);
// 	// co.print();
// 	// co.IndexToCp(1);
// 	// co.print();

// 	(void)av;
// }

int main (int ac, char **av)
{
	
	if (ac != 2)
		std::cerr << "argument error" << std::endl;
	Search	table(av[1]);

	(void)av;
}

// int main (int ac, char **av)
// {
	
// 	if (ac != 2)
// 		std::cerr << "argument error" << std::endl;
// 	Ep_E	c;
// 	c.L();
// 	c.D2();
// 	c.R();
// 	c.U2();
// 	c.L();
// 	c.F2();
// 	c.U2();
// 	c.L();
// 	c.F2();
// 	c.R2();
// 	c.B2();
// 	c.R();
// 	c.U3();
// 	c.R3();
// 	c.U2();
// 	c.F2();
// 	c.R3();
// 	c.D();
// 	c.B3();
// 	c.F2();
// 	c.print();
// 	(void)av;
// }