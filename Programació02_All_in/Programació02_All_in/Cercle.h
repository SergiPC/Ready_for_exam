// --------------------------------------------
//              Cercle class
// --------------------------------------------

#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "Point2D.h"
#define PI 3.141521f

template<class DITTO>
class Cercle
{
public:
	Point2D<DITTO>	position;
	DITTO			radius;

	Cercle(const DITTO& _x, const DITTO& _y, const DITTO& _r)
	{
		position.x = _x;
		position.y = _y;
		radius = _r;
	}

	DITTO getArea() const
	{
		return radius * radius * PI;
	}


};

#endif; // __CERCLE_H__