#pragma once

#include "includes.h"

class Reservoir
{
private:
	double width;
	double length;
	double depth;
	char* name;
	char* typeReservoir;
	static int sizeStr;
public:
	Reservoir() : Reservoir(0, 0, 0, "N", "N") {};
	Reservoir(double w, double l, double d, const char* name, const char* type);
	Reservoir(const Reservoir& r);
	
	void setWidth(double w);
	void setLength(double l);
	void setDepth(double d);
	void setName(const char* name);
	void setType(const char* type);

	double getWidth() const;
	double getLength() const;
	double getDepth() const;
	char* getName() const;
	char* getType() const;
	static int getSizeStr();

	// methods for works with objects:

	double volume() const;
	double area() const;
	bool compareType(const Reservoir& r);
	bool compareArea(const Reservoir& r);

	~Reservoir();
};

