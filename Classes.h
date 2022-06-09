#ifndef CLASSES_H_
#define CLASSES_H_

#include <vector>
#include <string>
#include <armadillo>
#include <fstream>
#include <sstream>
#include "Data.h"
#include <iostream>

class Alloy {
private:
	float copper;
	float zinc;
	float tin;
	std::string name;
	float amount;
public:
	/**
	 * @fn Alloy()
	 * Standart Konstruktor mit leeren Anfangswerten des typen Alloys
	 */
	Alloy();

	/**
	 * @fn Alloy(float copperIn, float zincIn, float tinIn, std::string nameIn,float amountIn)
	 * Konstruktor mit Anfangswerten des typen Alloy
	 * @param float copperIn
	 * Anfangswert von Kuppfer/Copper
	 * @param float zincIn
	 * Anfangswert von Zink/Zinc
	 * @param float tinIn
	 * Anfangswert von Zinn/Tin
	 * @param float nameIn
	 * Setzen vom Namen
	 * @param float amountIn
	 * Anfangswert von der Menge/amount
	 */
	Alloy(float copperIn, float zincIn, float tinIn, std::string nameIn, float amountIn);

	/**
	 *	@fn	float getCopper()
	 *	gibt den Kuppfer/Copper gehalt der Legierung wieder
	 */
	float getCopper();

	/**
	 *	@fn	float getZinc()
	 *	gibt den Zink/Zinc gehalt der Legierung wieder
	 */
	float getZinc();

	/**
	 *	@fn	float getTin()
	 *	gibt den Zinn/Tin gehalt der Legierung wieder
	 */
	float getTin();

	/**
	 *	@fn	std::string getName()
	 *	gibt den Namen der Legierung wieder
	 */
	std::string getName();

	/**
	 *	@fn	float getAmount()
	 *	gibt die Menge der Legierung wieder
	 */
	float getAmount();

	/**
	 *	@fn	setAmount(float ammountIn)
	 *	setzen/überschreiben der Menger der Legierung
	 *	@param amountIn
	 *	neuer Wert der Menge;
	 */
	void setAmount(float ammountIn);

	/**
	 *	@fn	operator==(const Alloy &b)
	 *	Vergleicht zwei Legierungen auf gleichheit a == b und gibt wahr oder falsch wieder
	 *	@param b
	 *	Ist der zu vergleichende Alloy
	 */
	bool operator==(const Alloy &b);

	/**
	 *	@fn	operator!=(const Alloy &b)
	 *	Vergleicht zwei Legierungen auf ungleichheit a !=b und gibt wahr oder falsch wieder
	 *	@param b
	 *	Ist der zu vergleichende Alloy
	 */
	bool operator!=(const Alloy &b);

	void print();
};

class Firm {
private:
	std::string name;
	std::string street;
	std::string zip;
	std::string city;
	std::string comment;
public:
	/**
	 * @fn Firm()
	 * Standart Konstruktor mit leeren Anfangswerten des typen Firm
	 */
	Firm();

	/**
	 * @fn Firm(std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn)
	 * Konstruktor mit Anfangswerten des typen Firm
	 * @param std::string nameIn
	 * Setzen vom Namen
	 * @param std::string streetIn
	 * Setzten der Straße
	 * @param std::sring zipIn
	 * Setzten der Postleitzahl
	 * @param std:.string cityIn
	 * Setzten der Stadt
	 * @param std:.string commandIn
	 * Kommentar über die Firma
	 */
	Firm(std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn);

	/**
	 * @fn std::string getName()
	 * gibt den Namen der Firma wieder
	 */
	std::string getName();

	/**
	 * @fn std::string getStreet()
	 * gibt den Straßennamen wieder
	 */
	std::string getStreet();

	/**
	 * @fn std::string getZip()
	 * gibt die Postleitzahl wieder
	 */
	std::string getZip();

	/**
	 * @fn std::string getCity()
	 * gibt den Stadtnamen wieder
	 */
	std::string getCity();

	/**
	 * @fn std:.string getCommnt()
	 * gibt Kommentar wieder
	 */
	std::string getComment();

	/**
	 * @fn void setname(std::string nameIn)
	 * setzte/überschreibt Firmennamen
	 * @param nameIn
	 * der zu setztende Name
	 */
	void setName(std::string nameIn);

	/**
	 * @fn void setStreet(std::string streetIn)
	 * setzt/überschreibt den Straßennamen
	 * @param steetIn
	 * der zu setztende Straßenname
	 */
	void setStreet(std::string streetIn);

	/**
	 * @fn void setZip(std::string zipIn)
	 * setzt/überschreibt die Postleitzahl
	 * @param zipnIn
	 * die zu setztende Postleitzahl
	 */
	void setZip(std::string zipIn);

	/**
	 * @fn void setCity(std::string cityIn)
	 * setzt/überschreibt den Stadtnamen
	 * @param cityIn
	 * der zu setztende Stadtnamen
	 */
	void setCity(std::string cityIn);

	/**
	 * @fn void commentZip(std::string commentIn)
	 * setzt/überschreibt den Kommentar
	 * @param commentIn
	 * der zu setztende Kommentar
	 */
	void setComment(std::string commentIn);
};

class Storage: public Firm {
private:
	std::vector<Alloy> alloy;
public:
	/**
	 * @fn Storage()
	 * Konstruktor mit leeren Werten des Typen Storage
	 */
	Storage();

	/**
	 * @fn Storage(std::vector<Alloy> aI)
	 * Konstruktor mit Anfangswerten des typen Storage
	 * @param alloyIn
	 * nimmt ein Vector des typen Alloys für die Anfangswerte
	 * wenn noch kein Vector vorliegt nimmt leeren konstruktor und Funktion addAlloy
	 */
	Storage(std::vector<Alloy> alloyIn);

	/**
	 * @fn std::vector<Alloy> getAlloys()
	 * gibt eine Kopie des Vector mit den Gelagerten Legierungen wieder
	 */
	std::vector<Alloy> getAlloys();

	/**
	 * @fn int getAlloyPosByName(std::string alloyNameIn)
	 * gibt einen integer mit der Position der gesuchten Legierung im Vector wieder.
	 * wenn die Legierung nicht gefunden wurde wird eine -1 zurückgeben
	 * @param alloyNameIn
	 * Name der gesuchten Legierung
	 */
	int getAlloyPosByName(std::string alloyNameIn);

	/**
	 * @fn int getAlloyPosByType(Alloy& alloyIn)
	 * gibt einen integer mit der Position der gesuchten Legierung im Vector wieder.
	 * wenn die Legierung nicht gefunden wurde wird eine -1 zurückgeben
	 * @param alloyIn
	 * Referenz der gesuchten Legierung
	 */
	int getAlloyPosByType(Alloy &alloyIn);

	/**
	 * @fn void addAlloy(Alloy alloyIn)
	 * packt ein Legierung dem Lager hinzu/Vector
	 * @param alloyIn
	 * Legierung welche dem lager hinzugefügt werden soll
	 */
	void addAlloy(Alloy alloyIn);

	/**
	 * @fn bool removeAlloyByName(std::string alloyNameIn)
	 * entfernt eine Legierung mit dem gesuchten Namen aus dem Lager
	 * Gibt wahr wider wenn gesuchte Legierung gefunden wurde, falsch wenn nicht
	 * @param alloyNameIn
	 * Name der gesuchten Legierung
	 */
	bool removeAlloyByName(std::string alloyNameIn);

	/**
	 * @fn bool removeAlloyByName(std::string alloyNameIn)
	 * entfernt eine Legierung mit der gesuchten Legierung aus dem Lager.
	 * Gibt wahr wider wenn gesuchte Legierung gefunden wurde, falsch wenn nicht
	 * @param alloyIn
	 * Referenz der gesuchten Legierung
	 */
	bool removeAlloyByType(Alloy &alloyIn);

	/**
	 * @fn bool saveStorage(std::string nameIn, std::string spacerIn)
	 * Speichert das Lager in einer csv Datei;
	 * Gibt wahr wider wenn beendet wurde
	 * @param nameIn
	 * gewünschter Dateiname
	 * @param spacerIn
	 * gewünschter spacer in der Datei
	 */
	bool saveStorage(std::string nameIn, std::string spacerIn);

	/**
	 * @fn bool readStorage(std::string filname, std::string spacerIn)
	 * Liest  das Lager aus einer csv Datei und gibt es in das Lager zurück
	 * Gibt wahr wider wenn beendet wurde
	 * @param filname
	 * der zu öffnende Dateiname
	 * @param spacerIn
	 * spacer in der Datei
	 */
	bool readStorage(std::string filename, std::string spacerIn);

	/**
	 * @fn std::vector<float> makeAlloyMix(std::vector<std::string> namesIn,Alloy& wantedIn)
	 * gibt die Verältnisse der gegebenen Legierung als Vector mit der Postions im Verglich zu der Pos. der gebenen Namen
	 * der gesuchten Legierung wieder und entfernt die benötigte Menge aus dem Lager
	 * @param namesIn
	 * ein Vector mit den Namen der gegebenen Legierungen
	 * @param  wantedIn
	 * eine Referenz der gewünschten Legierung
	 */
	std::vector<float> makeAlloyMix(std::vector<std::string> namesIn, Alloy &wantedIn);

	/**
	 * @fn bool editAlloyByName(std::string namesIn ,Alloy edit)
	 * bearbeitet die gesuchte Legierung mit den neuen Werten, sucht mit Namen.
	 * Gibt wahr wider wenn gesuchte Legierung gefunden wurde, falsch wenn nicht
	 * @param namesIn
	 * Name der gesuchten Legierung
	 * @param edit
	 * Kopie der neuen Legierung
	 */
	bool editAlloyByName(std::string namesIn, Alloy edit);

	/**
	 * @fn bool editAlloyByType(Alloy in ,Alloy edit)
	 * bearbeitet die gesuchte Legierung mit den neuen Werten, sucht mit einer Kopie des gesuchten Alloys.
	 * Gibt wahr wider wenn gesuchte Legierung gefunden wurde, falsch wenn nicht
	 * @param in
	 * kopie der gesuchten Legierung
	 * @param edit
	 * Kopie der neuen Legierung
	 */
	bool editAlloyByType(Alloy in, Alloy edit);
};

class Order {
private:
	float amount;
	std::string firmName;
	unsigned int id;
public:
	/**
	 * @fn Order()
	 * Konstruktor mit leeren Werten des typen Order
	 */
	Order();

	/**
	 * @fn Order(float amountIn, std::string firmNameIn,unsigned int idIn)
	 * Konstruktor mit Anfangswerten des typen Order
	 * @param amountIn
	 * menge der Bestellung
	 * @param firmNameIn
	 * name der Firma  welche die Bestellung aufgibt
	 * @param idIn
	 * Bestellnummer(unsigned int IMMER NUR POSITIVE WERTE)
	 *
	 */
	Order(float amountIn, std::string firmNameIn, unsigned int idIn);
	//~Order();

	/**
	 * @fn float getAmount()
	 * gibt die Menge der Bestellung wieder
	 */
	float getAmount();

	/**
	 * @fn std::string getFirmName()
	 * gibt den Namen der auftraggebenden Firma wieder
	 */
	std::string getFirmName();

	/**
	 * @fn unsigned int getId()
	 * gibt einen immer posetiven Integer wieder, welcher die Bestellungsid wiedergibt
	 */
	unsigned int getId();

	/**
	 * @fn void setAmount(float amountIn)
	 * setzt/überschreibt die Menge der Bestellung
	 * @param amountIn
	 * die neue Bestellmenge
	 */
	void setAmount(float amountIn);

	/**
	 * @fn void setFirmName(std::string firmNameIn)
	 * setzt/überschreibt den Namen der auftraggebenden Firma
	 * @param firmNameIn
	 * neuer Firmenname
	 */
	void setFirmName(std::string firmNameIn);

	/**
	 * @fn void setId(unsigned int idIn)
	 * setzt/überschreibt die Id der Bestellung
	 * @param idIn
	 * neue Id(unsigned int IMMER NUR POSITIVE WERTE)
	 */
	void setId(unsigned int idIn);
};

class Supplier: public Firm {
private:
	Alloy alloy;
	std::vector<Order> order;
public:
	/**
	 * @fn Supplier()
	 * Konstruktor mit leeren Werten des Typen Supplier
	 */
	Supplier();

	/**
	 * @fn Supplier(Alloy alloyIn)
	 * Konstruktor mit Anfangswert
	 * @param alloyIn
	 * Legierung des Zulieferes
	 * hier noch keine Bestellung erst in setOrder
	 */
	Supplier(Alloy alloyIn, std::string nameIn);
	//~Supplier();

	/**
	 * @fn setOrder(Order orderIn)
	 * fügt eine neue Bestellung dem vector Order hinzu
	 * @param
	 * orderIn
	 * neue Bestellung
	 */
	void setOrder(Order orderIn);

	/**
	 * @fn std::vector<Order> getOrder()
	 * gibt eine Kopie des vectors mit den Bestellungen wieder
	 */
	std::vector<Order> getOrder();

	/**
	 * @fn Alloy getAlloy()
	 * gibt eine Kopie der Legierung des Zulieferer wieder
	 */
	Alloy getAlloy();

	//bool saveSupplier(std::string nameIn, std::string spacerIn); muss noch neu überdacht werden speichern und lesen der Zulieferer noch nicht ganz gelöst
	//bool readSupplier(std::string filename, std::string spacerIn);

	/**
	 * @fn int getOrderPosById(unsigned int idIn)
	 * gibt einen integer mit der Position der gesuchten Bestellung im Vector wieder.
	 * wenn die Legierung nicht gefunden wurde wird eine -1 zurückgeben
	 * @param idIn
	 * Id der gesuchten Bestellung
	 */
	int getOrderPosById(unsigned int idIn);

	/**
	 * @fn editOrderById(unsigned int idIn,Order edit)
	 * bearbeitet die gesuchte Bestellung mit den neuen Werten, sucht mit der Id
	 * Gibt wahr wider wenn gesuchte Bestellung gefunden wurde, falsch wenn nicht
	 * @param idIn
	 * Id der gesuchten Bestellung
	 * @param edit
	 * Kopie der neuen Bestellung
	 */
	bool editOrderById(unsigned int idIn, Order edit);

	/**
	 * @fn bool removerOrderById(unsigned int idIn)
	 * entfernt eine Bestellung mit der gesuchten Id.
	 * Gibt wahr wider wenn gesuchte Bestellung gefunden wurde, falsch wenn nicht
	 * @param idIn
	 * Id der gesuchten Bestellung
	 */
	bool removerOrderById(unsigned int idIn);

	//void printOrder(); noch in bearbeitung
};


#endif /* CLASSES_H_ */
