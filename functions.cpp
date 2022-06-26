#include "Functions.h"

namespace functions {

int toInteger(std::string str) {

	//setzt voraus dass die Eingabe korrekt ist!
	int a, as = str.size();
	for (int i, j = as; i < as; i++) {
		a += (str[--j] - '0') * pow(10, i);
	}
	return a;
}

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

bool isPositive(std::string numberIn) {
	if (isNumber(numberIn))
		return (stof(numberIn) >= 0);
	else
		return false;
}

bool isValidZip(std::string zipIn) {
	if (isNumber(zipIn))
		if (isInt(stoi(zipIn)))
			return zipIn.size() == 5;
	return false;
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
	myfile
			<< "Modus" + spacer + "Kupfer" + spacer + "Zink" + spacer + "Zinn" + spacer + "Name" + spacer + "Menge" + spacer + "Firmname" + spacer + "Strasse" + spacer + "Plz" + spacer + "Stadt"
					+ spacer + "Kommentar" + "\n";

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

bool readSupplier(std::string filename, std::string spacer, std::vector<Supplier> &suppliers) {
	std::vector<std::string> search = { "Kupfer", "Zink", "Zinn", "Name", "Menge", "Firmname", "Strasse", "Plz", "Stadt", "Kommentar" };
	std::vector<std::string> data_ = data::getTextData(filename, spacer, search);
	if (data_.size() == 1)
		if (data_.at(0) == "false")
			return false;

	for (unsigned int x = 0; x < data_.size(); x += search.size()) {
		if (x % search.size() == 0) {
			try {
				Alloy a(std::stof(data_.at(x)), std::stof(data_.at(x + 1)), std::stof(data_.at(x + 2)), data_.at(x + 3), std::stof(data_.at(x + 4)));
				suppliers.push_back(Supplier(a, data_.at(x + 5), data_.at(x + 6), data_.at(x + 7), data_.at(x + 8), data_.at(x + 9)));
			} catch (const std::invalid_argument &ia) {
				return false;
			} catch (const std::out_of_range &ia) {
				return false;
			}
		}
	}
	return true;
}

std::vector<float> makeAlloyMix(std::vector<Alloy> alloyIn, Alloy &wantedIn) {
	std::vector<arma::vec> vec_;
	std::vector<float> returnAmount;
	for (auto i : alloyIn) {
		arma::vec alloyNew = { i.getCopper(), i.getZinc(), i.getTin() };
		vec_.push_back(alloyNew);
	}
	int size = 0;
	if (vec_.size() < 2)
		size = 2;
	else if (vec_.size() < 3 && vec_.size() == 2)
		size = 1;

	arma::mat Gauss(0, size, arma::fill::zeros);
	arma::vec wanted = { wantedIn.getCopper(), wantedIn.getZinc(), wantedIn.getTin() }; //var für Zielmischung
	for (auto i : vec_) {
		Gauss.insert_cols(0, i); //Vector wird in der Spalte nach in Zeilen gepackt: Vec1 füllt in der ersten Spalte die ganze Zeile usw;
	}
	arma::vec solution;
	bool status = solve(solution, Gauss, wanted, arma::solve_opts::no_approx);
	int f = solution.size()-1;
	if(!status){
		returnAmount.clear();
		return returnAmount;
	}

	for (auto i : alloyIn) {
		if (solution[f] > -1e-7 and solution[f]<0) {
			solution[f] = 0;
		}else if(solution[f]<-1e-7){
			returnAmount.clear();
			break;
		}
		returnAmount.push_back(solution[f]);
		f--;
	}
	return returnAmount;
}

//std::vector<float> makeAlloyMixLager(Storage &Lager, Alloy &wantedIn) {
//	std::vector<arma::vec> vec_;
//	std::vector<float> returnAmount;
//	arma::mat Gauss(0, 0);
//	int isPos = -1;
//	std::vector<Alloy> alloyIn = Lager.getAlloys();
//	arma::vec wanted = { wantedIn.getCopper(), wantedIn.getZinc(), wantedIn.getTin() };
//	int start = 0;
//	do {
//		isPos = 1;
//		if (start != 0) {
//			vec_.erase(vec_.begin() + 1);
//		}
//
//		arma::vec alloyNew = { alloyIn.at(start).getCopper(), alloyIn.at(start).getZinc(), alloyIn.at(start).getTin() };
//		vec_.push_back(alloyNew);
//
//		//var für Zielmischung
//		int x_ = 0;
//		for (auto i : vec_) {
//			Gauss.insert_cols(0, i); //Vector wird in der Spalte nach in Zeilen gepackt: Vec1 füllt in der ersten Spalte die ganze Zeile usw;
//			x_++; //Momentane pos;
//		}
//		std::cout << Gauss << std::endl;
//
//		arma::vec solution = solve(Gauss, wanted);
//		std::cout << wanted << std::endl;
//		std::cout << solution << std::endl;
//		std::cout << "ende" << std::endl;
//		int f = solution.size();
//		for (auto i : alloyIn) {
//			returnAmount.push_back(solution[f]);
//			if (solution[f] < 0) {
//				isPos = -1;
//			}
//			f--;
//		}
//	} while (isPos == -1);
//
//	returnAmount.push_back(isPos);
//	return returnAmount;
//}
//
}

