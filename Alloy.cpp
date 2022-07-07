#include "Classes.h"

Alloy::Alloy() {
	copper = 0;
	zinc = 0;
	tin = 0;
	name = "";
	amount = 0;
}

Alloy::Alloy(float copperIn, float zincIn, float tinIn, std::string nameIn, float amountIn) {
	float complet_value = copperIn + zincIn + tinIn;
	if ((complet_value > 1 && complet_value == 100)) {
			copperIn /= 100;
			zincIn /= 100;
			tinIn /= 100;
	}
	copper = copperIn;
	zinc = zincIn;
	tin = tinIn;
	name = nameIn;
	amount = amountIn;
}

bool Alloy::isValidAlloy(){
	float complet_value = this->copper + this->zinc + this->tin;
	if(complet_value == 1 || complet_value ==100 ){
		return true;
	}
	else if(complet_value <0.999999){
		std::cout<<"Legierung : "<<this->name <<" nicht konform, Legierungsanteile insgesamt "<<complet_value<<" <100%"<<std::endl;
		return false;
	}else if(complet_value > 1 && complet_value != 100 ){
		std::cout<<"Legierung : "<<this->name <<" nicht konform, Legierungsanteile insgesamt "<<complet_value<<" >100%"<<std::endl;
		return false;
	}
	return true;
}
float Alloy::getCopper() {
	return this->copper;
}

float Alloy::getZinc() {
	return this->zinc;
}

float Alloy::getTin() {
	return this->tin;
}

std::string Alloy::getName() {
	return this->name;
}

float Alloy::getAmount() {
	return this->amount;
}

void Alloy::setAmount(float amountIn) {
	this->amount = amountIn;
}

bool Alloy::operator==(const Alloy &b) {
	bool copper = this->copper == b.copper;
	bool zinc = this->zinc == b.zinc;
	bool tin = this->tin == b.tin;
	bool name = this->name == b.name;
	//bool amount = this->amount == b.amount;

	if (copper && zinc && tin && name)//&amount
		return true;
	else
		return false;
}

bool Alloy::operator!=(const Alloy &b) {
	bool copper = this->copper == b.copper;
	bool zinc = this->zinc == b.zinc;
	bool tin = this->tin == b.tin;
	bool name = this->name == b.name;
	//bool amount = this->amount == b.amount;

	if (copper && zinc && tin && name)//&amount
		return false;
	else
		return true;
}

bool Alloy::operator%(const Alloy &b) {
	bool copper = this->copper == b.copper;
	bool zinc = this->zinc == b.zinc;
	bool tin = this->tin == b.tin;
	//bool name = this->name == b.name;
	//bool amount = this->amount == b.amount;

	if (copper && zinc && tin)//&amount
		return true;
	else
		return false;
}

void Alloy::print() {

	std::cout << this->copper << " " << this->zinc << " " << this->tin << " ";

}
