#include <iostream>
#include <stdio.h>
#include <shogun/io/File.h>
#include <shogun/io/CSVFile.h>
#include <shogun/io/LineReader.h>
#include <shogun/lib/SGMatrix.h>
#include <eigen3/Eigen/Sparse>
#include <shogun/lib/DelimiterTokenizer.h>

using namespace shogun;
using namespace std;

void print_message(FILE* target, const char* str)
{
	fprintf(target, "%s", str);
}


void extract_user_rating(SGMatrix<int32_t> &userRatings) //user_ratings has the data in the 943*1682 matrix
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


void extract_movie_metadata(SGMatrix<int32_t> &movieMetadata)
{
	SGMatrix<int32_t> input_mdata(true); //matrix to take in the raw input

	FILE *fin;
	fin=new FILE("ml-100k/u.item",'r',NULL);

	SGVector<char> line;

	CDelimiterTokenizer *tokenLine=new CDelimiterTokenizer(true);
	tokenLine->delimiters['\n']=1;
	SG_REF(tokenLine);

	CDelimiterTokenizer *tokenizer=new CDelimiterTokenizer(true);
	tokenizer->delimiters['|']=1;
	SG_REF(tokenizer);
	
	CLineReader *reader=new CLineReader(fin,tokenLine);


}

int main(int argc, char const *argv[])
{
	init_shogun(&print_message);

	SGMatrix<int32_t> userRatings(943,1682,true); //defining the user rating matrix having the correspoinding rating in the 943x1682 matrix
	extract_user_rating(userRatings);

	SGMatrix<int32_t> movieMetadata(1682,19,true); //contains genre info
	extract_movie_metadata(movieMetadata);
	

	return 0;
}