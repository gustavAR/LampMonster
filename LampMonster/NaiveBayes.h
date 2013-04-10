#ifndef NAIVEBAYES_H
#define NAIVEBAYES_H

#include <map>
#include <vector>
#include <string>

double NBC(double probOfClass, std::map<std::string,int> vocabulary, std::vector<std::string> words, double prior);

#endif 