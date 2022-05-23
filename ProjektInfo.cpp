#include <iostream>
#include <armadillo>
#include <vector>
#include "Classes.h"

int main()
{
	std::vector<arma::vec>a_;
	arma::mat A(0,0);
	Alloy aA(0.8,0.2,0, "name",5);
	Alloy bA(0.95,0.0,0.05, "name",5);
	Alloy cA(0.8,0.1,0.1, "name",5);
	Storage a;
	a.addAlloy(aA);
	a.addAlloy(bA);
	a.addAlloy(cA);
	for(auto i: a.getAlloys()){
		if(i.getName() == "name"){
			arma::vec vec_ = {i.getCopper(),i.getZinc(),i.getTin()};
			a_.push_back(vec_);
		}
	}

//	arma::vec b1 = {0.8,0.2,0};
//	arma::vec b2 = {0.95,0.0,0.05};
//	arma::vec b3 = {0.8,0.1,0.1};
//	arma::vec b4 = {0.8,0.2,0.0};
	arma::vec b5 = {0.9,0.05,0.05};

	int x_ =0;
	for(auto i: a_){
		A.insert_cols(0,i);
		x_++;
	}

	arma::vec x = solve(A,b5);
	std::cout << x << std::endl; // double Matrix-Multiplikation ausführe
	a.saveStorage("test",";");
	Storage b;
	b.readStorage("test", ";");

	for(auto i:b.getAlloys()){
		//std::cout<<i.getCopper()<<"	"<<i.getZinc()<<"	"<<i.getTin()<<"	"<<i.getAmount()<<std::endl;
	}

	return 0;
}
