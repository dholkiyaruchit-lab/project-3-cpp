#include <iostream>
using namespace std;

class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    Vehicle()
    {
        totalVehicles++;
    }

    ~Vehicle()
    {
        totalVehicles--;
    }

    void setVehicle()
    {
        cout << "Enter Vehicle ID: " << endl;
        cin >> vehicleID;
        cin.ignore();

        cout << "Enter Manufacturer: " << endl;
        getline(cin, manufacturer);

        cout << "Enter Model: " << endl;
        getline(cin, model);

        cout << "Enter Year: " << endl;
        cin >> year;
        cin.ignore();
    }

    int getID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    void displayVehicle()
    {
        cout << "\nVehicle ID  : " << vehicleID << endl;
        cout << "Manufacturer  : " << manufacturer << endl;
        cout << "Model         : " << model << endl;
        cout << "Year          : " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

class Car : public Vehicle
{
protected:
    string fuelType;

public:
    void setCar()
    {
        setVehicle();

        cout << "Enter Fuel Type: " << endl;
        cin >> fuelType;
    }

    void display()
    {
        displayVehicle();
        cout << "\nFuel Type: " << fuelType << endl;
    }
};

class ElectricCar : public Car
{
private:
    int batteryCapacity;

public:
    void setElectricCar()
    {
        setVehicle();
        fuelType = "Electric";

        cout << "Enter Battery Capacity: " << endl;
        cin >> batteryCapacity;
    }

    void display()
    {
        displayVehicle();
        cout << "\nFuel Type: " << fuelType << endl;
        cout << "\nBattery Capacity: " << batteryCapacity << endl;
    }
};

class Aircraft
{
protected:
    int flightRange;

public:
    void setAircraft()
    {
        cout << "Enter Flight Range: " << endl;
        cin >> flightRange;
    }

    void displayAircraft()
    {
        cout << "\nFlight Range: " << flightRange << endl;
    }
};

class FlyingCar : public Car, public Aircraft
{
public:
    void setFlyingCar()
    {
        setCar();
        setAircraft();
    }

    void display()
    {
        Car::display();
        displayAircraft();
    }
};

class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    void setSportsCar()
    {
        setElectricCar();

        cout << "Enter Top Speed: " << endl;
        cin >> topSpeed;
    }

    void display()
    {
        ElectricCar::display();
        cout << "\nTop Speed: " << topSpeed << endl;
    }
};

class Sedan : public Car
{
};

class SUV : public Car
{
};

class VehicleRegistry
{
private:
    Vehicle *vehicles[50];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle(Vehicle *v)
    {
        vehicles[count] = v;
        count++;
    }

    void displayAll()
    {
        for (int i = 0; i < count; i++)
        {
            cout << "\n-------------------" << endl;
            vehicles[i]->displayVehicle();
            cout << endl;
        }
    }

    void searchByID(int id)
    {
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getID() == id)
            {
                vehicles[i]->displayVehicle();
                return;
            }
        }

        cout << "\nVehicle Not Found!" << endl;
    }
};

int main()
{
    VehicleRegistry vr;

    int choice, type, id;

    do
    {
        cout << "\n1. Add Vehicle" << endl;
        cout << "\n2. View All Vehicles" << endl;
        cout << "\n3. Search By ID" << endl;
        cout << "\n4. Exit" << endl;

        cout << "\nEnter Choice: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "\n1. Car" << endl;
            cout << "2. Electric Car" << endl;
            cout << "3. Flying Car" << endl;
            cout << "4. Sports Car" << endl;
            cout << "5. Sedan" << endl;
            cout << "6. SUV" << endl;

            cout << "\nEnter Type: " << endl;
            cin >> type;

            if (type == 1)
            {
                Car *c = new Car();
                c->setCar();
                vr.addVehicle(c);
            }

            else if (type == 2)
            {
                ElectricCar *e = new ElectricCar();
                e->setElectricCar();
                vr.addVehicle(e);
            }

            else if (type == 3)
            {
                FlyingCar *f = new FlyingCar();
                f->setFlyingCar();
                vr.addVehicle((Vehicle *)f);
            }

            else if (type == 4)
            {
                SportsCar *s = new SportsCar();
                s->setSportsCar();
                vr.addVehicle(s);
            }

            else if (type == 5)
            {
                Sedan *s = new Sedan();
                s->setCar();
                vr.addVehicle(s);
            }

            else if (type == 6)
            {
                SUV *s = new SUV();
                s->setCar();
                vr.addVehicle(s);
            }

            break;

        case 2:
            vr.displayAll();
            break;

        case 3:

            cout << "Enter Vehicle ID: " << endl;
            cin >> id;

            vr.searchByID(id);
            break;

        case 4:
            cout << "\nExit" << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while (choice != 4);

    return 0;
}