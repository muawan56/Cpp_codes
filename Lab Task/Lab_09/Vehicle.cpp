#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int mileage;
    double price;
    double ownershipFee;

public:
    Vehicle(int _mileage, double _price, double _ownershipFee)
        : mileage(_mileage), price(_price), ownershipFee(_ownershipFee) {}

    friend ostream &operator<<(ostream &out, const Vehicle &vehicle)
    {
        out << "\nPrice: Rs." << vehicle.price << endl;
        out << "Mileage: " << vehicle.mileage << endl;
        out << "Ownership Fee: " << vehicle.ownershipFee << endl;
        return out;
    }
};

class Car : public Vehicle
{
protected:
    int seatingCapacity;
    char fuelType;

public:
    Car(int _mileage, double _price, double _ownershipFee, int _seatingCapacity, char _fuelType)
        : Vehicle(_mileage, _price, _ownershipFee), seatingCapacity(_seatingCapacity), fuelType(_fuelType) {}

    friend ostream &operator<<(ostream &out, const Car &car)
    {
        out << static_cast<const Vehicle &>(car);
        out << "Seating Capacity: " << car.seatingCapacity << endl;
        out << "Fuel Type: " << car.fuelType << endl;
        return out;
    }
};

class ImportedCar : public Car
{
private:
    int importYear;
    int manufactureYear;
    int mileageAbroad;

public:
    ImportedCar(int _mileage, double _price, double _ownershipFee, int _seatingCapacity, char _fuelType, int _importYear, int _manufactureYear, int _mileageAbroad)
        : Car(_mileage, _price, _ownershipFee, _seatingCapacity, _fuelType), importYear(_importYear), manufactureYear(_manufactureYear), mileageAbroad(_mileageAbroad) {}

    friend ostream &operator<<(ostream &out, const ImportedCar &iCar)
    {
        out << static_cast<const Car &>(iCar);
        out << "Import Year: " << iCar.importYear << endl;
        out << "Manufactured Year: " << iCar.manufactureYear << endl;
        out << "Mileage Abroad: " << iCar.mileageAbroad << endl;
        out << "------------------" << endl;
        return out;
    }
};

class LocalCar : public Car
{
public:
    LocalCar(int _mileage, double _price, double _ownershipFee, int _seatingCapacity, char _fuelType, int _manufactureYear)
        : Car(_mileage, _price, _ownershipFee, _seatingCapacity, _fuelType), manufactureYear(_manufactureYear) {}

    friend ostream &operator<<(ostream &out, const LocalCar &lCar)
    {
        out << static_cast<const Car &>(lCar);
        out << "Manufactured Year: " << lCar.manufactureYear << endl;
        out << "------------------" << endl;
        return out;
    }

private:
    int manufactureYear;
};

class Bike : public Vehicle
{
private:
    int cc;
    int tankSize;

public:
    Bike(int _mileage, double _price, double _ownershipFee, int _cc, int _tankSize)
        : Vehicle(_mileage, _price, _ownershipFee), cc(_cc), tankSize(_tankSize) {}

    friend ostream &operator<<(ostream &out, const Bike &bike)
    {
        out << static_cast<const Vehicle &>(bike);
        out << "Engine Capacity: " << bike.cc << endl;
        out << "Tank Size: " << bike.tankSize << " Inches" << endl;
        out << "------------------" << endl;
        return out;
    }
};

class HeavyBike : public Bike
{
private:
    int cylinders;
    int numberOfGears;
    char coolingType;
    char wheelType;

public:
    HeavyBike(int _mileage, double _price, double _ownershipFee, int _cc, int _tankSize, int _cylinders, int _numberOfGears, char _coolingType, char _wheelType)
        : Bike(_mileage, _price, _ownershipFee, _cc, _tankSize), cylinders(_cylinders), numberOfGears(_numberOfGears), coolingType(_coolingType), wheelType(_wheelType) {}

    friend ostream &operator<<(ostream &out, const HeavyBike &hbike)
    {
        out << static_cast<const Bike &>(hbike);
        out << "Cylinders: " << hbike.cylinders << endl;
        out << "Number Of Gears: " << hbike.numberOfGears << endl;
        out << "Cooling Type: " << hbike.coolingType << endl;
        out << "Tyre Type: " << hbike.wheelType << endl;
        out << "------------------" << endl;
        return out;
    }
};

int main()
{
    Bike bike(120000, 70000, 1000, 70, 10);
    cout << bike;

    HeavyBike hbike(120000, 70000, 1000, 70, 10, 4, 6, 'A', 'A');
    cout << hbike;

    ImportedCar iCar(120000, 870000, 10000, 5, 'P', 2008, 2006, 90000);
    cout << iCar;

    LocalCar lCar(120000, 870000, 10000, 5, 'P', 2008);
    cout << lCar;

    return 0;
}
