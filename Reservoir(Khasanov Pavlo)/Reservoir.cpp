#include "Reservoir.h"

Reservoir::Reservoir(double w, double l, double d, const char* name, const char* type)
{
	if (w > 0)
		width = w;
	else
		width = 0;

	if (l > 0)
		length = l;
	else
		length = 0;

	if (d > 0)
		depth = d;
	else
		depth = 0;

	if (name != nullptr && strlen(name) >= 1) {
		this->name = new char[sizeStr];
		strcpy_s(this->name, sizeStr, name);
	}
	else {
		this->name = new char[sizeStr];
		this->name[0] = 'N';
		this->name[1] = '\0';
	}

	if (type != nullptr && strlen(type) >= 1) {
		typeReservoir = new char[sizeStr];
		strcpy_s(typeReservoir, sizeStr, type);
	}
	else {
		typeReservoir = new char[sizeStr];
		typeReservoir[0] = 'N';
		typeReservoir[1] = '\0';
	}
}

Reservoir::Reservoir(const Reservoir& r)
{
	width = r.width;
	length = r.length;
	depth = r.depth;

	name = new char[sizeStr];
	strcpy_s(name, sizeStr, r.name);

	typeReservoir = new char[sizeStr];
	strcpy_s(typeReservoir, sizeStr, r.typeReservoir);
}

void Reservoir::setWidth(double w)
{
	if (w > 0)
		width = w;
}

void Reservoir::setLength(double l)
{
	if (l > 0)
		length = l;
}

void Reservoir::setDepth(double d)
{
	if (d > 0)
		depth = d;
}

void Reservoir::setName(const char* name)
{
	if (name != nullptr && strlen(name) >= 1) {
		delete[] this->name;
		this->name = new char[sizeStr];
		strcpy_s(this->name, sizeStr, name);
	}
}

void Reservoir::setType(const char* type)
{
	if (type != nullptr && strlen(type) >= 1) {
		delete[] typeReservoir;
		typeReservoir = new char[sizeStr];
		strcpy_s(typeReservoir, sizeStr, type);
	}
}

double Reservoir::getWidth() const
{
	return width;
}

double Reservoir::getLength() const
{
	return length;
}

double Reservoir::getDepth() const
{
	return depth;
}

char* Reservoir::getName() const
{
	return name;
}

char* Reservoir::getType() const
{
	return typeReservoir;
}

int Reservoir::getSizeStr()
{
	return sizeStr;
}

double Reservoir::volume() const
{
	return (width * length * depth);
}

double Reservoir::area() const
{
	return (width * length);
}

bool Reservoir::compareType(const Reservoir& r)
{
	return strcmp(typeReservoir,r.typeReservoir);
}

bool Reservoir::compareArea(const Reservoir& r)
{
	return this->area() > r.area();
}

Reservoir::~Reservoir()
{
	if(name != nullptr && strlen(name) >= 1)
		delete[] name;
	if (typeReservoir != nullptr && strlen(typeReservoir) >= 1)
		delete[] typeReservoir;
	name = nullptr;
	typeReservoir = nullptr;
}

