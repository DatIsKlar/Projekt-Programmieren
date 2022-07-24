#ifndef DATA_H_
#define DATA_H_
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <math.h>
namespace data {

/**
 * @fn bool fileExists(std::string filename)
 * ueberprueft ob eine Datei existiert
 * @param filename
 * Dateiname
 * @return
 * gibt True wider wenn Datei gefunden wurde false falls nicht
 *  */
bool fileExists(std::string filename);

/**
 *	@fn std::vector<std::string> getText(char spacer, std::string filename, unsigned int startLine,unsigned int endLine)
 * 	gibt die Daten aus dem Text wieder, benötigt eine Start und End Zeile
 *	@param filename
 *	Dateiname
 *	@param spacer
 *	spacer
 *	@param startLine
 *	die Zeile ab welcher angefangen werden soll zu lesen
 * 	@param endLine
 * 	die Zeile ab welcher das lesen beended werden soll
 * 	@return
 *  gibt einen vector des Typen string zurück
 */
std::vector<std::string> getText(char spacer, std::string filename, unsigned int startLine,unsigned int endLine);

/**
 *	@fn	std::vector<std::string> getTextData((std::string filename, std::string spacer,std::vector<std::string> search)
 *	gibt die Daten aus dem Text in der Reihenfolge der Attribute von search wieder
 *	@param filename
 *	Dateiname
 *	@param spacer
 *	spacer
 *	@param search
 *	vector mit den Header welcher Werte die gesucht werden soll, gibt diese in der Reihenfolge wieder wie eingeben z.b a,b,c wird als a,b,c wiedergegeben wenn es mehere
 *	Werte unter Header a,b,c gibt werden diese wie folgt wieder gegeben header a,b,c als a1,b1,c1,a2,b2,c2 ...
 * 	@return
 * 	gibt einen vector des Typen string zurück
 */
std::vector<std::string> getTextData(std::string filename, std::string spacer, std::vector<std::string> search);
}

#endif /* DATA_H_ */

