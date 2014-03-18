#include <sushi.h>

void sushi::sushiudata()
{
	string line;
	string word;

	ifstream myfile("sushi3.udata");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			istringstream stm(line);
			v.clear();
			while(stm>>word)
				v.push_back(word);
			usermetadata.push_back(v);
		}
	}
	deletecolumn(usermetadata,0);
	display_double_vector(usermetadata);
}
