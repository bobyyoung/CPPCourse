/*
*���ܣ���������󷽷���̣���Բ���ܳ������
*/


#include<iostream>

using namespace std;

class Circle {
public:

	//���ð뾶
	void SetRadiu(double r) {
		radius = r;
	}

	//��ȡ�뾶
	double GetRadius() {
		return radius;
	}

	//��ȡ�ܳ�
	double GetGirth() {
		return 2 * 3.14f*radius;
	}

	//��ȡ���
	double GetArea() {
		return 3.14f*radius*radius;
	}

private:
	double radius;//�뾶

};


void main() {

	Circle A;
	Circle B;

	A.SetRadiu(6.23); //��ĵ���
	cout << "A.Radius = " << A.GetRadius() << endl;
	cout << "A.Girth = " << A.GetGirth() << endl;
	cout << "A.Area = " << A.GetArea() << endl;
	B.SetRadiu(10.5);
	cout << "B.radius = " << B.GetRadius() << endl;
	cout << "B.Girth=" << B.GetGirth() << endl;
	cout << "B.Area = " << B.GetArea() << endl;
	system("pause");
}

