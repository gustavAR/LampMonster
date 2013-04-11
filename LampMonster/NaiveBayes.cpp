#include <iostream>
#include "NaiveBayes.h"
#include "BuildBagOfWords.h"

#define VERSION_NUMBER 0.0
#define DEFAULT_TRAIN_SIZE 10
using namespace std;

NaiveBayes::NaiveBayes(CategoryPaths paths)
{
	categories = vector<Category> (paths.size()); //TODO: Think over this...
	int i = 0;
	for(auto path = paths.cbegin(); path != paths.cend(); path++) //for each training path in paths
		categories[i++] = Category(path->first,BuildBagOfWords(path->second));	//Build and fill a category with a bag of words
}

string NaiveBayes::Classify(vector<string>& words)
{
	string category = categories.begin()->first;	//Set first category as default
	double maxProb = 0;						//Set current maximum category probability to 0
	for(Category& c : categories) {			//For each category
		double curProb = (NBC(1/categories.size(), c.second, words, prior)); //Calculate probability for the words belonging to that category
		if (curProb>maxProb) {				//If probability is higher that of the previous most probable (fittest) category
			maxProb = curProb;				//Update maximums
			category = c.first;
		}	
	}
	return category;			//Returns the name of the most probable category
}




double NBC(double probOfClass, const map<string,int>& vocabulary, const vector<string>& words, double prior)
{
	double product = 1;
	int totNumWordsInVoc = 0;

	for(auto i = vocabulary.cbegin(); i != vocabulary.cend(); i++) //Get the sum of all words in the vocabulary map
		totNumWordsInVoc += i->second;

	double nom = (totNumWordsInVoc + vocabulary.size()*prior);
	for (string word : words) //calculate probalility for each word to belong to classification with the vocabulary
	{
		double denom = prior;
		if (vocabulary.find(word) != vocabulary.end())
			denom += vocabulary.at(word);
		product *= (denom/nom);
	}
	return product*probOfClass;
}


	/*
	double NBC(double probOfClass, const map<string,int>& vocabulary, const vector<string>& words, double prior)
	{
	double product = 1;
	int totNumWordsInVoc = 0;

	for(auto i = vocabulary.cbegin(); i != vocabulary.cend(); i++) //Get the sum of all words in the vocabulary map
	totNumWordsInVoc += i->second;

	double nom = (totNumWordsInVoc + vocabulary.size()*prior);
	for (string word : words) //calculate probalility for each word to belong to classification with the vocabulary
	{
	double denom = prior;
	if (vocabulary.find(word) != vocabulary.end())
	denom += vocabulary.at(word);
	product *= (denom/nom);
	}
	return product*probOfClass;
	}

	void NaiveBayesTest(void)
	{
	map<string,int> m;
	m["Buuuh"] = 2;
	m["Aaah"] = 1;
	m["Ooooh"] = 5;
	m["Oooiihihih"] = 2;
	m["Hehehaha"] = 3;
	m["Hahahahohohhuehue"] = 1;

	map<string,int> m2;
	m2["Buuuh"] = 1;
	m2["Aaah"] = 0;
	m2["Ooooh"] = 2;
	m2["Oooiihihih"] = 0;
	m2["Hehehaha"] = 2;
	m2["Hahahahohohhuehue"] = 0;

	vector<string> s (7);
	s[0]="Buuuh";
	s[1]="Buuuh";
	s[2]="Ooooh";
	s[3]="Hehehaha";
	s[4]="Buuuh";
	s[5]="Ooooh";
	s[6]="Hehehaha";

	cout << "Result: " << (NBC(0.5, m, s, 1) < NBC(0.5, m2, s, 1)? "yay!":"ops") <<endl;
	}
	*/