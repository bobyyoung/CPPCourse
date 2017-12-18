/*
*功能：用面向对象方法编程，求圆的周长和面积
*/


#include<iostream>

using namespace std;

class Circle {
public:

	//设置半径
	void SetRadiu(double r) {
		radius = r;
	}

	//获取半径
	double GetRadius() {
		return radius;
	}

	//获取周长
	double GetGirth() {
		return 2 * 3.14f*radius;
	}

	//获取面积
	double GetArea() {
		return 3.14f*radius*radius;
	}

private:
	double radius;//半径

};


void main() {

	Circle A;
	Circle B;

	A.SetRadiu(6.23); //类的调用
	cout << "A.Radius = " << A.GetRadius() << endl;
	cout << "A.Girth = " << A.GetGirth() << endl;
	cout << "A.Area = " << A.GetArea() << endl;
	B.SetRadiu(10.5);
	cout << "B.radius = " << B.GetRadius() << endl;
	cout << "B.Girth=" << B.GetGirth() << endl;
	cout << "B.Area = " << B.GetArea() << endl;
	system("pause");
}

