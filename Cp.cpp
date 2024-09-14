#include "Cp.hpp"

Cp::Cp():Table(NUM_CP, std::vector<int>(NUM_MOVES_P2, 0))
{
	input_index = -1;
	// for (int i = 0; i < 8; i ++)
	// 	_cp[i] = i;
	MakeTable();
}

Cp::~Cp(){}

void	Cp::IndexToCp(int index){
	std::memset(_cp, 0, sizeof(_cp));
	for (int i = 6; i >= 0 ; i --){
		_cp[i] = index %(8 - i);
		index /= 8 - i;
		for (int j = i + 1; j < 8; j ++){
			if (_cp[j] >= _cp[i]){
				_cp[j] += 1;
			}
		}
	}
}

int	Cp::CpToIndex(){
	int	index = 0;

	for (int i = 0; i < 8; i ++){
		index *= 8 - i;
		for (int j = i + 1; j < 8; ++j){
			if (_cp[i] > _cp[j]){
				index += 1;
			}
		}
	}
	return index;
}

void	Cp::print(){
	std::cout << "CP {";
	for (int i = 0; i < 8; i ++){
		std::cout << _cp[i];
		if (i != 7)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << "Index " << CpToIndex() << std::endl;
}

void	Cp::MakeTable(){
	for (int i = 0; i < NUM_CP ; i ++){
		IndexToCp(i);
		D();
		Table[i][0] = CpToIndex();//D
		D();
		Table[i][1] = CpToIndex();//D2
		D();
		Table[i][2] = CpToIndex();//D'

		IndexToCp(i);
		U();
		Table[i][3] = CpToIndex();//U
		U();
		Table[i][4] = CpToIndex();//U2
		U();
		Table[i][5] = CpToIndex();//U'

		IndexToCp(i);
		R2();
		Table[i][6] = CpToIndex();//R2
		IndexToCp(i);
		L2();
		Table[i][7] = CpToIndex();//L2
		IndexToCp(i);
		F2();
		Table[i][8] = CpToIndex();//F2
		IndexToCp(i);
		B2();
		Table[i][9] = CpToIndex();//B2
		// for (int j = 0; j < 10; j ++ )
		// 	std::cout << Table[i][j] << " " ;
		// std::cout << "i=" << i <<  std::endl;
	}
}

void	Cp::R()
{
	tmp = _cp[2];
	_cp[2] = _cp[6];
	_cp[6] = _cp[5];
	_cp[5] = _cp[1];
	_cp[1] = tmp;
}

void	Cp::D()
{
	tmp = _cp[6];
	_cp[6] = _cp[7];
	_cp[7] = _cp[4];
	_cp[4] = _cp[5];
	_cp[5] = tmp;
}

void	Cp::U()
{
	tmp = _cp[0];
	_cp[0] = _cp[3];
	_cp[3] = _cp[2];
	_cp[2] = _cp[1];
	_cp[1] = tmp;
}

void	Cp::L()
{
	tmp = _cp[0];
	_cp[0] = _cp[4];
	_cp[4] = _cp[7];
	_cp[7] = _cp[3];
	_cp[3] = tmp;
}

void	Cp::F()
{
	tmp = _cp[3];
	_cp[3] = _cp[7];
	_cp[7] = _cp[6];
	_cp[6] = _cp[2];
	_cp[2] = tmp;
}

void	Cp::B()
{
	tmp = _cp[0];
	_cp[0] = _cp[1];
	_cp[1] = _cp[5];
	_cp[5] = _cp[4];
	_cp[4] = tmp;
}

void	Cp::F2(){
	F();
	F();
}

void	Cp::F3(){
	F();
	F();
	F();
}

void	Cp::B2(){
	B();
	B();
}

void	Cp::B3(){
	B();
	B();
	B();
}

void	Cp::L2(){
	L();
	L();
}

void	Cp::L3(){
	L();
	L();
	L();
}

void	Cp::U2(){
	U();
	U();
}

void	Cp::U3(){
	U();
	U();
	U();
}

void	Cp::D2(){
	D();
	D();
}

void	Cp::D3(){
	D();
	D();
	D();
}

void	Cp::R2(){
	R();
	R();
}

void	Cp::R3(){
	R();
	R();
	R();
}

void	Cp::Input(std::vector<std::string> lst){
	IndexToCp(0);
	for (size_t i = 0; i < lst.size(); i ++)
		MoveStr(lst[i]);
	// print();
}

void	Cp::FinishP1(std::vector<std::string> lst){
	for (size_t i = 0; i < lst.size(); i ++)
		MoveStr(lst[i]);
	input_index = CpToIndex();
	// print();
}

void	Cp::MoveStr(std::string str){
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
