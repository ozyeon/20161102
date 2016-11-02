#include <iostream>
using namespace std;

class Vector4D
{
public:
	int x, y, z, w;

	Vector4D()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
	}

	Vector4D(int x_, int y_, int z_, int w_)
	{
		x = x_;
		y = y_;
		z = z_;
		w = w_;
	}
	friend ostream& operator<<(ostream& os, const Vector4D& dt);

	void operator=(const Vector4D &V)
	{
		this->x = V.x;
		this->y = V.y;
		this->z = V.z;
		this->w = V.w;
	}
};

ostream& operator<<(ostream& os, const Vector4D& dt)
{
	os << dt.x << '/' << dt.y << '/' << dt.z << '/' << dt.w;
	return os;
}

class VectorND
{
public:
	int a, b, c, d, e;

	VectorND()
	{
		a = 0;
		b = 0;
		c = 0;
		d = 0;
		e = 0;
	}

	VectorND(int a_, int b_, int c_, int d_, int e_)
	{
		a = a_;
		b = b_;
		c = c_;
		d = d_;
		e = e_;
	}
	friend ostream& operator<<(ostream& os, const VectorND& dt);

	void operator=(const VectorND &N)
	{
		this->a = N.a;
		this->b = N.b;
		this->c = N.c;
		this->d = N.d;
		this->e = N.e;
	}
};

ostream& operator<<(ostream& os, const VectorND& dt)
{
	os << dt.a << '\n' << dt.b << '\n' << dt.c << '\n' << dt.d << '\n' << dt.e;
	return os;
}


class Matrix3x3
{
public:
	Vector4D row1, row2, row3, row4, row5;

	Matrix3x3(const Vector4D& r1, const Vector4D& r2, const Vector4D& r3, const Vector4D& r4, const Vector4D& r5)
		: row1(r1), row2(r2), row3(r3), row4(r4), row5(r5)
	{}

	VectorND operator*(const Vector4D& rhs)
	{
		VectorND ans;
		ans.a = row1 * rhs;
		ans.b = row2 * rhs;
		ans.c = row3 * rhs;
		ans.d = row4 * rhs;
		ans.e = row5 * rhs;

		return ans;
	}
};

ostream& operator<<(ostream& os, const Matrix3x3& dt)
{
	os << dt.row1 << '/' << dt.row2 << '/' << dt.row3 << '/' << dt.row4;
	return os;
}

int main()
{
	Matrix3x3 m(Vector4D(1, 0, 0, 0), Vector4D(0, 2, 0, 0), Vector4D(0, 0, 3, 0), Vector4D(0, 0, 0, 4), Vector4D(0, 0, 0, 5));

	VectorND v(1, 2, 3, 4, 5);
	
	Vector4D y = m * v;
	std::cout << y << std::endl;

	return 0;
}
