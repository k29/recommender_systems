#include <iostream>
#include <shogun/io/CSVFile.h>
#include <shogun/lib/SGMatrix.h>

using namespace shogun;
using namespace std;

void print_message(FILE* target, const char* str)
{
	fprintf(target, "%s", str);
}

int main(int argc, char const *argv[])
{
	init_shogun(&print_message);
	CCSVFile *fin;
	// int32_t num_rows=5000;
	// int32_t num_cols=5000;
	int32_t rows=1;
	int32_t cols=11;
	SGMatrix<int32_t> sushidata(true);
	fin=new CCSVFile("sushi3.udata",'r',NULL);
	fin->set_delimiter('	');
	fin->get_matrix(sushidata.matrix,sushidata.num_cols,sushidata.num_rows);
	sushidata.display_matrix(sushidata.matrix,rows,cols,"sushidata","");
	cout<<"num_cols "<<sushidata.num_cols;
	cout<<"num_rows "<<sushidata.num_rows;

	return 0;
}