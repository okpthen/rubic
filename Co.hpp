#ifndef CO_HPP
# define CO_HPP

#include "rubic.hpp"

class Co
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
		int		_co[8];
		int		tmp;
	public:
		Co();
		~Co();
		int		input_index;
		std::vector<std::vector<int> >	Table;
		void	IndexToCo(int index);
		int		CoToIndex();
		void	print();
		void	Maketable();
		void	Input(std::vector<std::string> str);
		void	MoveStr(std::string str);
};

#endif