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

int Storage::getAlloyPosByType(const Alloy in) {
	unsigned int x = 0;
	for (auto i : this->alloy) {
		if (i == in) {
			return x;
		}
		x++;
	}
	return -1; //-1 ist ein fehler
}

void Storage::addAlloy(const Alloy alloy_i) {
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

bool Storage::removeAlloyByType(const Alloy alloyIn) {
	int x = this->getAlloyPosByType(alloyIn);
	if (x >= 0) {
		this->alloy.erase(this->alloy.begin() + x); // @suppress("Invalid arguments")
		return true;
	} else
		return false;
}


bool Storage::editAlloyByName(std::string namesIn, Alloy edit) {
	int x = this->getAlloyPosByName(namesIn);
	if (x >= 0) {
		this->alloy.at(x) = edit;
		return true;
	} else
		return false;

}

bool Storage::editAlloyByType(const Alloy alloyIn, Alloy edit) {
	int x = this->getAlloyPosByType(alloyIn);
	if (x >= 0) {
		this->alloy.at(x) = edit;
		return true;
	} else
		return false;

}


