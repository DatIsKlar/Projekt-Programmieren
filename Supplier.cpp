#include "Classes.h"
//test1
Supplier::Supplier(){
	alloy;
	order;
}

Supplier::Supplier(Alloy alloyIn){
	alloy = alloyIn;
	order;
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

int Supplier::getOrderPosById(unsigned int idIn){
	unsigned int x=0;
	for (auto i : this->order) {
		if (i.getId() == idIn) {
			return x;
		}
		x++;
	}
	return -1;
}

void Supplier::editOrderById(unsigned int idIn, Order edit){
	this->order.at(this->getOrderPosById(idIn)) = edit;
}

void Supplier::removerOrderById(unsigned int idIn){
	this->order.erase(this->order.begin()+this->getOrderPosById(idIn));
}

void Supplier::printOrder(){
	std::cout<<"Legierung	"<<"Namen	"<<"Menge	"<<"Id"<<std::endl;

	for(auto i: this->order){
		std::cout<<this->alloy.getCopper()<<"	"<<i.getFirmName()<<"	"<<i.getAmount()<<"	"<<i.getId()<<std::endl;
		std::cout<<this->alloy.getZinc()<<std::endl;
		std::cout<<this->alloy.getTin()<<std::endl;
	}
}
//bool Supplier::saveStorage(std::string filename, std::string spacer) {
//
//	std::ofstream myfile;
//
//	myfile.open(filename + ".csv");
//	myfile
//			<< "Type" + spacer + "Copper" + spacer + "Zinc" + spacer + "Tin"
//					+ spacer + "Name" + spacer + "Amount" + "\n";
//	for (auto i : this->alloy) {
//		char mode = 'x';
//		if (i.getCopper() + i.getZinc() + i.getTin() == 1)
//			mode = 'p';
//		else if (i.getCopper() + i.getZinc() + i.getTin() == 100)
//			mode = 'a';
//
//		myfile
//				<< mode + spacer + std::to_string(i.getCopper()) + spacer
//						+ std::to_string(i.getZinc()) + spacer
//						+ std::to_string(i.getTin()) + spacer + i.getName()
//						+ spacer + std::to_string(i.getAmount());
//		myfile << "\n";
//	}
//
//	myfile.close();
//	return true;
//}
//
//bool Supplier::readStorage(std::string filename, std::string spacer) {
//	std::ifstream myfile;
//	myfile.open(filename + ".csv");
//	std::string line;
//	int x = 0;
//	std::vector<std::string> splitt;
//	unsigned int pos_copper = 0;
//	unsigned int pos_zinc = 0;
//	unsigned int pos_tin = 0;
//	unsigned int pos_name = 0;
//	unsigned int pos_amount = 0;
//	unsigned int pos_firm_name = 0;
//	unsigned int total_lenthg = 0;
//	char spacer_ = spacer[0];
//	if (myfile.is_open()) {
//		while (getline(myfile, line)) {
//			x++;
//			if (x == 1) {
//				unsigned int j = 0;
//				std::vector<std::string> pos;
//				for (unsigned int i = 0; i < line.length(); i++) {
//					if (line[i] == spacer_) {
//						std::string temp;
//						for (unsigned int z = j; z < i; z++) {
//							temp += line[z];
//						}
//						j = i + 1;
//						pos.push_back(temp);
//					}
//					if (i == line.find_last_of(spacer_)) {
//						std::string temp;
//						for (unsigned int z = i + 1; z < line.length(); z++) {
//							temp += line[z];
//						}
//						pos.push_back(temp);
//					}
//
//				}
//				unsigned int z = 0;
//				for (auto i : pos) {
//					z++;
//					if (i == "Copper" or i == "Kupfer") {
//						pos_copper = z;
//					} else if (i == "Zinc" or i == "Zink") {
//						pos_zinc = z;
//
//					} else if (i == "Tin" or i == " Zinn") {
//						pos_tin = z;
//					} else if (i == "Amount" or i == " Menge") {
//						pos_amount = z;
//					} else if (i == "Name") {
//						pos_name = z;
//					} else if (i == "Firm") {
//						pos_firm_name = z;
//					}
//					total_lenthg = z;
//				}
//
//			}
//			if (x >= 2) {
//				unsigned int j = 0;
//				for (unsigned int i = 0; i < line.length(); i++) {
//					if (line[i] == spacer_) {
//						std::string temp;
//						for (unsigned int z = j; z < i; z++) {
//							temp += line[z];
//						}
//						j = i + 1;
//						splitt.push_back(temp);
//					}
//					if (i == line.find_last_of(spacer_)) {
//						std::string temp;
//						for (unsigned int z = i + 1; z < line.length(); z++) {
//							temp += line[z];
//						}
//						splitt.push_back(temp);
//					}
//				}
//			}
//
//		}
//		myfile.close();
//		unsigned int split = 0;
//		float copper = 0;
//		float zinc = 0;
//		float tin = 0;
//		std::string name = "";
//		float amount = 0;
//		std::string firm = "";
//		for (auto i : splitt) {
//			split++;
//			if (split == pos_copper) {
//				copper = std::stof(i);
//			} else if (split == pos_zinc) {
//				zinc = std::stof(i);
//			} else if (split == pos_tin) {
//				tin = std::stof(i);
//			} else if (split == pos_name) {
//				name = i;
//			} else if (split == pos_amount) {
//				amount = std::stof(i);
//			} else if (split == pos_firm_name) {
//				firm = i;
//			}
//
//			if (split == total_lenthg) {
//				this->alloy.push_back(Alloy(copper, zinc, tin, name, amount));
//				split = 0;
//			}
//
//		}
//	}
//	return true;
//}
