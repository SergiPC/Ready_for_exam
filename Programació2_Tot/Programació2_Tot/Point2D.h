// --------------------------------------------
//              Point2D class
// --------------------------------------------

#ifndef __POINT2D_H__
#define __POINT2D_H__

template<class KIND>
class Point2D
{
public:

	KIND x, y;

	// Basic Operations ------------------------------------
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


	bool operator==(const Point2D& other_point) const
	{
		return (x == other_point.x && y == other_point.y);
	}


	bool operator!=(const Point2D& other_point) const
	{
		return (x != other_point.x || y != other_point.y);
	}

	// Utilities -------------------------------------------
	bool isZero() const
	{
		return (x == 0 && y == 0);
	}


	Point2D& setZero()
	{
		x = y = 0;

		return(*this);
	}


	Point2D& setNegative()
	{
		x = -x;
		y = -y;

		return(*this);
	}

	// Distance To -----------------------------------------
	KIND distanceTo(const Point2D& other_point)
	{
		KIND dx = x - other_point.x;
		KIND dy = y - other_point.y;

		return(sqrt((dx * dx) + (dy * dy)));
	}
};
#endif //  __POINT2D_H__
