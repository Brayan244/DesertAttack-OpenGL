#ifndef _Matrix4f_
#define _Matrix4f_

#include "openglclass.h"
#include "Vector.h"

#include <iostream>
#include <math.h>
using namespace std;

class Matrix4f
{
public:
	float elementos[16];
	bool  transposicion;

public: 
	Matrix4f();
	~Matrix4f();

public:
	Matrix4f	CargarIdentidad();
	Matrix4f	operator * (float);
	Vector		operator * (Vector);
	Matrix4f	operator * (Matrix4f);
	Matrix4f	Transponer();
	void		operator = (Matrix4f);
	void		LlenaElementos(float*);
	

private:
	void IniciaMatriz();
	float* VectorToMatrix4f(Vector);
	
};

void MatrixRotationX(Matrix4f*, float);
void MatrixRotationY(Matrix4f*, float);
void MatrixRotationZ(Matrix4f*, float);
void MatrixTranslation(Matrix4f*, float, float, float);
void MatrixScale(Matrix4f*, float, float, float);

#endif