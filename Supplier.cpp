#include "Classes.h"
//test1
Supplier::Supplier(){
	alloy;
}

Supplier::Supplier(Alloy alloyIn){
	alloy = alloyIn;
}

void Supplier::setOrder(Order orderIn){
		this->order.push_back(orderIn);
}

std::vector<Order> Supplier::getOrder(){
		return this->order;
}

Alloy Supplier::getAlloy(){
	return this->alloy;
}
