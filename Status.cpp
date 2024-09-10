#include "rubic.hpp"

Status::Status(){
	for (int i = 0; i < 8 ; i ++)
	{
		cp[i] = i;
		co[i] = 0;
	}
	for (int i = 0; i < 12; i ++){
		ep[i] = i;
		eo[i] = 0;
	}
}

Status::~Status(){}
void	Status::print(){
	std::cout << "status" << std::endl <<"[";
	for (int i = 0; i < 8; i ++){
		std::cout << cp[i];
		if (i != 7)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl << "[" ;
	for (int i = 0; i < 8; i ++){
		std::cout << co[i];
		if (i != 7)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl << "[" ;
	for (int i = 0; i < 12; i ++){
		std::cout << ep[i];
		if (i != 11)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl << "[" ;
	for (int i = 0; i < 12; i ++){
		std::cout << eo[i];
		if (i != 11)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

void	Status::input_arg(char *str){
	std::size_t		find;
	std::string		cmd = str;
	std::vector<std::string>	lst;
	std::string		s;

	while ((find = cmd.find("  "))  != std::string::npos)
		cmd.erase(find, 1);
	std::istringstream stream(cmd.c_str());
	while(std::getline(stream, s, ' '))
		lst.push_back(s);
	for (size_t i = 0; i < lst.size(); i ++)
		move_str(lst[i]);
}