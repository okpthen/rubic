#include "Ep_Ud.hpp"

Ep_Ud::Ep_Ud(): Table(NUM_UD_EP, std::vector<int>(NUM_MOVES_P2, 0))
{
	input_index = -1;
	// for (int i = 0; i < 4; i ++)
	// 	_ep[i] = 0;
	// for (int i = 4; i < 12; i ++)
	// 	_ep[i] = i;
	MakeTable();
}

Ep_Ud::~Ep_Ud(){}

void	Ep_Ud::IndexToEp(int index){
	std::memset(_ep, 0, sizeof(_ep));
	for (int i = 6; i >= 0; i --){
		_ep[i + 4] = index % (8 - i);
		index /= 8 - i;
		for (int j = i + 1; j < 8; j ++){
			if (_ep[j + 4] >= _ep[i + 4])
				_ep[j + 4] += 1;
		}
	}
	for (int i = 4; i < 12; i ++)
		_ep[i] += 4;
}

int		Ep_Ud::EpToIndex(){
	int	index = 0;

	for (int i = 0; i < 8 ; i ++){
		index *= 8 - i;
		for (int j = i + 1; j < 8; ++j){
			if (_ep[i + 4] > _ep[j + 4])
				index += 1;
		}
	}
	return index;
}

void	Ep_Ud::print(){
	std::cout << "EP{";
	for (int i = 0; i < 12; i ++){
		std::cout << _ep[i];
		if (i != 11)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << EpToIndex() << std::endl;
}

void	Ep_Ud::MakeTable(){
	for (int i = 0; i < NUM_UD_EP; i ++){
		IndexToEp(i);
		D();
		Table[i][0] = EpToIndex();//D
		D();
		Table[i][1] = EpToIndex();//D2
		D();
		Table[i][2] = EpToIndex();//D'

		IndexToEp(i);
		U();
		Table[i][3] = EpToIndex();//U
		U();
		Table[i][4] = EpToIndex();//U2
		U();
		Table[i][5] = EpToIndex();//U'

		IndexToEp(i);
		R2();
		Table[i][6] = EpToIndex();//R2
		IndexToEp(i);
		L2();
		Table[i][7] = EpToIndex();//L2
		IndexToEp(i);
		F2();
		Table[i][8] = EpToIndex();//F2
		IndexToEp(i);
		B2();
		Table[i][9] = EpToIndex();//B2
		// for (int j = 0; j < 10; j ++ )
		// 	std::cout << Table[i][j] << " " ;
		// std::cout << "i=" << i <<  std::endl;
	}
}

void	Ep_Ud::Input(std::vector<std::string> lst){
	for (int i = 0; i < 12; i ++)
		_ep[i] = i;
	for (size_t i = 0; i < lst.size(); i ++)
		MoveStr(lst[i]);
}

void	Ep_Ud::FinishP1(std::vector<std::string> lst){
	for (size_t i = 0; i < lst.size(); i ++)
		MoveStr(lst[i]);
	input_index = EpToIndex();
}

void	Ep_Ud::MoveStr(std::string str){
	if (str == "R")
		R();
	else if (str == "R'")
		R3();
	else if (str == "R2")
		R2();
	else if (str == "D")
		D();
	else if (str == "D'")
		D3();
	else if (str == "D2")
		D2();
	else if (str == "U")
		U();
	else if (str == "U'")
		U3();
	else if (str == "U2")
		U2();
	else if (str == "L")
		L();
	else if (str == "L'")
		L3();
	else if (str == "L2")
		L2();
	else if (str == "F")
		F();
	else if (str == "F'")
		F3();
	else if (str == "F2")
		F2();
	else if (str == "B")
		B();
	else if (str == "B'")
		B3();
	else if (str == "B2")
		B2();
	else{
		std::cerr << "comannd error" << std::endl;
		std::exit(1);
	}
}