#ifndef _Matrix4f_
#define _Matrix4f_


#include "Vector.h"

#include <iostream>
#include <math.h>
using namespace std;

class Matrix4f
{
public:
	float elements[16];
	
public: 
	Matrix4f();
	~Matrix4f();

public:
	Matrix4f	CargarIdentidad();
	Matrix4f	operator * (float);
	Matrix4f	operator * (Matrix4f);
	Vector		operator * (Vector);
	void		operator = (Matrix4f);
	void		SetElements(float*);
	float*		GetElements();
	float&		operator [] (int);


private:
	void InitializeMatrix();
	float* VectorToMatrix4f(Vector);
	
};

void MatrixRotationX(Matrix4f*, float);
void MatrixRotationY(Matrix4f*, float);
void MatrixRotationZ(Matrix4f*, float);
void MatrixTranslation(Matrix4f*, float, float, float);
void MatrixScale(Matrix4f*, float, float, float);

#endif