// --------------------------------------------
//              Point3D class
// --------------------------------------------

#ifndef __VECTOR3D_H__
#define __VECTOR3D_H__

template<class DITTO>
class Vector3D
{
public:

	DITTO x, y, z;

	// Operators --------------------------------------------
	Vector3D operator-(const Vector3D &other_point)
	{
		Vector3D tmp;

		tmp.x = x - other_point.x;
		tmp.y = y - other_point.y;
		tmp.z = z - other_point.z;

		return(tmp);
	}


	Vector3D operator+(const Vector3D &other_point)
	{
		Vector3D tmp;

		tmp.x = x + other_point.x;
		tmp.y = y + other_point.y;
		emp.z = z + other_point.z;

		return(tmp);
	}


	const Vector3D& operator+=(const Vector3D &other_point)
	{
		x += other_point.x;
		y += other_point.y;
		z += other_point.z;

		return(*this);
	}


	const Vector3D& operator-=(const Vector3D &other_point)
	{
		x -= other_point.x;
		y -= other_point.y;
		z -= other_point.z;

		return(*this);
	}


	bool operator==(const Vector3D &other_point) const
	{
		if (x == other_point.x && y == other_point.y && z == other_point.z)
			return true;

		else
			return false;

		//return (x == other_point.x && y == other_point.y);
	}


	bool operator!=(const Vector3D &other_point) const
	{
		if (x == other_point.x && y == other_point.y && z == other_point.z)
			return false;

		else
			return true;

		// return (x != other_point.x || y != other_point.y);
	}


	// Utilities --------------------------------------------
	bool isZero() const
	{
		if (x == 0 && y == 0 && z == 0)
			return true;

		else
			return false;

		// return (x == 0 && y == 0);
	}


	const Vector3D& setZero()
	{
		x = y = z = 0;

		return(*this);
	}


	const Vector3D& setNegative()
	{
		x = -x;
		y = -y;
		z = -z;

		return(*this);
	}


	DITTO distanceTo(const Vector3D &other_point)
	{
		DITTO dx = other_point.x - x;
		DITTO dy = other_point.y - y;
		DITTO dz = other_point.z - z;
		DITTO db = sqrt((dx * dx) + (dy * dy));

		return(sqrt((db * db) + (dz * dz)));
	}

};

#endif //__VECTOR3D_H__