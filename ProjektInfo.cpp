#include <iostream>
#include <armadillo>
#include <vector>
#include "Classes.h"


int main()
{

	std::vector<arma::vec>a_;//3D Vector im Vector Array def
	arma::mat A(0,0);//0x0 Matrix zu def
	Alloy aA(0.8,0.2,0, "name",5);//test alloys
	Alloy bA(0.95,0.0,0.05, "test",5);
	Alloy cA(0.8,0.1,0.1, "better",5);
	Alloy dA(0.7,0.3,0.0, "better2",5);
	Storage a;
	Alloy wanted(0.9,0.05,0.05,"test2",5);
	a.addAlloy(aA);
	a.addAlloy(bA);
	a.addAlloy(cA);
	//a.editAlloyByType(bA ,Alloy(0.8,0.1,0.1, "better2",5));
	a.removeAlloyByType(bA);
	Supplier b(aA);

	b.setOrder(Order(20,"test",1));
	b.setOrder(Order(10,"test2",2));
	b.printOrder();

	return 0;
}
