#include "Classes.h"

Storage::Storage() {
	alloy;
}

Storage::Storage(std::vector<Alloy> aI) {
	alloy = aI;
}

std::vector<Alloy> Storage::getAlloys() {
	return this->alloy;
}

int Storage::getAlloyPosByName(std::string alloyNameIn) {
	unsigned int x = 0;
	for (auto i : this->alloy) {
		if (i.getName() == alloyNameIn) {
			return x;
		}
		x++;
	}
	return -1; //-1 ist ein fehler
}

int Storage::getAlloyPosByType(Alloy &in) {
	unsigned int x = 0;
	for (auto i : this->alloy) {
		if (i == in) {
			return x;
		}
		x++;
	}
	return -1; //-1 ist ein fehler
}

void Storage::addAlloy(Alloy alloy_i) {
	this->alloy.push_back(alloy_i);
}

bool Storage::removeAlloyByName(std::string alloyNameIn) {
	int x = this->getAlloyPosByName(alloyNameIn);
	if (x >= 0) {
		this->alloy.erase(this->alloy.begin() + x); // @suppress("Invalid arguments")
		return true;
	} else
		return false;

}

bool Storage::removeAlloyByType(Alloy &alloyIn) {
	int x = this->getAlloyPosByType(alloyIn);
	if (x >= 0) {
		this->alloy.erase(this->alloy.begin() + x); // @suppress("Invalid arguments")
		return true;
	} else
		return false;
}

bool Storage::saveStorage(std::string filename, std::string spacer) {

	std::ofstream myfile;

	myfile.open(filename + ".csv");
	myfile << "Type" + spacer + "Copper" + spacer + "Zinc" + spacer + "Tin" + spacer + "Name" + spacer + "Amount" + "\n";
	for (Alloy i : this->alloy) {
		char mode = 'x';
		if (i.getCopper() + i.getZinc() + i.getTin() == 1)
			mode = 'p';
		else if (i.getCopper() + i.getZinc() + i.getTin() == 100)
			mode = 'a';

		myfile
				<< mode + spacer + std::to_string(i.getCopper()) + spacer + std::to_string(i.getZinc()) + spacer + std::to_string(i.getTin()) + spacer + i.getName() + spacer
						+ std::to_string(i.getAmount());
		myfile << "\n";
	}

	myfile.close();
	return true;
}

bool Storage::readStorage(std::string filename, std::string spacer) {
//	std::ifstream myfile;
//	myfile.open(filename + ".csv");
	std::vector<std::string> splitt;
	unsigned int posCopper = 0;
	unsigned int posZinc = 0;
	unsigned int posTin = 0;
	unsigned int posName = 0;
	unsigned int posAmount = 0;
	unsigned int posFirmName = 0;

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
	}
	splitt = data::getBodyText(spacer_, filename);
	unsigned int split = 0;
	unsigned int total_length = pos.size();
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
			this->alloy.push_back(Alloy(copper, zinc, tin, name, amount));
			split = 0;
		}

	}
	return true;
}

std::vector<float> Storage::makeAlloyMix(std::vector<std::string> namesIn, Alloy &wantedIn) {
	std::vector<arma::vec> vec_;
	std::vector<float> returnAmount;
	arma::mat Gauss(0, 0);
	for (auto i : namesIn) {
		unsigned int a_ = this->getAlloyPosByName(i);
		arma::vec alloyNew = { this->alloy.at(a_).getCopper(), this->alloy.at(a_).getZinc(), this->alloy.at(a_).getTin() };
		vec_.push_back(alloyNew);
	}

	arma::vec wanted = { wantedIn.getCopper(), wantedIn.getZinc(), wantedIn.getTin() }; //var f�r Zielmischung
	int x_ = 0;
	for (auto i : vec_) {
		Gauss.insert_cols(0, i); //Vector wird in der Spalte nach in Zeilen gepackt: Vec1 f�llt in der ersten Spalte die ganze Zeile usw;
		x_++; //Momentane pos;
	}

	arma::vec solution = solve(Gauss, wanted);
	int f = 0;
	for (auto i : namesIn) {
		unsigned int a_ = this->getAlloyPosByName(i);
		float finalAmount = this->alloy.at(a_).getAmount() - solution[f] * wantedIn.getAmount();
		f++;
		if (finalAmount >= 0)
			this->alloy.at(a_).setAmount(finalAmount); //setzten der neuen Menge im Lager
		//else
		//error

		returnAmount.push_back(solution[f]);
	}
	return returnAmount;

}

bool Storage::editAlloyByName(std::string namesIn, Alloy edit) {
	unsigned int x = this->getAlloyPosByName(namesIn);
	if (x >= 0) {
		this->alloy.at(x) = edit;
		return true;
	} else
		return false;

}

bool Storage::editAlloyByType(Alloy alloyIn, Alloy edit) {
	unsigned int x = this->getAlloyPosByType(alloyIn);
	if (x >= 0) {
		this->alloy.at(x) = edit;
		return true;
	} else
		return false;

}

