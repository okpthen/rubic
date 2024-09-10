#ifndef STATUS_HPP
# define STATUS_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

class	Status
{
	private:
		int	cp[8];
		int	co[8];
		int	ep[12];
		int	eo[12];
		int tmp;
	public:
		Status();
		~Status();
		void	print();
		void	input_arg(char *str);
		void	move_str(std::string str);

		void	move_R();
		void	move_D();
		void	move_U();
		void	move_L();
		void	move_F();
		void	move_B();
		void	move_R2();
		void	move_R3();
		void	move_D2();
		void	move_D3();
		void	move_U2();
		void	move_U3();
		void	move_L2();
		void	move_L3();
		void	move_F2();
		void	move_F3();
		void	move_B2();
		void	move_B3();
};

#endif