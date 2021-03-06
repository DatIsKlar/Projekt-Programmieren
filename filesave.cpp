#include "Filesave.h"

namespace filesave {

bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup) {

	std::ofstream myfile;

	myfile.open(filename + ".csv");
	myfile << "Modus" + spacer + "Kupfer" + spacer + "Zink" + spacer + "Zinn" + spacer + "Name" + spacer + "Menge" + spacer + "Firmname" + spacer + "Strasse" + spacer + "Plz" + spacer + "Stadt" + spacer + "Kommentar" + "\n";

	for (auto x : sup) {
		Alloy i = x.getAlloy();
		char mode = 'x';
		if (i.getCopper() + i.getZinc() + i.getTin() == 1)
			mode = 'p';
		else if (i.getCopper() + i.getZinc() + i.getTin() == 100)
			mode = 'a';

		myfile
				<< mode + spacer + std::to_string(i.getCopper()) + spacer + std::to_string(i.getZinc()) + spacer + std::to_string(i.getTin()) + spacer + i.getName() + spacer + std::to_string(i.getAmount()) + spacer + x.getName() + spacer
						+ x.getStreet() + spacer + x.getZip() + spacer + x.getCity() + spacer + x.getComment();
		myfile << "\n";
	}

	myfile.close();
	return true;
}

bool saveStorage(std::string filename, std::string spacer, Storage lager) {

	std::ofstream myfile;

	myfile.open(filename + ".csv");
	myfile << "Modus" + spacer + "Kupfer" + spacer + "Zink" + spacer + "Zinn" + spacer + "Name" + spacer + "Menge" + "\n";
	for (Alloy i : lager.getAlloys()) {
		char mode = 'x';
		if (i.getCopper() + i.getZinc() + i.getTin() == 1)
			mode = 'p';
		else if (i.getCopper() + i.getZinc() + i.getTin() == 100)
			mode = 'a';

		myfile << mode + spacer + std::to_string(i.getCopper()) + spacer + std::to_string(i.getZinc()) + spacer + std::to_string(i.getTin()) + spacer + i.getName() + spacer + std::to_string(i.getAmount());
		myfile << "\n";
	}

	myfile.close();
	return true;
}

bool saveFirma(std::string filename, std::string spacer, Firm eigenFirma) {

	std::ofstream myfile;

	myfile.open(filename + ".csv");
	myfile << "Firmname" + spacer + "Strasse" + spacer + "Plz" + spacer + "Stadt" + spacer + "Kommentar" + "\n";

		myfile
				<< eigenFirma.getName() + spacer+ eigenFirma.getStreet() + spacer + eigenFirma.getZip() + spacer +
				eigenFirma.getCity() + spacer + eigenFirma.getComment();
		myfile << "\n";
	myfile.close();
	return true;
}

int readSupplier(std::string filename, std::string spacer, std::vector<Supplier> &suppliers) {
	std::vector<std::string> search = { "Kupfer", "Zink", "Zinn", "Name", "Menge", "Firmname", "Strasse", "Plz", "Stadt", "Kommentar" };
	std::vector<std::string> data_ = data::getTextData(filename, spacer, search);
	if (!data::fileExists(filename ))
		return 2;

	if (data_.size() == 1)
		if (data_.at(0) == "false")
			return 3;

	unsigned int y = 2;
	std::vector<unsigned int> posError;
	std::vector<Supplier> supError;
	std::vector<bool> lineError;
	for(unsigned int x = 0; x<data_.size(); x+= search.size()){
		if(x%search.size() == 0){
			bool wasError = false;
			unsigned int errorSize = 0;
			for (unsigned int supIt_ = x; supIt_ < search.size()+x-1; supIt_++) {
				std::string s = data_.at(supIt_);
//				std::cout << search.at(supIt_) << ": " << s << std::endl;
				if (s.size() == 0){
					errorSize++;
					wasError = true;
				}
			}
			if(wasError && (errorSize != search.size() -1) ){
				std::cout << "Error with Supplier at Line " << y << std::endl;
				for (unsigned int supIt_ = x; supIt_ < search.size()+x-1; supIt_++) {
					std::string s = data_.at(supIt_);
					if (s.size() == 0){
						s = search.at(supIt_-x) + " fehlt";
					}
					std::cout << search.at(supIt_-x) << ": " << s << std::endl;
				}
				Supplier supNew = menu::supplierNew(menu::alloyNewSupplier());
				supError.push_back(supNew);
				posError.push_back(x);
				lineError.push_back(false);
			}
			else if(wasError && (errorSize == search.size() -1) ){
				posError.push_back(x);
				lineError.push_back(true);
			}

			y++;
		}
	}
	int dataSizeOld = data_.size();
	unsigned int supErrorIt = 0;
	unsigned int lineErrorIt = 0;
	for (auto i : posError) {
		int delta1 = static_cast<int>(i + data_.size()) - dataSizeOld;
		int delta2 = static_cast<int>(i + search.size() + data_.size()) - dataSizeOld;
		if (!lineError.at(lineErrorIt)){
			suppliers.push_back(supError.at(supErrorIt));
			supErrorIt++;
		}
		data_.erase(data_.begin() + delta1, data_.begin() + delta2); // @suppress("Invalid arguments")
		lineErrorIt++;
	}

	unsigned int line = posError.size()-1;
	for (unsigned int x = 0; x < data_.size(); x += search.size()) {
		if (x % search.size() == 0) {
			line++;
			try {
				Alloy a(std::stof(data_.at(x)), std::stof(data_.at(x + 1)), std::stof(data_.at(x + 2)), data_.at(x + 3), std::stof(data_.at(x + 4)));
				if (a.isValidAlloy())
					suppliers.push_back(Supplier(a, data_.at(x + 5), data_.at(x + 6), data_.at(x + 7), data_.at(x + 8), data_.at(x + 9)));
				else{
					std::cout <<" Legierung: " << a.getName() << "\t Kupfer: " << a.getCopper() << "\t Zink: " << a.getZinc() <<
					"\t Zinn:\t" << a.getTin() <<"\t Menge: " << a.getAmount() <<std::endl;
					suppliers.push_back(Supplier(menu::alloyNewSupplier(), data_.at(x + 5), data_.at(x + 6), data_.at(x + 7), data_.at(x + 8), data_.at(x + 9)));
				}

			} catch (const std::invalid_argument &ia) {
				std::cout << "Unexpected data type with Suppliers Alloy " << data_.at(x + 3) << std::endl;
				suppliers.push_back(Supplier(menu::alloyNewSupplier(), data_.at(x + 5), data_.at(x + 6), data_.at(x + 7), data_.at(x + 8), data_.at(x + 9)));
			} catch (const std::out_of_range &ia) {
				return 4;
			}
		}
	}
	return 1;
}

int readStorage(std::string filename, std::string spacer, Storage &lager) {


	std::vector<std::string> search = { "Kupfer", "Zink", "Zinn", "Name", "Menge" };
	if (!data::fileExists(filename))
		return 2;
	std::vector<std::string> data_ = data::getTextData(filename, spacer, search);
	if (data_.size() == 1)
		if (data_.at(0) == "false")
			return 3;

	unsigned int y = 2;
	std::vector<unsigned int> posError;
	std::vector<Alloy> alloyError;
	std::vector<bool> lineError;

	for(unsigned int x = 0; x<data_.size(); x+= search.size()){
		if(x%search.size() == 0){
			bool wasError = false;
			unsigned int errorSize = 0;
			for (unsigned int supIt_ = x; supIt_ < search.size()+x; supIt_++) {
				std::string s = data_.at(supIt_);
				if (s.size() == 0){
					wasError = true;
					errorSize++;
				}
			}
			if(wasError && (errorSize != search.size())){
				std::cout << "Error with Lager at Line " << y << std::endl;
				for (unsigned int supIt_ = x; supIt_ < search.size()+x; supIt_++) {
					std::string s = data_.at(supIt_);
					if (s.size() == 0){
						s = search.at(supIt_-x) + " fehlt";
					}
					std::cout << search.at(supIt_-x) << ": " << s << std::endl;
				}
				Alloy alloyNew = menu::alloyNewLager(lager);
				alloyError.push_back(alloyNew);
				posError.push_back(x);
				lineError.push_back(false);
			}
			else if(wasError && (errorSize == search.size()) ){
				posError.push_back(x);
				lineError.push_back(true);
			}
			y++;
		}
	}
	int dataSizeOld = data_.size();
	unsigned int alloyErrorIt = 0;
	unsigned int lineErrorIt = 0;
	for (auto i : posError) {
		int delta1 = static_cast<int>(i + data_.size()) - dataSizeOld;
		int delta2 = static_cast<int>(i + search.size() + data_.size()) - dataSizeOld;
		if (!lineError.at(lineErrorIt)){
			lager.addAlloy(alloyError.at(alloyErrorIt));
			alloyErrorIt++;
		}
		data_.erase(data_.begin() + delta1, data_.begin() + delta2); // @suppress("Invalid arguments")
		lineErrorIt++;
	}
	unsigned int line = posError.size()-1;
	for (unsigned int x = 0; x < data_.size(); x += search.size()) {
		if (x % search.size() == 0) {
			line++;
			try {
				Alloy a(std::stof(data_.at(x)), std::stof(data_.at(x + 1)), std::stof(data_.at(x + 2)), data_.at(x + 3), std::stof(data_.at(x + 4)));

				if (a.isValidAlloy())
					lager.addAlloy(a);
				else{
					std::cout <<" Legierung: " << a.getName() << "\t Kupfer: " << a.getCopper() << "\t Zink: " << a.getZinc() <<
					"\t Zinn:\t" << a.getTin() <<"\t Menge: " << a.getAmount() <<std::endl;
					lager.addAlloy(menu::alloyNewLager(lager));
				}

			} catch (const std::invalid_argument &ia) {
				std::cout << "Unexpected data type at with Alloy " << data_.at(x + 3) << std::endl;
				lager.addAlloy(menu::alloyNewSupplier());
			} catch (const std::out_of_range &ia) {
				return 4;
			}
		}
	}
	return 1;
}

int readFirma(std::string filename, std::string spacer, Firm &eigenFirma) {

	std::vector<std::string> search = { "Firmname", "Strasse", "Plz", "Stadt", "Kommentar"};
	std::vector<std::string> data_ = data::getTextData(filename, spacer, search);

	if (!data::fileExists(filename + ".csv"))
		return 2;

	if (data_.size() == 1)
		if (data_.at(0) == "false")
			return 3;
	try{
		eigenFirma = {data_.at(0),data_.at(1),data_.at(2),data_.at(3),data_.at(4)};
	} catch (const std::invalid_argument &ia) {
		std::cout << "Unerwarteter Fehler mit Eigener Firma " <<std::endl;
		return 4;
	} catch (const std::out_of_range &ia) {
		std::cout << "Unerwarteter Fehler mit Eigener Firma " <<std::endl;
		return 4;
	}
	return 1;
}

}
