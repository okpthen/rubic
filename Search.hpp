#ifndef SEARCH_HPP
# define SEARCH_HPP

#include "PruningTable.hpp"

class Search: public	PruningTable
{
	public:
		Search(char *str);
		~Search();
	private:
		// p1
		bool	depth_limited_search_ph1(int co_index, int eo_index, int e_comb_index, int depth);
		void	search_ph1();
		bool	is_move_available_ph1(int prev, int move);
		void	solution_join_p1();
		std::vector<int>	current_solution_p1;

		// p2
		void	FinishP1();
		bool	depth_limited_search_ph2(int cp_index, int udep_index, int eep_index, int depth);
		void	search_ph2();
		bool	is_move_available_ph2(int prev, int move);
		void	solution_join_p2();
		std::vector<int>	current_solution_p2;

		std::string			solution;
};

#endif