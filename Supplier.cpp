#include "Classes.h"
//test1

Supplier::Supplier() {
	alloy;
	order;
}

Supplier::Supplier(Alloy alloyIn, std::string nameIn) {
	alloy = alloyIn;
	order;
	this->setName(nameIn);
}

void Supplier::setOrder(Order orderIn) {
	this->order.push_back(orderIn);
}

std::vector<Order> Supplier::getOrder() {
	return this->order;
}

Alloy Supplier::getAlloy() {
	return this->alloy;
}

int Supplier::getOrderPosById(unsigned int idIn) {
	unsigned int x = 0;
	for (auto i : this->order) {
		if (i.getId() == idIn) {
			return x;
		}
		x++;
	}
	return -1;
}

bool Supplier::editOrderById(unsigned int idIn, Order edit) {
	int x = this->getOrderPosById(idIn);
	if (x >= 0) {
		this->order.at(x) = edit;
		return true;
	} else
		return false;

}

bool Supplier::removerOrderById(unsigned int idIn) {
	int x = this->getOrderPosById(idIn);
	if (x >= 0) {
		this->order.erase(this->order.begin() + x); // @suppress("Invalid arguments")
		return true;
	} else
		return false;
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

