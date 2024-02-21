#pragma once
#include<iostream>
#include<fstream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include<string>
#include<vector>


const double pi = 3.14;

class EQ {

private:
	int n;
	int m;
	double* x;
	double* t;
	double** V;
	double h = 1;
	double tau = 1;
	double A = 1;
	double** f;

public:
	EQ() {}

	EQ(int n_, int m_)
	{
		this->n = n_;
		this->m = m_;

		// объявление переменных и констант
		this->h = (1 / (double)this->n);
		this->tau = (0.2 / ((double)this->m));
		//std::cout << tau << std::endl << tmp << std::endl;
		this->A = (1 - ((this->tau) / (this->h * this->h)));
		//std::cout << A << std::endl;
		this->x = new double[n + 1];
		this->t = new double[m + 1];
		this->V = new double* [n + 1];
		this->f = new double* [n + 1];


		this->x[0] = 0;
		this->x[n] = 1;
		this->t[0] = 0;
		this->t[m] = 0.2;
		//std::cout << "tau = " << tau << std::endl << "h = " << h << std::endl << std::endl << x[0] << std::endl;

		for (int i = 1; i < n; i++)
		{
			x[i] = i * h;
			//std::cout << x[i] << std::endl;
		}
		//std::cout << x[n] << std::endl;
		//std::cout << std::endl << std::endl << std::endl << t[0] << std::endl;
		for (int j = 1; j < m; j++)
		{
			t[j] = j * tau;
			//std::cout << t[j] << std::endl;
		}
		//std::cout << t[m] << std::endl ;
		//std::cout << std::endl << std::endl;
		for (int i = 0; i < n + 1; i++)
		{
			V[i] = new double[this->m + 1];
			f[i] = new double[this->m + 1];
		}

		// начальные и граничные условия
		for (int i = 0; i <= this->n; i++)
		{
			V[i][0] = 1;
		}
		for (int j = 1; j <= this->m; j++)
		{
			V[0][j] = 0;
			V[n][j] = 0;

		}
		
		for (int i = 1; i < this->n; i++)
			for (int j = 1; j < this->m; j++)
			{
				this->V[i][j] = 0.0001;
				//std::cout << V[i][j] << std::endl;
			}
		// заполнение f[i][j]
		for (int i = 0; i < this->n + 1; i++)
			for (int j = 0; j < this->m + 1; j++)
			{
				f[i][j] = 0;//std::exp(-t[j]) * sin(7 * pi * x[i]) + 1;
			}
	}

	~EQ()
	{
		delete[] this->x;
		delete[] this->t;
		for (int i = 0; i < this->n + 1; i++)
		{
			delete[] this->V[i];
		}
		delete[] this->V;

		for (int i = 0; i < n + 1; i++)
		{
			delete[] this->f[i];
		}
		delete[] this->f;
	}
	// рассчет элементов
	void run_through(int j)
	{
		double A_ = ((this->tau ) / (this->h * this->h));
		double B_ = A_;
		double C_ = this->A;
		//std::cout << A_ << std::endl << C_ << std::endl;
		double* fi = new double[n + 1];
		fi[0] = V[0][j + 1];
		fi[n] = V[n][j + 1];
		for (int i = 1; i < this->n; i++)
		{
			fi[i] = (this->V[i][j]);
			//std::cout /* << fi[i] << std::endl*/ << this->V[i][j] << std::endl;
			//std::cout << fi[i] << std::endl;
		}

		double* alpha = new double[this->n + 1];
		double* beta = new double[this->n + 1];
		alpha[1] = 0;
		beta[1] = this->V[0][j + 1];
		//std::cout << beta[1] << std::endl;
		//прямой ход прогонки
		//std::cout << alpha[1] << std::endl;
		for (int i = 1; i < this->n; i++)
		{
			alpha[i + 1] = B_ / (C_ - A_ * alpha[i]);

			//if (i == n-1)
			//	std::cout << alpha[i + 1] << std::endl;
		}
		//std::cout << std::endl << std::endl << beta[1] << std::endl;
		for (int i = 1; i < this->n; i++)
		{
			beta[i + 1] = (fi[i] + (A_ * beta[i])) / (C_ - (A_ * alpha[i]));
			//if (i == n - 1)
			//	std::cout << beta[i + 1] << std::endl;
		}


		for (int i = n - 1; i >= 0; i--)
		{
			V[i][j + 1] = alpha[i + 1] * V[i + 1][j + 1] + beta[i + 1];
			//if (i == 0)
			//std::cout << V[i][j+1] << std::endl;
		}

		//std::cout << std::endl << std::endl << "new iteration " << std::endl << std::endl;
	}

	void layers()
	{
		for (int i = 0; i < this->m; i++)
			run_through(i);

	}


	// вывод 
	void print()
	{

		int max_len = 15;
		int spaces_amount;
		int digits;

		for (int i = this->n; i >= 0; i--)
		{
			std::cout << std::endl;
			for (int j = this->m; j >= 0; j--)
			{
				digits = count_digits(i, j);
				spaces_amount = max_len - digits;
				std::cout << std::to_string(this->V[j][i]);
				for (int i = 0; i < spaces_amount; i++)
					std::cout << " ";

				std::cout << "|";
			}

		}

	}

	int count_digits(int i, int j)
	{
		std::string d = std::to_string(this->V[i][j]);
		return d.length();
	}


	// тестовая ерунда 
	void print_layer(int j)
	{
		std::cout << "layer " << j << std::endl;
		for (int i = 0; i < this->n + 1; i++)
			std::cout << V[i][j] << std::endl;

	}

	void print_a_b(double* alph, double* bet)
	{
		for (int i = 0; i < this->n + 1; i++)
			std::cout << alph[i] << std::endl;
		std::cout << "beta: " << std::endl;
		for (int i = 0; i < this->n + 1; i++)
			std::cout << bet[i] << std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}

	void out_file()
	{
		std::ofstream out;
		out.open("Data.txt");
		out << this->tau << std::endl;
		out << this->h << std::endl;
		out << this->n << std::endl;
		out << this->m << std::endl;
		//out.fixed;
		//out.precision(10);
		//for (int i = 0; i < n; i++)
		//	out << x[i] << std::endl;
		for (int j = this->m ; j >= 0; j--)
			for (int i = 0; i < this->n+1; i++)
			{
				out << V[i][j] << std::endl;
				//std::cout << "i  " << i << "      " << "j  " << j << "      " << "V  " << V[i][j] << std::endl;
			}
		out.close();
		
	}
};


