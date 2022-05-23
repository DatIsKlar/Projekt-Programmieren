#include "Classes.h"

Firm::Firm() {
	name = "";
	street = "";
	zip = "";
	city = "";
	comment = "";
}

Firm::Firm(std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn) {
	name = nameIn;
	street = streetIn;
	zip = zipIn;
	city = cityIn;
	comment = commentIn;

}

std::string Firm::getName() {
	return this->name;
}

std::string Firm::getStreet() {
	return this->street;
}

std::string Firm::getZip() {
	return this->zip;
}

std::string Firm::getCity() {
	return this->city;
}

std::string Firm::getComment() {
	return this->comment;
}

void Firm::setName(std::string nameIn) {
	this->name = nameIn;
}

void Firm::setStreet(std::string streetIn) {
	this->street = streetIn;
}

void Firm::setZip(std::string zipIn) {
	this->zip = zipIn;
}

void Firm::setCity(std::string cityIn) {
	this->city = cityIn;
}

void Firm::setComment(std::string commentIn) {
	this->comment = commentIn;
}


