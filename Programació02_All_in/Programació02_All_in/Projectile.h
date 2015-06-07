// --------------------------------------------
//              Projectile class
// --------------------------------------------

#ifndef __PROJECTILE_H__
#define __PROJECTILE_H__

#include "Point2D.h" 

class Projectile
{
public:

	Point2D<float>point;
	Point2D<float>speed;

	Point2D<float> getCurrentPosition(float time) const
	{
		Point2D<float>t;
		t.x = point.x + speed.x * time;
		t.y = point.y + speed.y * time;

		return t;
	}
};

#endif // __PROJECTILE_H__