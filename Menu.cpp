/*
 * Menu.cpp
 *
 *  Created on: 13.06.2022
 *      Author: broelaar
 */
#include "Menu.h"
#include "Functions.h"

namespace menu{
void anschriftPflegen(Firm &eigeneFirma) {
	/**
	 * Dieses 'Menue' geht nur eine Ebene tief, d.h. man wählt eine Option aus und wird dann
	 * durch den Prozess durchgeführt.
	 * An manchen Stellen muss die Eingabe zwei mal mit Enter bestätigt werden, bevor man
	 * zum nächsten Punkt weitergeführt wird.
	 *
	 * Die Einbindung der eigenen Firma wurde hier auch noch nicht realisiert.
	 */
	std::string choiceA;

	do {
		std::cout
				<< "Was moechten Sie bearbeiten? \n 1. Ganze Adresse bearbeiten \n "
						"2. Strasse bearbeiten \n 3. ZIP bearbeiten \n 4. City bearbeiten"
						"\n 5. Comment bearbeiten \n 6. Namen bearbeiten \n 0. beenden"
				<< std::endl;

		// bsp objekt unsere eigener Firma, wird später aus anderer Datei genommen
		//Firm EigeneFirma;
		do {
			std::cin >> choiceA;
			if (functions::eingabe(7, choiceA) == -1) {
				std::cout << "Ungueltige Eingabe, bitte neu eingeben: \n"
						<< std::endl;
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
			std::string checkAdresse = eigeneFirma.getStreet();
			checkAdresse.append(eigeneFirma.getZip()).append(
					eigeneFirma.getCity()).append(eigeneFirma.getComment());

			if (checkAdresse == "") {
				std::cout << "Bitte geben Sie die Adresse der Firma ein."
						<< std::endl;
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
				std::cout << "Die aktuelle Adresse lautet:" << std::endl
						<<eigeneFirma.getName() <<std::endl
						<< eigeneFirma.getStreet() << std::endl;
				std::cout << eigeneFirma.getZip() << std::endl
						<< eigeneFirma.getCity() << std::endl
						<< eigeneFirma.getComment() << std::endl;
				std::cout << "Bitte geben Sie die neue Adresse ein."
						<< std::endl;
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
				std::cout << "Bitte geben Sie die Strasse der Firma ein."
						<< std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, strassenname);
				eigeneFirma.setStreet(strassenname);
			} else {
				std::string neueStrassenName;
				std::cout << "Der aktuelle Strassenname lautet: "
						<< eigeneFirma.getStreet() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie den neuen Strassennamen ein."
						<< std::endl;
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
				std::cout << "Bitte geben Sie den ZIP-Code der Firma ein."
						<< std::endl;
				std::string zip;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, zip);
				eigeneFirma.setZip(zip);
			} else {
				std::cout << "Der aktuelle ZIP-Code lautet: "
						<< eigeneFirma.getZip() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie den neuen ZIP-Code ein."
						<< std::endl;
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
				std::cout << "Bitte geben Sie die Stadt der Firma ein."
						<< std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, stadt);
				eigeneFirma.setCity(stadt);
			} else {
				std::string neueStadt;
				std::cout << "Die aktuelle Stadt lautet: "
						<< eigeneFirma.getCity() << ". \n" << std::endl;
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
				std::cout << "Bitte geben Sie einen Kommentar ein."
						<< std::endl;
				std::string comment;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, comment);
				eigeneFirma.setComment(comment);
				break;
			} else {
				std::cout << "Aktueller Kommentar: " << eigeneFirma.getComment()
						<< ". \n" << std::endl;
				std::cout << "Bitte geben Sie einen neuen Kommentar ein. \n"
						<< std::endl;
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
				std::cout << "Aktueller Name: " << eigeneFirma.getName()
						<< ". \n" << std::endl;
				std::cout << "Bitte geben Sie einen neuen Namen ein. \n"
						<< std::endl;
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

std::vector<Supplier> supplierPlfegen(std::vector<Supplier> suppliers) {
	/**
	 * Dieses 'Menue' geht nur eine Ebene tief, d.h. man wählt eine Option aus und wird dann
	 * durch den Prozess durchgeführt.
	 * An manchen Stellen muss die Eingabe zwei mal mit Enter bestätigt werden, bevor man
	 * zum nächsten Punkt weitergeführt wird.
	 *
	 * Die Einbindung der eigenen Firma wurde hier auch noch nicht realisiert.
	 */
	unsigned sup = 1;
	unsigned y = 0;
	for (auto i : suppliers) {
		y++;
		std::cout << y << "	" << i.getName() << std::endl;
	}
	std::cin >> sup;

	std::string choiceA;

	do {
		std::cout
				<< "Was moechten Sie bearbeiten? \n 1. Ganze Adresse bearbeiten \n "
						"2. Strasse bearbeiten \n 3. ZIP bearbeiten \n 4. City bearbeiten"
						"\n 5. Comment bearbeiten \n 6. Namen bearbeiten \n 0. beenden"
				<< std::endl;

		// bsp objekt unsere eigener Firma, wird später aus anderer Datei genommen
		//Firm EigeneFirma;
		do {
			std::cin >> choiceA;
			if (functions::eingabe(7, choiceA) == -1) {
				std::cout << "Ungueltige Eingabe, bitte neu eingeben: \n"
						<< std::endl;
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
			std::cout << "Die aktuelle Adresse lautet:" << std::endl
					<<suppliers.at(y - 1).getName() <<std::endl
					<< suppliers.at(y - 1).getStreet() << std::endl;
			std::cout << suppliers.at(y - 1).getZip() << std::endl
					<< suppliers.at(y - 1).getCity() << std::endl
					<< suppliers.at(y - 1).getComment() << std::endl;
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
				std::cout << "Bitte geben Sie die Strasse der Firma ein."
						<< std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, strassenname);
				suppliers.at(y - 1).setStreet(strassenname);
			} else {
				std::string neueStrassenName;
				std::cout << "Der aktuelle Strassenname lautet: "
						<< suppliers.at(y - 1).getStreet() << ". \n"
						<< std::endl;
				std::cout << "Bitte geben Sie den neuen Strassennamen ein."
						<< std::endl;
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
				std::cout << "Bitte geben Sie den ZIP-Code der Firma ein."
						<< std::endl;
				std::string zip;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, zip);
				suppliers.at(y - 1).setZip(zip);
			} else {
				std::cout << "Der aktuelle ZIP-Code lautet: "
						<< suppliers.at(y - 1).getZip() << ". \n" << std::endl;
				std::cout << "Bitte geben Sie den neuen ZIP-Code ein."
						<< std::endl;
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
				std::cout << "Bitte geben Sie die Stadt der Firma ein."
						<< std::endl;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, stadt);
				suppliers.at(y - 1).setCity(stadt);
			} else {
				std::string neueStadt;
				std::cout << "Die aktuelle Stadt lautet: "
						<< suppliers.at(y - 1).getCity() << ". \n" << std::endl;
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
				std::cout << "Bitte geben Sie einen Kommentar ein."
						<< std::endl;
				std::string comment;
				std::cin.ignore(500, '\n');
				std::getline(std::cin, comment);
				suppliers.at(y - 1).setComment(comment);
				break;
			} else {
				std::cout << "Aktueller Kommentar: "
						<< suppliers.at(y - 1).getComment() << ". \n"
						<< std::endl;
				std::cout << "Bitte geben Sie einen neuen Kommentar ein. \n"
						<< std::endl;
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
				std::cout << "Aktueller Name: " << suppliers.at(y - 1).getName()
						<< ". \n" << std::endl;
				std::cout << "Bitte geben Sie einen neuen Namen ein. \n"
						<< std::endl;
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

	return suppliers;
}

}


