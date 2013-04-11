#include <boost/filesystem.hpp>
#include <map>
#include <string>
using namespace std;

const map<string, int> BuildBagOfWords(const vector<boost::filesystem::path>& files);

void BuildBagTest(void);