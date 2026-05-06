Vehicle Management System 🚗✈️
https://onlinegdb.com/sNSWpIinXE

The Vehicle Management System is a C++ console-based project developed using Object-Oriented Programming (OOP) concepts.
This project allows users to add, display, and search different types of vehicles such as Cars, Electric Cars, Flying Cars, Sports Cars, Sedans, and SUVs.

The project demonstrates important C++ concepts like:

Classes & Objects
Inheritance
Multilevel Inheritance
Multiple Inheritance
Hierarchical Inheritance
Encapsulation
Static Data Members
Dynamic Memory Allocation
Arrays of Objects
Function Overriding
Features ✨
Add different vehicle types
Display all stored vehicles
Search vehicle by ID
Supports multiple inheritance (FlyingCar)
Supports multilevel inheritance (SportsCar)
Uses dynamic memory allocation with new
Tracks total vehicles using static member
Class Structure 🏗️
Base Class
Vehicle

Stores common vehicle details:

Vehicle ID
Manufacturer
Model
Year
Derived Classes
Car : public Vehicle

Adds:

Fuel Type
ElectricCar : public Car

Adds:

Battery Capacity
FlyingCar : public Car, public Aircraft

Demonstrates:

Multiple Inheritance

Adds:

Flight Range
SportsCar : public ElectricCar

Demonstrates:

Multilevel Inheritance

Adds:

Top Speed
Sedan : public Car

Simple inherited class.

SUV : public Car

Simple inherited class.

Additional Class
Aircraft

Stores:

Flight Range

Used in:

FlyingCar
Registry System 📋
VehicleRegistry

Manages all vehicles using:

Vehicle *vehicles[50];

Functions:

Add Vehicle
Display All Vehicles
Search Vehicle by ID
Concepts Used 📚
Concept	Usage
Encapsulation	Private data members
Inheritance	Vehicle → Car
Multilevel Inheritance	Vehicle → Car → ElectricCar → SportsCar
Multiple Inheritance	FlyingCar inherits Car & Aircraft
Hierarchical Inheritance	Sedan & SUV inherit Car
Dynamic Memory Allocation	new keyword
Static Member	totalVehicles
Arrays of Pointers	Vehicle *vehicles[50]
Menu System 🖥️
1. Add Vehicle
2. View All Vehicles
3. Search By ID
4. Exit
Sample Output 📌
1. Add Vehicle
2. View All Vehicles
3. Search By ID
4. Exit

Enter Choice:
1

1. Car
2. Electric Car
3. Flying Car
4. Sports Car
5. Sedan
6. SUV


Author 👨‍💻

Ruchit
