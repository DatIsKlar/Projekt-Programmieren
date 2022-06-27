#include <iostream>
#include <armadillo>
#include <vector>
#include "Classes.h"
#include "Data.h"
#include "Functions.h"
#include "Menu.h"

std::vector<Supplier> suppliers;
int main() {

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
//	Storage lager(alloyIn);
//	Firm eigeneFirma("meineFirma", "meineStr", "02034", "Berlin", "meinKomment");
//	Supplier Zulieferer(AEins,"meinSupp", "suppStr", "12345", "Berlin", "SuppKomentar");
//	Alloy meineLeg(50, 30, 20, "Legierung1", 2);
//	Order meineBestellung(200, eigeneFirma);
//	suppliers.push_back(Zulieferer);
//	menu::produktion(lager,suppliers, eigeneFirma);

//	arma::vec wanted = { 0.9, 0.05, 0.05 };
//	std::vector<arma::vec> vec_;
//	std::vector<float> returnAmount;
//	arma::vec solution;
//	bool status = false;
//	for (auto i : alloyIn)
//		if (i == wantedIn)
//			//doo
//
//		do {
//
//			std::vector<arma::vec> vec_;
//			for (auto i : alloyIn) {
//				arma::vec alloyNew = { i.getCopper(), i.getZinc(), i.getTin() };
//				vec_.push_back(alloyNew);
//			}
//
//			int size = 0;
//			if (vec_.size() < 2)
//				size = 2;
//			else if (vec_.size() < 3 && vec_.size() == 2)
//				size = 1;
//			arma::mat Gauss(0, size, arma::fill::zeros);
//
//			for(auto i : vec_){
//				Gauss.insert_cols(0, i);
//			}
//
//			arma::vec solution;
//			status = solve(solution, Gauss, wanted, arma::solve_opts::no_approx);
//			for (int x = 0; x < solution.size(); x++) {
//				if (solution[x] < 0)
//					status = false;
//			}
//
//		} while (status);
//

	Firm eigeneFirma("meinName", "meineStr", "12345", "Cottbus","meinKommentar");
		Alloy AEins(0.8,0.2,0,"Uno",15);
		Alloy AZwei(0.95,0,0.05,"Dos",15);
		Alloy ADrei(0.8,0.1,0.1,"Tres",15);
		Alloy AVier(0.9,0.05,0.05,"Quatro",15);
	Storage Lager;
	Lager.readStorage("test", ";");
	Lager.addAlloy(AEins);
	Lager.addAlloy(AZwei);
	Lager.addAlloy(ADrei);
	Lager.addAlloy(AVier);
	suppliers.push_back(Supplier(AEins,"test1","t","t","t","t"));
	suppliers.push_back(Supplier(AZwei,"test2","t","t","t","t"));
	suppliers.push_back(Supplier(ADrei,"test3","t","t","t","t"));
	suppliers.push_back(Supplier(AVier,"test4","t","t","t","t"));

	/**
		 *  Die MenuefXXXhrung geht drei Ebenen in die Tiefe, also man kann max. drei Punkte nacheinander ablaufen
		 *  jede Ebene lXXXuft in einer eigenen While schleife die erst aufhXXXrt wenn der Nutzer eine 0 eingibt
		 *
		 */

		std::string choiceA;
		std::string choiceB;
		std::string choiceC;

		//----------------------------------------------------------------------Anfang A MenXXX
		do {

			std::cout
					<< "\n Bitte eingeben: \n (1) Kontaktbuch \n (2) Lager \n (3) Produktion \n (4) Bestellung \n (0) Beenden \n";

			//Anfang Eingabe A-MenXXX
			/**
			 * XXXberprXXXfung mittels o.G. Funktionen auf Korrektheit
			 */

			do {
				std::cin >> choiceA;
				if (functions::eingabe(5, choiceA) == -1) {
					std::cout << "ungueltige Eingabe, bitte neu eingeben: \n"
							<< std::endl;
				}
			} while (functions::eingabe(5, choiceA) == -1);
			//Ende Eingabe A-MenXXX

			/**
			 *  Bei Erfolgreicher Auswahl
			 */

			switch (stoi(choiceA)) {
			case 0:
				break; //Exit

			case 1: //Kontaktbuch
				std::cout << "1 Kontaktbuch";

				//----------------------------------------------------------------------Anfang B MenXXX

				do {
					std::cout
							<< "\n Bitte eingeben: \n (1) Eigene Anschrift \n (2) Lieferant \n (0) ZurXXXck \n";

					//Anfang Eingabe B-MenXXX
					do {
						std::cin >> choiceB;
						if (functions::eingabe(3, choiceB) == -1) {
							std::cout
									<< "ungueltige Eingabe, bitte neu eingeben: \n"
									<< std::endl;
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

					case 2: //LieferantXXX
						std::cout << "\n 1.2 Lieferant";
						//----------------------------------------------------------------------Anfang C MenXXX

						do {
							std::cout
									<< "\n Bitte eingeben: \n (1) Neuerstellung \n (2) XXXbersicht \n (0) ZurXXXck \n";

							//Anfang Eingabe C-MenXXX
							do {
								std::cin >> choiceC;
								if (functions::eingabe(3, choiceC) == -1) {
									std::cout
											<< "ungueltige Eingabe, bitte neu eingeben: \n"
											<< std::endl;
								}
							} while (functions::eingabe(3, choiceC) == -1);
							//Ende Eingabe C-MenXXX

							switch (stoi(choiceC)) {
							case 0:
								break; //Exit

							case 1: //Neuerstellung
								std::cout << "\n 1.1.2 Neuerstellung"<<std::endl;
								suppliers.push_back(menu::supplierNew(menu::alloyNew(Lager)));
							// ???
								break;

							case 2: //UEbersicht
								std::cout << "\n 1.1.1 Uebersicht"<<std::endl;
								menu::supplierPlfegen(suppliers);
								break;
							}
						} while (stoi(choiceC) != 0);
						break;
					}
					//----------------------------------------------------------------------Ende C MenXXX

				} while (stoi(choiceB) != 0);
				break;
				//----------------------------------------------------------------------Ende B MenXXX

			case 2: //Lager
				std::cout << "\n 2 Lager: ";
				std::cout << "Auflistung Zulieferer + Legierungen\n";
				break;

			case 3: //Produktion
				std::cout << "\n 3 Produktion: ";
				std::cout << "Auflistung Legierungen + Auwahl jener\n";
				menu::produktion(Lager, suppliers,eigeneFirma);


				break;

			case 4: //Bestellung
				std::cout << "\n4 Bestellung: ";
				std::cout << "Eingabe Wunschmenge und Anteile\n";
				break;
			}
		Lager.saveStorage("test",";");
		} while (stoi(choiceA) != 0);
		//----------------------------------------------------------------------Ende A MenXXX
		std::cout << "\n Programm beendet, bis zum naechsten mal!";


}
