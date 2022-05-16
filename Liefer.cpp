#include "Classes.h"
//test2
Liefer::Liefer(){
	alloy;
	order = 0;
}

Liefer::Liefer(Alloy alloyIn, float orderIn){
	alloy = alloyIn;
	order = orderIn;
}

void Liefer::getOrder(float orderIn){
		this->order = orderIn;
		float delta = this->alloy.getAmount()-orderIn;
		if(delta >=0)
			this->alloy.setAmount(delta);
		//else
			//error
}


Alloy Liefer::returnOrder(){
	this->alloy.setAmount( this->order);
	return this->alloy;
}

