/*
 * Filesave.h
 *
 *  Created on: 30.06.2022
 *      Author: Aaron
 */

#ifndef FILESAVE_H_
#define FILESAVE_H_
#include "Menu.h"
#include <type_traits>
namespace filesave{

/**
 * @fn bool readSupplier(std::string filename, std::string spacer, std::vector<Supplier> &suppliers)
 * Liest den Supplier aus einer Datei aus.
 * @param filename
 * dateiname
 * @param spacer
 * spacer ( in csv am besten ";" )
 * @param &sup
 * Referenz des vector mit in welchem die Supplier gespeichert werden sollen
 * 1 = Erfolg
 * 2 = Datei konnte nicht gefunden werden
 * 3 = Datei inhalt stimmt nicht ueberein
 * 4 = unbekannter fehler eventuell falsche datei
 */
int readSupplier(std::string filename, std::string spacer, std::vector<Supplier> &suppliers);

/**
 * @fn bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup)
 * Speichert ein vector vom typ Supplier in einer csv datei.
 * Gibt true wieder wenn wahr and false wenn falsch.
 * @param filename
 * dateiname
 * @param pacer
 * spacer ( in csv am besten ";" )
 * @param sup
 * Kopie des vector mit den Supplier
 */
bool saveSupplier(std::string filename, std::string spacer, std::vector<Supplier> sup);


/**
 * @fn bool saveStorage(std::string nameIn, std::string spacerIn, Storage lager)
 * Speichert das Lager in einer csv Datei;
 * Gibt wahr wider wenn beendet wurde
 * @param nameIn
 * gewuenschter Dateiname
 * @param spacerIn
 * gewuenschter spacer in der Datei
 * @param lager
 * lager welches gespeichert werden soll
 */
bool saveStorage(std::string nameIn, std::string spacerIn, Storage lager);

/**
 * @fn bool readStorage(std::string filname, std::string spacerIn,Storage &lager))
 * Liest  das Lager aus einer Datei aus und gibt es in das Lager zurueck
 * @param filname
 * der zu oeffnende Dateiname
 * @param spacerIn
 * spacer in der Datei
 * @param &lager
 * Referenz des Lagers zu welchem gelesen werden soll.
 * return values:
 * 1 = Erfolg
 * 2 = Datei konnte nicht gefunden werden
 * 3 = Datei inhalt stimmt nicht ueberein
 * 4 = unbekannter fehler eventuell falsche datei
 */
int readStorage(std::string filename, std::string spacerIn, Storage &lager);

/**
 * @fn bool saveFirma(std::string filename, std::string spacer, Firm eigenFirma)
 * Speichert die Firmer in einer csv Datei;
 * Gibt wahr wider wenn beendet wurde
 * @param filename
 * gewuenschter Dateiname
 * @param spacer
 * gewuenschter spacer in der Datei
 * @param eigenFirma
 * die eigene Firma
 */
bool saveFirma(std::string filename, std::string spacer, Firm eigenFirma);

/**
 * @fn bool readFirma(std::string filename, std::string spacer, Firm &eigenFirma)
 * Liest die Firma aus einer Datei aus und gibt es in die eigene Firma zurück
 * @param filname
 * der zu oeffnende Dateiname
 * @param spacer
 * spacer in der Datei
 * @param eigenFirma
 * Referenz zur eigenen Firma
 * return values:
 * 1 = Erfolg
 * 2 = Datei konnte nicht gefunden werden
 * 3 = Datei inhalt stimmt nicht ueberein
 * 4 = unbekannter fehler eventuell falsche datei
 */
void readFirma(std::string filename, std::string spacer, Firm &eigenFirma);
}



#endif /* FILESAVE_H_ */
