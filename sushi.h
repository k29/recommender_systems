#ifndef SUSHI
#define SUSHI

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

typedef std::vector<string> Vector;
typedef std::vector<Vector> DoubleVector;

class sushi
{
private:
	Vector v;
	DoubleVector usermetadata;
	DoubleVector itemmetadata;
	void display_double_vector( DoubleVector& dv);
	void display_vector(vector<string> &v);
	void deletecolumn(DoubleVector& dv,int n);
	void deleterow(DoubleVector& dv, int n);

public:
	void sushiudata();
	void sushiidata();
	void ranking_sushi_A();
	void ranking_sushi_B();
	void sushiB_ratings();

	



};
#endif