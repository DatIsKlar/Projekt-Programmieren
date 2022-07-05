#include "Classes.h"
//test1

Supplier::Supplier() {
	alloy;
	order;
	this->setName("");
	this->setStreet("");
	this->setZip("");
	this->setCity("");
	this->setComment("");
}

Supplier::Supplier(Alloy alloyIn, std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn) {
	alloy = alloyIn;
	order;
	this->setName(nameIn);
	this->setStreet(streetIn);
	this->setZip(zipIn);
	this->setCity(cityIn);
	this->setComment(commentIn);
}

void Supplier::setOrder(Order orderIn) {
	this->order.push_back(orderIn);
}

void Supplier::setAlloy(Alloy alloyIn) {
	this->alloy = alloyIn;
}

std::vector<Order> Supplier::getOrder() {
	return this->order;
}

Alloy Supplier::getAlloy() {
	return this->alloy;
}

//void Supplier::printOrder(){
//	std::cout<<"Legierung	"<<"Namen	"<<"Menge	"<<"Id"<<std::endl;
//
//	for(auto i: this->order){
//		std::cout<<this->alloy.getCopper()<<"	"<<i.getFirmName()<<"	"<<i.getAmount()<<"	"<<i.getId()<<std::endl;
//		std::cout<<this->alloy.getZinc()<<std::endl;
//		std::cout<<this->alloy.getTin()<<std::endl;
//	}
//}

