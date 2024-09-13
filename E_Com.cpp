#include "E_Com.hpp"

E_Com::E_Com():Table(NUM_E_COMBINATIONS, std::vector<int>(NUM_MOVES_P1, 0))
{
	// for (int i = 0; i < 4 ; i ++){
	// 	_ep[i] = 1;
	// }
	// for (int i = 4; i < 12; i ++){
	// 	_ep[i] = 0;
	// }
	MakeTable();
}

E_Com::~E_Com(){}

void	E_Com::IndexToEcom(int index){
	std::memset(_ep, 0, sizeof(_ep));
	int r = 4;

	for (int i = 11; i >= 0; --i){
		if (index >= Combination(i, r)){
			_ep[i] = 1;
			index -= Combination(i, r);
			r --;
		}
	}
}

int		E_Com::EcomToIndex(){
	int	index = 0;
	int r = 4;

	for (int i = 11; i >= 0; i --){
		if (_ep[i]){
			index += Combination(i, r);
			r -= 1;
		}
	}
	return index;
}

int		E_Com::Combination(int n, int r){
	if (r > n || r < 0)
    	return 0;
	if (r == 0 || r == n)
    	return 1;

	int	ret = 1;

	for (int i = 0; i < r; i ++){
		ret *= n - i;
	}
	for (int i = 0; i < r; i ++){
		ret /= r - i;
	}
	return ret;
}

void	E_Com::print(){
	std::cout << "EP{";
	for (int i = 0; i < 12; i ++){
		std::cout << _ep[i];
		if (i != 11)
			std::cout << ", ";
	}
	std::cout << "}" << std::endl;
	std::cout << EcomToIndex() << std::endl;
}

void	E_Com::MakeTable(){
	for (int i = 0; i < NUM_E_COMBINATIONS; i ++)
	{
		IndexToEcom(i);
		R();
		Table[i][0] = EcomToIndex();//R
		R();
		Table[i][1] = EcomToIndex();//R2
		R();
		Table[i][2] = EcomToIndex();//R'
		IndexToEcom(i);
		L();
		Table[i][3] = EcomToIndex();//L
		L();
		Table[i][4] = EcomToIndex();//L2
		L();
		Table[i][5] = EcomToIndex();//L'
		IndexToEcom(i);
		U();
		Table[i][6] = EcomToIndex();//U
		U();
		Table[i][7] = EcomToIndex();//U2
		U();
		Table[i][8] = EcomToIndex();//U'
		IndexToEcom(i);
		D();
		Table[i][9] = EcomToIndex();//D
		D();
		Table[i][10] = EcomToIndex();//D2
		D();
		Table[i][11] = EcomToIndex();//D'
		IndexToEcom(i);
		F();
		Table[i][12] = EcomToIndex();//F
		F();
		Table[i][13] = EcomToIndex();//F2
		F();
		Table[i][14] = EcomToIndex();//F'
		IndexToEcom(i);
		B();
		Table[i][15] = EcomToIndex();//B
		B();
		Table[i][16] = EcomToIndex();//B2
		B();
		Table[i][17] = EcomToIndex();//B'
		// for (int j = 0; j < 18; j ++ )
		// 	std::cout << Table[i][j] << " " ;
		// std::cout << "i=" << i <<  std::endl;
	}
}

void	E_Com::Input(std::vector<std::string> lst){
	IndexToEcom(0);
	for (size_t i = 0; i < lst.size(); i ++)
		MoveStr(lst[i]);
	input_index = EcomToIndex();
}

void	E_Com::MoveStr(std::string str){
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
	// if (str == "R")
	// 	input_index = Table[input_index][0];
	// else if (str == "R'")
	// 	input_index = Table[input_index][2];
	// else if (str == "R2")
	// 	input_index = Table[input_index][1];
	// else if (str == "D")
	// 	input_index = Table[input_index][9];
	// else if (str == "D'")
	// 	input_index = Table[input_index][11];
	// else if (str == "D2")
	// 	input_index = Table[input_index][10];
	// else if (str == "U")
	// 	input_index = Table[input_index][6];
	// else if (str == "U'")
	// 	input_index = Table[input_index][8];
	// else if (str == "U2")
	// 	input_index = Table[input_index][7];
	// else if (str == "L")
	// 	input_index = Table[input_index][3];
	// else if (str == "L'")
	// 	input_index = Table[input_index][5];
	// else if (str == "L2")
	// 	input_index = Table[input_index][4];
	// else if (str == "F")
	// 	input_index = Table[input_index][12];
	// else if (str == "F'")
	// 	input_index = Table[input_index][14];
	// else if (str == "F2")
	// 	input_index = Table[input_index][13];
	// else if (str == "B")
	// 	input_index = Table[input_index][15];
	// else if (str == "B'")
	// 	input_index = Table[input_index][17];
	// else if (str == "B2")
	// 	input_index = Table[input_index][16];
	// else{
	// 	std::cerr << "comannd error" << std::endl;
	// 	std::exit(1);
	// }
}