#include "Classes.h"

Alloy::Alloy() {
	copper = 0;
	zinc = 0;
	tin = 0;
	name = "";
	amount = 0;
}

Alloy::Alloy(float copperIn, float zincIn, float tinIn, std::string nameIn,
		float amountIn) {

	float complet_value = copperIn + zincIn + tinIn;
	if ((complet_value > 1 || complet_value < 1)) {
		if (complet_value > 1
				&& (complet_value < 100 || complet_value > 100)) {
			//do error
		} else{
			copperIn /= 100;
			zincIn /= 100;
			tinIn /= 100;
		}
	}

	copper = copperIn;
	zinc = zincIn;
	tin = tinIn;
	name = nameIn;
	amount = amountIn;
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

bool Alloy::operator==(const Alloy &b){
	bool copper = this->copper == b.copper;
	bool zinc = this->zinc == b.zinc;
	bool tin = this->tin == b.tin;
	bool name = this->name == b.name;
	bool amount = this->amount == b.amount;

	if(copper && zinc&&tin&&name&&amount)
		return true;
	else
		return false;
}

bool Alloy::operator!=(const Alloy &b){
	bool copper = this->copper == b.copper;
	bool zinc = this->zinc == b.zinc;
	bool tin = this->tin == b.tin;
	bool name = this->name == b.name;
	bool amount = this->amount == b.amount;

	if(copper && zinc&&tin&&name&&amount)
		return false;
	else
		return true;
}

//void Alloy::normalize() {
//
//	if (this->mode == 'a') {
//		this->copper = this->copper / 100;
//		this->zinc = this->zinc / 100;
//		this->tin = this->tin / 100;
//	}
//
//	if (this->mode == 'x') {
//		if (this->copper + this->zinc + this->tin == 100) {
//			this->copper = this->copper / 100;
//			this->zinc = this->zinc / 100;
//			this->tin = this->tin / 100;
//		} else if (this->copper + this->zinc + this->tin != 100
//				&& this->copper + this->zinc + this->tin != 1) {
//			//error
//		}
//	}
//}

