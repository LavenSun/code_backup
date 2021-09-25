#if 0
//ÀàĞÍ×ª»»cast
#include<iostream>
using namespace std;
class Point2D
{
public:
	Point2D(int x, int y)
		:_x(x), _y(y){}
	friend class Point3D;
private:
	int _x, _y;
};
class Point3D
{
public:
	Point3D(int x, int y, int z)
		:_x(x), _y(y), _z(z) {}
	Point3D(const Point2D& p2)
	{
		this->_x = p2._x;
		this->_y = p2._y;
		this->_z = 0;
	}
	operator Point2D(void)
	{
		return Point2D(this->_x, this->_y);
	}
#if 0
	Point3D& operator=(const Point3D& another)
	{
		this->_x = another._x;
		this->_y = another._y;
		this->_z = another._z;
		return *this;
	}
#endif
private:
	int _x, _y, _z;
};
int main()
{
	Point2D p2(1, 2);
	Point3D p3(3, 4, 5);
	p3 = p2;
	Point2D pp2(0, 0);
	pp2 = p3;
	return 0;
}
#endif