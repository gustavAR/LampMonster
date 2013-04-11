#include "IPathFinder.h"

class PathFinderBase : IPathFinder
{
public:
	PathFinderBase(const boost::filesystem::path& root,
				   const int numTrainingFiles,
				   const int numProcessingFiles);
protected:
	const boost::filesystem::path root;
	const int numTrainingFiles;
	const int numProcessingFiles;

};

PathFinderBase::PathFinderBase(const boost::filesystem::path& root,
				const int numTrainingFiles,
				const int numProcessingFiles) 
					: root(root), 
					  numTrainingFiles(numTrainingFiles),
					  numProcessingFiles(numProcessingFiles) { }