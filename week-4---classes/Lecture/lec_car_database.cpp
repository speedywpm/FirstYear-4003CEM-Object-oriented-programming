#include <iostream>
using namespace std;

#include "lec_car_database.h"

int main()
{
	Car carA( "Peugeot", "306" );
	Car carB( "Porsche", "911" );
	Car carC( "Bugatti", "Vayron" );

	// getting the attribute of a specific instance
	cout << "carA: " << carA.make << endl; // Peugeot
	cout << "carC: " << carC.make << endl; // Bugatti

	// calling a non-static member function
	carB.sell( 20000 );

	// calling a static member function, either works
	cout << "Stock1: " << carA.getStockCount() << endl; // 2
	cout << "Stock2: " << Car::getStockCount() << endl; // 2

	return 0;
}