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
	std::cout << "������ �������� �������� ������" << std::endl;
	std::cout << "������ ��������� �������� ��� ����� ��������� ������� ��������������� ��������� ����������������" << std::endl;
	std::cout << "��� ����� ����� �������������� ������� �����" << std::endl;
	std::cout << "������ ��� ����� ������ ����������� �����:" << std::endl;
	std::cout << "����������, ������� ����� ��������� �� ��� ������������: " << std::endl << std::endl;
	//std::cin >> n;
	std::cout << std::endl;
	std::cout << "������, ����������, ������� ����� ��������� �� ��� �������: " << std::endl;
	std::cout << std::endl;
	//std::cin >> m;
	std::cout << std::endl;
	std::cout << "��� ����������� ������ �������, �������� ������� �������" << std::endl;
	std::cout << std::endl << std::endl;
	if ((n < 0) || (m < 0))
	{
		std::cout << "���! � ���������, �� �� ������ ������� ������������� ����� ���������, ����������, �������� �������� � ���������� ��� ���" << std::endl;
		return 0;
	}
	if ((n > maxn) || (m > maxm))
	{
		std::cout << "���! ������, �� ����� ������� ������� ����� ���������, ����������, �������� �������� � ���������� ��� ���" << std::endl;
		return 0;
	}
	EQ EQ(n, m);
	EQ.layers();
	EQ.out_file();
	
	return 0;
}
