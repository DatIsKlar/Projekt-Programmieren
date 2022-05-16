
#include <vector>
#include <iostream>
#include "Classes.h"
#include <fstream>


int main()
{
	Alloy aA(0.5, 0.5, 0.0, "test1",5);
	Alloy bA(30, 30, 40, "test2",5);
	Alloy dA(30, 30, 40, "test2",5);
	Storage a;
	a.addAlloy(aA);
	a.addAlloy(bA);
	a.saveStorage("test",";");
	Storage b;
	b.readStorage("test", ";");
	for(auto i:b.getAlloys()){
		std::cout<<i.getCopper()<<"	"<<i.getZinc()<<"	"<<i.getTin()<<"	"<<i.getAmount()<<std::endl;
	}

	return 0;
}
