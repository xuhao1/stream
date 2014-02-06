#ifndef __XUHAO__STREAM_H__
#define __XUHAO__STREAM_H__
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
class stream
{
public:
	std::vector<vector2f> line;
	int k;
	std::ofstream of;
	stream():
		of("data.txt")
	{
		line=mkstream();
		k=0;
	}
	double func(double x,double y);
	void relaxline(std::vector<vector2f>&);
	void printline();
	std::vector<vector2f> mkstream();
};


#endif
