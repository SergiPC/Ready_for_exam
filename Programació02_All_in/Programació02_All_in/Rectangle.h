// --------------------------------------------
//              Rectangle class
// --------------------------------------------


#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "Point2D.h"

template<class DITTO>
class Rectangle
{
public:

	Point2D<DITTO>	position;
	DITTO			w;
	DITTO			h;


	Rectangle(const DITTO& _x, const DITTO& _y, const DITTO& _w, const DITTO& _h)
	{
		position.x = _x;
		position.y = _y;
		w = _w;
		h = _h;
	}


	Rectangle(const Rectangle& other_rec)
	{
		position.x = other_rec.position.x;
		position.y = other_rec.position.y;
		w = other_rec.w;
		h = other_rec.h;
	}


	DITTO getArea() const
	{
		return w * h;
	}


	bool intersects(const Rectangle& other_rec)
	{
		if ((other_rec.position.x - position.x < w) && (other_rec.position.y - position.y < h))
			return true;

		else
			return false;
	}

};

#endif; // __RECTANGLE_H__