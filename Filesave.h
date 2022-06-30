/*
 * Filesave.h
 *
 *  Created on: 30.06.2022
 *      Author: Aaron
 */

#ifndef FILESAVE_H_
#define FILESAVE_H_
#include "Menu.h"

namespace filesave{

/**
 * @fn bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup)
 * Speichert ein vector vom typ Supplier in einer csv datei.
 * Gibt true wieder wenn erfolgreich and false wenn nicht.
 * @param std::string filename
 * dateiname
 * @param std::string spacer
 * spacer ( in csv am besten ";" )
 * @param std::vector<Supplier> &sup
 * Refnerz des vector mit in welchem die Supplier gespeichert werden sollen
 */
bool readSupplier(std::string filename, std::string spacer, std::vector<Supplier> &suppliers);

/**
 * @fn bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup)
 * Speichert ein vector vom typ Supplier in einer csv datei.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param std::string filename
 * dateiname
 * @param std::string spacer
 * spacer ( in csv am besten ";" )
 * @param std::vector<Supplier> sup
 * Kopie des vector mit den Supplier
 */
bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup);


/**
 * @fn bool saveStorage(std::string nameIn, std::string spacerIn)
 * Speichert das Lager in einer csv Datei;
 * Gibt wahr wider wenn beendet wurde
 * @param nameIn
 * gew�nschter Dateiname
 * @param spacerIn
 * gew�nschter spacer in der Datei
 */
bool saveStorage(std::string nameIn, std::string spacerIn, Storage lager);

/**
 * @fn bool readStorage(std::string filname, std::string spacerIn)
 * Liest  das Lager aus einer csv Datei und gibt es in das Lager zur�ck
 * Gibt wahr wider wenn beendet wurde
 * @param filname
 * der zu �ffnende Dateiname
 * @param spacerIn
 * spacer in der Datei
 */
bool readStorage(std::string filename, std::string spacerIn, Storage &lager);
}



#endif /* FILESAVE_H_ */
