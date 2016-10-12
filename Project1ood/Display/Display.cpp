/////////////////////////////////////////////////////////////////////
//  Dispaly.cpp - display analysis facility of a build catalogue.  //
//					                							   //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2013                                 //
//  Platform:      Dell, Windows 8.1                               //
//  Application:   Scope analysis, OOD Assignment 1, Spring2015    //
//  Author:		   Ankur Pandey                                    //
/////////////////////////////////////////////////////////////////////

#include "Display.h"
#include <iomanip>
#include <iostream>

//----< Display Constructor >------------------------------------------
Display::Display(filesCatDisplay filesCatDisplay, duplicatedisplay dupDispalyVec,
	DulicateFilesAndDir numberOfFilesAndDir){
	this->filesCatDisplayVec_ = filesCatDisplay;
	this->duplicatedisplayVec_ = dupDispalyVec;
	this->numberOfFilesAndDirVec_ = numberOfFilesAndDir;
}

//----< Display Default Constructor >------------------------------------------
Display::Display(){
}

//----< Print Path Store >-------------------------------------------------
void Display::printPathStore(VectorElementDisplay pathStore){
	printHeader(" Print All Paths ");
	for (auto pathDisplay : pathStore){
		printPathsFoundOutput(pathDisplay);
	}
}

//----< Print File Store >--------------------------------------------------
void Display::printFileStore(VectorElementDisplay fileStore){
	printHeader("Print All Files Along with Paths ");
	for (auto filesCat : fileStore){
		printFileAndPaths(filesCat);
	}
}

//----< Print Header String in Specific Format >----------------------------
void Display::printHeader(std::string header){
	std::cout << "\n" << std::string(75, '-');
	std::cout << "\n" << header;
	std::cout << "\n" << std::string(75, '-');
	std::cout << "\n";
}

//----< Print User Command line Input  >----------------------------------
void Display::userInput(std::string userInputString){
	printHeader("Entered Command");
	std::cout << " " << userInputString << std::endl;
}

//----< Print output based on duplicate search , text search and dispaly num of file and path  >---
void Display::printOutput(bool isDuplicateSearch, bool isSearchtext,
	bool isDisplayNumofFileAndDirect){
	if (isDuplicateSearch){
		printHeader("Displaying Duplicate Files and Directories");
		if (!duplicatedisplayVec_.size()){
			std::cout << "\n" << " No Duplicate Files Found" << std::endl;
		}
		for (auto dubDisplay : duplicatedisplayVec_){
			printFileAndPaths(dubDisplay);
		}
	}
	if (isDisplayNumofFileAndDirect){
		printHeader("Displaying Number Of Files Found In Directories");
		for (auto ndDisplay : numberOfFilesAndDirVec_){
			printDisplayNumofFileAndDirectOutput(ndDisplay);
		}
	}
	if (isSearchtext){
		printHeader("Displaying File Found");
		if (!filesCatDisplayVec_.size()){
			std::cout << "\n" << " No Files Found" << std::endl;
		}
		for (auto fileDisplay : filesCatDisplayVec_){
			printFilesFoundOutput(fileDisplay);
		}
	}
}

//----< Print Duplicate files and path >-----------------------------
void Display::printFileAndPaths(ElementDisplay dubDisplay)
{
	std::cout << dubDisplay.showFileAndPaths();
	std::cout << "\n";
}

//----< Print Number Of Files and Directories >-----------------------
void Display::printDisplayNumofFileAndDirectOutput(ElementDisplay ndDisplay)
{
	std::cout << ndDisplay.NumberOfFilesAndDirectories();
	std::cout << "\n";
}

//----< Print Files found >-------------------------------------------
void Display::printFilesFoundOutput(ElementDisplay fileDisplay)
{
	std::cout << fileDisplay.showFiles();
	std::cout << "\n";
}

//----< Print Path found >-------------------------------------------
void Display::printPathsFoundOutput(ElementDisplay fileDisplay)
{
	std::cout << fileDisplay.showPath();
	std::cout << "\n";
}

// test Stub
#ifdef TEST_DISPLAY
#include "../FileMgr/FileMgr.h"
#include "../Cataloger/Cataloger.h"
#include "../ParseCommand/ParseCommand.h"

//----< Print Header String in Specific Format>---------------------------
void printHeader(std::string header){
	std::cout << "\n" << header;
	std::cout << "\n" << std::string(75, '*');
	std::cout << "\n";
}

//----< Calling Display Main >-------------------------------------------
int main(int argc, char* argv[])
{
	try{
		printHeader("Testing Display Package Begin::");
		ParseCmd parser;
		std::cout << "\nParsing Command line arguments: " << std::endl;
		parser.parseCmdLine(argc, argv);
		try{
			FileMgr fileManager;
			std::cout << "Searching for files and building Datastore: " << std::endl;
			fileManager.search(parser.getPath(), parser.getPatterns(), parser.getisSearchRecursively());
			try
			{
				do{
					Cataloger Catalog(fileManager);
					std::vector< ElementDisplay> duplicate;
					if (parser.getIsDuplicateSearch()){
						std::cout << "Searching duplicate Directories : " << std::endl;
						duplicate = Catalog.displayDuplicateFilesAndDirectories();
					}
					std::vector< ElementDisplay> numberOfFilesAndDir;
					if (parser.getIsDisplayNumofFileAndDirect()){
						std::cout << "Display Number Of Files And Directories : " << std::endl;
						numberOfFilesAndDir = Catalog.displayNumofFileAndDirectories();
					}
					std::vector< ElementDisplay> filesCatlog;
					if (parser.getIsSearchtext()){
						std::cout << "Searching User Text : " << std::endl;
						filesCatlog = Catalog.searchUserText(parser.getPatterns(), parser.getSearchtext());
					}
					std::cout << "Displaying Content :" << std::endl;
					Display display(filesCatlog, duplicate, numberOfFilesAndDir);
					display.printOutput(parser.getIsDuplicateSearch(), 
						parser.getIsSearchtext(), parser.getIsDisplayNumofFileAndDirect());

					std::string userInputString;
					std::getline(std::cin, userInputString);
					std::cout << userInputString << std::endl;
					userInputString += " ";

					std::cout << "\nParsing User Command line arguments : \n" << std::endl;
					if (!parser.parseUserCommand(userInputString)){
						std::cout << " Usage: \n" << "/f<search text> patterns" << std::endl;
					}
				} while (true);
			}
			catch (std::exception& ex)
			{
				std::cout << "\n\n    " << ex.what() << "\n\n";
			}
		}
		catch (std::exception& ex){
			std::cout << "\n\n    " << ex.what() << "\n\n";
		}
	}
	catch (std::exception& ex){
		std::cout << "\n\n    " << ex.what() << "\n\n";
	}
	printHeader("Testing Display Package End::");
	return 0;
}
#endif