#ifndef EXECU_H
#define EXECU_H

#include"../FileMgr/FileMgr.h"
#include"../Cataloger/Cataloger.h"

#include <iostream>
#include <vector>
class Executive
{
public:

	//using iterator = DataStore::iterator;

	// constructor
	Executive(FileMgr& fm, Cataloger& cat) :fileMgr_(fm), cataloger_(cat){
	}

	void addPattern(const std::string& patt);
	void search();
	void find(const std::string& path);
	void parseCmdLine(int argc, char* argv[]);
	void textSearch(std::string pattern, const std::string& filePath, std::string& filename);

private:
	Cataloger& cataloger_;
	FileMgr& fileMgr_;
};
#endif