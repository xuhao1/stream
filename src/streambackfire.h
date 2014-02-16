//THIS IS INDENTED TO CALCULATE \Delta \int I dx=0 Variational Problem
#ifndef __XUHAO__streambackfire_H__
#define __XUHAO__streambackfire_H__
#include "vector2f.h"
#include "vector3f.h"
#include <vector>
#include "math.h"
#include <iostream>
#include <fstream>

double randf()
{
	return (double)rand()/(double)RAND_MAX;
}
class streambackfire
{
public:
	std::vector<vector2f> line;
	int k;
	double T;
	std::ofstream of;
	streambackfire():
		of("data.txt"),T(100)
	{
		line=mkstream();
		k=0;
	}
	double func(vector2f x,vector2f y);
	void relaxline(std::vector<vector2f>&);
	void printline();
	void backfire();
	std::vector<vector2f> mkstream();
};

#endif
