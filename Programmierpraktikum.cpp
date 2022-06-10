#include <iostream>
#include <armadillo>
#include <vector>
#include "Classes.h"
#include "Data.h"
#include "Functions.h"


//

//std::vector<Supplier> a;
//
//int main() {
//
//
////functions bps. functions::readSupplierFile("test",";") wurde einen array mit auﬂ Supplier mit den dataen aus der datei test welche spacer ; benutzt wiedergeben
//	for(auto i : data::getHeaderText(';',"test")){
//		std::cout<<i<<" ";
//	}
//
//
//	std::cout<<functions::isInt(-2);
////	std::vector<arma::vec> a_; //3D Vector im Vector Array def
////	arma::mat A(0, 0); //0x0 Matrix zu def
////	Alloy aA(0.8, 0.2, 0, "name", 5); //test alloys
////	Alloy bA(0.95, 0.0, 0.05, "test", 5);
////	Alloy cA(0.8, 0.1, 0.1, "better", 5);
////	Storage a;
////	Alloy wanted(0.9, 0.05, 0.05, "test2", 5);
////	a.addAlloy(aA);
////	a.addAlloy(bA);
////	a.addAlloy(cA);
////	a.editAlloyByType(bA, Alloy(0.9, 0.1, 0.1, "better2", 5));
////	a.removeAlloyByType(bA);
////	Supplier ac;
////	std::vector<std::string> search = {"Copper","Zinc","Tin","Name","Amount"};
////	std::vector<std::string> da_ = data::getTextData("test",";",search);
//
////	for(auto i: da_){
////		std::cout<<i<<std::endl;
////	}
////
////	for(auto i:a.getAlloys()){
////		std::cout<<i.getName()<<std::endl;
////	}
////	a.editAlloyByName("test",Alloy(.8,0.1,0.1, "better2",5));
////	unsigned int x1 = a.getAlloyPosByName("better2");
////	std::cout<<a.getAlloys().at(x1).getCopper();
//
//	//a.saveStorage("test", ";"); //Lager read/save test;
////	Storage b;
////	b.readStorage("test", ";");
////	for (auto i : b.getAlloys()) {
////		std::cout << i.getCopper() << "	" << i.getName() << std::endl;
////	}
//
//	return 0;
//}

int main() {

		/**
		 *  Die Men¸f¸hrung geht drei Ebenen in die Tiefe, also man kann max. drei Punkte nacheinander ablaufen
		 *  jede Ebene l‰uft in einer eigenen While schleife die erst aufhˆrt wenn der Nutzer eine 0 eingibt
		 *
		 */

		std::string choiceA;
		std::string choiceB;
		std::string choiceC;

		//----------------------------------------------------------------------Anfang A Men¸
		do{

		std::cout << "\n Bitte eingeben: \n (1) Kontaktbuch \n (2) Lager \n (3) Produktion \n (4) Bestellung \n (0) Beenden \n";

		//Anfang Eingabe A-Men¸
		/**
		 * ‹berpr¸fung mittels o.G. Funktionen auf Korrektheit
		 */

		do{
				std::cin >> choiceA;
				if(functions::eingabe(5,choiceA) == -1){
					std::cout<<"ungueltige Eingabe, bitte neu eingeben: \n"<<std::endl;
				}
			}while(functions::eingabe(5,choiceA) == -1);
		//Ende Eingabe A-Men¸

		/**
		 *  Bei Erfolgreicher Auswahl
		 */

		switch(stoi(choiceA)){ case 0: break; //Exit

			case 1: //Kontaktbuch
				std::cout << "1 Kontaktbuch";

				//----------------------------------------------------------------------Anfang B Men¸

					do{ std::cout << "\n Bitte eingeben: \n (1) Eigene Anschrift \n (2) Lieferant \n (0) Zur¸ck \n";

					//Anfang Eingabe B-Men¸
							do{
								std::cin >> choiceB;
								if(functions::eingabe(3,choiceB) == -1){
								std::cout<<"ungueltige Eingabe, bitte neu eingeben: \n"<<std::endl;
								}
							}while(functions::eingabe(3,choiceB) == -1);
					//Ende Eingabe B-Men¸

						switch(stoi(choiceB)){ case 0: break; //Exit

						case 1: //Eigene Anschrift
								std::cout << "\n 1.1 Eigene Anschrift";
								break;

						case 2: //Lieferant
								std::cout << "\n 1.2 Lieferant";
								//----------------------------------------------------------------------Anfang C Men¸

								do{ std::cout << "\n Bitte eingeben: \n (1) Neuerstellung \n (2) ‹bersicht \n (0) Zur¸ck \n";

								//Anfang Eingabe C-Men¸
									do{
										std::cin >> choiceC;
										if(functions::eingabe(3,choiceC) == -1){
										std::cout<<"ungueltige Eingabe, bitte neu eingeben: \n"<<std::endl;
										}
									}while(functions::eingabe(3,choiceC) == -1);
								//Ende Eingabe C-Men¸

									switch(stoi(choiceC)){ case 0: break; //Exit

										case 1: //Neuerstellung
												std::cout << "\n 1.1.2 Neuerstellung";
												break;

										case 2: //‹bersicht
												std::cout << "\n 1.1.1 ‹bersicht";
												break; }
								} while(stoi(choiceC) != 0); break;}
								//----------------------------------------------------------------------Ende C Men¸

					} while(stoi(choiceB) != 0);break;
				//----------------------------------------------------------------------Ende B Men¸

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
		//----------------------------------------------------------------------Ende A Men¸
 std::cout << "\n Programm beendet, bis zum n‰chsten mal!";

}
