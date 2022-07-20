#include "Classes.h"

Alloy::Alloy() {
	copper = 0;
	zinc = 0;
	tin = 0;
	name = "";
	amount = 0;
}

Alloy::Alloy(float copperIn, float zincIn, float tinIn, std::string nameIn, float amountIn) {
	float complet_value = copperIn + zincIn + tinIn;
	if (complet_value > 1.0001 && functions::clampFloat(complet_value, 100, 0.0001)) {
			copperIn /= 100;
			zincIn /= 100;
			tinIn /= 100;
	}
	copper = copperIn;
	zinc = zincIn;
	tin = tinIn;
	name = nameIn;
	amount = amountIn;
}

bool Alloy::isValidAlloy(){
    float complet_value = this->copper + this->zinc + this->tin;
    if(functions::clampFloat(complet_value, 1, 0.0001) ||  functions::clampFloat(complet_value, 100, 0.0001) ){
        return true;
    }
    else if(complet_value <0.9999){
        std::cout<<"Legierung : "<<this->name <<" nicht konform, Legierungsanteile insgesamt "<<complet_value*100<<"%, dies ist ungleich 100%"<<std::endl;
        return false;
    }else if(complet_value > 1.0001 && !functions::clampFloat(complet_value, 100, 0.0001) ){
        std::cout<<"Legierung : "<<this->name <<" nicht konform, Legierungsanteile insgesamt "<<complet_value<<"%, dies ist ungleich 100%"<<std::endl;
        return false;
    }
    return true;
}
float Alloy::getCopper() {
	return this->copper;
}

float Alloy::getZinc() {
	return this->zinc;
}

float Alloy::getTin() {
	return this->tin;
}

std::string Alloy::getName() {
	return this->name;
}

float Alloy::getAmount() {
	return this->amount;
}

void Alloy::setAmount(float amountIn) {
	this->amount = amountIn;
}

bool Alloy::operator==(const Alloy &b) {
	bool copper = this->copper == b.copper;
	bool zinc = this->zinc == b.zinc;
	bool tin = this->tin == b.tin;
	bool name = this->name == b.name;
	//bool amount = this->amount == b.amount;

	if (copper && zinc && tin && name)//&amount
		return true;
	else
		return false;
}

bool Alloy::operator!=(const Alloy &b) {
	bool copper = this->copper == b.copper;
	bool zinc = this->zinc == b.zinc;
	bool tin = this->tin == b.tin;
	bool name = this->name == b.name;
	//bool amount = this->amount == b.amount;

	if (copper && zinc && tin && name)//&amount
		return false;
	else
		return true;
}

bool Alloy::operator%(const Alloy &b) {
	bool copper = this->copper == b.copper;
	bool zinc = this->zinc == b.zinc;
	bool tin = this->tin == b.tin;
	//bool name = this->name == b.name;
	//bool amount = this->amount == b.amount;

	if (copper && zinc && tin)//&amount
		return true;
	else
		return false;
}
std::vector<float> Alloy::makeAlloyMix(std::vector<Alloy> alloyIn){
		std::vector<arma::vec> vec_;
		std::vector<float> returnAmount;
		bool check = false;
		Alloy myAlloy(this->copper, this->zinc, this->tin, this->name, this->amount);
		if(alloyIn.size() == 1){
			if(alloyIn.at(0)%myAlloy){
				returnAmount.push_back(1);
			}else{
				returnAmount.clear();
			}
			return returnAmount;
		}else{
			for (auto i : alloyIn) {
				arma::vec alloyNew = { i.getCopper(), i.getZinc(), i.getTin() };
				vec_.push_back(alloyNew);
				if(i%myAlloy){
					returnAmount.push_back(1);
					check = true;
				}else
					returnAmount.push_back(0);
			}
			if(check)
				return returnAmount;
			else
				returnAmount.clear();
		}

		int size = 0;
		if (vec_.size() < 2)
			size = 2;
		else if (vec_.size() < 3 && vec_.size() == 2)
			size = 1;

		arma::mat Gauss(3, size, arma::fill::zeros);
		arma::vec wanted = { this->copper, this->zinc, this->tin }; //var fuer Zielmischung
		for (auto i : vec_) {
			Gauss.insert_cols(0, i); //Vector wird in der Spalte nach in Zeilen gepackt: Vec1 fuellt in der ersten Spalte die ganze Zeile usw;
		}
		arma::vec solution;
	//	try{
	//		solution = solve(Gauss, wanted);
	//	}catch(std::runtime_error &i){
	//
	//	}
		bool status = solve(solution, Gauss, wanted);
		int f = solution.size()-1;
		if(!status){
			returnAmount.clear();
			return returnAmount;
		}

		for (auto i : alloyIn) {
			if (solution[f-size] > -1e-5 and solution[f-size]<0) {
				solution[f-size] = 0;
			}else if (solution[f-size] < 1e-5 and solution[f-size]>0) {
				solution[f-size] = 0;

			}else if(solution[f-size]<-1e-5){
				returnAmount.clear();
				break;
			}else if(solution[f-size]>1){
				returnAmount.clear();
				break;
			}
			returnAmount.push_back(solution[f-size]);
			f--;
		}
		return returnAmount;
}

void Alloy::print() {

	std::cout << this->copper << " " << this->zinc << " " << this->tin << " ";

}
