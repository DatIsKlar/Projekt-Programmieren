#include "Classes.h"

Order::Order() {
	amount = 0;
	firm;
}

Order::Order(float amountIn, Firm firmaIn) {
	amount = amountIn;
	firm = firmaIn;
}

float Order::getAmount() {
	return this->amount;
}

Firm Order::getFirm() {
	return this->firm;
}

void Order::setAmount(float amountIn) {
	this->amount = amountIn;
}

void Order::setFirmName(Firm firmaIn) {
	this->firm = firmaIn;
}

