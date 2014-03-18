#ifndef SUSHI
#define SUSHI

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

class sushi
{
private:
	typedef std::vector<std::string> Vector;
	typedef std::vector<Vector> DoubleVector;
	Vector v;
	
	void display_double_vector( DoubleVector& dv);
	void display_vector(Vector &v);
	void deletecolumn(DoubleVector& dv,int n);
	void deleterow(DoubleVector& dv, int n);

public:
	DoubleVector usermetadata;
	DoubleVector itemmetadata;
	DoubleVector rankingA;
	DoubleVector rankingB;
	DoubleVector sushiB_ratings;
	
	void sushiudata();
	void sushiidata();
	void ranking_sushi_A();
	void ranking_sushi_B();
	void sushiB_score();

};
#endif