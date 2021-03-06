#include <iostream>
#include <armadillo>
#include <vector>
#include "Classes.h"
#include "Data.h"
#include "Functions.h"
#include "Menu.h"
#include "Filesave.h"

std::vector<Supplier> suppliers;
int main() {
//
//	std::vector<Alloy> alloyIn;
//	Alloy AEins(0.8,0.2,0,"Uno",15);
//	Alloy AZwei(0.95,0,0.05,"Dos",15);
//	Alloy ADrei(0.8,0.1,0.1,"Tres",15);
//	Alloy AVier(0.9,0.05,0.05,"Quatro",15);
//	Alloy AVF(0.7,0.3,0,"Quatro",15);
//	alloyIn.push_back(AEins);
//	alloyIn.push_back(AZwei);
//	alloyIn.push_back(ADrei);
//	alloyIn.push_back(AVier);
//	alloyIn.push_back(AVF);
//	Alloy wantedIn(0.9, 0.05, 0.05,"want",15);
//	Storage Lager;
//	Firm eigeneFirma("meineFirma", "meineStr", "02034", "Berlin", "meinKomment");
//	Supplier Zulieferer(AEins,"meinSupp1", "suppStr1", "12345", "Berlin1", "SuppKomentar1");
//	Supplier Zulieferer2(AZwei,"meinSupp2", "suppStr2", "12345", "Berlin2", "SuppKomentar2");
//	Supplier Zulieferer3(ADrei,"meinSupp3", "suppStr3", "12345", "Berlin3", "SuppKomentar3");
//	Supplier Zulieferer4(AVier,"meinSupp4", "suppStr4", "12345", "Berlin4", "SuppKomentar4");
//	Alloy meineLeg(50, 30, 20, "Legierung1", 2);
//	Order meineBestellung(200, eigeneFirma);
//	suppliers.push_back(Zulieferer);
//	suppliers.push_back(Zulieferer2);
//	suppliers.push_back(Zulieferer3);
//	suppliers.push_back(Zulieferer4);
//
//	std::cout<<filesave::readSupplier("test", ";", suppliers);
//
//	//functions::saveSupplier("testsup", ";", suppliers);

//todo einlesen datei falls die standart nicht existiert
//	if(couldReadStorage == 2){
//		std::string choiceA;
//		std::cout<<"Standart Datei existiert nicht moechte Sie eine manuell einlesen?"<<std::endl;
//		std::cout<<"1. Yes"<<std::endl;
//		std::cout<<"2. No"<<std::endl;
//		std::cout<<"0. Exist Programm"<<std::endl;
//		do {
//			std::cin >> choiceA;
//			if (functions::eingabe(3, choiceA) == -1) {
//				std::cout << "ungueltige Eingabe, bitte neu eingeben: \n"
//						<< std::endl;
//			}
//		} while (functions::eingabe(3, choiceA) == -1);
//	}
//	if(couldReadSuppliers == 2){
//		std::cout<<"Standart Datei fuer Zuliefere existiert nicht moechte Sie eine manuell einlesen?"<<std::endl;
//	}
//

	/**
	 *  Die MenuefUehrung geht drei Ebenen in die Tiefe, also man kann max. drei Punkte nacheinander ablaufen
	 *  jede Ebene laeuft in einer eigenen While schleife die erst aufhoert wenn der Nutzer eine 0 eingibt
	 *
	 */

//todo ProdProduktion in produktion aufrufen, Dateinamen ver?ndern
//--------------------TobiTest Protokoll
//		Alloy AEins(10,20,70,"asdf",15);
//		Alloy AZwei(20,20,60,"Dos",15);
//		Alloy ADrei(50,25,25,"Trassdfsdfes",15);
//		Alloy AVier(90,5,5,"Qro",15);
//		lager.addAlloy(AEins);
//		lager.addAlloy(AZwei);
//		lager.addAlloy(ADrei);
//		lager.addAlloy(AVier);
//		Alloy wantedIn(0.9, 0.05, 0.05,"want",15);
//		std::vector<Alloy> vekki = {AEins, AZwei, ADrei, AVier};
//		std::vector<float> t = {1,1,1,1};
	//menu::ProdProtokoll(vekki,eigeneFirma,wantedIn,t);
	//--------------------------Ende
	Storage lager;
	std::string storageName = "storage";
	std::string suppliersName = "suppliers";
	int couldReadStorage = filesave::readStorage("storage", ";", lager);
	int couldReadSuppliers = filesave::readSupplier("suppliers", ";", suppliers);

	Firm eigeneFirma("meineFirma", "meineStr", "01234", "meineStadt", "meinKomment");
	filesave::readFirma("firma",";",eigeneFirma);

	std::string choiceA;
	std::string choiceB;
	std::string choiceC;
	//----------------------------------------------------------------------Anfang A Menue
	do {

		std::cout << "\n Bitte eingeben: \n (1) Kontaktbuch \n (2) Lager \n (3) Produktion \n (4) Bestellung \n (0) Beenden \n";

		//Anfang Eingabe A-Menue
		/**
		 * ueberpruefung mittels o.G. Funktionen auf Korrektheit
		 */

		do {
			std::cin >> choiceA;
			if (functions::eingabe(5, choiceA) == -1) {
				std::cout << "Ungueltige Eingabe, bitte neu eingeben: \n" << std::endl;
			}
		} while (functions::eingabe(5, choiceA) == -1);
		//Ende Eingabe A-Menue

		/**
		 *  Bei Erfolgreicher Auswahl
		 */

		switch (stoi(choiceA)) {
		case 0:
			break; //Exit

		case 1: //Kontaktbuch
			std::cout << "1 Kontaktbuch";

			//----------------------------------------------------------------------Anfang B Menue

			do {
				std::cout << "\n Bitte eingeben: \n (1) Eigene Anschrift \n (2) Lieferant \n (0) Zurueck \n";

				//Anfang Eingabe B-Menue
				do {
					std::cin >> choiceB;
					if (functions::eingabe(3, choiceB) == -1) {
						std::cout << "Ungueltige Eingabe, bitte neu eingeben: \n" << std::endl;
					}
				} while (functions::eingabe(3, choiceB) == -1);
				//Ende Eingabe B-Menue

				switch (stoi(choiceB)) {
				case 0:
					break; //Exit

				case 1: //Eigene Anschrift
					std::cout << "\n 1.1 Eigene Anschrift: \n";
					menu::anschriftPflegen(eigeneFirma);
					break;

				case 2: //Lieferantue

				//----------------------------------------------------------------------Anfang C Menue

				do {
					std::cout << "\n Bitte eingeben: \n (1) Neuerstellung \n (2) Uebersicht \n (0) Zurueck \n";

					//Anfang Eingabe C-MenUe
					do {
						std::cin >> choiceC;
						if (functions::eingabe(3, choiceC) == -1) {
							std::cout << "Ungueltige Eingabe, bitte neu eingeben: \n" << std::endl;
						}
					} while (functions::eingabe(3, choiceC) == -1);
					//Ende Eingabe C-MenUe

					switch (stoi(choiceC)) {
					case 0:
						break; //Exit

					case 1: //Neuerstellung
						std::cout << "\n 1.1.2 Neuerstellung" << std::endl;
						suppliers.push_back(menu::supplierNew(menu::alloyNewSupplier()));
						// ???
						break;

					case 2: //UEbersicht
						std::cout << "\n 1.1.1 Uebersicht" << std::endl;
						menu::supplierPlfegen(suppliers);
						break;
					}
					} while (stoi(choiceC) != 0);
					break;
				}
				//----------------------------------------------------------------------Ende C MenUe

			} while (stoi(choiceB) != 0);
			break;
			//----------------------------------------------------------------------Ende B MenUe

		case 2: //Lager
		{
			std::cout << "\n 2 Lager: ";
			std::cout << "Auflistung Legierungen\n";
			unsigned counterNew = 0;
			for (auto i : lager.getAlloys()) {
				counterNew++;
				std::cout << counterNew << " Legierung: " << i.getName() << "\t Kupfer: " << i.getCopper() << "\t Zink: " << i.getZinc() << "\t Zinn:\t" << i.getTin() <<
						"\t Menge: " << i.getAmount() <<std::endl;
				//std::cout << counterSupplier << " " << i.getName() <<": "<<i.getCopper()<< << std::endl;
			}
		}
			break;
			//alloyHinzufuegen menu::alloyNewLager(lager)

		case 3: //Produktion
			std::cout << "\n 3 Produktion: ";
			std::cout << "Auflistung Legierungen + Auwahl jener\n";
			menu::produktion(lager, suppliers, eigeneFirma);
			break;

		case 4: //Bestellung
			std::cout << "\n4 Bestellung: " << std::endl;
			//Storage newLager = Lager;
			int bestellungSucces = menu::bestellung(lager, suppliers, eigeneFirma);
			//Lager = newLager;

			break;
		}
		filesave::saveStorage("storage", ";", lager);
		filesave::saveSupplier("suppliers", ";", suppliers);
		filesave::saveFirma("firma",";",eigeneFirma);
	} while (stoi(choiceA) != 0);
	//----------------------------------------------------------------------Ende A MenUe
	std::cout << "\n Programm beendet, bis zum naechsten mal!";
}
