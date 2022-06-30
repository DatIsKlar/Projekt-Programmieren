/*
 * Menu.cpp
 *
 *  Created on: 13.06.2022
 *      Author: broelaar
 */
#include "Menu.h"
#include "Functions.h"

namespace menu {
void anschriftPflegen(Firm &eigeneFirma) {
	/**
	 * Dieses 'Menue' geht nur eine Ebene tief, d.h. man w�hlt eine Option aus und wird dann
	 * durch den Prozess durchgef�hrt.
	 * An manchen Stellen muss die Eingabe zwei mal mit Enter best�tigt werden, bevor man
	 * zum n�chsten Punkt weitergef�hrt wird.
	 *
	 * Die Einbindung der eigenen Firma wurde hier auch noch nicht realisiert.
	 */
	std::string choiceA;

	do {
		std::cout << "Was moechten Sie bearbeiten? \n 1. Ganze Adresse bearbeiten \n "
				"2. Strasse bearbeiten \n 3. ZIP bearbeiten \n 4. City bearbeiten"
				"\n 5. Comment bearbeiten \n 6. Namen bearbeiten \n 0. zurueck" << std::endl;

		// bsp objekt unsere eigener Firma, wird sp�ter aus anderer Datei genommen
		//Firm EigeneFirma;
		do {
			std::cin >> choiceA;
			if (functions::eingabe(7, choiceA) == -1) {
				std::cout << "Ungueltige Eingabe, bitte neu eingeben: \n" << std::endl;
			}
		} while (functions::eingabe(7, choiceA) == -1);

		//cin >> integer;

		switch (stoi(choiceA)) {
		case 0: // programm beenden
		{
			std::cout << "Zurueck." << std::endl;
			break;
		} // ende case 6

		case 1: {
			std::string checkAdresse = eigeneFirma.getStreet();
			checkAdresse.append(eigeneFirma.getZip()).append(eigeneFirma.getCity()).append(eigeneFirma.getComment());

			if (checkAdresse == "") {
				std::cout << "Bitte geben Sie die Adresse der Firma ein." << std::endl;
				std::cout << "Name: " << std::endl;
				std::string neueName;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neueName);
				eigeneFirma.setName(neueName);
				std::cout << "Strassenname: " << std::endl;
				std::string strasse;
				//std::cin.ignore(500, '\n');
				std::getline(std::cin, strasse);
				eigeneFirma.setStreet(strasse);
				std::cout << "ZIP-Code: " << std::endl;
				std::string zip;
				//std::cin.ignore(500, '\n');
				std::getline(std::cin, zip);
				eigeneFirma.setZip(zip);
				std::cout << "City: " << std::endl;
				std::string city;
				//std::cin.ignore(500, '\n');
				std::getline(std::cin, city);
				eigeneFirma.setCity(city);
				std::cout << "Comment: " << std::endl;
				std::string comment;
				//std::cin.ignore(500, '\n');
				std::getline(std::cin, comment);
				eigeneFirma.setComment(comment);
			} else {
				std::cout << "Die aktuelle Adresse lautet:" << std::endl << eigeneFirma.getName() << std::endl << eigeneFirma.getStreet() << std::endl;
				std::cout << eigeneFirma.getZip() << std::endl << eigeneFirma.getCity() << std::endl << eigeneFirma.getComment() << std::endl;
				std::cout << "Bitte geben Sie die neue Adresse ein." << std::endl;
				std::cout << "Name: " << std::endl;
				std::string neueName;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neueName);
				eigeneFirma.setName(neueName);
				std::cout << "Strassenname: " << std::endl;
				std::string neueStrasse;
				//std::cin.ignore(500, '\n');
				std::getline(std::cin, neueStrasse);
				eigeneFirma.setStreet(neueStrasse);
				std::cout << "ZIP-Code: " << std::endl;
				std::string neueZip;
				//std::cin.ignore(500, '\n');
				std::getline(std::cin, neueZip);
				eigeneFirma.setZip(neueZip);
				std::cout << "City: " << std::endl;
				std::string neueCity;
				//std::cin.ignore(500, '\n');
				std::getline(std::cin, neueCity);
				eigeneFirma.setCity(neueCity);
				std::cout << "Comment: " << std::endl;
				std::string neueComment;
				//std::cin.ignore(500, '\n');
				std::getline(std::cin, neueComment);
				eigeneFirma.setComment(neueComment);
			} // else ende
			break;
		} // case 1 ende

		case 2: // Strasse bearbeiten
		{
			std::string checkStrasse = eigeneFirma.getStreet();
			if (checkStrasse == "") {
				std::string strassenname;
				std::cout << "Bitte geben Sie die Strasse der Firma ein." << std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, strassenname);
				eigeneFirma.setStreet(strassenname);
			} else {
				std::string neueStrassenName;
				std::cout << "Der aktuelle Strassenname lautet: " << eigeneFirma.getStreet() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie den neuen Strassennamen ein." << std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neueStrassenName);
				eigeneFirma.setStreet(neueStrassenName);
			} // else ende
			break;
		} // ende case 2

		case 3: // zip bearbeiten
		{
			std::string checkZip = eigeneFirma.getZip();
			if (checkZip == "") {
				std::cout << "Bitte geben Sie den ZIP-Code der Firma ein." << std::endl;
				std::string zip;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, zip);
				eigeneFirma.setZip(zip);
			} else {
				std::cout << "Der aktuelle ZIP-Code lautet: " << eigeneFirma.getZip() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie den neuen ZIP-Code ein." << std::endl;
				std::string neueZip;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neueZip);
				eigeneFirma.setZip(neueZip);
			} // else ende
			break;
		} // ende case 3

		case 4: //City bearbeiten
		{
			std::string checkCity = eigeneFirma.getCity();
			if (checkCity == "") {
				std::string stadt;
				std::cout << "Bitte geben Sie die Stadt der Firma ein." << std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, stadt);
				eigeneFirma.setCity(stadt);
			} else {
				std::string neueStadt;
				std::cout << "Die aktuelle Stadt lautet: " << eigeneFirma.getCity() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie die neue Stadt ein." << std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neueStadt);
				eigeneFirma.setCity(neueStadt);
			} // else ende
			break;
		} // ende case 4

		case 5: // Comment bearbeiten
		{
			std::string checkComment = eigeneFirma.getComment();
			if (checkComment == "") {
				std::cout << "Bitte geben Sie einen Kommentar ein." << std::endl;
				std::string comment;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, comment);
				eigeneFirma.setComment(comment);
				break;
			} else {
				std::cout << "Aktueller Kommentar: " << eigeneFirma.getComment() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie einen neuen Kommentar ein. \n" << std::endl;
				std::string neuerKommentar;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neuerKommentar);
				eigeneFirma.setComment(neuerKommentar);
			} // else ende
			break;
		} // ende case 5

		case 6: {
			std::string checkName = eigeneFirma.getName();
			if (checkName == "") {
				std::cout << "Bitte geben Sie einen Namen ein." << std::endl;
				std::string name;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, name);
				eigeneFirma.setName(name);
				break;
			} else {
				std::cout << "Aktueller Name: " << eigeneFirma.getName() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie einen neuen Namen ein. \n" << std::endl;
				std::string neuerName;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neuerName);
				eigeneFirma.setName(neuerName);
			} // else ende
			break;
		}
		default: {
			std::cout << "Ungueltige Eingabe! \n" << std::endl;
			break;
		} // ende default case

		} // ende switch schleife

	} // ende do schleife
	while (stoi(choiceA) != 0);

}

void supplierPlfegen(std::vector<Supplier> &suppliers) {
	/**
	 * Dieses 'Menue' geht nur eine Ebene tief, d.h. man w�hlt eine Option aus und wird dann
	 * durch den Prozess durchgef�hrt.
	 * An manchen Stellen muss die Eingabe zwei mal mit Enter best�tigt werden, bevor man
	 * zum n�chsten Punkt weitergef�hrt wird.
	 *
	 * Die Einbindung der eigenen Firma wurde hier auch noch nicht realisiert.
	 */

	unsigned y = 1;
	std::string y_in = "";
	std::string choiceA;

	do {

		unsigned sup = 0;
		for (auto i : suppliers) {
			sup++;
			std::cout << sup << " " << i.getName() << std::endl;

		}
		std::cout << "0. beenden" << std::endl;

		do {
			std::cin >> y_in;
			if (functions::eingabe(suppliers.size() + 1, y_in) == -1) {
				std::cout << "Ungueltige Eingabe, bitte neu eingeben: " << std::endl;
			}
		} while (functions::eingabe(suppliers.size() + 1, y_in) == -1);
		y = stoi(y_in);
		if (y == 0)
			return;

		std::cout << "Was moechten Sie bearbeiten? \n 1. Ganze Adresse bearbeiten \n "
				"2. Strasse bearbeiten \n 3. ZIP bearbeiten \n 4. City bearbeiten"
				"\n 5. Comment bearbeiten \n 6. Namen bearbeiten \n 0. beenden" << std::endl;

		// bsp objekt unsere eigener Firma, wird sp�ter aus anderer Datei genommen
		//Firm EigeneFirma;
		do {
			std::cin >> choiceA;
			if (functions::eingabe(7, choiceA) == -1) {
				std::cout << "Ungueltige Eingabe, bitte neu eingeben: \n" << std::endl;
			}
		} while (functions::eingabe(7, choiceA) == -1);

		//cin >> integer;

		switch (stoi(choiceA)) {
		case 0: // programm beenden
		{
			std::cout << "Programm beendet." << std::endl;
			break;
		} // ende case 6

		case 1: {
			std::cout << "Die aktuelle Adresse lautet:" << std::endl << suppliers.at(y - 1).getName() << std::endl << suppliers.at(y - 1).getStreet() << std::endl;
			std::cout << suppliers.at(y - 1).getZip() << std::endl << suppliers.at(y - 1).getCity() << std::endl << suppliers.at(y - 1).getComment() << std::endl;
			std::cout << "Bitte geben Sie die neue Adresse ein." << std::endl;
			std::cout << "Name: " << std::endl;
			std::string neueName;
			std::cin.ignore(500, '\n');
			std::getline(std::cin, neueName);
			suppliers.at(y - 1).setName(neueName);
			std::cout << "Strassenname: " << std::endl;
			std::string neueStrasse;
			std::getline(std::cin, neueStrasse);
			suppliers.at(y - 1).setStreet(neueStrasse);
			std::cout << "ZIP-Code: " << std::endl;
			std::string neueZip;
			//std::cin.ignore(500, '\n');
			std::getline(std::cin, neueZip);
			suppliers.at(y - 1).setZip(neueZip);
			std::cout << "City: " << std::endl;
			std::string neueCity;
			//std::cin.ignore(500, '\n');
			std::getline(std::cin, neueCity);
			suppliers.at(y - 1).setCity(neueCity);
			std::cout << "Comment: " << std::endl;
			std::string neueComment;
			//std::cin.ignore(500, '\n');
			std::getline(std::cin, neueComment);
			suppliers.at(y - 1).setComment(neueComment);
			// else ende
			break;
		} // case 1 ende

		case 2: // Strasse bearbeiten
		{
			std::string checkStrasse = suppliers.at(y - 1).getStreet();
			if (checkStrasse == "") {
				std::string strassenname;
				std::cout << "Bitte geben Sie die Strasse der Firma ein." << std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, strassenname);
				suppliers.at(y - 1).setStreet(strassenname);
			} else {
				std::string neueStrassenName;
				std::cout << "Der aktuelle Strassenname lautet: " << suppliers.at(y - 1).getStreet() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie den neuen Strassennamen ein." << std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neueStrassenName);
				suppliers.at(y - 1).setStreet(neueStrassenName);
			} // else ende
			break;
		} // ende case 2

		case 3: // zip bearbeiten
		{
			std::string checkZip = suppliers.at(y - 1).getZip();
			if (checkZip == "") {
				std::cout << "Bitte geben Sie den ZIP-Code der Firma ein." << std::endl;
				std::string zip;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, zip);
				suppliers.at(y - 1).setZip(zip);
			} else {
				std::cout << "Der aktuelle ZIP-Code lautet: " << suppliers.at(y - 1).getZip() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie den neuen ZIP-Code ein." << std::endl;
				std::string neueZip;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neueZip);
				suppliers.at(y - 1).setZip(neueZip);
			} // else ende
			break;
		} // ende case 3

		case 4: //City bearbeiten
		{
			std::string checkCity = suppliers.at(y - 1).getCity();
			if (checkCity == "") {
				std::string stadt;
				std::cout << "Bitte geben Sie die Stadt der Firma ein." << std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, stadt);
				suppliers.at(y - 1).setCity(stadt);
			} else {
				std::string neueStadt;
				std::cout << "Die aktuelle Stadt lautet: " << suppliers.at(y - 1).getCity() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie die neue Stadt ein." << std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neueStadt);
				suppliers.at(y - 1).setCity(neueStadt);
			} // else ende
			break;
		} // ende case 4

		case 5: // Comment bearbeiten
		{
			std::string checkComment = suppliers.at(y - 1).getComment();
			if (checkComment == "") {
				std::cout << "Bitte geben Sie einen Kommentar ein." << std::endl;
				std::string comment;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, comment);
				suppliers.at(y - 1).setComment(comment);
				break;
			} else {
				std::cout << "Aktueller Kommentar: " << suppliers.at(y - 1).getComment() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie einen neuen Kommentar ein. \n" << std::endl;
				std::string neuerKommentar;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neuerKommentar);
				suppliers.at(y - 1).setComment(neuerKommentar);
			} // else ende
			break;
		} // ende case 5

		case 6: {
			std::string checkName = suppliers.at(y - 1).getName();
			if (checkName == "") {
				std::cout << "Bitte geben Sie einen Namen ein." << std::endl;
				std::string name;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, name);
				suppliers.at(y - 1).setName(name);
				break;
			} else {
				std::cout << "Aktueller Name: " << suppliers.at(y - 1).getName() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie einen neuen Namen ein. \n" << std::endl;
				std::string neuerName;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, neuerName);
				suppliers.at(y - 1).setName(neuerName);
			} // else ende
			break;
		}
		default: {
			std::cout << "Ungueltige Eingabe! \n" << std::endl;
			break;
		} // ende default case

		} // ende switch schleife
	} // ende do schleife
	while (stoi(choiceA) != 0);
	//auswahl
	//suppliers.at(auswahl-1).Set..

	return;
}

Alloy alloyNewLager(Storage &stor) {
	float copper = 0;
	float zinc = 0;
	float tin = 0;
	float amount = 0;
	bool metals = false;
	std::cout << "Bitte geben Sie die Daten der Legierung an." << std::endl;
	//dummy alloy
	do {
		std::string copperString;
		do {
			std::cout << "Kupfer " << std::endl;
			std::cin >> copperString;
			if (!functions::isPositive(copperString))
				std::cout << "Nicht erlaubter Wert" << std::endl;
		} while (!functions::isPositive(copperString));
		copper = stof(copperString);

		std::string zincString;
		do {
			std::cout << "Zink " << std::endl;
			std::cin >> zincString;
			if (!functions::isPositive(zincString))
				std::cout << "Nicht erlaubter Wert" << std::endl;
		} while (!functions::isPositive(zincString));
		zinc = stof(zincString);

		std::string tinString;
		do {
			std::cout << "Zinn " << std::endl;
			std::cin >> tinString;
			if (!functions::isPositive(tinString))
				std::cout << "Nicht erlaubter Wert" << std::endl;
		} while (!functions::isPositive(tinString));
		tin = stof(tinString);

		metals = (copper + zinc + tin == 1) or (copper + zinc + tin == 100);
		if (!metals)
			std::cout << "Legierung hat mehr als 100% Bestandteile" << std::endl;

	} while (!metals);

	std::string name;
	do {
		std::cout << "Name: " << std::endl;
		std::cin >> name;
		if (stor.getAlloyPosByName(name) != -1)
			std::cout << "Legierung mit diesem Namen existier bereits" << std::endl;
	} while (stor.getAlloyPosByName(name) != -1);

	do {
		std::string amountString;
		do {
			std::cout << "Menge " << std::endl;
			std::cin >> amountString;
			if (!functions::isPositive(amountString))
				std::cout << "Nicht erlaubter Wert" << std::endl;
		} while (!functions::isPositive(amountString));
		amount = stof(amountString);
		if (amount <= 0)
			std::cout << "Menge kann nicht kleiner gleich 0 sein" << std::endl;
	} while (amount <= 0);

	return Alloy(copper, zinc, tin, name, amount);
}

Alloy alloyNewSupplier() {
	float copper = 0;
	float zinc = 0;
	float tin = 0;
	float amount = 0;
	bool metals = false;
	std::cout << "Bitte geben Sie die Daten der Legierung an." << std::endl;
	//dummy alloy
	do {
		std::string copperString;
		do {
			std::cout << "Kupfer " << std::endl;
			std::cin >> copperString;
			if (!functions::isPositive(copperString))
				std::cout << "Nicht erlaubter Wert" << std::endl;
		} while (!functions::isPositive(copperString));
		copper = stof(copperString);

		std::string zincString;
		do {
			std::cout << "Zink " << std::endl;
			std::cin >> zincString;
			if (!functions::isPositive(zincString))
				std::cout << "Nicht erlaubter Wert" << std::endl;
		} while (!functions::isPositive(zincString));
		zinc = stof(zincString);

		std::string tinString;
		do {
			std::cout << "Zinn " << std::endl;
			std::cin >> tinString;
			if (!functions::isPositive(tinString))
				std::cout << "Nicht erlaubter Wert" << std::endl;
		} while (!functions::isPositive(tinString));
		tin = stof(tinString);

		metals = (copper + zinc + tin == 1) or (copper + zinc + tin == 100);
		if (!metals)
			std::cout << "Legierung hat mehr als 100% Bestandteile" << std::endl;

	} while (!metals);

	std::string name;
	std::cout << "Name: " << std::endl;
	std::cin >> name;

	do {
		std::string amountString;
		do {
			std::cout << "Menge " << std::endl;
			std::cin >> amountString;
			if (!functions::isPositive(amountString))
				std::cout << "Nicht erlaubter Wert" << std::endl;
		} while (!functions::isPositive(amountString));
		amount = stof(amountString);
		if (amount <= 0)
			std::cout << "Menge kann nicht kleiner gleich 0 sein" << std::endl;
	} while (amount <= 0);

	return Alloy(copper, zinc, tin, name, amount);
}

Supplier supplierNew(Alloy alloyIn) {
	Supplier s(Alloy(), "", "", "", "", "");
	s.setAlloy(alloyIn);
	std::cout << "Bitte geben Sie die Daten des Zuliefers an." << std::endl;
	//dummy alloy
	std::cout << "Name: " << std::endl;
	std::string neueName;
	std::cin.ignore(500, '\n');
	std::getline(std::cin, neueName);
	s.setName(neueName);
	std::cout << "Strassenname: " << std::endl;
	std::string strasse;
	//std::cin.ignore(500, '\n');
	std::getline(std::cin, strasse);
	s.setStreet(strasse);
	std::cout << "ZIP-Code: " << std::endl;
	std::string zip;
	//std::cin.ignore(500, '\n');
	std::getline(std::cin, zip);
	s.setZip(zip);
	std::cout << "City: " << std::endl;
	std::string city;
	//std::cin.ignore(500, '\n');
	std::getline(std::cin, city);
	s.setCity(city);
	std::cout << "Comment: " << std::endl;
	std::string comment;
	//std::cin.ignore(500, '\n');
	std::getline(std::cin, comment);
	s.setComment(comment);

	return s;
}

int bestellung(Storage &lager,std::vector<Supplier> &supplierVec, Firm firm){
	std::vector<Alloy> lagerKopie = lager.getAlloys();
	int auswahl = 1;
	std::string supplierChoiceIn = "";
	// Liste Zulieferer

	bool mengeCheck = false;
	// Auswahl Zulieferer
	do {
		unsigned int counterSupplier = 0;
		if( supplierVec.size() ==0)
			std::cout<<"Es gibt keine Zuhliefere"<<std::endl;
		for (auto i : supplierVec) {
			counterSupplier++;
			Alloy output;
			output = i.getAlloy();
			std::cout<<counterSupplier<<". "<<i.getName()<<" Legierung: "<<output.getName()<<" Kupfer: "<<output.getCopper()<<"  Zink:"<<output.getZinc()<<
			" Zinn:"<<output.getTin()<<std::endl;

		}
		std::cout << "0. beenden" << std::endl;
		std::cin >> supplierChoiceIn;
		auswahl = functions::eingabe(supplierVec.size() + 1, supplierChoiceIn);
		if (auswahl == -1) {
			std::cout << "Ungueltige Eingabe, bitte neu eingeben: " << std::endl;
		}
	} while (auswahl == -1);
	if (auswahl == 0)
		return -1;
	Alloy alloySupplier;
	alloySupplier = supplierVec.at(auswahl-1).getAlloy();
	int alloyPosLager = lager.getAlloyPosByType(alloySupplier);
	float menge = lager.getAlloys().at(alloyPosLager).getAmount();
	// Eingabe Wunschmenge
	std::string amountIn ="";
	std::cout<<"Menge die Sie bestellen wollen: "<<std::endl;
	do {
			std::cin >> amountIn;
			if(functions::isPositive(amountIn)){
				if (std::numeric_limits<float>::max()-menge < stof(amountIn) )
					std::cout << "Ungueltige Eingabe, bitte neu eingeben: " << std::endl;
				else
					mengeCheck = true;
			}
		} while (!mengeCheck);

	Alloy alloySupplierCopy = alloySupplier;
	alloySupplierCopy.setAmount(stof(amountIn)+lager.getAlloys().at(alloyPosLager).getAmount());
	Order meineBestellung(stof(amountIn),firm);
	supplierVec.at(auswahl-1).setOrder(meineBestellung);
	lager.editAlloyByType(alloySupplier, alloySupplierCopy);
	std::cout<<lager.getAlloys().at(lager.getAlloyPosByType(alloySupplier)).getAmount()<<" "<<lager.getAlloys().at(lager.getAlloyPosByType(alloySupplier)).getName()<<std::endl;
	//lagerKopie = Lager.getAlloys();
	//HTML
	functions::html(supplierVec.at(auswahl-1),alloySupplierCopy,meineBestellung);
	return 0;
}

void produktion(Storage &lager,std::vector<Supplier> &supplierVec, Firm firm) {

	std::vector<float> mengen;
	mengen.push_back(-1);
	Alloy alloyWanted;
	std::vector<Alloy> Auswahl;
	do {
		std::cout << " Bitte waehlen sie die gewuenschten Legierungen aus, indem sie die Nummern eingeben. \n Sind Sie fertig, geben sie eine 0 ein. \n";

		//Deklarationen
		std::string alloyChoice = "";
		//std::string choiceA;
		int alloyChoiceNumber = 0;

		//Ausgabe Liste vorhandener Legierungen
		std::vector<Alloy> alloyVec = lager.getAlloys();
		do {
			unsigned counterSupplier = 0;
			for (auto i : alloyVec) {
				counterSupplier++;
				std::cout<<counterSupplier<<" Legierung: "<<i.getName()<<" Kupfer: "<<i.getCopper()<<"  Zink:"<<i.getZinc()<<" Zinn:"<<i.getTin()<<std::endl;
				//std::cout << counterSupplier << " " << i.getName() <<": "<<i.getCopper()<< << std::endl;

			}

			std::cout << "0. Fertig" << std::endl;

			//Auswahl der Legierungen(wieviele?)

			do {
				std::cin >> alloyChoice;
				if (functions::eingabe(alloyVec.size() + 1, alloyChoice) == -1) {
					std::cout << "Ungueltige Eingabe, bitte neu eingeben: " << std::endl;
				}

			} while (functions::eingabe(alloyVec.size() + 1, alloyChoice) == -1);

			if (stoi(alloyChoice) == 0) {
				break;
			}
			Auswahl.push_back(alloyVec.at(stoi(alloyChoice) - 1));
			alloyVec.erase(alloyVec.begin() + stoi(alloyChoice) - 1); // @suppress("Invalid arguments")
			alloyChoiceNumber = stoi(alloyChoice);

		} while (alloyChoiceNumber != 0);

		for (auto i : Auswahl) {
			std::cout << i.getName() << std::endl;
		}

		//Eingabeaufforderung Arroy

		std::cout << " Bitte geben sie die gewuenschte Ziellegierung ein: " << std::endl;
		alloyWanted = alloyNewLager(lager);
		mengen = functions::makeAlloyMix(Auswahl, alloyWanted);
		if (mengen.size() == 0)
			std::cout << "Produktion so nicht m�glich" << std::endl;
	} while (mengen.size() == 0);


	//Abzug Material Lager
	std::vector<Alloy> lagerAlloysCopy = lager.getAlloys();
	int bestellungSucces = 0;
	unsigned int counterMengen = 0;
	for(auto alloyIterator: Auswahl){
		float amount = lager.getAlloys().at(lager.getAlloyPosByType(alloyIterator)).getAmount();
		bool orderAmount = (amount - mengen.at(counterMengen)*(alloyWanted.getAmount())) <0;
		if(!orderAmount)
			bestellungSucces = -1;
		if(!orderAmount){
			counterMengen++;
			continue;
		}

		do{
			std::cout<<lager.getAlloys().at(lager.getAlloyPosByType(alloyIterator)).getName()<<" "<<"Hat nicht genug im Lager, benoetigt "<<mengen.at(counterMengen)*alloyWanted.getAmount()
			<<" hat aber nur "<<lager.getAlloys().at(lager.getAlloyPosByType(alloyIterator)).getAmount()<<std::endl;
			Storage newLager = lager;
			bestellungSucces = bestellung(newLager,supplierVec,firm);
			lager = newLager;
			orderAmount = (lager.getAlloys().at(lager.getAlloyPosByType(alloyIterator)).getAmount() - mengen.at(counterMengen)*alloyWanted.getAmount()) <0;
			if(bestellungSucces == -1)
				 break;
		}while(orderAmount);
		if(bestellungSucces == -1){
			std::cout<<"Produktion beendet"<<std::endl;
			return;
		}

		//Lager Abziehen
		if(orderAmount){
			Alloy copyAlloy = alloyIterator;
			copyAlloy.setAmount((lager.getAlloys().at(lager.getAlloyPosByType(alloyIterator)).getAmount() - mengen.at(counterMengen)));
			lager.editAlloyByType(alloyIterator,copyAlloy);
			copyAlloy.setAmount(mengen.at(counterMengen));
		}
		counterMengen++;
		//std::cout<<(b2.at(Lager.getAlloyPosByType(i)).getAmount() - mengen.at(x2))<<" "<<(b2.at(Lager.getAlloyPosByType(i)).getName())<<std::endl;
			//BESTELLUNGSFUNKTION!!!		// bzw ABBRUCH
	}
	//Protokollierungswunsch

}


}

