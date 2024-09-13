#include "PruningTable.hpp"

PruningTable::PruningTable(char *str)
{
	co_ecom = std::vector<std::vector<int> >(NUM_CO, std::vector<int>(NUM_E_COMBINATIONS, -1));
	eo_ecom = std::vector<std::vector<int> >(NUM_EO, std::vector<int>(NUM_E_COMBINATIONS, -1));
	cp_epe = std::vector<std::vector<int> >(NUM_CP, std::vector<int>(NUM_E_EP, -1));
	epud_epe = std::vector<std::vector<int> >(NUM_UD_EP, std::vector<int>(NUM_E_EP, -1));
	Make1();
	Make2();
	Make3();
	Make4();
	Input(str);
	// print();
}

PruningTable::~PruningTable(){}

void	PruningTable::Make1(){
	int		distance = 0;
	int		filled = 1;

	co_ecom[0][0] = 0;

	while (filled != NUM_CO * NUM_E_COMBINATIONS){
		for (int i = 0; i < NUM_CO; ++i){
			for (int j = 0; j < NUM_E_COMBINATIONS; ++j){
				if (co_ecom[i][j] == distance){
					for (int move = 0; move < NUM_MOVES_P1; ++move){
						int	co_next = co.Table[i][move];
						int	ecom_next = ecom.Table[j][move];
						if (co_ecom[co_next][ecom_next] == -1){
							co_ecom[co_next][ecom_next] = distance + 1;
							++filled;
						}
					}
				}
			}
		}
		++distance;
	}
}

void	PruningTable::Make2(){
	int		distance = 0;
	int		filled = 1;

	eo_ecom[0][0] = 0;
	while (filled != NUM_EO * NUM_E_COMBINATIONS){
		for (int i = 0; i < NUM_EO; ++i){
			for (int j = 0; j < NUM_E_COMBINATIONS; ++j){
				if (eo_ecom[i][j] == distance){
					for (int move = 0; move < NUM_MOVES_P1; ++move){
						int	eo_next = eo.Table[i][move];
						int	ecom_next = ecom.Table[j][move];
						if (eo_ecom[eo_next][ecom_next] == -1){
							eo_ecom[eo_next][ecom_next] = distance + 1;
							filled ++ ;
						}
					}
				}
			}
		}
		++distance;
	}
}

void	PruningTable::Make3(){
	int		distance = 0;
	int		filled = 1;

	cp_epe[0][0] =0;
	while (filled != NUM_CP * NUM_E_EP){
		for (int i = 0; i < NUM_CP; ++i){
			for (int j = 0; j < NUM_E_EP; ++j){
				if (cp_epe[i][j] == distance){
					for (int move = 0; move < NUM_MOVES_P2; ++move){
						int	cp_next = cp.Table[i][move];
						int	epe_next = epe.Table[j][move];
						if (cp_epe[cp_next][epe_next] == -1){
							cp_epe[cp_next][epe_next] = distance + 1;
							filled ++;
						}
					}
				}
			}
		}
		distance ++;
	}
}

void	PruningTable::Make4(){
	int		distance = 0;
	int		filled = 1;

	epud_epe[0][0] = 0;
	while (filled != NUM_UD_EP * NUM_E_EP){
		for (int i = 0; i < NUM_UD_EP; ++i){
			for (int j = 0; j < NUM_E_EP; ++j){
				if (epud_epe[i][j] == distance){
					for (int move = 0; move < NUM_MOVES_P2; ++move){
						int	epud_next = epud.Table[i][move];
						int	epe_next = epe.Table[j][move];
						if (epud_epe[epud_next][epe_next] == -1){
							epud_epe[epud_next][epe_next] = distance + 1;
							filled ++;
						}
					}
				}
			}
		}
		distance ++;
	}
}

void	PruningTable::Input(char *str){
	std::size_t		find;
	std::string		cmd = str;
	std::vector<std::string>	lst;
	std::string		s;

	while ((find = cmd.find("  "))  != std::string::npos)
		cmd.erase(find, 1);
	std::istringstream stream(cmd.c_str());
	while(std::getline(stream, s, ' '))
		lst.push_back(s);
	
	co.Input(lst);
	eo.Input(lst);
	ecom.Input(lst);
	cp.Input(lst);
	epe.Input(lst);
	epud.Input(lst);
}

void	PruningTable::print(){
	// for (int i = 0; i < NUM_CO; i ++){
	// 	for (int j = 0; j < NUM_E_COMBINATIONS; j ++){
	// 		std::cout << co_ecom[i][j] << " ";
	// 	}
	// 	std::cout << " i=" << i << std::endl;
	// }
	std::cout << co.input_index << " " << eo.input_index << " " << ecom.input_index << std::endl;
	std::cout << co_ecom[107][61] << " " << eo_ecom[1604][61] << std::endl;
}