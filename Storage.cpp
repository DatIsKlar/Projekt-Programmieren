#include "Classes.h"
#include <fstream>
#include <sstream>

Storage::Storage() {
	alloy;
}

Storage::Storage(std::vector<Alloy> aI) {
	alloy= aI;
}

std::vector<Alloy> Storage::getAlloys() {
	return this->alloy;
}

int Storage::getAlloyPosByName(std::string alloyNameIn) {
	unsigned int x=0;
	for (auto i : this->alloy) {
		if (i.getName() == alloyNameIn) {
			return x;
		}
		x++;
	}
	return -1;
}

int Storage::getAlloyPosByType(Alloy in){
	unsigned int x=0;
	for (auto i : this->alloy) {
		if (i == in) {
			return x;
		}
		x++;
	}
	return -1;
}

void Storage::addAlloy(Alloy alloy_i) {
	this->alloy.push_back(alloy_i);
}

void Storage::removeAlloyByName(std::string alloyNameIn) {
	int x = this->getAlloyPosByName(alloyNameIn);
	if(x>=0)
		this->alloy.erase(this->alloy.begin()+x); // @suppress("Invalid arguments")
}

void Storage::removeAlloyByType(Alloy alloyIn) {
	int x = this->getAlloyPosByType(alloyIn);
	if(x>=0)
		this->alloy.erase(this->alloy.begin()+x); // @suppress("Invalid arguments")
}

bool Storage::saveStorage(std::string filename, std::string spacer) {

	std::ofstream myfile;

	myfile.open(filename + ".csv");
	myfile
			<< "Type" + spacer + "Copper" + spacer + "Zinc" + spacer + "Tin"
					+ spacer + "Name" + spacer + "Amount" + "\n";
	for (Alloy i : this->alloy) {
		char mode = 'x';
		if (i.getCopper() + i.getZinc() + i.getTin() == 1)
			mode = 'p';
		else if (i.getCopper() + i.getZinc() + i.getTin() == 100)
			mode = 'a';

		myfile
				<< mode + spacer + std::to_string(i.getCopper()) + spacer
						+ std::to_string(i.getZinc()) + spacer
						+ std::to_string(i.getTin()) + spacer + i.getName()
						+ spacer + std::to_string(i.getAmount());
		myfile << "\n";
	}

	myfile.close();
	return true;
}

bool Storage::readStorage(std::string filename, std::string spacer) {
	std::ifstream myfile;
	myfile.open(filename + ".csv");
	std::string line;
	int x = 0;
	std::vector<std::string> splitt;
	unsigned int pos_copper = 0;
	unsigned int pos_zinc = 0;
	unsigned int pos_tin = 0;
	unsigned int pos_name = 0;
	unsigned int pos_amount = 0;
	unsigned int pos_firm_name = 0;
	unsigned int total_lenthg = 0;
	char spacer_ = spacer[0];
	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			x++;
			if (x == 1) {
				unsigned int j = 0;
				std::vector<std::string> pos;
				for (unsigned int i = 0; i < line.length(); i++) {
					if (line[i] == spacer_) {
						std::string temp;
						for (unsigned int z = j; z < i; z++) {
							temp += line[z];
						}
						j = i + 1;
						pos.push_back(temp);
					}
					if (i == line.find_last_of(spacer_)) {
						std::string temp;
						for (unsigned int z = i + 1; z < line.length(); z++) {
							temp += line[z];
						}
						pos.push_back(temp);
					}

				}
				unsigned int z = 0;
				for (auto i : pos) {
					z++;
					if (i == "Copper" || i == "Kupfer") {
						pos_copper = z;
					} else if (i == "Zinc" || i == "Zink") {
						pos_zinc = z;

					} else if (i == "Tin" || i == " Zinn") {
						pos_tin = z;
					} else if (i == "Amount" || i == " Menge") {
						pos_amount = z;
					} else if (i == "Name") {
						pos_name = z;
					} else if (i == "Firm") {
						pos_firm_name = z;
					}
					total_lenthg = z;
				}

			}
			if (x >= 2) {
				unsigned int j = 0;
				for (unsigned int i = 0; i < line.length(); i++) {
					if (line[i] == spacer_) {
						std::string temp;
						for (unsigned int z = j; z < i; z++) {
							temp += line[z];
						}
						j = i + 1;
						splitt.push_back(temp);
					}
					if (i == line.find_last_of(spacer_)) {
						std::string temp;
						for (unsigned int z = i + 1; z < line.length(); z++) {
							temp += line[z];
						}
						splitt.push_back(temp);
					}
				}
			}

		}
		myfile.close();
		unsigned int split = 0;
		float copper = 0;
		float zinc = 0;
		float tin = 0;
		std::string name = "";
		float amount = 0;
		std::string firm = "";
		for (auto i : splitt) {
			split++;
			if (split == pos_copper) {
				copper = std::stof(i);
			} else if (split == pos_zinc) {
				zinc = std::stof(i);
			} else if (split == pos_tin) {
				tin = std::stof(i);
			} else if (split == pos_name) {
				name = i;
			} else if (split == pos_amount) {
				amount = std::stof(i);
			} else if (split == pos_firm_name) {
				firm = i;
			}

			if (split == total_lenthg) {
				this->alloy.push_back(Alloy(copper, zinc, tin, name, amount));
				split = 0;
			}

		}
	}
	return true;
}

void Storage::makeAlloyMix(std::vector<std::string> namesIn, Alloy &wantedIn) {
	std::vector<arma::vec> vec_;
	arma::mat Gauss(0, 0);
	for (auto i : namesIn) {
		unsigned int a_ = this->getAlloyPosByName(i);
		arma::vec alloyNew = { this->alloy.at(a_).getCopper(),this->alloy.at(a_).getZinc(), this->alloy.at(a_).getTin() };
		vec_.push_back(alloyNew);
	}

	arma::vec wanted = { wantedIn.getCopper(), wantedIn.getZinc(),
			wantedIn.getTin() }; //var f�r Zielmischung
	int x_ = 0;
	for (auto i : vec_) {
		Gauss.insert_cols(0, i); //Vector wird in der Spalte nach in Zeilen gepackt: Vec1 f�llt in der ersten Spalte die ganze Zeile usw;
		x_++; //Momentane pos;
	}

	arma::vec solution = solve(Gauss, wanted);
	int f = 0;
	for (auto i : namesIn) {
		unsigned int a_ = this->getAlloyPosByName(i);
		float finalAmount = this->alloy.at(a_).getAmount()-solution[f]*wantedIn.getAmount();
		f++;
		if(finalAmount<0)
			this->alloy.at(a_).setAmount(finalAmount);//setzten der neuen Menge im Lager
		//else
			//error
	}
}

void Storage::editAlloyByName(std::string namesIn ,Alloy edit){
	this->alloy.at(this->getAlloyPosByName(namesIn)) = edit;
}

void Storage::editAlloyByType(Alloy alloyIn ,Alloy edit){
	this->alloy.at(this->getAlloyPosByType(alloyIn)) = edit;
}





