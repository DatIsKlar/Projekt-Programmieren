#include <iostream>
#include <armadillo>
#include <vector>
#include "Classes.h"
#include "Data.h"
#include "Functions.h"

int main() {

		/**
		 *  Die Men�f�hrung geht drei Ebenen in die Tiefe, also man kann max. drei Punkte nacheinander ablaufen
		 *  jede Ebene l�uft in einer eigenen While schleife die erst aufh�rt wenn der Nutzer eine 0 eingibt
		 *
		 */

		std::string choiceA;
		std::string choiceB;
		std::string choiceC;

		//----------------------------------------------------------------------Anfang A Men�
		do{

		std::cout << "\n Bitte eingeben: \n (1) Kontaktbuch \n (2) Lager \n (3) Produktion \n (4) Bestellung \n (0) Beenden \n";

		//Anfang Eingabe A-Men�
		/**
		 * �berpr�fung mittels o.G. Funktionen auf Korrektheit
		 */

		do{
				std::cin >> choiceA;
				if(functions::eingabe(5,choiceA) == -1){
					std::cout<<"ungueltige Eingabe, bitte neu eingeben: \n"<<std::endl;
				}
			}while(functions::eingabe(5,choiceA) == -1);
		//Ende Eingabe A-Men�

		/**
		 *  Bei Erfolgreicher Auswahl
		 */

		switch(stoi(choiceA)){ case 0: break; //Exit

			case 1: //Kontaktbuch
				std::cout << "1 Kontaktbuch";

				//----------------------------------------------------------------------Anfang B Men�

					do{ std::cout << "\n Bitte eingeben: \n (1) Eigene Anschrift \n (2) Lieferant \n (0) Zur�ck \n";

					//Anfang Eingabe B-Men�
							do{
								std::cin >> choiceB;
								if(functions::eingabe(3,choiceB) == -1){
								std::cout<<"ungueltige Eingabe, bitte neu eingeben: \n"<<std::endl;
								}
							}while(functions::eingabe(3,choiceB) == -1);
					//Ende Eingabe B-Men�

						switch(stoi(choiceB)){ case 0: break; //Exit

						case 1: //Eigene Anschrift
								std::cout << "\n 1.1 Eigene Anschrift";
								break;

						case 2: //Lieferant
								std::cout << "\n 1.2 Lieferant";
								//----------------------------------------------------------------------Anfang C Men�

								do{ std::cout << "\n Bitte eingeben: \n (1) Neuerstellung \n (2) �bersicht \n (0) Zur�ck \n";

								//Anfang Eingabe C-Men�
									do{
										std::cin >> choiceC;
										if(functions::eingabe(3,choiceC) == -1){
										std::cout<<"ungueltige Eingabe, bitte neu eingeben: \n"<<std::endl;
										}
									}while(functions::eingabe(3,choiceC) == -1);
								//Ende Eingabe C-Men�

									switch(stoi(choiceC)){ case 0: break; //Exit

										case 1: //Neuerstellung
												std::cout << "\n 1.1.2 Neuerstellung";
												break;

										case 2: //�bersicht
												std::cout << "\n 1.1.1 �bersicht";
												break; }
								} while(stoi(choiceC) != 0); break;}
								//----------------------------------------------------------------------Ende C Men�

					} while(stoi(choiceB) != 0);break;
				//----------------------------------------------------------------------Ende B Men�

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
		//----------------------------------------------------------------------Ende A Men�
 std::cout << "\n Programm beendet, bis zum n�chsten mal!";

}
