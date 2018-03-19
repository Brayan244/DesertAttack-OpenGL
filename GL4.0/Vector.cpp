#include "Vector.h"


Vector::Vector()
{
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
}
Vector::Vector(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
void Vector::operator ()(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}
void Vector::operator()(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
}
void Vector::operator()(Vector value)
{
	this->x = value.x;
	this->y = value.y;
	this->z = value.z;
}

void Vector::operator+=(float value)
{
	
	this->x += value;
	this->y += value;
	this->z += value;

}
void Vector::operator+=(Vector V)
{
	this->x += V.x;
	this->y += V.y;
	this->z += V.z;
}
void Vector::operator-=(float value)
{
	this->x -= value;
	this->y -= value;
	this->z -= value;
}
void Vector::operator-=(Vector V)
{
	this->x -= V.x;
	this->y -= V.y;
	this->z -= V.z;
}
void Vector::operator=(float value)
{
	this->x = value;
	this->y = value;
	this->z = value;
}
void Vector::operator=(Vector V)
{
	this->x = V.x;
	this->y = V.y;
	this->z = V.z;
}
Vector Vector::operator*(float value)
{
	Vector result(*this);

	result.x *= value;
	result.y *= value;
	result.z *= value;

	return result;
}