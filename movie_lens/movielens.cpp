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
	fin=fopen("ml-100k/u.item","rb");


	//Read the ascii file using LineReader and delimiter "\n"
	SGVector<char> line;
	CDelimiterTokenizer *tokenLineReader=new CDelimiterTokenizer(false);
	tokenLineReader->delimiters['\n']=1;
	SG_REF(tokenLineReader);

	CLineReader *lineReader=new CLineReader(fin,tokenLineReader);

	//Read the line(string) using a parse and the delimiter "|"
	CDelimiterTokenizer *tokenizer=new CDelimiterTokenizer(false);
	tokenizer->delimiters['|']=1;
	// tokenizer->set_skip_delimiters(false);
	SG_REF(tokenizer);

	CParser *parse;

	//Actual reading:
	int32_t row=0;
	while(lineReader->has_next())
	{
		line=lineReader->read_line();
		parse=new CParser(line,tokenizer);
		int32_t col=0;
		while(parse->has_next())
		{
			if(col<5)
				(parse->read_string());
			else
			{
				movieMetadata(row,col-5)=parse->read_real();
			}
			col++;
		}
		row++;
		
	}
	SG_UNREF(tokenLineReader);
	SG_UNREF(tokenizer);

	movieMetadata.display_matrix("movieMetadata");
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