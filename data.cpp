#include "Data.h"

namespace data {
std::vector<std::string> getHeaderText(char spacer, std::string filename) {
	std::ifstream myfile;
	std::string line;
	myfile.open(filename + ".csv");
	unsigned int x = 0;
	std::vector<std::string> pos;
	while (getline(myfile, line)) {
		x++;
		if (x == 1) {
			unsigned int j = 0;
			for (unsigned int i = 0; i < line.length(); i++) {
				if (line[i] == spacer) {
					std::string temp;
					for (unsigned int z = j; z < i; z++) {
						temp += line[z];
					}
					j = i + 1;
					pos.push_back(temp);
				}
				if (i == line.find_last_of(spacer)) {
					std::string temp;
					for (unsigned int z = i + 1; z < line.length(); z++) {
						temp += line[z];
					}
					pos.push_back(temp);
				}
			}
			return pos;
		}
	}
	myfile.close();
	return pos;
}

std::vector<std::string> getBodyText(char spacer, std::string filename) {
	std::ifstream myfile;
	std::string line;
	myfile.open(filename + ".csv");
	std::vector<std::string> splitt;
	unsigned int x = 0;
	while (getline(myfile, line)) {
		x++;
		if (x >= 2) {
			unsigned int j = 0;
			for (unsigned int i = 0; i < line.length(); i++) {
				if (line[i] == spacer) {
					std::string temp;
					for (unsigned int z = j; z < i; z++) {
						temp += line[z];
					}
					j = i + 1;
					splitt.push_back(temp);
				}
				if (i == line.find_last_of(spacer)) {
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
	return splitt;
}
}

