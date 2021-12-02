#include <iostream>

using namespace std;

class Point
{
private:
	double x; //���������� ����� ������ � ������ ������������� ������ (y ����� ����� x �, �� ����, � ���� ����� ���������� �� ������ (&x + 1) ��� ���-�� ���.
	double y;

public:
	Point(double x, double y) //���������� �������� �� ��������� ������ ��� ����������� ��������� � ��������� ��� ������� ��� � ��� ���������� � � ����������� � � ����� ����������, � �����, ��� ������
	{
		this->x = x;
		this->y = y;
		cout << "\nConstructor triggered: " << this; //������� ����� �� �������� ������ ��� ������
	}
	Point(double x)
	{
		this->x = x;
		//this->y = 0;
		this->y = double(); //double() - �������� ��-��������� ��� ���� double
							//����� �������� ����������� �� ��������� ��� double (������ �����? ������ ��� double - ��� ����������� ��� � � ���� ��� �� �������������, ������ �� �� ���)
		cout << "\nConstructor triggered: " << this;
	}
	
	Point(const Point& other) //����������� ����������� ��������� ��� ���
	{
		this->x = other.x;
		this->y = other.y;
		cout << "\nCopy constructor triggered: " << this;
	}

	double distance(const Point &other) const	//��� ������� �� �������� �������� �� ������ ������, �� ������������, � ���� �������� �� ��� ������, ������� �� ����������, ������ � ������� � �������� �����������.
	{											//� �������� �� ������, ����� �� �������� ������ ��� copy �����������
		double x = this->getX() - other.x;
		double y = this->getY() - other.y;
		return sqrt(x * x + y * y);
	}

	//get ������ ������ ���� ������������
	//����������� ���������� �����, ������� �� �������� ������, ��� �������� ����������
	//��� ������������ ������� ����� ���� ������� ������ ����������� ������

	double getX()const { return x; }
	double getY()const { return y; }
	void setX(double x) { this->x = x; }
	void setY(double y) { this->y = y; }

	~Point()
	{
		cout << "\nDestructor triggered: " << this;
	}

	void print()const
	{
		cout << "\nX = " << x << '\t' << "Y = " << y;
	}

	//OPERATORS
	Point& operator= (const Point &other) //����� copy ������������ �� ���������� � ���������� � ��������� �� ������, �� ����� ������� ������ �� ������.
	{
		this->x = other.x;
		this->y = other.y;
		cout << "\nCopy assignment triggered: " << this;
		return *this;
	}

};

double distance(const Point &A, const Point &B) //����� �� �� ����� ��������, ��� � � �������
{
	double x = A.getX() - B.getX();
	double y = A.getY() - B.getY();
	return sqrt(x * x + y * y);
}

//#define INPUT;

Point G(1, 2);	//Global object <-- �����, �� ������������. �� 100% ������������ ������� ������ ����� ��� ������ 
int g;		//Global variable <-- � ��� ���������� ����� ������� ������ ��� ������, ������ ��� ������ ����� DEPRECATED (����������)
const int Pi = 3.14; //global constant <-- ��� ������ �����, ���� ��� ���������

int main()
{
	double x, y;
	Point A(1, 2); //instance - ���������; instantiate - ������� ���������;
	Point* pA = &A; //���������	��������� �� Point 'pA' //��������� �� ���� ��� ������ �� ����� �������� �� �����������, �� ����������	
					//� �������������� ��� ������� ������� A.
#ifdef INPUT
	cout << "Please enter x: ";
	cin >> x;
	pA->setX(x);
	cout << "\nPlease enter y: ";
	cin >> y;
	pA->setY(y);
#endif // INPUT 

	//cout << "x = " << pA->getX() << '\t' << "y = " << pA->getY();
	A.print();

	Point C = 5; //Single-argument constructor
	C.print();

	Point D(8);
	D.print(); //Single-argument constructor

	Point E = D; //CopyConstructor
	E.print();

	Point F(C); //��� ���� ������ ������ ������������ �����������
	F.print();
	cout << "\n--------------------------------";
	Point(123, 234).print(); //���������� ��������� ������ ���������� ������ � �������� ������ ���������. //� ��������� ���� ���� ������� ���������
	cout << "\n--------------------------------";

	Point G(0);
	G = F;

	Point Z(255, 255);

	cout << "\n--------------------------------";
	cout << "\nDistance C(D):" << C.distance(D) << '\n';
	cout << "\nDistance (D, Z):" << distance(Z, D) << '\n';


	

	{//<--- ���������� ������������ ���� (������ �������� ������ ������� ������������ ����.
		int a = 2; //<- ����� ������� �� ������ ����� ����, ��� ���������� ���� ���� ����
	}
	//cout << a; //���� ��� �� ���������, ��������� a ���������� ������ � �������, � �� �� ���������.
	return 0;
}