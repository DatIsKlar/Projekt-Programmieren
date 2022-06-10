#include <iostream>
#include <armadillo>
#include <vector>
#include "Classes.h"
#include "Data.h"
#include "Functions.h"

int main() {

		/**
		 *  Die Menüführung geht drei Ebenen in die Tiefe, also man kann max. drei Punkte nacheinander ablaufen
		 *  jede Ebene läuft in einer eigenen While schleife die erst aufhört wenn der Nutzer eine 0 eingibt
		 *
		 */

		std::string choiceA;
		std::string choiceB;
		std::string choiceC;

		//----------------------------------------------------------------------Anfang A Menü
		do{

		std::cout << "\n Bitte eingeben: \n (1) Kontaktbuch \n (2) Lager \n (3) Produktion \n (4) Bestellung \n (0) Beenden \n";

		//Anfang Eingabe A-Menü
		/**
		 * Überprüfung mittels o.G. Funktionen auf Korrektheit
		 */

		do{
				std::cin >> choiceA;
				if(functions::eingabe(5,choiceA) == -1){
					std::cout<<"ungueltige Eingabe, bitte neu eingeben: \n"<<std::endl;
				}
			}while(functions::eingabe(5,choiceA) == -1);
		//Ende Eingabe A-Menü

		/**
		 *  Bei Erfolgreicher Auswahl
		 */

		switch(stoi(choiceA)){ case 0: break; //Exit

			case 1: //Kontaktbuch
				std::cout << "1 Kontaktbuch";

				//----------------------------------------------------------------------Anfang B Menü

					do{ std::cout << "\n Bitte eingeben: \n (1) Eigene Anschrift \n (2) Lieferant \n (0) Zurück \n";

					//Anfang Eingabe B-Menü
							do{
								std::cin >> choiceB;
								if(functions::eingabe(3,choiceB) == -1){
								std::cout<<"ungueltige Eingabe, bitte neu eingeben: \n"<<std::endl;
								}
							}while(functions::eingabe(3,choiceB) == -1);
					//Ende Eingabe B-Menü

						switch(stoi(choiceB)){ case 0: break; //Exit

						case 1: //Eigene Anschrift
								std::cout << "\n 1.1 Eigene Anschrift";
								break;

						case 2: //Lieferant
								std::cout << "\n 1.2 Lieferant";
								//----------------------------------------------------------------------Anfang C Menü

								do{ std::cout << "\n Bitte eingeben: \n (1) Neuerstellung \n (2) Übersicht \n (0) Zurück \n";

								//Anfang Eingabe C-Menü
									do{
										std::cin >> choiceC;
										if(functions::eingabe(3,choiceC) == -1){
										std::cout<<"ungueltige Eingabe, bitte neu eingeben: \n"<<std::endl;
										}
									}while(functions::eingabe(3,choiceC) == -1);
								//Ende Eingabe C-Menü

									switch(stoi(choiceC)){ case 0: break; //Exit

										case 1: //Neuerstellung
												std::cout << "\n 1.1.2 Neuerstellung";
												break;

										case 2: //Übersicht
												std::cout << "\n 1.1.1 Übersicht";
												break; }
								} while(stoi(choiceC) != 0); break;}
								//----------------------------------------------------------------------Ende C Menü

					} while(stoi(choiceB) != 0);break;
				//----------------------------------------------------------------------Ende B Menü

			case 2: //Lager
				std::cout << "\n 2 Lager: ";
				std::cout << "Auflistung Zulieferer + Legierungen\n";
				break;


			case 3: //Produktion
				std::cout << "\n 3 Produktion: ";
				std::cout << "Auflistung Legierungen + Auwahl jener\n";
				break;


			case 4: //Bestellung
				std::cout << "\n4 Bestellung: ";
				std::cout << "Eingabe Wunschmenge und Anteile\n";
				break;
			}

		} while(stoi(choiceA) != 0);
		//----------------------------------------------------------------------Ende A Menü
 std::cout << "\n Programm beendet, bis zum nächsten mal!";

}
