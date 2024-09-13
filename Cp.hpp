#ifndef MOVECP_HPP
#define MOVECP_HPP

#include "rubic.hpp"

class Cp
{
	private:
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
		int		_cp[8];
		int		tmp;
	public:
		Cp();
		~Cp();
		int		input_index;
		std::vector<std::vector<int> >	Table;
		void	IndexToCp(int index);
		int		CpToIndex();
		void	print();
		void	MakeTable();
		void	Input(std::vector<std::string> str);
		void	MoveStr(std::string str);
		void	FinishP1(std::vector<std::string> str);
};

#endif