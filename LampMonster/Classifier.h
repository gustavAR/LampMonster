#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <vector>
#include <string>

class Classifier
{
public:
	virtual std::string Classify(std::vector<std::string> words);
};
#endif 