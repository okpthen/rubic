#ifndef PRUNINGTABLE
# define  PRUNINGTABLE

#include "Cp.hpp"
#include "Co.hpp"
#include "Eo.hpp"
#include "E_Com.hpp"
#include "Ep_Ud.hpp"
#include "Ep_E.hpp"

class PruningTable
{
	public:
		std::vector<std::vector<int> >	co_ecom;
		std::vector<std::vector<int> >	eo_ecom;
		std::vector<std::vector<int> >	cp_epe;
		std::vector<std::vector<int> >	epud_epe;
		PruningTable(char *str);
		~PruningTable();
		void	print();
	protected:
		Co		co;
		Eo		eo;
		E_Com	ecom;
		Cp		cp;
		Ep_E	epe;
		Ep_Ud	epud;
		void	Make1();
		void	Make2();
		void	Make3();
		void	Make4();
		void	Input(char *str);
};

#endif