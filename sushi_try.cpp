#include <iostream>
#include <shogun/io/CSVFile.h>
#include <shogun/lib/SGMatrix.h>

using namespace shogun;
using namespace std;

void print_message(FILE* target, const char* str)
{
	fprintf(target, "%s", str);
}

void extract_user_metadata(SGMatrix<int32_t>& user_metadata)
{
	CCSVFile *fin;
	fin=new CCSVFile("sushi3.udata",'r',NULL);
	fin->set_delimiter('	');
	fin->get_matrix(user_metadata.matrix,user_metadata.num_cols,user_metadata.num_rows);

	int32_t rows=1;
	int32_t cols=11;
	user_metadata.display_matrix(user_metadata.matrix,rows,cols,"user_metadata","");
	
	cout<<"num_cols "<<user_metadata.num_cols<<"\n";
	cout<<"num_rows "<<user_metadata.num_rows;
}

void extract_item_metadata(SGMatrix<float32_t>& item_metadata)
{
	CCSVFile *fin;
	fin=new CCSVFile("sushi3.idata",'r',NULL);
	fin->set_delimiter('	');
	fin->get_matrix(item_metadata.matrix,item_metadata.num_cols,item_metadata.num_rows);

	int32_t rows=1;
	int32_t cols=11;
	item_metadata.display_matrix(item_metadata.matrix,rows,cols,"item_metadata","");
	
	cout<<"num_cols "<<item_metadata.num_cols<<"\n";
	cout<<"num_rows "<<item_metadata.num_rows;
}

int main(int argc, char const *argv[])
{
	init_shogun(&print_message);

	SGMatrix<int32_t> user_metadata(true);
	extract_user_metadata(user_metadata);

	SGMatrix<float32_t> item_metadata(true);
	extract_item_metadata(item_metadata);

	return 0;
}