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

std::vector<std::string> getTextData(std::string filename, std::string spacer, std::vector<std::string> search) {
	unsigned int total_length = 0;
	char spacer_ = spacer[0];
	std::vector<std::string> pos = getHeaderText(spacer_, filename);
	std::vector<unsigned int> pos_(pos.size());

	unsigned int z = 0;
	int start_val = -1;
	for (auto i : pos) {
		for (auto x : search) {
			if (i == x) {
				if (start_val == -1)
					start_val = z;

				pos_.at(z) = z;
			}
		}
		z++;
		total_length = z;
	}

	std::vector<std::string> splitt = getBodyText(spacer_, filename);
	unsigned int split = 0;
	std::vector<std::string> test;
	for (auto i : splitt) {
		unsigned int x_ = start_val;
		for (auto x : search) {
			if (split == pos_[x_]) {
				test.push_back(i);
			}
			x_++;
		}
		split++;
		if (split == total_length) {
			split = 0;
		}
	}

	std::vector<unsigned int> pos_search;
	for (auto i : pos) {
		unsigned int y = 0;
		for (auto x : search) {
			if (i == x) {
				pos_search.push_back(y);
			}
			y++;
		}
	}

	std::vector<int> delta_pos;
	unsigned int y_ = 0;
	for (auto i : search) {
		int delta = (int) pos_search.at(y_) - (int) pos_.at(y_);
		delta_pos.push_back(delta);
		y_++;
	}

	std::vector<std::string> sortet(test.size());
	unsigned int y_x = 0;
	int y_x_ = 0;
	for (auto i : test) {
		sortet.at(y_x_ + delta_pos.at(y_x)) = i;
		y_x++;
		if (y_x == delta_pos.size())
			y_x = 0;
		y_x_++;
	}
	return sortet;
}

}

