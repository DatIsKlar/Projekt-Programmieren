#include "Functions.h"

namespace functions {

bool isNumber(std::string number) {
	try {
		std::string::size_type size;
		stoi(number, &size);
		if (size == number.length())
			return true;
		else {
			stof(number, &size);
			if (size == number.length())
				return true;
			else
				return false;
		}
	} catch (const std::invalid_argument &ia) {
		return false;
	}
}

bool isInt(float numberIn) {
	return (numberIn == static_cast<int>(numberIn));
}

int eingabe(int obereGrenze, std::string CC) {
	int b = -1;
	if (isNumber(CC)) {
		int ein = stoi(CC);
		if (ein < obereGrenze and ein >= 0)
			return ein;
	}
	return b;
}

bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup) {

	std::ofstream myfile;

	myfile.open(filename + ".csv");
	myfile << "Modus" + spacer + "Kupfer" + spacer + "Zink" + spacer + "Zinn" + spacer + "Name" + spacer + "Menge" + spacer + "Firmname" + spacer + "Strasse" + spacer + "Plz" +spacer + "Stadt" +spacer + "Kommentar" +"\n";

	for (auto x : sup) {
		Alloy i = x.getAlloy();
		char mode = 'x';
		if (i.getCopper() + i.getZinc() + i.getTin() == 1)
			mode = 'p';
		else if (i.getCopper() + i.getZinc() + i.getTin() == 100)
			mode = 'a';

		myfile
				<< mode + spacer + std::to_string(i.getCopper()) + spacer + std::to_string(i.getZinc()) + spacer + std::to_string(i.getTin()) + spacer + i.getName() + spacer
						+ std::to_string(i.getAmount()) + spacer + x.getName() + spacer + x.getStreet() + spacer + x.getZip() + spacer + x.getCity() + spacer + x.getComment();
		myfile << "\n";
	}

	myfile.close();
	return true;
}


}

