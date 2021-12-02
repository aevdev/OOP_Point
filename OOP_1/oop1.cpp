#include <iostream>

using namespace std;

class Point
{
private:
	double x; //переменные члены класса в памяти располагаются подряд (y лежит после x и, по идее, к нему можно обратиться по адресу (&x + 1) или как-то так.
	double y;

public:
	Point(double x, double y) //добавление значений по умолчанию делает наш конструктор дефолтным и позволяет нам вызвать его и без параметров и с параметрами и с одним параметром, в общем, все подряд
	{
		this->x = x;
		this->y = y;
		cout << "\nConstructor triggered: " << this; //выводит адрес по которому создан наш объект
	}
	Point(double x)
	{
		this->x = x;
		//this->y = 0;
		this->y = double(); //double() - значение по-умолчанию для типа double
							//якобы вызываем конструктор по умолчанию для double (почему якобы? потому что double - это примитивный тип и у него нет ни конструкторов, ничего бы ты еще)
		cout << "\nConstructor triggered: " << this;
	}
	
	Point(const Point& other) //Конструктор копирования создается вот так
	{
		this->x = other.x;
		this->y = other.y;
		cout << "\nCopy constructor triggered: " << this;
	}

	double distance(const Point &other) const	//эта функция не изменяет значений ни нашего метода, ни принимаемого, а лишь получает из них данные, которые мы используем, потому и функция и параметр константные.
	{											//а передаем по ссылке, чтобы не вызывать лишний раз copy конструктор
		double x = this->getX() - other.x;
		double y = this->getY() - other.y;
		return sqrt(x * x + y * y);
	}

	//get методы должны быть константными
	//константным называется метод, который НЕ изменяет объект, для которого вызывается
	//для константного объекта могут быть вызваны только константные методы

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
	Point& operator= (const Point &other) //чтобы copy конструкторы не вызывались в выражениях с передачей по ссылке, то нужно ВЕРНУТЬ объект по ссылке.
	{
		this->x = other.x;
		this->y = other.y;
		cout << "\nCopy assignment triggered: " << this;
		return *this;
	}

};

double distance(const Point &A, const Point &B) //здесь та же самая ситуация, что и с методом
{
	double x = A.getX() - B.getX();
	double y = A.getY() - B.getY();
	return sqrt(x * x + y * y);
}

//#define INPUT;

Point G(1, 2);	//Global object <-- можно, но неоднозначно. со 100% уверенностью сказать нельзя можно или нельзя 
int g;		//Global variable <-- в эту переменную может сделать запись кто угодно, потому так делать плохо DEPRECATED (осуждается)
const int Pi = 3.14; //global constant <-- так делать можно, если это константы

int main()
{
	double x, y;
	Point A(1, 2); //instance - экземпляр; instantiate - создать экземпляр;
	Point* pA = &A; //объявляем	указатель на Point 'pA' //указатель на этот тип данных не будет вызывать ни конструктор, ни деструктор	
					//и инициализируем его адресом объекта A.
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

	Point F(C); //Еще один способ вызова конструктора копирования
	F.print();
	cout << "\n--------------------------------";
	Point(123, 234).print(); //безымянный временный объект существует только в пределах одного выражения. //у выражений тоже есть область видимости
	cout << "\n--------------------------------";

	Point G(0);
	G = F;

	Point Z(255, 255);

	cout << "\n--------------------------------";
	cout << "\nDistance C(D):" << C.distance(D) << '\n';
	cout << "\nDistance (D, Z):" << distance(Z, D) << '\n';


	

	{//<--- безымянное пространство имен (каждые фигурные скобки создают пространство имен.
		int a = 2; //<- будет удалено из памяти после того, как закончится этот блок кода
	}
	//cout << a; //этот код не сработает, поскольку a существует только в скобках, а не их пределами.
	return 0;
}