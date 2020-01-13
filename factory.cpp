#include <iostream>
#include <string>

using namespace std;

class Sofa
{
private:
public:
	string material;
	virtual void prepare() =0;
};

class leather:public Sofa
{
public:
	void prepare() override
	{
		Sofa::material = "Leather";
		cout << "Sofa prepared with : " << Sofa::material << endl;
	}
};

class rexin:public Sofa
{
public:
	void prepare() override
	{
		Sofa::material = "Rexin";
		cout << "Sofa prepared with : " << Sofa::material << endl;
	}
};

class Factory
{
public:
	virtual Sofa *prepareSofa(string s) = 0;
};

class SofaFactory:public Factory
{
public:
	Sofa *prepareSofa(string s) override
	{
		if (s == "leather")
		{
			Sofa *p = new leather();
			return p;
		}		
		else if (s == "rexin")
		{
			Sofa *p = new rexin();
			return p;
		}		
		
	}
};

int main()
{
	SofaFactory *pFactory = new SofaFactory();
	Sofa *p = pFactory->prepareSofa("leather"); 
	p->prepare();
	p = pFactory->prepareSofa("rexin"); 
	p->prepare();
	return 0;
}


