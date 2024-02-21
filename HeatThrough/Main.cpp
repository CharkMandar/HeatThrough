#include<iostream>
#include<cmath>
#include <iomanip>
#include"EQ.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	int n = 10;       //std::stoi(argv[1]);
	int	m = 1000;        //std::stoi(argv[2]);
	int maxm = 1000000000;
	int maxn = 1000000000;
	std::cout << "Работу выполнил Кузнецов Михаил" << std::endl;
	std::cout << "Данная программа позволит Вам найти численное решение нестационарного уравнения теплопроводности" << std::endl;
	std::cout << "Для этого будет использоваться неявная схема" << std::endl;
	std::cout << "Сейчас Вам нужно задать размерность сетки:" << std::endl;
	std::cout << "Пожалуйста, введите число разбиений по оси пространства: " << std::endl << std::endl;
	//std::cin >> n;
	std::cout << std::endl;
	std::cout << "Теперь, пожалуйста, введите число разбиений по оси времени: " << std::endl;
	std::cout << std::endl;
	//std::cin >> m;
	std::cout << std::endl;
	std::cout << "Все необходимые данные введены, начинаем процесс расчета" << std::endl;
	std::cout << std::endl << std::endl;
	if ((n < 0) || (m < 0))
	{
		std::cout << "Упс! К сожалению, вы не можете вводить отрицательное число разбиений, пожалуйста, измените значения и попробуйте еще раз" << std::endl;
		return 0;
	}
	if ((n > maxn) || (m > maxm))
	{
		std::cout << "Упс! Похоже, вы ввели слишком большое число разбиений, пожалуйста, измените значения и попробуйте еще раз" << std::endl;
		return 0;
	}
	EQ EQ(n, m);
	EQ.layers();
	EQ.out_file();
	
	return 0;
}
