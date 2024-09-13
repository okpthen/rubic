#include "Eo.hpp"

Eo::Eo():Table(NUM_EO, std::vector<int>(NUM_MOVES_P1, 0))
{
	// for (int i = 0 ; i < 12; i ++){
	// 	_eo[i] = 0;
	// }
	MakeTable();
}

Eo::~Eo(){}

void	Eo::IndexToEo(int index){
	int sum = 0;
	for (int i = 10; i >= 0; i --){
		_eo[i] = index % 2;
		index /= 2;
		sum += _eo[i];
	}
	_eo[11] = (2 - sum % 2) % 2;
}

int		Eo::EoToIndex(){
	int	index = 0;
	for (int i = 0; i < 11; i ++){
		index *= 2;
		index += _eo[i];
	}
	return index;
}

void	Eo::print(){
	std::cout << "EO{";
	for (int i = 0; i < 12; i ++){
		std::cout << _eo[i];
		if (i != 11)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Index " << EoToIndex() << std::endl;
}

void	Eo::MakeTable(){
	for (int i = 0; i < NUM_EO; i ++){
		IndexToEo(i);
		R();
		Table[i][0] = EoToIndex();//R
		R();
		Table[i][1] = EoToIndex();//R2
		R();
		Table[i][2] = EoToIndex();//R'
		IndexToEo(i);
		L();
		Table[i][3] = EoToIndex();//L
		L();
		Table[i][4] = EoToIndex();//L2
		L();
		Table[i][5] = EoToIndex();//L'
		IndexToEo(i);
		U();
		Table[i][6] = EoToIndex();//U
		U();
		Table[i][7] = EoToIndex();//U2
		U();
		Table[i][8] = EoToIndex();//U'
		IndexToEo(i);
		D();
		Table[i][9] = EoToIndex();//D
		D();
		Table[i][10] = EoToIndex();//D2
		D();
		Table[i][11] = EoToIndex();//D'
		IndexToEo(i);
		F();
		Table[i][12] = EoToIndex();//F
		F();
		Table[i][13] = EoToIndex();//F2
		F();
		Table[i][14] = EoToIndex();//F'
		IndexToEo(i);
		B();
		Table[i][15] = EoToIndex();//B
		B();
		Table[i][16] = EoToIndex();//B2
		B();
		Table[i][17] = EoToIndex();//B'
		// for (int j = 0; j < 18; j ++ )
		// 	std::cout << Table[i][j] << " " ;
		// std::cout << "i=" << i <<  std::endl;
	}
}

void	Eo::R(){
	tmp = _eo[5];
	_eo[5] = _eo[2];
	_eo[2] = _eo[9];
	_eo[9] = _eo[1];
	_eo[1] = tmp;
}

void	Eo::D(){
	tmp = _eo[10];
	_eo[10] = _eo[11];
	_eo[11] = _eo[8];
	_eo[8] = _eo[9];
	_eo[9] = tmp;
}

void	Eo::U(){
	tmp = _eo[5];
	_eo[5] = _eo[4];
	_eo[4] = _eo[7];
	_eo[7] = _eo[6];
	_eo[6] = tmp;
}

void	Eo::L(){
	tmp = _eo[7];
	_eo[7] = _eo[0];
	_eo[0] = _eo[11];
	_eo[11] = _eo[3];
	_eo[3] = tmp;
}

void	Eo::F()
{
	tmp = _eo[6];
	_eo[6] = (_eo[3] + 1) % 2;
	_eo[3] = (_eo[10] + 1) % 2;
	_eo[10] = (_eo[2] + 1) % 2;
	_eo[2] = (tmp + 1) % 2;
}

void	Eo::B()
{
	tmp = _eo[1];
	_eo[1] = (_eo[8] + 1) % 2;
	_eo[8] = (_eo[0] + 1) % 2;
	_eo[0] = (_eo[4] + 1) % 2;
	_eo[4] = (tmp + 1) % 2;
}

void	Eo::F2(){
	F();
	F();
}

void	Eo::F3(){
	F();
	F();
	F();
}

void	Eo::B2(){
	B();
	B();
}

void	Eo::B3(){
	B();
	B();
	B();
}

void	Eo::L2(){}

void	Eo::L3(){}

void	Eo::U2(){}

void	Eo::U3(){}

void	Eo::D2(){}

void	Eo::D3(){}

void	Eo::R2(){}

void	Eo::R3(){}

void	Eo::Input(std::vector<std::string> lst){
	IndexToEo(0);
	for (size_t i = 0; i < lst.size(); i ++)
		MoveStr(lst[i]);
	input_index = EoToIndex();
	// print();
}

void	Eo::MoveStr(std::string str){
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