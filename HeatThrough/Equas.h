//#pragma once
//#include<iostream>
//#include <cmath>
//#include <iomanip>
//#include <sstream>
//#include<string>
//#include<vector>
//const double pi = 3.14;
//
//class EQ {
//
//private:
//	int n;
//	int m;
//	double* x;
//	double* t;
//	double** V;
//	double h = 1;
//	double tau = 1;
//	double A = 1;
//	double** f;
//
//public:
//	EQ() {}
//
//	EQ(int n_, int m_)
//	{
//		this->n = n_;
//		this->m = m_;
//
//		// объявление переменных и констант
//		this->h = (1 / (double)this->n);
//		this->tau = 5 / (double)this->m;
//		this->A = 2 / (this->h * this->h) + 1 / this->tau;
//
//
//		this->x = new double[n + 1];
//		this->t = new double[m + 1];
//		this->V = new double* [n + 1];
//		this->f = new double* [n + 1];
//
//
//		this->x[0] = 0;
//		this->x[n] = 1;
//		this->t[0] = 0;
//		this->t[m] = 5;
//
//
//		for (int i = 1; i < n; i++)
//		{
//			x[i] = i * h;
//		}
//		for (int j = 1; j < m; j++)
//			t[j] = j * tau;
//
//
//
//		for (int i = 0; i < n + 1; i++)
//		{
//			V[i] = new double[this->m + 1];
//			f[i] = new double[this->m + 1];
//		}
//
//		// начальные и граничные условия
//		for (int i = 0; i <= this->n; i++)
//		{
//			V[i][0] = 1 - (x[i] * x[i]);
//		}
//		for (int j = 0; j <= this->m; j++)
//		{
//			V[0][j] = cos(t[j]);
//			V[n][j] = sin(4 * t[j]);
//			//	std::cout << "t = " << t[j] << std::endl << " sin = " << sin(4 * t[j]) << std::endl;
//		}
//
//		for (int i = 1; i < this->n; i++)
//			for (int j = 1; j < this->m; j++)
//				this->V[i][j] = 0.0001;
//		// заполнение f[i][j]
//		for (int i = 0; i < this->n + 1; i++)
//			for (int j = 0; j < this->m + 1; j++)
//			{
//				f[i][j] = std::exp(-t[j]) * sin(7 * pi * x[i]) + 1;
//			}
//	}
//
//	~EQ()
//	{
//		delete[] this->x;
//		delete[] this->t;
//		for (int i = 0; i < this->n + 1; i++)
//		{
//			delete[] this->V[i];
//		}
//		delete[] this->V;
//
//		for (int i = 0; i < n + 1; i++)
//		{
//			delete[] this->f[i];
//		}
//		delete[] this->f;
//	}
//	// рассчет элементов
//	void run_through(int j)
//	{
//		double A_ = 1 / (this->h * this->h);
//		double B_ = A_;
//		double C_ = this->A;
//		double* fi = new double[n + 1];
//		fi[0] = V[0][j + 1];
//		fi[n] = V[n][j + 1];
//		for (int i = 1; i < this->n; i++)
//		{
//			fi[i] = f[i][j + 1] + (V[i][j] / this->tau);
//		}
//
//		double* alpha = new double[this->n + 1];
//		double* beta = new double[this->n + 1];
//		alpha[1] = 0;
//		beta[1] = this->V[0][j + 1];
//		//прямой ход прогонки
//		for (int i = 1; i < n; i++)
//		{
//			alpha[i + 1] = B_ / (C_ - A_ * alpha[i]);
//		}
//
//		for (int i = 1; i < n; i++)
//		{
//			beta[i + 1] = (fi[i] + (A_ * beta[i])) / (C_ - (A_ * alpha[i]));
//		}
//		//
//
//		//обратный ход
//		this->V[this->n][j + 1] = fi[j + 1];
//
//		for (int i = n - 1; i >= 0; i--)
//		{
//			V[i][j + 1] = alpha[i + 1] * V[i + 1][j + 1] + beta[i + 1];
//		}
//
//	}
//
//	void layers()
//	{
//		for (int i = 0; i < this->m; i++)
//			run_through(i);
//
//	}
//
//
//	// вывод 
//	void print()
//	{
//		//for (int i = 0; i < this->n ; i++)
//		//	for (int j = 0; j < this->m ; j++)
//		//		std::cout << "f " << i << " " << j << " = " << this->f[i][j] << std::endl;
//		//std::cout.precision(4);
//		//for (int i = this->n; i >= 0 ; i--)
//		//{
//		//	std::cout << std::endl;
//		//	for (int j = this->m; j >= 0 ; j--)
//		//		std::cout << V[j][i] << " " ;
//		//
//		//}
//		int max_len = 15;
//		int spaces_amount;
//		int digits;
//
//		for (int i = this->n; i >= 0; i--)
//		{
//			std::cout << std::endl;
//			for (int j = this->m; j >= 0; j--)
//			{
//				digits = count_digits(i, j);
//				spaces_amount = max_len - digits;
//				//std::cout << digits << std::endl << spaces_amount << std::endl;
//				std::cout << std::to_string(this->V[j][i]);
//				for (int i = 0; i < spaces_amount; i++)
//					std::cout << " ";
//
//				std::cout << "|";
//			}
//
//		}
//
//	}
//
//	int count_digits(int i, int j)
//	{
//		std::string d = std::to_string(this->V[i][j]);
//		return d.length();
//	}
//
//	void print_boundary() {}
//	//void print_equasion_system()
//	//{
//	//	for (int i = 0; i < this->n + 1; i++)
//	//	{
//	//		std::cout << std::endl;
//	//		for (int j = 0; j < this->m + 1; j++)
//	//			std::cout << 
//	//	}
//	//}
//
//	// тестовая ерунда 
//	void print_layer(int j)
//	{
//		std::cout << "layer " << j << std::endl;
//		for (int i = 0; i < this->n + 1; i++)
//			std::cout << V[i][j] << std::endl;
//
//	}
//
//	void print_a_b(double* alph, double* bet)
//	{
//		for (int i = 0; i < this->n + 1; i++)
//			std::cout << alph[i] << std::endl;
//		std::cout << "beta: " << std::endl;
//		for (int i = 0; i < this->n + 1; i++)
//			std::cout << bet[i] << std::endl;
//		std::cout << std::endl << std::endl << std::endl;
//	}
//
//
//};
//
//
////система уравнений
////
////V[0][j+1] = cos(t[j+1])
////-1/h^2*V[i-1][j+1] + AV[i][j+1]-1/h^2*V[i+1][j+1] = f[i][j+1] + V[i][j]/tau
////V[n][j+1] = sin(4*t[j+1])
////
//
//
//
//
//
////std::cout << "h = " << h << std::endl;
//		//std::cout << "tau = " << tau << std::endl;
//		//for (int i = 0; i < m + 1; i++)
//		//	std::cout << "t " << i << " = " << t[i] << std::endl;
//		//for (int i = 0; i < n + 1; i++)
//		//	std::cout << "x " << i << " = " << x[i] << 5std::endl;