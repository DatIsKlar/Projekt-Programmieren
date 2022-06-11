#include "Data.h"

namespace data {
std::vector<std::string> getHeaderText(char spacer, std::string filename) {
	std::ifstream myfile;
	std::string line;
	myfile.open(filename + ".csv");
	unsigned int currentLine = 0;
	std::vector<std::string> headers;
	while (getline(myfile, line)) {
		currentLine++;
		if (currentLine == 1) {
			unsigned int j = 0;
			for (unsigned int i = 0; i < line.length(); i++) {
				if (line[i] == spacer) {
					std::string temp;
					for (unsigned int z = j; z < i; z++) {
						temp += line[z];
					}
					j = i + 1;
					headers.push_back(temp);
				}
				if (i == line.find_last_of(spacer)) {
					std::string temp;
					for (unsigned int z = i + 1; z < line.length(); z++) {
						temp += line[z];
					}
					headers.push_back(temp);
				}
			}
			return headers;
		}
	}
	myfile.close();
	return headers;
}

std::vector<std::string> getBodyText(char spacer, std::string filename) {
	std::ifstream myfile;
	std::string line;
	myfile.open(filename + ".csv");
	std::vector<std::string> body;
	unsigned int currentLine = 0;
	while (getline(myfile, line)) {
		currentLine++;
		if (currentLine >= 2) {
			unsigned int j = 0;
			for (unsigned int i = 0; i < line.length(); i++) {
				if (line[i] == spacer) {
					std::string temp;
					for (unsigned int z = j; z < i; z++) {
						temp += line[z];
					}
					j = i + 1;
					body.push_back(temp);
				}
				if (i == line.find_last_of(spacer)) {
					std::string temp;
					for (unsigned int z = i + 1; z < line.length(); z++) {
						temp += line[z];
					}
					body.push_back(temp);
				}
			}
		}
	}
	myfile.close();
	return body;
}

std::vector<std::string> getTextData(std::string filename, std::string spacer, std::vector<std::string> search) {
	unsigned int totalLength = 0;
	char spacer_ = spacer[0];
	std::vector<std::string> pos = getHeaderText(spacer_, filename);
	std::vector<unsigned int> pos_(pos.size());
	std::vector<unsigned int> posSearch;

	unsigned int currentPosition = 0;
	int startPos = -1;
	for (auto i : pos) {
		unsigned int y = 0;
		for (auto x : search) {
			if (i == x) {
				if (startPos == -1)
					startPos = currentPosition;

				posSearch.push_back(y);
				pos_.at(currentPosition) = currentPosition;
			}
			y++;
		}
		currentPosition++;
		totalLength = currentPosition;
	}


	std::vector<std::string> splitt = getBodyText(spacer_, filename);
	unsigned int splittPostition = 0;
	std::vector<std::string> valuesAfterFile;
	for (auto i : splitt) {
		unsigned int x_ = startPos;
		for (auto x : search) {
			if (splittPostition == pos_[x_]) {
				valuesAfterFile.push_back(i);
			}
			x_++;
		}
		splittPostition++;
		if (splittPostition == totalLength) {
			splittPostition = 0;
		}
	}

//	std::vector<unsigned int> posSearch;
//	for (auto i : pos) {
//		unsigned int y = 0;
//		for (auto x : search) {
//			if (i == x) {
//				posSearch.push_back(y);
//			}
//			y++;
//		}
//	}

	std::vector<int> delta_pos;
	for (unsigned int y_ = 0; y_ < posSearch.size(); y_++) {
		int delta = static_cast<int>(posSearch.at(y_)) - static_cast<int>(pos_.at(y_));
		delta_pos.push_back(delta);

	}

	std::vector<std::string> valuesAfterSearch(valuesAfterFile.size());
	unsigned int y_x = 0;
	int y_x_ = 0;
	for (auto i : valuesAfterFile) {
		valuesAfterSearch.at(y_x_ + delta_pos.at(y_x)) = i;
		y_x++;
		if (y_x == delta_pos.size())
			y_x = 0;
		y_x_++;
	}

	return valuesAfterSearch;
}

}

