#include <string>
using namespace std;

class Car
{
public:
	static int inStock;     // class attribute
	string make, model;     // object attributes
	int salePrice;

	Car( string _make, string _model )  // constructor method
	{   make = _make;
		model = _model;
		salePrice = 0;
		inStock = inStock + 1;
	}

	void sell( int price )  // object method
	{   salePrice = price;
		inStock = inStock - 1;
	}

	static int getStockCount()  // class method
	{   return inStock;
	}
};
int Car::inStock = 0;   // static variable initialisation.
