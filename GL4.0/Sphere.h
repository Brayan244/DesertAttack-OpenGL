#pragma once
#include "modelclass.h"

#define D3DX_PI 3.141592


class Sphere :
	public ModelClass
{
public:
	Sphere();
	~Sphere();

protected:
	bool Estrategia();
};

