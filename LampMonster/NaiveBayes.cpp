#include <iostream>
#include "NaiveBayes.h"

#define VERSION_NUMBER 0.0
#define DEFAULT_TRAIN_SIZE 10


using namespace std;

double NBC(double probOfClass, map<string,int> vocabulary, vector<string> words, double prior)
{
double product = 1;
int totNumWordsInVoc = 0;

for(auto i = vocabulary.cbegin(); i != vocabulary.cend(); i++) //Get the sum of all words in the vocabulary map
totNumWordsInVoc += i->second;
cout<<"total number of words: "<<totNumWordsInVoc<<endl;
for (string word : words) //calculate probalility for each word to belong to classification with the vocabulary
{
//cout<<"Product = "<<product<<endl;
double denom = (vocabulary.at(word)+prior);
//cout<<"Word = "<< word << "\t#times+1: "<< denom <<endl;

double nom = (totNumWordsInVoc + vocabulary.size()*prior);
//cout<<"nominator: "<<nom<<endl;
product *= (denom/nom);
//cout<<endl;
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