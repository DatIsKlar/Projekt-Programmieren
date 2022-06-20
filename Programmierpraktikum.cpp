#include <iostream>
#include <armadillo>
#include <vector>
#include "Classes.h"
#include "Data.h"
#include "Functions.h"
#include "Menu.h"

std::vector<Supplier> suppliers;
int main() {

	Firm eigeneFirma("meinName", "meineStr", "12345", "Cottbus","meinKommentar");
	std::cout<<((std::numeric_limits<float>::max()-200) > 200)<<std::endl;
	std::cout<<functions::eingabe(std::numeric_limits<float>::max()-200, "200")<<std::endl;
	Alloy AEins(10,20,70,"Uno",15);
	Alloy AZwei(20,20,60,"Dos",15);
	Alloy ADrei(50,25,25,"Tres",15);
	Alloy AVier(90,5,5,"Quatro",15);
	Storage Lager;
	Lager.readStorage("test", ";");
	Lager.addAlloy(AEins);
	Lager.addAlloy(AZwei);
	Lager.addAlloy(ADrei);
	Lager.addAlloy(AVier);

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
						std::cout << "\n 1.1 Eigene Anschrift, ";
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
