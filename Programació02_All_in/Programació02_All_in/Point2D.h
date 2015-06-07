// --------------------------------------------
//              Point2D class
// --------------------------------------------

#ifndef __POINT2D_H__
#define __POINT2D_H__

template<class DITTO>
class Point2D
{
public:

	DITTO x, y;

	// Operators --------------------------------------------
	Point2D operator-(const Point2D &other_point)
	{
		Point2D tmp;

		tmp.x = x - other_point.x;
		tmp.y = y - other_point.y;

		return(tmp);
	}


	Point2D operator+(const Point2D &other_point)
	{
		Point2D tmp;

		tmp.x = x + other_point.x;
		tmp.y = y + other_point.y;

		return(tmp);
	}


	const Point2D& operator+=(const Point2D &other_point)
	{
		x += other_point.x;
		y += other_point.y;

		return(*this);
	}


	const Point2D& operator-=(const Point2D &other_point)
	{
		x -= other_point.x;
		y -= other_point.y;

		return(*this);
	}


	bool operator==(const Point2D &other_point) const
	{
		if (x == other_point.x && y == other_point.y)
			return true;

		else
			return false;

		//return (x == other_point.x && y == other_point.y);
	}


	bool operator!=(const Point2D &other_point) const
	{
		if (x == other_point.x && y == other_point.y)
			return false;

		else
			return true;

		// return (x != other_point.x || y != other_point.y);
	}


	// Utilities --------------------------------------------
	bool isZero() const
	{
		if (x == 0 && y == 0)
			return true;

		else
			return false;

		// return (x == 0 && y == 0);
	}


	const Point2D& setZero()
	{
		x = y = 0;

		return(*this);
	}


	const Point2D& setNegative()
	{
		x = -x;
		y = -y;

		return(*this);
	}


	DITTO distanceTo(const Point2D &other_point)
	{
		DITTO dx = other_point.x - x;
		DITTO dy = other_point.y - y;

		return(sqrt((dx * dx) + (dy * dy)));
	}
	
};

#endif //__POINT2D_H__