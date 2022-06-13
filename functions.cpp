#include "Functions.h"

namespace functions {

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

int eingabe(int obereGrenze, std::string CC) {
	int b = -1;
	if (isNumber(CC)) {
		int ein = stoi(CC);
		if (ein < obereGrenze and ein >= 0)
			return ein;
	}
	return b;
}

bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup) {

	std::ofstream myfile;

	myfile.open(filename + ".csv");
	myfile << "Modus" + spacer + "Kupfer" + spacer + "Zink" + spacer + "Zinn" + spacer + "Name" + spacer + "Menge" + spacer + "Firmname" + spacer + "Strasse" + spacer + "Plz" +spacer + "Stadt" +spacer + "Kommentar" +"\n";

	for (auto x : sup) {
		Alloy i = x.getAlloy();
		char mode = 'x';
		if (i.getCopper() + i.getZinc() + i.getTin() == 1)
			mode = 'p';
		else if (i.getCopper() + i.getZinc() + i.getTin() == 100)
			mode = 'a';

		myfile
				<< mode + spacer + std::to_string(i.getCopper()) + spacer + std::to_string(i.getZinc()) + spacer + std::to_string(i.getTin()) + spacer + i.getName() + spacer
						+ std::to_string(i.getAmount()) + spacer + x.getName() + spacer + x.getStreet() + spacer + x.getZip() + spacer + x.getCity() + spacer + x.getComment();
		myfile << "\n";
	}

	myfile.close();
	return true;
}

void anschriftplfegen(Firm& eigeneFirma){
	/**
	 * Dieses 'Menue' geht nur eine Ebene tief, d.h. man wählt eine Option aus und wird dann
	 * durch den Prozess durchgeführt.
	 * An manchen Stellen muss die Eingabe zwei mal mit Enter bestätigt werden, bevor man
	 * zum nächsten Punkt weitergeführt wird.
	 *
	 * Die Einbindung der eigenen Firma wurde hier auch noch nicht realisiert.
	 */
	std::string choiceA;

	do{
		std::cout << "Was moechten Sie bearbeiten? \n 1. Ganze Adresse bearbeiten \n "
				"2. Strasse bearbeiten \n 3. ZIP bearbeiten \n 4. City bearbeiten"
				"\n 5. Comment bearbeiten \n 0. beenden" << std::endl;

		// bsp objekt unsere eigener Firma, wird später aus anderer Datei genommen
		//Firm EigeneFirma;
		do{
			std::cin >> choiceA;
			if(functions::eingabe(6, choiceA) == -1){
				std::cout << "Ungueltige Eingabe, bitte neu eingeben: \n" << std::endl;
				}
		}while(functions::eingabe(6, choiceA) == -1);

		//cin >> integer;

		switch(stoi(choiceA))
		{
			case 0: // programm beenden
					{
						std::cout << "Programm beendet." << std::endl;
						break;
					} // ende case 6

			case 1:
			{
				std::string checkAdresse = eigeneFirma.getStreet();
				checkAdresse.append(eigeneFirma.getZip()).append(eigeneFirma.getCity()).append(eigeneFirma.getComment());

				if (checkAdresse == ""){
					std::cout << "Bitte geben Sie die Adresse der Firma ein." << std::endl;
					std::cout << "Strassenname: " << std::endl;
					std::string strasse;
					std::cin.ignore(500, '\n');
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
					std::cout << "Die aktuelle Adresse lautet:" <<std::endl<< eigeneFirma.getStreet() << std::endl;
					std::cout << eigeneFirma.getZip() << std::endl << eigeneFirma.getCity() << std::endl << eigeneFirma.getComment() << std::endl;
					std::cout << "Bitte geben Sie die neue Adresse ein." << std::endl;
					std::cout << "Strassenname: "<<std::endl;
					std::string neueStrasse;
					std::cin.ignore(500, '\n');
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
				if(checkStrasse == ""){
					std::string strassenname;
					std::cout << "Bitte geben Sie die Strasse der Firma ein." << std::endl;
					std::cin.ignore(500, '\n');
					std::getline(std::cin, strassenname);
					eigeneFirma.setStreet(strassenname);
				}else{
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
				if(checkZip == ""){
					std::cout << "Bitte geben Sie den ZIP-Code der Firma ein." << std::endl;
					std::string zip;
					std::cin.ignore(500, '\n');
					std::getline(std::cin, zip);
					eigeneFirma.setZip(zip);
				} else{
					std::cout << "Der aktuelle ZIP-Code lautet: " << eigeneFirma.getZip() << ". \n" << std::endl;
					std::cout <<	"Bitte geben Sie den neuen ZIP-Code ein." << std::endl;
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
				if(checkCity == ""){
					std::string stadt;
					std::cout << "Bitte geben Sie die Stadt der Firma ein." << std::endl;
					std::cin.ignore(500, '\n');
					std::getline(std::cin, stadt);
					eigeneFirma.setCity(stadt);
				} else{
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
				if(checkComment == ""){
					std::cout << "Bitte geben Sie einen Kommentar ein." << std::endl;
					std::string comment;
					std::cin.ignore(500, '\n');
					std::getline(std::cin, comment);
					eigeneFirma.setComment(comment);
					break;
				} else {
					std::cout << "Aktueller Kommentar: " << eigeneFirma.getComment() << ". \n" << std::endl;
					std::cout <<	"Bitte geben Sie einen neuen Kommentar ein. \n" << std::endl;
					std::string neuerKommentar;
					std::cin.ignore(500, '\n');
					std::getline(std::cin, neuerKommentar);
					eigeneFirma.setComment(neuerKommentar);
				} // else ende
				break;
			} // ende case 5

			default:
			{
				std::cout << "Ungueltige Eingabe! \n" << std::endl;
				break;
			} // ende default case


		} // ende switch schleife

	} // ende do schleife
	while(stoi(choiceA) != 0);

}

}

