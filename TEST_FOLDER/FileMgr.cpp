// FileMgr.cpp
#include "FileMgr.h"
#include <iostream>
#include <sstream>



FileMgr::FileMgr(const std::string& path, DataStore& ds) :path_(path), store_(ds){
	std::cout << "my path " << path_ << std::endl;
	patterns_.push_back("*.*");
}

void FileMgr::addPattern(const std::string& patt){
	if (patterns_.size() == 1 && patterns_[0] == "*.*"){
		patterns_.pop_back();
		patterns_.push_back(patt);
	}
}

void FileMgr::find(const std::string& path){
	for (auto patt : patterns_){
		searchFiles(path, patt, TRUE);
	}
}

void FileMgr::search(){
	find(path_);
}

//----< parses command line arguments>--------------------------------
void FileMgr::parseCmdLine(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++){
		std::string tmpArg = argv[i];
		if (tmpArg == "/s"){
			isSearchRecursively = true;
		}
		else if (tmpArg == "/b"){
			bShowFuncSizeComplexity = true;
		}
		else if (path_.empty()){
			path_ = FileSystem::Path::getFullFileSpec(argv[i]);
		}
		else{
			addPattern(tmpArg);
		}
	}

	if (path_.empty()){
		path_ = FileSystem::Path::getFullFileSpec(".");  // default path
	}

	//if (searchPatterns.empty()){
	//	searchPatterns.push_back("*.*"); // default pattern
	//}
}



//----< Lists the file recursively, if listRecursively is true >--------------------------------
void FileMgr::searchFiles(std::string path, std::string pattern, bool listRecursively)
{
	//std::cout << "\n I m here =" << path << "   pattern=" << pattern << "    listRecursively= " << listRecursively <<std::endl;
	if (!FileSystem::Directory::exists(path))
	{
		std::ostringstream out;
		out << "Path " << path << " does not exist";
		throw std::exception(out.str().c_str());
	}
	std::vector<std::string> tmpFiles = FileSystem::Directory::getFiles(path, pattern);
	for (auto tmpFile : tmpFiles){
		//files.push_back(path + "\\" + tmpFile);
		std::string filePath = FileSystem::Path::fileSpec(path, tmpFile);
		//std::cout << "\n File path :" << FileSystem::Path::getFullFileSpec(filePath);
		std::string fullPathwithFile = FileSystem::Path::getFullFileSpec(filePath);
		std::string fullPath = FileSystem::Path::getPath(fullPathwithFile);
		store_.save(tmpFile, fullPath);
	}

	if (listRecursively){
		std::vector<std::string> dirs = FileSystem::Directory::getDirectories(path);
		for (auto dir : dirs){
			if (dir == "." || dir == ".."){
				continue;
			}
			std::string dirPath = FileSystem::Path::fileSpec(path, dir);
			searchFiles(dirPath, pattern, listRecursively);
		}
	}

}

int main(){
	DataStore ds;
	FileMgr fm("D:\List", ds);
	fm.addPattern("*.h*");
	//fm.addPattern("*.partial");
	//fm.addPattern("*.*");

	fm.search();

	for (auto fs : ds){
		std::cout << " \n files: \n" << fs.c_str();
	}
	ds.printSet();
	std::cout << " print map \n \n";
	ds.printMap();
	std::cout << "\n\n";
	return 0;
}