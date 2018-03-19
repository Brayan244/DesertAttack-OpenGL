#ifndef _VECTOR_
#define _VECTOR_

class Vector
{
public:
	float x;
	float y;
	float z;

	Vector();
	Vector(float,float,float);

	void operator () (float,float,float);
	void operator () (float);
	void operator () (Vector);
	Vector operator * (float);
	Vector operator * (Vector);
	void operator +=(float);
	void operator +=(Vector);
	void operator -=(float);
	void operator -=(Vector);
	void operator = (float);
	void operator = (Vector);
};

#endif
