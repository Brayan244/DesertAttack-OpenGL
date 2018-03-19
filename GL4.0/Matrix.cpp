#include "Matrix.h"

Matrix4f::Matrix4f()
{
	IniciaMatriz();
	transposicion = false;
}

Matrix4f::~Matrix4f()
{
	
}

Matrix4f Matrix4f::CargarIdentidad()
{
	IniciaMatriz();
	for(int i = 0; i < 4; i++ )
		elementos[i * 5] = 1.0f;

	return *this;
}

Matrix4f Matrix4f::operator*(float f)
{
	Matrix4f result(*this);

	for(int i = 0; i < 16; i++)
		result.elementos[i] *= f;
	
	return result;
}

Vector Matrix4f::operator*(Vector vector)
{
	Vector result;
	float punto[] = {vector.x, vector.y, vector.z, 1};
	float puntoResultante[] = {0, 0, 0, 0};
	
	for(int y = 0; y < 4; y++)
		for(int x = 0; x < 4; x++)
			puntoResultante[y] += this->elementos[(y * 4) + x] * punto[x];

	return result;
}

Matrix4f Matrix4f::operator*(Matrix4f m)
{
	Matrix4f result;


	for(int y = 0; y < 4; y++)
		for(int x = 0; x < 4; x++)
			for(int z = 0; z < 4; z++)
			{
				if(z < 4)
					result.elementos[(y * 4) + x] += (this->elementos[(y * 4) + z] * m.elementos[( z * 4) + x]);
			}
	return result;

}

void Matrix4f::IniciaMatriz()
{
	for(int i = 0; i < 16; i++)
		elementos[i] = 0.0f;
}

void Matrix4f::LlenaElementos(float* buffer)
{
	if(!buffer)
		return;

	Matrix4f result(*this);
	try
	{
		for(int i = 0; i < 16; i++)
			this->elementos[i] = buffer[i];
	}
	catch(std::out_of_range e)
	{
		for(int i = 0; i < 16; i++)
			this->elementos[i] = buffer[i];
	}
}

float* Matrix4f::VectorToMatrix4f(Vector vector)
{
	float result[] = {vector.x, vector.y, vector.z, 1.0f};
	return result;
}

void Matrix4f::operator=(Matrix4f m)
{
	for(int i = 0; i < 16; i++)
		this -> elementos[i] = m.elementos[i];
	
	this->transposicion = m.transposicion;
}

Matrix4f Matrix4f::Transponer()
{
	Matrix4f result;

	for(int y = 0; y < 4; y++)
		for(int x = 0; x < 4; x++)
			result.elementos[(x * 4) + y] = this->elementos[(y * 4) + x];
	*this = result;
	transposicion = true;
	return result;
}

void MatrixRotationX(Matrix4f* matrix, float angle)
{

	matrix->CargarIdentidad();
	matrix->elementos[5] = matrix->elementos[10] = cos(angle);
	matrix->elementos[6] = -(sin(angle));
	matrix->elementos[9] = sin(angle);
}
	 
void MatrixRotationY(Matrix4f* matrix, float angle)
{
	matrix->CargarIdentidad();
	matrix->elementos[0] = matrix->elementos[10] = cos(angle);
	matrix->elementos[2] = sin(angle);
	matrix->elementos[8] = -(sin(angle));
}
	 
void MatrixRotationZ(Matrix4f* matrix, float angle)
{
	matrix->CargarIdentidad();
	matrix->elementos[0] = matrix->elementos[5] = cos(angle);
	matrix->elementos[1] = -(sin(angle));
	matrix->elementos[4] = sin(angle);
}
	 
void MatrixTranslation(Matrix4f* matrix, float x, float y, float z)
{
	matrix->CargarIdentidad();
	matrix->elementos[12] = x;
	matrix->elementos[13] = y;
	matrix->elementos[14] = z;
}
	 
void MatrixScale(Matrix4f* matrix, float x, float y, float z)
{
	matrix->CargarIdentidad();
	matrix->elementos[0] = x;
	matrix->elementos[5] = y;
	matrix->elementos[10] = z;
}