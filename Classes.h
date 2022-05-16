
#include <vector>
#include <string>

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
	std::string adress;
public:
	Firm();
	Firm(std::string nameIn, std::string adressIn);
	std::string getName();
	std::string getAdress();
	void setName(std::string nameIn);
	void setAdress(std::string adressIn);
	void setOrder(float orderIn);
};

class Storage : public Firm {
private:
	std::vector<Alloy> alloy;
public:
	Storage();
	Storage(Alloy);
	std::vector<Alloy> getAlloys();
	Alloy getAlloyByName(std::string alloyNameIn);
	void addAlloy(Alloy);
	void removeAlloy(std::string alloyNameIn, float alloyAmountIn);
	bool saveStorage(std::string nameIn, std::string spacerIn);
	bool readStorage(std::string filename,std::string spacerIn);
};


class Liefer : public Firm{
private:
	Alloy alloy;
	float order;
public:
	Liefer();
	Liefer(Alloy alloyIn,float orderIn);
	void getOrder(float amount);
	Alloy returnOrder();
	Alloy getAlloyLiefer();
};


