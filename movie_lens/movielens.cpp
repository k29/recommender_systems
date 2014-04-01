#include <iostream>
#include <shogun/io/CSVFile.h>
#include <shogun/lib/SGMatrix.h>
#include <eigen3/Eigen/Sparse>

using namespace shogun;
using namespace std;

void print_message(FILE* target, const char* str)
{
	fprintf(target, "%s", str);
}


void user_rating(SGMatrix<int32_t> &userRatings) //user_ratings has the data in the 943*1682 matrix
{
	SGMatrix<int32_t> input_udata(true); //matrix to take in the raw input

	CCSVFile *fin;
	fin=new CCSVFile("ml-100k/u.data",'r',NULL);
	fin->set_delimiter('	');
	fin->get_matrix(input_udata.matrix,input_udata.num_cols,input_udata.num_rows);
	
	userRatings.zero(); //filling all elements in the userRatings matrix with 0

	int user_id;
	int movie_id;
	int rating;

	for(int i=0;i<100000;i++)
	{
		user_id=input_udata[4*i];
		movie_id=input_udata[4*i+1];
		rating=input_udata[4*i+2];
		userRatings(user_id-1,movie_id-1)=rating;
	}
	//userRatings.display_matrix("userRatings");

}

int main(int argc, char const *argv[])
{
	init_shogun(&print_message);

	index_t nrows_users=943;
	index_t ncols_users=1682;	
	SGMatrix<int32_t> userRatings(nrows_users,ncols_users,true); //defining the user rating matrix having the correspoinding rating in the 943x1682 matrix

	user_rating(userRatings);
	

	return 0;
}