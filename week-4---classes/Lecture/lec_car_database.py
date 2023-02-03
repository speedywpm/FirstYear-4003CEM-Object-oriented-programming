class Car:
    inStock = 0

    def __init__( self, _make, _model, _year ):
        self.make = _make
        self.model = _model
        self.year = _year
        self.salePrice = 0

        Car.inStock = Car.inStock + 1
    
    def sell( self, price ):
        self.salePrice = price
        Car.inStock = Car.inStock - 1;

    @staticmethod   # optional, but makes it clear
    def getStockCount():
        return Car.inStock

if __name__ == "__main__":
    carA = Car( "Peugeot", "306", 2018 )
    carB = Car( "Porsche", "911", 1997 )
    carC = Car( "Bugatti", "Vayron", 2005 )

    # getting the attribute of a specific instance
    print( "carA:", carA.make ) # Peugeot
    print( "carC:", carC.make ) # Bugatti

    # calling a non-static member function
    carB.sell( 20000 )

    # calling a static member function, either works
    print( "Stock1:", carA.getStockCount() ) # 2
    print( "Stock2:", Car.getStockCount() ) # 2
