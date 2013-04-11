#ifndef FILE_PARSER_H
#define FILE_PARSER_H
#include <string>
#include <vector>
#include <boost/filesystem.hpp>

class FileParser
{
public:
	FileParser(const std::string& delimiters);

	/* Given a file it returns all the words in that file. */
	std::vector<std::string> ParseFile(const boost::filesystem::path& filepath) const;
	
	/* Given a collection of files it returns all the words in those files. */
	std::vector<std::string> ParseFiles(const std::vector<boost::filesystem::path>& paths) const;
private:
	void Parse(const boost::filesystem::path& path, std::vector<std::string>& words) const;
	const std::string delimiters;
};


void testFileParser();

#endif