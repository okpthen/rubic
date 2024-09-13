#include "Search.hpp"

Search::Search(char *str):	PruningTable(str)
{
	search_ph1();
	solution_join_p1();
	// std::cout << "P1 solution "<< solution << std::endl;
	// std::cout << cp.input_index << " " << epe.input_index << " " << epud.input_index << std::endl;
	FinishP1();
	// std::cout << solution << std::endl;
	// std::cout << cp.input_index << " " << epe.input_index << " " << epud.input_index << std::endl;
	search_ph2();
	solution_join_p2();
	std::cout << solution  << std::endl;
}

Search::~Search(){}

bool	Search::depth_limited_search_ph1(int co_index, int eo_index, int e_comb_index, int depth)
{
	if (depth == 0 && co_index == 0 && eo_index == 0 && e_comb_index == 0){
		return true;
	}
	if (depth == 0)
		return false;
	if (std::max(co_ecom[co_index][e_comb_index], eo_ecom[eo_index][e_comb_index]) > depth)
		return false;
	int prev_move = current_solution_p1.empty() ? -1 : current_solution_p1.back();
	for (int move = 0; move < NUM_MOVES_P1; move ++){
		if (!is_move_available_ph1(prev_move, move)){
			continue;
		}

		current_solution_p1.push_back(move);
		int	next_co_index = co.Table[co_index][move];
		int	next_eo_index = eo.Table[eo_index][move];
		int	next_ecom_index = ecom.Table[e_comb_index][move];
		if (depth_limited_search_ph1(next_co_index, next_eo_index, next_ecom_index, depth - 1))
			return true;
		current_solution_p1.pop_back();
	}
	return false;
}

void	Search::search_ph1(){
	int	depth = 0;
	while (depth <= MAX_SEARCH_P1){
		current_solution_p1.clear();
		if (depth_limited_search_ph1(co.input_index, eo.input_index, ecom.input_index, depth))
			return ;
		depth ++;
	}
	std::cerr << "No Solution P1" << std::endl;
	std::exit(1);
}

bool Search::is_move_available_ph1(int prev, int move) {
	if (prev == -1)
		return true;
    static const std::map<int, std::set<int> > forbidden_moves = {
        {0, {0, 1, 2}},
        {1, {0, 1, 2}},
        {2, {0, 1, 2}},
        {3, {0, 1, 2, 3, 4, 5}},
        {4, {0, 1, 2, 3, 4, 5}},
        {5, {0, 1, 2, 3, 4, 5}},
		{6, {6, 7, 8}},
        {7, {6, 7, 8}},
        {8, {6, 7, 8}},
        {9, {6, 7, 8, 9, 10, 11}},
        {10, {6, 7, 8, 9, 10, 11}},
        {11, {6, 7, 8, 9, 10, 11}},
		{12, {12, 13, 14}},
        {13, {12, 13, 14}},
        {14, {12, 13, 14}},
        {15, {12, 13, 14, 15, 16, 17}},
        {16, {12, 13, 14, 15, 16, 17}},
        {17, {12, 13, 14, 15, 16, 17}},
    };

    auto it = forbidden_moves.find(prev);
    if (it != forbidden_moves.end() && it->second.count(move)) {
        return false;
    }

    return true;
}

void	Search::solution_join_p1(){
	for (size_t i = 0; i < current_solution_p1.size(); i ++){
		if (current_solution_p1[i] == 0)
			solution += "R";
		else if (current_solution_p1[i] == 1)
			solution += "R2";
		else if (current_solution_p1[i] == 2)
			solution += "R'";
		else if (current_solution_p1[i] == 3)
			solution += "L";
		else if (current_solution_p1[i] == 4)
			solution += "L2";
		else if (current_solution_p1[i] == 5)
			solution += "L'";
		else if (current_solution_p1[i] == 6)
			solution += "U";
		else if (current_solution_p1[i] == 7)
			solution += "U2";
		else if (current_solution_p1[i] == 8)
			solution += "U'";
		else if (current_solution_p1[i] == 9)
			solution += "D";
		else if (current_solution_p1[i] == 10)
			solution += "D2";
		else if (current_solution_p1[i] == 11)
			solution += "D'";
		else if (current_solution_p1[i] == 12)
			solution += "F";
		else if (current_solution_p1[i] == 13)
			solution += "F2";
		else if (current_solution_p1[i] == 14)
			solution += "F'";
		else if (current_solution_p1[i] == 15)
			solution += "B";
		else if (current_solution_p1[i] == 16)
			solution += "B2";
		else if (current_solution_p1[i] == 17)
			solution += "B'";
		if (i != current_solution_p1.size() - 1)
			solution += " ";
	}
}

void	Search::FinishP1(){
	std::string		cmd = solution;
	std::vector<std::string>	lst;
	std::string		s;

	std::istringstream stream(cmd.c_str());
	while(std::getline(stream, s, ' '))
		lst.push_back(s);
	cp.FinishP1(lst);
	epe.FinishP1(lst);
	epud.FinishP1(lst);
}

void	Search::search_ph2(){
	int	depth = 0;
	while (depth <= MAX_SEARCH_P2){
		current_solution_p2.clear();
		if (depth_limited_search_ph2(cp.input_index, epud.input_index, epe.input_index, depth))
			return ;
		depth ++;
	}
	std::cerr << "No Solution P2" << std::endl;
	std::exit(1);
}

bool	Search::depth_limited_search_ph2(int cp_index, int udep_index, int eep_index, int depth){
	if (depth == 0 && cp_index == 0 && udep_index == 0 && eep_index == 0)
		return true;
	if (depth == 0)
		return false;
	if (std::max(cp_epe[cp_index][eep_index], epud_epe[udep_index][eep_index]) > depth)
		return false;
	int prev_move = current_solution_p2.empty() ? -1 : current_solution_p2.back();
	for (int move = 0; move < NUM_MOVES_P2; move ++){
		if (!is_move_available_ph2(prev_move, move)){
			continue;
		}

		current_solution_p2.push_back(move);
		int	next_cp_index = cp.Table[cp_index][move];
		int	next_udep_index = epud.Table[udep_index][move];
		int	next_eep_index = epe.Table[eep_index][move];
		if (depth_limited_search_ph2(next_cp_index, next_udep_index, next_eep_index, depth - 1))
			return true;
		current_solution_p2.pop_back();
	}
	return false;
}

bool	Search::is_move_available_ph2(int prev, int move){
	if (prev == -1)
		return true;
    static const std::map<int, std::set<int> > forbidden_moves = {
        {0, {0, 1, 2}},
        {1, {0, 1, 2}},
        {2, {0, 1, 2}},
        {3, {0, 1, 2, 3, 4, 5}},
        {4, {0, 1, 2, 3, 4, 5}},
        {5, {0, 1, 2, 3, 4, 5}},
		{6, {6}},
        {7, {6, 7}},
        {8, {8}},
        {9, {8, 9}},
    };

    auto it = forbidden_moves.find(prev);
    if (it != forbidden_moves.end() && it->second.count(move)) {
        return false;
    }

    return true;
}

void	Search::solution_join_p2(){

	for (size_t i = 0; i < current_solution_p2.size(); i ++){
		if (!solution.empty())
			solution += " ";
		if (current_solution_p2[i] == 0)
			solution += "D";
		else if (current_solution_p2[i] == 1)
			solution += "D2";
		else if (current_solution_p2[i] == 2)
			solution += "D'";
		else if (current_solution_p2[i] == 3)
			solution += "U";
		else if (current_solution_p2[i] == 4)
			solution += "U2";
		else if (current_solution_p2[i] == 5)
			solution += "U'";
		else if (current_solution_p2[i] == 6)
			solution += "R2";
		else if (current_solution_p2[i] == 7)
			solution += "L2";
		else if (current_solution_p2[i] == 8)
			solution += "F2";
		else if (current_solution_p2[i] == 9)
			solution += "B2";
	}
}
