#ifndef EO_HPP
#define EO_HPP

#include "rubic.hpp"

class	Eo
{
	public:
		void	R();
		void	R2();
		void	R3();
		void	D();
		void	D2();
		void	D3();
		void	U();
		void	U2();
		void	U3();
		void	L();
		void	L2();
		void	L3();
		void	F();
		void	F2();
		void	F3();
		void	B();
		void	B2();
		void	B3();
		int		_eo[12];
		int		tmp;
	public:
		int		input_index;
		Eo();
		~Eo();
		std::vector<std::vector<int> >	Table;
		void	IndexToEo(int index);
		int		EoToIndex();
		void	print();
		void	MakeTable();
		void	Input(std::vector<std::string> str);
		void	MoveStr(std::string str);
};

#endif