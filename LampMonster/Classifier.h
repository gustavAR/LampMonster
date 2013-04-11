#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <vector>
#include <string>

class Classifier
{
public:
	virtual ~Classifier() { }
	virtual std::string Classify(std::vector<std::string> words) { return ""; }
};
#endif 