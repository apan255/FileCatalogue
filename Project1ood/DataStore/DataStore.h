#ifndef DATASTORE_H
#define DATASTORE_H
/////////////////////////////////////////////////////////////////////
//  DataStore.h - Stores Catalog Data in map and set               //
//					                  							   //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2013                                 //
//  Platform:      Dell, Windows 8.1                               //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Author:		   Ankur Pandey                                    //
/////////////////////////////////////////////////////////////////////
/*
Module Operations:
==================
This module defines a class that provides services necessary to Store
a datastore catalog of all files in the file catalogue,
saving each file name only once map Store and saving each path only once in set Store,
while preserving all of the containment relationships between directories
and their files. That implies that each file storage will have to save a
list of references into a set of paths where they are found.

Public Interface:
=================

DataStore ds;                                                           // Get DataStore Instance
ds.savingData(const std::string& filename, const std::string& path);    // Saves Data Store in map
std::vector<ElementDisplay> dataStoreVec = ds.printDataStoreMap();      // Return vector for Displaying Map Store
std::vector<ElementDisplay> pathVec = ds.printPathStoreMap();           // Return vector for Displaying Path Store
std::set<std::string>::iterator pathItr = ds.pathBegin();               // Return Path Store Begin
std::set<std::string>::iterator pathItr = ds.pathEnd();                 // Return Path Store End
int Value = ds.dataStoreSize();                                         // Return Data Store Size
std::map<file, pathList>::iterator mapItr = ds.mapDataStoreBegin();     // Return Map Store Begin
std::map<file, pathList>::iterator mapItr = ds.mapDataStoreEnd();       // Return Map Store End

Build Process:
==============
Required files
- DataStore.h, DataStore.cpp ,ElementDisplay.h
Build commands
- devenv DataStore.vcxproj

Maintenance History:
====================
ver 1.0 : 8 Feb 2015
- first release
*/

#include<map>
#include<list>
#include<set>
#include<vector>
#include "ElementDisplay.h"

class DataStore{

public:

	using file = std::string;
	using path = std::string;
	using setPathStore = std::set < path > ;
	using pathIterator = std::set<path>::iterator;
	using pathList = std::list < pathIterator > ;
	using pathListIterator = std::list<pathIterator>::iterator;
	using mapDataStore = std::map < file, pathList > ;
	using mapDataStoreIterator = std::map<file, pathList>::iterator;
	using retVector = std::vector < ElementDisplay > ;

	void savingData(const std::string& filename, const std::string& path);
	retVector printDataStoreMap();
	retVector printPathStoreMap();
	int DataStoreSize();

	pathIterator pathBegin();
	pathIterator pathEnd();
	mapDataStoreIterator mapDataStoreBegin();
	mapDataStoreIterator mapDataStoreEnd();
	DataStore();
private:
	bool isPathExist(const std::string& path);
	bool isFileExist(const std::string& filename);
	pathIterator getPathRefernce(const std::string& path);

	setPathStore setPathStore_;
	mapDataStore mapDataStore_;
};
#endif