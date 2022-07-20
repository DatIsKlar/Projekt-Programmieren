#include "Data.h"

namespace data {
bool fileExists(std::string filename) {
	std::ifstream myfile;
	myfile.open(filename);
	if (myfile)
		return true;
	else
		return false;
}


std::vector<std::string> getText(char spacer, std::string filename, unsigned int startLine, unsigned int endLine){
	std::ifstream myfile;
	std::string line;
	myfile.open(filename);
	std::vector<std::string> text;
	unsigned int currentLine = 0;
	while (getline(myfile, line)) {
		currentLine++;
		if (currentLine >= startLine and currentLine <= endLine) {
			unsigned int j = 0;
			for (unsigned int i = 0; i < line.length(); i++) {
				if (line[i] == spacer) {
					std::string temp;
					for (unsigned int z = j; z < i; z++) {
						temp += line[z];
					}
					j = i + 1;
					text.push_back(temp);
				}
				if (i == line.find_last_of(spacer)) {
					std::string temp;
					for (unsigned int z = i + 1; z < line.length(); z++) {
						temp += line[z];
					}
					text.push_back(temp);
				}
			}
		}
	}
	myfile.close();
	return text;
}

std::vector<std::string> getTextData(std::string filename, std::string spacer, std::vector<std::string> search) {
	unsigned int totalLength = 0;
	char spacer_ = spacer[0];
	std::vector<std::string> textHeader = getText(spacer_, filename,1,1);
	std::vector<std::string> textBody = getText(spacer_, filename,2,0xffffffff);

	std::vector<unsigned int> pos_(textHeader.size());
	std::vector<unsigned int> posSearch;
	unsigned int currentPosition = 0;
	int startPos = -1;
	for (auto i : textHeader) {
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

	if(posSearch.size() != search.size()){
		std::vector<std::string> a = {"false"};
		return a;
	}

	unsigned int splittPostition = 0;
	std::vector<std::string> valuesAfterFile;
	for (auto i : textBody) {
		for(unsigned int x_ = startPos; x_ <pos_.size(); x_++){
			if (splittPostition == pos_.at(x_)) {
				valuesAfterFile.push_back(i);
			}
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

