#include "Matrix.h"

Matrix4f::Matrix4f()
{
	InitializeMatrix();
}

Matrix4f::~Matrix4f()
{
	
}

Matrix4f Matrix4f::CargarIdentidad()
{
	InitializeMatrix();
	for(int i = 0; i < 4; i++ )
		elements[i * 5] = 1.0f;

	return *this;
}

Matrix4f Matrix4f::operator*(float f)
{
	Matrix4f result(*this);

	for(int i = 0; i < 16; i++)
		result.elements[i] *= f;
	
	return result;
}

Vector Matrix4f::operator*(Vector vector)
{
	Vector result;
	float punto[] = {vector.x, vector.y, vector.z, 1};
	float puntoResultante[] = {0, 0, 0, 0};
	
	for(int y = 0; y < 4; y++)
		for(int x = 0; x < 4; x++)
			puntoResultante[y] += this->elements[(y * 4) + x] * punto[x];

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
					result.elements[(y * 4) + x] += (this->elements[(y * 4) + z] * m.elements[( z * 4) + x]);
			}
	return result;

}

void Matrix4f::InitializeMatrix()
{
	for(int i = 0; i < 16; i++)
		elements[i] = 0.0f;
}

float* Matrix4f::VectorToMatrix4f(Vector vector)
{
	float result[] = {vector.x, vector.y, vector.z, 1.0f};
	return result;
}

void Matrix4f::operator=(Matrix4f m)
{
	for(int i = 0; i < 16; i++)
		this -> elements[i] = m.elements[i];
}

void Matrix4f::SetElements(float * buffer)
{
	if (!buffer)
		return;

	Matrix4f result(*this);
	try
	{
		for (int i = 0; i < 16; i++)
			this->elements[i] = buffer[i];
	}
	catch (std::out_of_range e)
	{
		for (int i = 0; i < 16; i++)
			this->elements[i] = buffer[i];
	}
}

float* Matrix4f::GetElements()
{
	return elements;
}

float& Matrix4f::operator[](int index)
{
	if (index < 0 || index > 15)
		return elements[0];

	return elements[index];
}

void MatrixRotationX(Matrix4f* matrix, float angle)
{

	matrix->CargarIdentidad();
	matrix->elements[5] = matrix->elements[10] = cos(angle);
	matrix->elements[6] = -(sin(angle));
	matrix->elements[9] = sin(angle);
}
	 
void MatrixRotationY(Matrix4f* matrix, float angle)
{
	matrix->CargarIdentidad();
	matrix->elements[0] = matrix->elements[10] = cos(angle);
	matrix->elements[2] = sin(angle);
	matrix->elements[8] = -(sin(angle));
}
	 
void MatrixRotationZ(Matrix4f* matrix, float angle)
{
	matrix->CargarIdentidad();
	matrix->elements[0] = matrix->elements[5] = cos(angle);
	matrix->elements[1] = -(sin(angle));
	matrix->elements[4] = sin(angle);
}
	 
void MatrixTranslation(Matrix4f* matrix, float x, float y, float z)
{
	matrix->CargarIdentidad();
	matrix->elements[12] = x;
	matrix->elements[13] = y;
	matrix->elements[14] = z;
}
	 
void MatrixScale(Matrix4f* matrix, float x, float y, float z)
{
	matrix->CargarIdentidad();
	matrix->elements[0] = x;
	matrix->elements[5] = y;
	matrix->elements[10] = z;
}