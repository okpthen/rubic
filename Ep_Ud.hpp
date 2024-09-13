#ifndef EP_UD_HPP
# define EP_UD_HPP

#include "Ep.hpp"

class	Ep_Ud: public	Ep
{
	public:
		int		input_index;
		Ep_Ud();
		~Ep_Ud();
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