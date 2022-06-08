
#include "Functions.h"

namespace functions{
std::vector<Supplier> readSupplierFile(std::string filename, std::string spacer) {
	std::vector<Supplier> vec_;
	unsigned int posCopper = 0;
	unsigned int posZinc = 0;
	unsigned int posTin = 0;
	unsigned int posName = 0;
	unsigned int posAmount = 0;
	unsigned int posFirmName = 0;
	unsigned int total_length = 0;
	char spacer_ = spacer[0];
	std::vector<std::string> pos = data::getHeaderText(spacer_, filename);
	unsigned int z = 0;
	for (auto i : pos) {
		z++;
		if (i == "Copper" || i == "Kupfer") {
			posCopper = z;
		} else if (i == "Zinc" || i == "Zink") {
			posZinc = z;

		} else if (i == "Tin" || i == " Zinn") {
			posTin = z;
		} else if (i == "Amount" || i == " Menge") {
			posAmount = z;
		} else if (i == "Name") {
			posName = z;
		} else if (i == "Firm") {
			posFirmName = z;
		}
		total_length = z;
	}
	std::vector<std::string> splitt = data::getBodyText(spacer_, filename);
	unsigned int split = 0;
	float copper = 0;
	float zinc = 0;
	float tin = 0;
	std::string name = "";
	float amount = 0;
	std::string firm = "";
	for (auto i : splitt) {
		split++;
		if (split == posCopper) {
			copper = std::stof(i);
		} else if (split == posZinc) {
			zinc = std::stof(i);
		} else if (split == posTin) {
			tin = std::stof(i);
		} else if (split == posName) {
			name = i;
		} else if (split == posAmount) {
			amount = std::stof(i);
		} else if (split == posFirmName) {
			firm = i;
		}

		if (split == total_length) {
			vec_.push_back(Supplier(Alloy(copper, zinc, tin, name, amount), firm));
			split = 0;
		}

	}
	return vec_;
}

bool isNumber(std::string number){
	unsigned int x = 0;
	unsigned int posCount = 0;
	unsigned int pos = 0;
	unsigned int le_ = 0;
	for(auto i:number){
		++posCount;
		if(i == '.'){
			x++;
			pos = posCount;
			le_++;
		}
		if(posCount !=pos && isdigit(i)){
			le_++;
		}
	}
	if(le_ == number.length() && x <=1)
		return true;
		else
			return false;
}
}


