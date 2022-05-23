#include <vector>
#include <string>
#include <armadillo>

class Alloy {
private:
	float copper;
	float zinc;
	float tin;
	std::string name;
	float amount;
public:
	Alloy();
	Alloy(float copperIn, float zincIn, float tinIn, std::string nameIn,float amountIn);
	float getCopper();
	float getZinc();
	float getTin();
	char getMode();
	std::string getName();
	float getAmount();
	void setAmount(float ammountIn);
	//void normalize();
};

class Firm {
private:
	std::string name;
	std::string street;
	std::string zip;
	std::string city;
	std::string comment;
public:
	Firm();
	Firm(std::string nameIn, std::string streetIn, std::string zipIn, std::string cityIn, std::string commentIn);
	std::string getName();
	std::string getStreet();
	std::string getZip();
	std::string getCity();
	std::string getComment();
	void setName(std::string nameIn);
	void setStreet(std::string streetIn);
	void setZip(std::string zipIn);
	void setCity(std::string cityIn);
	void setComment(std::string commentIn);
};

class Storage : public Firm{
private:
	std::vector<Alloy> alloy;
public:
	Storage();
	Storage(std::vector<Alloy> aI);
	std::vector<Alloy> getAlloys();
	unsigned int getAlloyPosByName(std::string alloyNameIn);
	void addAlloy(Alloy);
	void removeAlloy(std::string alloyNameIn, float alloyAmountIn);
	bool saveStorage(std::string nameIn, std::string spacerIn);
	bool readStorage(std::string filename,std::string spacerIn);
	void makeAlloyMix(std::vector<std::string> namesIn,Alloy& wantedIn);
};

class Order{
private:
	float amount;
	std::string firmName;
public:
	Order();
	Order(float amountIn, std::string firmNameIn);
	//~Order();
	float getAmount();
	std::string getFirmName();
	void setAmount(float amountIn);
	void setFirmName(std::string firmNameIn);
};

class Supplier : public Firm{
private:
	Alloy alloy;
	std::vector<Order> order;
public:
	Supplier();
	Supplier(Alloy alloyIn);
	//~Supplier();
	void setOrder(Order orderIn);
	std::vector<Order> getOrder();
	Alloy getAlloy();
	bool saveSupplier(std::string nameIn, std::string spacerIn);
	bool readSupplier(std::string filename, std::string spacerIn);
};


