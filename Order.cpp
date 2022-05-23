#include "Classes.h"

Order::Order(){
	amount = 0;
	firmName = "";
}

Order::Order(float amountIn, std::string firmNameIn){
	amount = amountIn;
	firmName = firmNameIn;
}

float Order::getAmount(){
	return this->amount;
}

std::string Order::getFirmName(){
	return this->firmName;
}

void Order::setAmount(float amountIn){
	this->amount = amountIn;
}

void Order::setFirmName(std::string firmNameIn){
	this->firmName = firmNameIn;
}



