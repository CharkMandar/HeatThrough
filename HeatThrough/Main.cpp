#include<iostream>
#include<cmath>
#include <iomanip>
#include"EQ.h"

int main()
{

	int n = 10;       //std::stoi(argv[1]);
	int	m = 1000;        //std::stoi(argv[2]);

	EQ EQ(n, m);
	EQ.layers();
	EQ.out_file();
	
	return 0;
}
