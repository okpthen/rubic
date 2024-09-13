#include "Co.hpp"

Co::Co(): Table(NUM_CO, std::vector<int>(NUM_MOVES_P1, 0))
{
	// for (int i = 0; i < 8; i ++)
	// 	_co[i] = 0;
	Maketable();
}

Co::~Co(){}

void	Co::IndexToCo(int index){
	int	sum = 0;
	for (int i = 6; i >= 0; i --){
		_co[i] = index % 3;
		index /= 3;
		sum += _co[i];
	}
	_co[7] = (3 - sum % 3) % 3;
}

int		Co::CoToIndex(){
	int	index = 0;
	for (int i = 0; i < 7; i ++){
		index *= 3;
		index += _co[i];
	}
	return index;
}

void	Co::print(){
	std::cout << "CO {" ;
	for (int i = 0; i < 8; i ++){
		std::cout << _co[i];
		if (i != 7)
			std::cout << ", " ;
	}
	std::cout << "}" << std::endl;
	std::cout << "Index " <<  CoToIndex() << std::endl;
}

void	Co::Maketable(){
	for (int i = 0; i < NUM_CO; i ++)
	{
		IndexToCo(i);
		R();
		Table[i][0] = CoToIndex();//R
		R();
		Table[i][1] = CoToIndex();//R2
		R();
		Table[i][2] = CoToIndex();//R'
		IndexToCo(i);
		L();
		Table[i][3] = CoToIndex();//L
		L();
		Table[i][4] = CoToIndex();//L2
		L();
		Table[i][5] = CoToIndex();//L'
		IndexToCo(i);
		U();
		Table[i][6] = CoToIndex();//U
		U();
		Table[i][7] = CoToIndex();//U2
		U();
		Table[i][8] = CoToIndex();//U'
		IndexToCo(i);
		D();
		Table[i][9] = CoToIndex();//D
		D();
		Table[i][10] = CoToIndex();//D2
		D();
		Table[i][11] = CoToIndex();//D'
		IndexToCo(i);
		F();
		Table[i][12] = CoToIndex();//F
		F();
		Table[i][13] = CoToIndex();//F2
		F();
		Table[i][14] = CoToIndex();//F'
		IndexToCo(i);
		B();
		Table[i][15] = CoToIndex();//B
		B();
		Table[i][16] = CoToIndex();//B2
		B();
		Table[i][17] = CoToIndex();//B'
		// for (int j = 0; j < 18; j ++ )
		// 	std::cout << Table[i][j] << " " ;
		// std::cout << "i=" << i <<  std::endl;
	}
}

void	Co::R()
{
	tmp = _co[2];
	_co[2] = (_co[6] + 2) % 3;
	_co[6] = (_co[5] + 1) % 3;
	_co[5] = (_co[1] + 2) % 3;
	_co[1] = (tmp + 1) % 3;
}

void	Co::R2(){
	R();
	R();
}

void	Co::R3(){
	R();
	R();
	R();
}

void	Co::D()
{
	tmp = _co[6];
	_co[6] = _co[7];
	_co[7] = _co[4];
	_co[4] = _co[5];
	_co[5] = tmp;
}

void	Co::D2(){
	D();
	D();
}

void	Co::D3(){
	D();
	D();
	D();
}

void	Co::U()
{
	tmp = _co[0];
	_co[0] = _co[3];
	_co[3] = _co[2];
	_co[2] = _co[1];
	_co[1] = tmp;
}

void	Co::U2(){
	U();
	U();
}

void	Co::U3(){
	U();
	U();
	U();
}


void	Co::L()
{
	tmp = _co[0];
	_co[0] = (_co[4] + 2) % 3;
	_co[4] = (_co[7] + 1) % 3;
	_co[7] = (_co[3] + 2) % 3;
	_co[3] = (tmp + 1) % 3;
}

void	Co::L2(){
	L();
	L();
}

void	Co::L3(){
	L();
	L();
	L();
}

void	Co::F()
{
	tmp = _co[3];
	_co[3] = (_co[7] + 2) % 3;
	_co[7] = (_co[6] + 1) % 3;
	_co[6] = (_co[2] + 2) % 3;
	_co[2] = (tmp + 1) % 3;
}

void	Co::F2(){
	F();
	F();
}

void	Co::F3(){
	F();
	F();
	F();
}

void	Co::B()
{
	tmp = _co[0];
	_co[0] = (_co[1] + 1) % 3;
	_co[1] = (_co[5] + 2) % 3;
	_co[5] = (_co[4] + 1) % 3;
	_co[4] = (tmp + 2) % 3;
}

void	Co::B2(){
	B();
	B();
}

void	Co::B3(){
	B();
	B();
	B();
}

void	Co::Input(std::vector<std::string> lst){
	IndexToCo(0);
	for (size_t i = 0; i < lst.size(); i ++)
		MoveStr(lst[i]);
	input_index = CoToIndex();
	// print();
}

void	Co::MoveStr(std::string str){
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
