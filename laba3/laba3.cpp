#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

void Task1();
void Task2();
void Task3();

int gcd(int m, int n);
void Task4();
void Task5() {
 float x, eps;
 cout << "введите x: ";
 cin >> x; 
 cout<< "введите eps: ";
 cin >> eps;

 cout << func_5(x, eps);
}
float func_5(float x, float eps) {
 float y, n, y_pred;
 y = 1;
 
 y_pred = 0;
 while (abs(y - y_pred) > eps) {
  y_pred = y;
  y = 0.5 * (y_pred + x / y_pred);
  
 }
 return y;
}

void Task6() {
 float xn, xk, dx;
 cout << "Введите X начальное, Х конечное, шаг: "; 
 cin >> xn >> xk >> dx;
 float a, b, c;
 cout << "Введите a, b, c: "; 
 cin >> a >> b >> c;
 func_6_1(xn, xk, dx, a, b, c);
}
void func_6_1(float xn, float xk, float dx, float a, float b, float c) {
 int ai = int(a), bi = int(b), ci = int(c);
 float x = xn;
 while (x <= xk) {
  if ((int (~(ai | bi) & (bi | ci))) != 0)
   cout << setw(10) << x << setw(10) << func_6_2(x, a, b, c) << endl;
  else
   cout << setw(10) << x << setw(10) << int(func_6_2(x, a, b, c)) << endl;
  x += dx;
 }
}
float func_6_2(float x, float a, float b, float c) {
 if (a < 0 && x != 0)
  return a * x * x + b * b * x;
 else if (a > 0 && x == 0)
  return x - (a / (x - c));
 else
  return 1+x/c;
}



void Task5_1(double x, double eps);
void Task5();

void Task6();
void Task6_1(double x_start, double x_end, double dx, double a, double b, double c);

void Task7();
double Task7_1(int n, float x);

void Task8();
int fibonacci(int n);
int fibonacci_non_recursive(int n);

void Task9();
int mccarthy_cycle(int n);
int mccarthy_recursion(int n);



int main()
{
	setlocale(LC_ALL, "");
	srand(unsigned(time(0)));
	cout << "*******************************" << endl;
	cout << setw(45) << "Лабораторная работа №3" << endl;
	cout << setw(40) << "Одномерные массивы" << endl;
	cout << "Выполнил студент группы 151412" << endl;
	cout << setw(49) << "Пирогов Павел Алексеевич" << endl;
	cout << setw(30) << "Вариант №17" << endl;
	cout << "*******************************" << endl << endl;
	int n;
	cout << "Какую задачу хотите запустить? "; cin >> n;
	switch (n) {
	case 1:
		Task1();
		break;
	case 2:
		Task2();
		break;
	case 3:
		Task3();
		break;
	case 4:
		Task4();
		break;
	case 5:
		Task5();
		break;
	case 6:
		Task6();
		break;
	case 7:
		Task7();
		break;
	case 8:
		Task8();
		break;
	case 9:
		Task9();
		break;

	default:
		cout << "Такой задачи нет((";
		break;
	}
}

void Task1() {
	int n;
	double P = 0.0;

	// Ввод n с клавиатуры
	cout << "Введите n: ";
	cin >> n;

	// Вычисление суммы
	for (int i = 1; i <= n; i++) {
		P += 1.0 / (i * (i + 1));
	}

	// Вывод результата
	cout << "Значение P: " << P << endl;
}

void Task2() {
	int* a = new int[2];
	int n;
	do {
		cout << "Введите первое число "; cin >> a[0];
		cout << "Введите второе число "; cin >> a[1];
		sort(a, a + 2);
	} while (a[1] - a[0] == 0);

	do {
		cout << "Введите  число "; cin >> n;
	} while (n<a[0] || n>a[1]);
	cout << "Ура Вы угадали";
}

void Task3() {
	int secretNumber = rand() % 100 + 1;
	int userGuess = 0;
	int count = 0;
	while (userGuess != secretNumber) {
		cout << "Введите ваше число: "; cin >> userGuess;
		count++;
		if (userGuess > secretNumber) {
			cout << "Перелет! Попробуйте ввести число меньше." << endl;
		}
		else if (userGuess < secretNumber) {
			cout << "Недолет! Попробуйте ввести число больше." << endl;
		}
	}
	cout << "Поздравляю! Вы угадали число " << secretNumber << " за " << count << " попыток!" << endl;
}


int gcd(int m, int n) {
	if (m == n) {
		return m;
	}

	while (m != n) {
		if (m > n) {
			m -= n;
		}
		else {
			n -= m;
		}
	}

	return m;
}

void Task4() {
	int num1, num2;
	cout << "Введите два целых числа: ";
	cin >> num1 >> num2;

	int result = gcd(num1, num2);
	cout << "НОД чисел " << num1 << " и " << num2 << " равен " << result << std::endl;

}


void Task5_1(double x, double eps) {
	double y = 1;
	double y_prev = 1;

	int n = 1;

	while (abs(y - y_prev) >= eps) {
		y_prev = y;
		y = 0.5 * (y_prev + x / y_prev);
		n++;
	}

	cout << "y = " << y << endl;
	cout << "n = " << n << endl;
}

void Task5() {
	double x, eps;

	cout << "Enter x: ";
	cin >> x;

	cout << "Enter eps: ";
	cin >> eps;
	Task5_1(x,eps);
}

void Task6_1(double x_start, double x_end, double dx, double a, double b, double c) {
	cout << "x | F(x)" << endl;
	cout << "--------------" << endl;
	for (double x = x_start; x <= x_end; x += dx) {
		double F;
		if (x + 10 < 0 && b != 0) {
			F = (a * x * x - c * x + b) / (x - a);
		}
		else if (x + 10 > 0 && b == 0) {
			F = (x - c) / (x - a);
		}
		else {
			F = -x / (a - c);
		}

		int ac = floor(a);
		int bc = floor(b);
		int cc = floor(c);
		bool condition = ((ac || bc) && !(ac || cc));

		cout << x << " | ";
		if (condition) {
			cout << static_cast<int>(F);
		}
		else {
			cout << F;
		}
		cout << endl;
	}
}
void Task6() {
	double a, b, c, x_start, x_end, dx;
	cout << "Введите значение a: ";
	cin >> a;
	cout << "Введите значение b: ";
	cin >> b;
	cout << "Введите значение c: ";
	cin >> c;
	cout << "Введите начальное значение x (Xнач.): ";
	cin >> x_start;
	cout << "Введите конечное значение x (Xкон.): ";
	cin >> x_end;
	cout << "Введите шаг (dX): ";
	cin >> dx;
	Task6_1(x_start, x_end,  dx,  a,  b,  c);
}

void Task7() {
	float x;
	int n;
	do {
		cout << "Введите х (0<x<=2) n: "; cin >> x >> n;
	} while (x <= 0 || x > 2);
	double lnx = Task7_1(n, x);
	cout << "Натуральный логарифм будет равен " << lnx;
}
double Task7_1(int n, float x) {
	double y = 0.0;
	for (int i = 0; i <= n; i++) {
		y += pow(-1, n) * pow(x - 1, n + 1) / (n + 1);
	}
	return y;
}

int fibonacci(int n) {
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int fibonacci_non_recursive(int n) {
	return fibonacci(n);
}
void Task8() {
	int n;
	cout << "Введите n: ";
	cin >> n;
	cout << "числа фибоначи: " << fibonacci_non_recursive(n) << endl;
}

int mccarthy_cycle(int n) {
	while (n >= 100) {
		n -= 10;
	}
	while (n < 100) {
		n += 11;
	}
	return n;
}

int mccarthy_recursion(int n) {
	if (n >= 100) {
		return n - 10;
	}
	else {
		return mccarthy_recursion(n + 11);
	}
}

void Task9() {
	int n;
	cout << "Введите целое число n: ";
	cin >> n;

	cout << "Значение функции Маккарти (цикл): " << mccarthy_cycle(n) << endl;
	cout << "Значение функции Маккарти (рекурсия): " << mccarthy_recursion(n) << endl;
}
