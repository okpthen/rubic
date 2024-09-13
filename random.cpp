#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>

int main (int ac, char **av){
	int max;
	if (ac == 2)
		max = std::atoi(av[1]);
	else
		max = 20;
	std::string	res;
	std::srand(std::time(0));
    int result;
	for (int i = 0; i < max; i ++){
		result = std::rand() % 18;
		if (result == 0)
			res += "R";
		else if (result == 1)
			res += "R'";
		else if (result == 2)
			res += "R2";
		else if (result == 3)
			res += "D";
		else if (result == 4)
			res += "D'";
		else if (result == 5)
			res += "D2";
		else if (result == 6)
			res += "U";
		else if (result == 7)
			res += "U'";
		else if (result == 8)
			res += "U2";
		else if (result == 9)
			res += "L";
		else if (result == 10)
			res += "L'";
		else if (result == 11)
			res += "L2";
		else if (result == 12)
			res += "F";
		else if (result == 13)
			res += "F'";
		else if (result == 14)
			res += "F2";
		else if (result == 15)
			res += "B";
		else if (result == 16)
			res += "B'";
		else if (result == 17)
			res += "B2";
		if (i != max - 1)
			res += " ";
	}
	std::cout << res;
	return 0;
}