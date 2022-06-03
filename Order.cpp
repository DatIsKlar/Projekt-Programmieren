#include "Classes.h"

Order::Order() {
	amount = 0;
	firmName = "";
	id = 0;
}

Order::Order(float amountIn, std::string firmNameIn, unsigned int idIn) {
	amount = amountIn;
	firmName = firmNameIn;
	id = idIn;
}

float Order::getAmount() {
	return this->amount;
}

std::string Order::getFirmName() {
	return this->firmName;
}

unsigned int Order::getId() {
	return this->id;
}

void Order::setAmount(float amountIn) {
	this->amount = amountIn;
}

void Order::setFirmName(std::string firmNameIn) {
	this->firmName = firmNameIn;
}

void Order::setId(unsigned int idIn) {
	this->firmName = idIn;
}

