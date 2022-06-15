#ifndef DATA_H_
#define DATA_H_
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace data {

/**
 * @fn bool fileExists(std::string filename)
 * �berpr�ft ob eine Datei existiert.
 * Gibt true wieder wenn es existiert falsch wenn nicht.
 * @param std::string filename
 * Dateiname welcher �berpr�ft werden soll.
 */
bool fileExists(std::string filename);
std::vector<std::string> getHeaderText(char spacer, std::string filename);
std::vector<std::string> getBodyText(char spacer, std::string filename);

//a,b,c
//a1,b1,c1,a2,b2,c2
/**
 *	@fn	std::vector<std::string> getTextData((std::string filename, std::string spacer,std::vector<std::string> search)
 *	gibt die Daten aus dem Text in der Reienfolge der Attribute von search wieder
 *	@param filename
 *	Dateiname
 *	@param spacer
 *	spacer
 *	@param search
 *	vector mit den Header welcher werte gesucht werden soll, gibt diese in der Reihenfolge wieder wie eingeben z.b a,b,c wird als a,b,c wiedergegeben wenn es mehere
 *	Werte unter Header a,b,c gibt werden diese wie folgt wieder gegeben header a,b,c als a1,b1,c1,a2,b2,c2 ...
 */
std::vector<std::string> getTextData(std::string filename, std::string spacer, std::vector<std::string> search);
}

#endif /* DATA_H_ */

