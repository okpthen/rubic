#include "Status.hpp"

void	Status::move_R(){
	tmp = cp[2];
	cp[2] = cp[6];
	cp[6] = cp[5];
	cp[5] = cp[1];
	cp[1] = tmp;

	tmp = ep[2];
	ep[2] = ep[9];
	ep[9] = ep[1];
	ep[1] = ep[5];
	ep[5] = tmp;

	tmp = co[2];
	co[2] = (co[6] + 2) % 3;
	co[6] = (co[5] + 1) % 3;
	co[5] = (co[1] + 2) % 3;
	co[1] = (tmp + 1) % 3;
}

void	Status::move_R2(){
	move_R();
	move_R();
}

void	Status::move_R3(){
	move_R2();
	move_R();
}

void	Status::move_L()
{
	tmp = cp[0];
	cp[0] = cp[4];
	cp[4] = cp[7];
	cp[7] = cp[3];
	cp[3] = tmp;

	tmp = ep[7];
	ep[7] = ep[0];
	ep[0] = ep[11];
	ep[11] = ep[3];
	ep[3] = tmp;

	tmp = co[0];
	co[0] = (co[4] + 2) % 3;
	co[4] = (co[7] + 1) % 3;
	co[7] = (co[3] + 2) % 3;
	co[3] = (tmp + 1) % 3;
}


void	Status::move_L2(){
	move_L();
	move_L();
}

void	Status::move_L3(){
	move_L2();
	move_L();
}


void	Status::move_D()
{
	tmp = cp[6];
	cp[6] = cp[7];
	cp[7] = cp[4];
	cp[4] = cp[5];
	cp[5] = tmp;

	tmp = ep[9];
	ep[9] = ep[10];
	ep[10] = ep[11];
	ep[11] = ep[8];
	ep[8] = tmp;

	tmp = co[6];
	co[6] = co[7];
	co[7] = co[4];
	co[4] = co[5];
	co[5] = tmp;
}

void	Status::move_D2(){
	move_D();
	move_D();
}

void	Status::move_D3(){
	move_D2();
	move_D();
}


void	Status::move_U()
{
	tmp = cp[0];
	cp[0] = cp[3];
	cp[3] = cp[2];
	cp[2] = cp[1];
	cp[1] = tmp;

	tmp = ep[7];
	ep[7] = ep[6];
	ep[6] = ep[5];
	ep[5] = ep[4];
	ep[4] = tmp;

	tmp = co[0];
	co[0] = co[3];
	co[3] = co[2];
	co[2] = co[1];
	co[1] = tmp;
}

void	Status::move_U2(){
	move_U();
	move_U();
}

void	Status::move_U3(){
	move_U2();
	move_U();
}


void	Status::move_F()
{
	tmp = cp[3];
	cp[3] = cp[7];
	cp[7] = cp[6];
	cp[6] = cp[2];
	cp[2] = tmp;

	tmp = ep[3];
	ep[3] = ep[10];
	ep[10] = ep[2];
	ep[2] = ep[6];
	ep[6] = tmp;

	tmp = co[3];
	co[3] = (co[7] + 2) % 3;
	co[7] = (co[6] + 1) % 3;
	co[6] = (co[2] + 2) % 3;
	co[2] = (tmp + 1) % 3;

	tmp = eo[6];
	eo[6] = (eo[3] + 1) % 2;
	eo[3] = (eo[10] + 1) % 2;
	eo[10] = (eo[2] + 1) % 2;
	eo[2] = (tmp + 1) % 2;
}

void	Status::move_F2(){
	move_F();
	move_F();
}

void	Status::move_F3(){
	move_F2();
	move_F();
}


void	Status::move_B()
{
	tmp = cp[0];
	cp[0] = cp[1];
	cp[1] = cp[5];
	cp[5] = cp[4];
	cp[4] = tmp;

	tmp = ep[4];
	ep[4] = ep[1];
	ep[1] = ep[8];
	ep[8] = ep[0];
	ep[0] = tmp;

	tmp = co[0];
	co[0] = (co[1] + 1) % 3;
	co[1] = (co[5] + 2) % 3;
	co[5] = (co[4] + 1) % 3;
	co[4] = (tmp + 2) % 3;

	tmp = eo[1];
	eo[1] = (eo[8] + 1) % 2;
	eo[8] = (eo[0] + 1) % 2;
	eo[0] = (eo[4] + 1) % 2;
	eo[4] = (tmp + 1) % 2;
}

void	Status::move_B2(){
	move_B();
	move_B();
}

void	Status::move_B3(){
	move_B2();
	move_B();
}

void	Status::move_str(std::string str){
	if (str == "R")
		move_R();
	else if (str == "R'")
		move_R3();
	else if (str == "R2")
		move_R2();
	else if (str == "D")
		move_D();
	else if (str == "D'")
		move_D3();
	else if (str == "D2")
		move_D2();
	else if (str == "U")
		move_U();
	else if (str == "U'")
		move_U3();
	else if (str == "U2")
		move_U2();
	else if (str == "L")
		move_L();
	else if (str == "L'")
		move_L3();
	else if (str == "L2")
		move_L2();
	else if (str == "F")
		move_F();
	else if (str == "F'")
		move_F3();
	else if (str == "F2")
		move_F2();
	else if (str == "B")
		move_B();
	else if (str == "B'")
		move_B3();
	else if (str == "B2")
		move_B2();
	else{
		std::cerr << "comannd error" << std::endl;
		std::exit(1);
	}
}