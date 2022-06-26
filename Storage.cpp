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

int Storage::getAlloyPosByType(Alloy in) {
	unsigned int x = 0;
	for (auto i : this->alloy) {
		if (i == in) {
			return x;
		}
		x++;
	}
	return -1; //-1 ist ein fehler
}

void Storage::addAlloy(const Alloy &alloy_i) {
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
	myfile << "Modus" + spacer + "Kupfer" + spacer + "Zink" + spacer + "Zinn" + spacer + "Name" + spacer + "Menge" + "\n";
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
	std::vector<std::string> search = { "Copper", "Zinc", "Tin", "Name", "Amount" };
	std::vector<std::string> data_ = data::getTextData(filename, spacer, search);
	if(data_.size() == 1)
		if(data_.at(0) == "false")
			return false;

	for (unsigned int x = 0; x < data_.size(); x += search.size()) {
		if (x % search.size() == 0) {
			try {
				this->alloy.push_back(Alloy(std::stof(data_.at(x)), std::stof(data_.at(x + 1)), std::stof(data_.at(x + 2)), data_.at(x + 3), std::stof(data_.at(x + 4))));
			} catch (const std::invalid_argument &ia) {
				return false;
			}catch(const std::out_of_range  &ia){
				return false;
			}
		}
	}
	return true;
}

bool Storage::editAlloyByName(std::string namesIn, Alloy edit) {
	int x = this->getAlloyPosByName(namesIn);
	if (x >= 0) {
		this->alloy.at(x) = edit;
		return true;
	} else
		return false;

}

bool Storage::editAlloyByType(Alloy alloyIn, Alloy edit) {
	int x = this->getAlloyPosByType(alloyIn);
	if (x >= 0) {
		this->alloy.at(x) = edit;
		return true;
	} else
		return false;

}


