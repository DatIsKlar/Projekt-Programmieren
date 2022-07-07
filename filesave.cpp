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

int readSupplier(std::string filename, std::string spacer, std::vector<Supplier> &suppliers) {
	std::vector<std::string> search = { "Kupfer", "Zink", "Zinn", "Name", "Menge", "Firmname", "Strasse", "Plz", "Stadt", "Kommentar" };
	std::vector<std::string> data_ = data::getTextData(filename, spacer, search);
	if (!data::fileExists(filename + ".csv"))
		return 2;

	if (data_.size() == 1)
		if (data_.at(0) == "false")
			return 3;
	unsigned int y = 2;
	std::vector<unsigned int> posError;
	std::vector<Supplier> supError;
	for(unsigned int x = 0; x<data_.size(); x+= search.size()){
		if(x%search.size() == 0){
			bool wasError = false;
			for (unsigned int supIt_ = x; supIt_ < search.size()+x; supIt_++) {
				std::string s = data_.at(supIt_);
//				std::cout << search.at(supIt_) << ": " << s << std::endl;
				if (s.size() == 0){
					wasError = true;
				}
			}
			if(wasError){
				std::cout << "Error with Supplier at Line " << y << std::endl;
				std::cout << "Error with Supplier at Line " << search.size()+x << std::endl;
				std::cout << "Error with Supplier at Line " << data_.size() << std::endl;
				for (unsigned int supIt_ = x; supIt_ < search.size()+x; supIt_++) {
					std::string s = data_.at(supIt_);
					if (s.size() == 0){
						s = search.at(supIt_-x) + " fehlt";
					}
					std::cout << search.at(supIt_-x) << ": " << s << std::endl;
				}
				Supplier supNew = menu::supplierNew(menu::alloyNewSupplier());
				supError.push_back(supNew);
				posError.push_back(x);
			}
			y++;
		}
	}

//	for (unsigned int x = 1; x < data_.size(); x++) {
//		if (data_.at(x - 1).size() == 0) {
//			posError.push_back(supIt);
//
//			std::cout << "Error with Supplier at Line " << y << std::endl;
//			for (unsigned int supIt_ = 0; supIt_ < search.size(); supIt_++) {
//				std::string s = data_.at(supIt_ + supIt);
//				if (s.size() == 0)
//					s = search.at(supIt_) + " fehlt";
//				std::cout << search.at(supIt_) << ": " << s << std::endl;
//			}
//			Supplier supNew = menu::supplierNew(menu::alloyNewSupplier());
//			supError.push_back(supNew);
//			x += search.size() * y - x - 1;
//		}
//		posSearch++;
//		if ((x + 1) % search.size() == 0 and x != 0) {
//			posSearch = 0;
//			y++;
//			supIt += search.size();
//		}
//	}
//
	int dataSizeOld = data_.size();
	unsigned int supErrorIt = 0;
	for (auto i : posError) {
		int delta1 = static_cast<int>(i + data_.size()) - dataSizeOld;
		int delta2 = static_cast<int>(i + search.size() + data_.size()) - dataSizeOld;
		suppliers.push_back(supError.at(supErrorIt));
		data_.erase(data_.begin() + delta1, data_.begin() + delta2); // @suppress("Invalid arguments")
		supErrorIt++;
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
				std::cout << "Unexpected data type at Line with Suppliers Alloy" << line << std::endl;
				suppliers.push_back(menu::supplierNew(menu::alloyNewSupplier()));
			} catch (const std::out_of_range &ia) {
				return 4;
			}
		}
	}
	return 1;
}

int readStorage(std::string filename, std::string spacer, Storage &lager) {

	std::vector<std::string> search = { "Kupfer", "Zink", "Zinn", "Name", "Menge" };
	std::vector<std::string> data_ = data::getTextData(filename, spacer, search);

	if (!data::fileExists(filename + ".csv"))
		return 2;

	if (data_.size() == 1)
		if (data_.at(0) == "false")
			return 3;

	unsigned int y = 1;
	std::vector<unsigned int> posError;
	std::vector<Alloy> alloyError;
	for(unsigned int x = 0; x<data_.size(); x+= search.size()){
		if(x%search.size() == 0){
			bool wasError = false;
			for (unsigned int supIt_ = 0; supIt_ < search.size(); supIt_++) {
				std::string s = data_.at(supIt_);
				if (s.size() == 0){
					wasError = true;
				}
			}
			if(wasError){
				std::cout << "Error with Supplier at Line " << y << std::endl;
				for (unsigned int supIt_ = 0; supIt_ < search.size(); supIt_++) {
					std::string s = data_.at(supIt_);
					if (s.size() == 0){
						s = search.at(supIt_-x) + " fehlt";
					}
					std::cout << search.at(supIt_-x) << ": " << s << std::endl;
				}
				Alloy alloyNew = menu::alloyNewLager(lager);
				alloyError.push_back(alloyNew);
				posError.push_back(x);
			}
			y++;
		}
	}

//	for (unsigned int x = 1; x < data_.size(); x++) {
//
//		if (data_.at(x - 1).size() == 0) {
//			posError.push_back(supIt);
//			std::cout << "Error with Alloy at Line " << y << std::endl;
//			for (unsigned int supIt_ = 0; supIt_ < search.size(); supIt_++) {
//				std::string s = data_.at(supIt_ + supIt);
//				if (s.size() == 0)
//					s = search.at(supIt_) + " fehlt";
//
//				std::cout << search.at(supIt_) << ": " << s << std::endl;
//			}
//			Alloy alloyNew = menu::alloyNewLager(lager);
//			alloyError.push_back(alloyNew);
//			x += search.size() * y - x - 1;
//
//		}
//		posSearch++;
//		if ((x + 1) % search.size() == 0 and x != 0) {
//			posSearch = 0;
//			y++;
//			supIt += search.size();
//		}
//	}

	int dataSizeOld = data_.size();
	unsigned int supErrorIt = 0;
	for (auto i : posError) {
		int delta1 = static_cast<int>(i + data_.size()) - dataSizeOld;
		int delta2 = static_cast<int>(i + search.size() + data_.size()) - dataSizeOld;
		lager.addAlloy(alloyError.at(supErrorIt));
		data_.erase(data_.begin() + delta1, data_.begin() + delta2); // @suppress("Invalid arguments")
		supErrorIt++;
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

				lager.addAlloy(menu::alloyNewSupplier());
			} catch (const std::out_of_range &ia) {
				return 4;
			}
		}
	}
	return 1;
}
}
