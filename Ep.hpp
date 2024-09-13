#ifndef EP_HPP
#define EP_HPP

#include "rubic.hpp"

class	Ep
{
	public:
		void	R();
		void	R2();
		void	R3();
		void	D();
		void	D2();
		void	D3();
		void	U();
		void	U2();
		void	U3();
		void	L();
		void	L2();
		void	L3();
		void	F();
		void	F2();
		void	F3();
		void	B();
		void	B2();
		void	B3();
		int		_ep[12];
		int		tmp;
		Ep();
		~Ep();
};

#endif