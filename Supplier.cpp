#include "Classes.h"
//test1

Supplier::Supplier() {
	alloy;
	order;
	this->setName("");
	this->setStreet("");
	this->setZip("");
	this->setCity("");
	this->setComment("");
}

Supplier::Supplier(Alloy alloyIn, std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn) {
	alloy = alloyIn;
	order;
	this->setName(nameIn);
	this->setStreet(streetIn);
	this->setZip(zipIn);
	this->setCity(cityIn);
	this->setComment(commentIn);
}

void Supplier::setOrder(Order orderIn) {
	this->order.push_back(orderIn);
}

void Supplier::setAlloy(Alloy alloyIn) {
	this->alloy = alloyIn;
}

std::vector<Order> Supplier::getOrder() {
	return this->order;
}

Alloy Supplier::getAlloy() {
	return this->alloy;
}

void Supplier::html(){
	Order meineBestellung = this->order.back();
	Firm eigeneFirma = meineBestellung.getFirm();
	Alloy meineLeg = this->alloy;
	std::ofstream html_file;
	unsigned int number = 1;
	std::string name = "Bestellformular_" + this->getName();

	std::string in;
	std:: cout << "Moechten sie einen eigenen oder automatischen Dateinamen fuer das Bestellformular? \n"
			<< "\n 1. Eigenen | 2. Automatisch \n ";
		do {
			std::cin >> in;
			if (functions::eingabe(3, in) == -1) {
				std::cout << "ungueltige Eingabe, bitte neu eingeben: " << std::endl;
			}
		} while (functions::eingabe(3, in) == -1);

		int ig = stoi(in);
		if(ig==1){
			std:: cout << "Bitte geben sie den Dateinamen ein: \n";
			std::string g;
			std:: cin >> g;
			name = g;
			while(data::fileExists(name+".html")){
				std:: cout << "Dateiname existiert bereits. Moechten Sie ihn ueberschreiben? \n 1. Ja \n 2. Nein\n";
				std::string overwrite;
				do {
					std::cin >> overwrite;
					if (functions::eingabe(3, overwrite) == -1) {
						std::cout << "ungueltige Eingabe, bitte neu eingeben: " << std::endl;
					}
				} while (functions::eingabe(3, overwrite) == -1);
				int overwriteInt = stoi(overwrite);
				if (overwriteInt == 1){
					break;
				}
				if(overwriteInt == 2){
					std:: cout << "Bitte geben sie den Dateinamen ein: \n";
					std:: cin >> g;
					name = g;
				}

				}
		}else if(ig == 2){
			while(data::fileExists(name+".html")){
				std::string s = std::to_string(number);
				name = name+"_"+s;
				number++;
			}
				}
	name = name+".html";
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
					<< this->getName()
					<<"<br>"
					//<<"[Strassenname Emp&aumlngers]"
					<< this->getStreet()
					<<"<br>"
					//<<"[PLZ und Stadt des Emp&aumlngers]"
					<< this->getZip() << " " << this->getCity()
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
						<< meineLeg.getCopper()*100
						<<"</td>"
						<<"<td valign=\"top\" >"
						<< meineLeg.getZinc()*100
						<< "</td>"
						<<"<td valign=\"top\" >"
						<< meineLeg.getTin()*100
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

