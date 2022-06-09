#include "Functions.h"

namespace functions {

bool isNumber(std::string number) {
//	unsigned int x = 0;
//	unsigned int posCount = 0;
//	unsigned int pos = 0;
//	unsigned int le_ = 0;
//	for (auto i : number) {
//		++posCount;
//		if (i == '.') {
//			x++;
//			pos = posCount;
//			le_++;
//		}
//		if (posCount != pos && isdigit(i)) {
//			le_++;
//		}
//	}
//	if (le_ == number.length() && x <= 1)
//		return true;
//	else
//		return false;

	try {
		std::string::size_type size;
		stoi(number, &size);
		if (size == number.length())
			return true;
		else {
			stof(number, &size);
			if (size)
				return true;
			else
				return false;
		}
	} catch (const std::invalid_argument &ia) {
		return false;
	}
}

}

