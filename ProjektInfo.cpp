#include <iostream>
#include <armadillo>
#include <vector>
#include "Classes.h"

int main()
{
	std::vector<arma::vec>a_;//3D Vector im Vector Array def
	arma::mat A(0,0);//0x0 Matrix zu def
	Alloy aA(0.8,0.2,0, "name",5);//test alloys
	Alloy bA(0.95,0.0,0.05, "name",5);
	Alloy cA(0.8,0.1,0.1, "name",5);
	Storage a;
	a.addAlloy(aA);
	a.addAlloy(bA);
	a.addAlloy(cA);
	for(auto i: a.getAlloys()){
		if(i.getName() == "name"){//ihr dann über eingabe entsprechenden Namen nehmen
			arma::vec vec_ = {i.getCopper(),i.getZinc(),i.getTin()};
			a_.push_back(vec_);//Packt Vector mit Kupfer usw in den Array
		}
	}

//	arma::vec b1 = {0.8,0.2,0};
//	arma::vec b2 = {0.95,0.0,0.05};
//	arma::vec b3 = {0.8,0.1,0.1};
//	arma::vec b4 = {0.8,0.2,0.0};
	arma::vec b5 = {0.9,0.05,0.05}; //var für Zielmischung

	int x_ =0;
	for(auto i: a_){
		A.insert_cols(0,i);//Vector wird in der Spalte nach in Zeilen gepackt: Vec1 füllt in der ersten Spalte die ganze Zeile usw;
		x_++;//Momentane pos;
	}

	arma::vec x = solve(A,b5);
	std::cout << x << std::endl;
	a.saveStorage("test",";"); //Lager read/save test;
	Storage b;
	b.readStorage("test", ";");

	for(auto i:b.getAlloys()){
		std::cout<<i.getCopper()<<"	"<<i.getZinc()<<"	"<<i.getTin()<<"	"<<i.getAmount()<<std::endl; // ausgabe Lager
	}

	return 0;
}
