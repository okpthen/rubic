#ifndef EP_E_HPP
# define EP_E_HPP

#include "Ep.hpp"

class	Ep_E: public	Ep
{
	public:
		int		input_index;
		Ep_E();
		~Ep_E();
		std::vector<std::vector<int> >	Table;
		void	IndexToEp(int index);
		int		EpToIndex();
		void	print();
		void	MakeTable();
		void	Input(std::vector<std::string> str);
		void	MoveStr(std::string str);
		void	FinishP1(std::vector<std::string> str);
};

#endif