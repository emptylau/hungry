#include <iostream>
#include "vehicle.h"


// vehicle
Vehicle::Vehicle(){
	run();
}

Vehicle::~Vehicle(){

}

void Vehicle::run(){
	std::cout << "Vehicle run" << std::endl;
}

// bicycle
Bicycle::Bicycle(){

}

Bicycle::~Bicycle(){

}

void Bicycle::run(){
	std::cout << "Bicycle run" << std::endl;
}

// motorcycle
Motorcycle::Motorcycle(){
}

Motorcycle::~Motorcycle(){

}

void Motorcycle::run(){
	std::cout << "Motorcycle run" << std::endl;
}
