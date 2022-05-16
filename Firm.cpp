#include "Classes.h"
#include <string>
#include <iostream>

Firm::Firm() {
	name = "";
	adress = "";
}

Firm::Firm(std::string nameIn, std::string adressIn) {
	name = nameIn;
	adress = adressIn;
}

std::string Firm::getName() {
	return this->name;
}

std::string Firm::getAdress() {
	return this->adress;
}

void Firm::setName(std::string nameIn) {
	this->name = nameIn;
}

void Firm::setAdress(std::string adressIn) {
	this->adress = adressIn;
}

