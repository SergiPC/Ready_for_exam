// --------------------------------------------
//              Cercle class
// --------------------------------------------

#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "Point2D.h"
//MACRO PI

template<class KIND>
class Cercle
{
public:
	Point2D<KIND>	position;
	KIND			radius;

	Cercle(const KIND& _x, const KIND& _y, const KIND& _r)
	{
		position.x = _x;
		position.y = _y;
		radius = _r;
	}

	KIND getArea() const
	{
		return = radius * radius * //PI
	}


};

#endif;