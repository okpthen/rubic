#ifndef E_COM_HPP
#define E_COM_HPP

#include "Ep.hpp"

class	E_Com:	public	Ep
{
	public:
		int		input_index;
		E_Com();
		~E_Com();
		std::vector<std::vector<int> >	Table;
		void	IndexToEcom(int index);
		int		EcomToIndex();
		void	print();
		int		Combination(int n, int r);
		void	MakeTable();
		void	Input(std::vector<std::string> str);
		void	MoveStr(std::string str);
};

#endif