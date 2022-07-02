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

std::vector<float> makeAlloyMix(std::vector<Alloy> alloyIn, Alloy &wantedIn) {
	std::vector<arma::vec> vec_;
	std::vector<float> returnAmount;
	bool check = false;
	for (auto i : alloyIn) {
		arma::vec alloyNew = { i.getCopper(), i.getZinc(), i.getTin() };
		vec_.push_back(alloyNew);
		if(i%wantedIn){
			returnAmount.push_back(1);
			check = true;
		}else
			returnAmount.push_back(0);
	}
	if(check)
		return returnAmount;
	else
		returnAmount.clear();


	int size = 0;
	if (vec_.size() < 2)
		size = 2;
	else if (vec_.size() < 3 && vec_.size() == 2)
		size = 1;

	arma::mat Gauss(3, size, arma::fill::zeros);

	arma::vec wanted = { wantedIn.getCopper(), wantedIn.getZinc(), wantedIn.getTin() }; //var für Zielmischung
	for (auto i : vec_) {
		Gauss.insert_cols(0, i); //Vector wird in der Spalte nach in Zeilen gepackt: Vec1 füllt in der ersten Spalte die ganze Zeile usw;
	}
	arma::vec solution;
//	try{
//		solution = solve(Gauss, wanted);
//	}catch(std::runtime_error &i){
//
//	}
	bool status = solve(solution, Gauss, wanted);
	int f = solution.size()-1;
	if(!status){
		returnAmount.clear();
		return returnAmount;
	}

	for (auto i : alloyIn) {
		if (solution[f-size] > -1e-5 and solution[f-size]<0) {
			solution[f-size] = 0;
		}else if (solution[f-size] < 1e-5 and solution[f-size]>0) {
			solution[f-size] = 0;

		}else if(solution[f-size]<-1e-5){
			returnAmount.clear();
			break;
		}else if(solution[f-size]>1){
			returnAmount.clear();
			break;
		}
		returnAmount.push_back(solution[f-size]);
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

void html(Supplier Zulieferer,Alloy meineLeg,Order meineBestellung){

	Firm eigeneFirma = meineBestellung.getFirm();
	std::ofstream html_file;
	unsigned int number = 1;
	std::string name = "Bestellformular_"+Zulieferer.getName()+".html";

	std::cout<<data::fileExists(name)<<std::endl;
	while(data::fileExists(name)){
		std::string s = std::to_string(number);
		name = "Bestellformular_"+Zulieferer.getName()+"_"+s+".html";
		number++;
	}

	html_file.open(name);
	if (html_file.is_open())
	{
		html_file << "<h1 style=\"text-align:center;\">"
				<< "Bestellformular f&uumlr Legierungen </h1>"

				<<"<br>"
				<<"<br>"
				<<"<br>"

				<< "<p style=\"text-indent:187px\">"
				<<"Empf&aumlnger:"
				<<"</p><table width=\"70%\" align=center>"

				<<"<tr>"
				<<"<td valign=\"top\" width= \"35%\">"
					//<<"[Name des Empf&aumlngers]"
					<< Zulieferer.getName()
					<<"<br>"
					//<<"[Strassenname Emp&aumlngers]"
					<< Zulieferer.getStreet()
					<<"<br>"
					//<<"[PLZ und Stadt des Emp&aumlngers]"
					<< Zulieferer.getZip() << " " << Zulieferer.getCity()
					<<"<br>"
				<<"</td>"
				<<"<td valign=\"top\" width=\"30%\"> </td>"

				<<"<td valign=\"top\" width=\"35%\">"
					//<<"[Name eigene Firma]:"
					<< eigeneFirma.getName()
					<<"<br>"
					//<<"[Strassenname eigene Firma]"
					<< eigeneFirma.getStreet()
					<<"<br>"
					//<<"[PLZ und Stadt eigene Firma]"
					<< eigeneFirma.getZip() << " " << eigeneFirma.getCity()
					<<"<br>"
				<<"</td>"
				<<"</table>"

				<<"<br>"
				<<"<br>"
				<<"<br>"
				<<"<br>"

//				<<"<table width=\"100%\" heigth=\"100\" >"
//					<<"<tr>"
//						<<"<div align=\"center\"> <strong>Rechnungsnummer: "
//						<< meineBestellung.getId()
//						<<"</strong> </div>"
//
//				<<"<br>"
//				<<"<br>"
//				<<"<br>"
//				<<"<br>"

				<<"<table width=\"70%\" height=\"100\" border=\"1\" align=center >"
				<<"<tbody>"
					<<"<tr>"
						<<"<td width=\"35%\" bgcolor=\"#f2f2f2\">"
						<<"<strong> Legierung </strong>"
						<<"</td>"

						<<"<td width=\"15%\" bgcolor=\"#f2f2f2\">"
						<<"<strong> Kupfer [%] </strong>"
						<<"</td>"

						<<"<td width=\"15%\" bgcolor=\"#f2f2f2\">"
						<<"<strong> Zink [%]</strong>"
						<<"</td>"

						<<"<td width=\"15%\" bgcolor=\"#f2f2f2\">"
						<<"<strong> Zinn [%]</strong>"
						<<"</td>"

						<<"<td width=\"20%\" bgcolor=\"#f2f2f2\">"
						<<"<strong> Menge [kg] </strong>"
						<<"</td>"

					<<"</tr>"
					<<"<tr>"
						<<"<td valign=\"top\" >"
						<< meineLeg.getName()
						<<"</td>"
						<<"<td valign=\"top\" >"
						<< meineLeg.getCopper()
						<<"</td>"
						<<"<td valign=\"top\" >"
						<< meineLeg.getZinc()
						<< "</td>"
						<<"<td valign=\"top\" >"
						<< meineLeg.getTin()
						<< "</td>"
						<<"<td valign=\"top\" >"
						<< meineBestellung.getAmount()
						<< "</td>"
					<<"</tr>"
				<<"</tbody>"
				<<"</table>";




		html_file.close();
	} else {
		std::cout << "File konnte nicht geoeffnet werden." << std::endl;
	}
}
}

