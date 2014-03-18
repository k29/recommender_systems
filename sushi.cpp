#include "sushi.h"

using namespace std;


void sushi::display_double_vector( DoubleVector& dv)
{
    for(int i=0;i<4;i++)
    {
    	for(int j=0;j<dv[i].size();j++)
    		cout<<dv[i][j]<<"\t";
    	cout<<"\n";
    }
    cout<<"\n\n\n\n";
}

void sushi::display_vector(Vector &v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<"\t";
	}
	cout<<"\n";
}

void sushi::deletecolumn(DoubleVector& dv,int n)
{
	for(int i=0;i<dv.size();i++)
	{
		dv[i].erase(dv[i].begin() + n);
	}
}

void sushi::deleterow(DoubleVector& dv, int n)
{
	dv.erase(dv.begin()+n);
}

void sushi::sushiudata()
{
	string line;
	string word;
	v.clear();
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
	cout<<"Displaying user metadata (DoubleVector usermetadata)\n";
	display_double_vector(usermetadata);
}


void sushi::sushiidata()
{
	string line;
	string word;
	v.clear();
	ifstream myfile("sushi3.idata");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			istringstream stm(line);
			v.clear();
			while(stm>>word)
			{
				v.push_back(word);
				//display_vector(v);
			}
			itemmetadata.push_back(v);
		}
	}
	deletecolumn(itemmetadata,0); //to delete the first column
	deletecolumn(itemmetadata,0); //to delete the first column after the previous deletion
	cout<<"Displaying item metadata (DoubleVector itemmetadata)\n";
	display_double_vector(itemmetadata);
}



void sushi::ranking_sushi_A()
{
	string line;
	string word;
	v.clear();
	ifstream myfile("sushi3a.5000.10.order");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			istringstream stm(line);
			v.clear();
			while(stm>>word)
			{
				if(word=="5")
					word="15";
				else if(word=="8")
					word="26";
				else if(word=="9")
					word="29";
				else if(word=="7")
					word="8";
				else if(word=="6")
					word="7";
				v.push_back(word);
				//display_vector(v);
			}
			rankingA.push_back(v);
		}
	}
	deleterow(rankingA,0);
	deletecolumn(rankingA,0);
	deletecolumn(rankingA,0);
	cout<<"Displaying the rankings for Sushi A (first 4 rows)(DoubleVector rankingA) \n";
	display_double_vector(rankingA);
}

void sushi::ranking_sushi_B()
{
	v.clear();
	string line;
	string word;
	
	ifstream myfile("sushi3b.5000.10.order");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			istringstream stm(line);
			v.clear();
			while(stm>>word)
			{
				if(word=="-1")
					word="0";
				else if(word=="0")
					word="1";
				else if(word=="1")
					word="2";
				else if(word=="2")
					word="3";
				else if(word=="3")
					word="4";
				else if(word=="4")
					word="5";
				v.push_back(word);
				//display_vector(v);
			}
			rankingB.push_back(v);
		}
	}
	deleterow(rankingB,0);
	deletecolumn(rankingB,0);
	deletecolumn(rankingB,0);
	cout<<"Displaying the rankings for Sushi B (first 4 rows)(DoubleVector rankingB)\n";
	display_double_vector(rankingB);
}

void sushi::sushiB_score()
{
	string line;
	string word;
	v.clear();
	ifstream myfile("sushi3b.5000.10.score");
	if(myfile.is_open())
	{
		while(getline(myfile,line))
		{
			istringstream stm(line);
			v.clear();
			while(stm>>word)
			{
				v.push_back(word);
				//display_vector(v);
			}
			sushiB_ratings.push_back(v);
		}
	}
	cout<<"Displaying the ratings for Sushi B (first 4 rows) (Doublevector sushiB_ratings) \n";
	display_double_vector(sushiB_ratings);
}