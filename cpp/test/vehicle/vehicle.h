#ifndef _VEHICLE_H_
#define _VEHICLE_H_



class Vehicle{

public:
	Vehicle();
	virtual ~Vehicle();
	
	virtual void run();

};

class Bicycle: public Vehicle{
public:
	Bicycle();
	~Bicycle();
	void run();
};

class Motorcycle: public Vehicle{
public:
	Motorcycle();
	~Motorcycle();
	void run();
};

#endif
