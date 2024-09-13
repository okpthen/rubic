#include "Ep.hpp"

Ep::Ep(){
	for (int i = 0; i < 12 ; i ++)
		_ep[i] = i;
}

Ep::~Ep(){}

void	Ep::R()
{
	tmp = _ep[2];
	_ep[2] = _ep[9];
	_ep[9] = _ep[1];
	_ep[1] = _ep[5];
	_ep[5] = tmp;
}

void	Ep::D()
{
	tmp = _ep[9];
	_ep[9] = _ep[10];
	_ep[10] = _ep[11];
	_ep[11] = _ep[8];
	_ep[8] = tmp;
}

void	Ep::U()
{
	tmp = _ep[7];
	_ep[7] = _ep[6];
	_ep[6] = _ep[5];
	_ep[5] = _ep[4];
	_ep[4] = tmp;
}

void	Ep::L()
{
	tmp = _ep[7];
	_ep[7] = _ep[0];
	_ep[0] = _ep[11];
	_ep[11] = _ep[3];
	_ep[3] = tmp;
}

void	Ep::F()
{
	tmp = _ep[3];
	_ep[3] = _ep[10];
	_ep[10] = _ep[2];
	_ep[2] = _ep[6];
	_ep[6] = tmp;
}

void	Ep::B()
{
	tmp = _ep[4];
	_ep[4] = _ep[1];
	_ep[1] = _ep[8];
	_ep[8] = _ep[0];
	_ep[0] = tmp;
}

void	Ep::F2(){
	F();
	F();
}

void	Ep::F3(){
	F();
	F();
	F();
}

void	Ep::B2(){
	B();
	B();
}

void	Ep::B3(){
	B();
	B();
	B();
}

void	Ep::L2(){
	L();
	L();
}

void	Ep::L3(){
	L();
	L();
	L();
}

void	Ep::U2(){
	U();
	U();
}

void	Ep::U3(){
	U();
	U();
	U();
}

void	Ep::D2(){
	D();
	D();
}

void	Ep::D3(){
	D();
	D();
	D();
}

void	Ep::R2(){
	R();
	R();
}

void	Ep::R3(){
	R();
	R();
	R();
}