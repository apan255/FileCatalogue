/////////////////////////////////////////////////////////////////////
//  Executive.cpp - Makes call to the ParseCmd, FileManager,       //
//                  Cataloger and Display Classes              	   //
//  ver 1.0                                                        //
//  Language:      Visual C++ 2013                                 //
//  Platform:      Dell Inspiron, Windows 8.1                      //
//  Application:   File Catalogue, OOD Assignment 1, Spring2015    //
//  Author:		   Ankur Pandey                                    //
/////////////////////////////////////////////////////////////////////
/*
Module Operations:
==================
This module defines a Executive Package to run – File Catalogue Project.

Build Process:
==============
Required files
- FileMgr.h, FileMgr.cpp, Display.h, Display.cpp , Cataloger.h, Cataloger.cpp, ElementDisplay.h
Build commands
- devenv Project1ood.sln

Maintenance History:
====================
ver 1.0 : 8 Feb 2015
- first release
*/

#include "../FileMgr/FileMgr.h"
#include "../Cataloger/Cataloger.h"
#include "../ParseCommand/ParseCommand.h"
#include "../DataStore/ElementDisplay.h"
#include "../Display/Display.h"
#include <string>

#ifdef TEST_EXECUTIVE

//----< Print Header String in Specific Format>---------------------------
void printHeader(std::string header){
	std::cout << "\n";
	std::cout << std::string(75, '*');
	std::cout << "\n" << header;
	std::cout << "\n" << std::string(75, '*');
	std::cout << "\n";
}

//----< Calling Executive Main >-------------------------------------------
int main(int argc, char* argv[])
{
	try{
		printHeader("Testing Executive Package :: ");
		ParseCmd parser;
		std::cout << "\nParsing Command line arguments: " << std::endl;
		parser.parseCmdLine(argc, argv);
		try{
			FileMgr fileManager;
			std::cout << "Searching for files and building Datastore: " << std::endl;
			fileManager.search(parser.getPath(), parser.getPatterns(), parser.getisSearchRecursively());
			try
			{
				std::string loopBreakCheck = "";
				Cataloger Catalog(fileManager);
				Display ds;
				std::vector< ElementDisplay> printPathStore = Catalog.printPathStore();
				std::vector< ElementDisplay> printFileStore = Catalog.printFileStore();
				ds.printFileStore(printFileStore);
				ds.printPathStore(printPathStore);

				do{
					std::vector< ElementDisplay> duplicate;
					if (parser.getIsDuplicateSearch()){
						duplicate = Catalog.displayDuplicateFilesAndDirectories();
					}
					std::vector< ElementDisplay> numberOfFilesAndDir;
					if (parser.getIsDisplayNumofFileAndDirect()){
						numberOfFilesAndDir = Catalog.displayNumofFileAndDirectories();
					}
					std::vector< ElementDisplay> filesCatlog;
					if (parser.getIsSearchtext()){
						filesCatlog = Catalog.searchUserText(parser.getPatterns(), parser.getSearchtext());
					}
					Display display(filesCatlog, duplicate, numberOfFilesAndDir);
					display.printOutput(parser.getIsDuplicateSearch(), parser.getIsSearchtext(), parser.getIsDisplayNumofFileAndDirect());
					std::cout << " \n";
					std::cout << "*** Demonstrating Requirement 8 :" << std::endl;
					std::string userInputString;
					std::getline(std::cin, userInputString);
					userInputString += " ";
					loopBreakCheck = userInputString;
					std::cout << " \n";
					if ((loopBreakCheck != " ") && !parser.parseUserCommand(userInputString)){
						std::cout << " Usage: \n" << "\"search text\" patterns" << std::endl;
					}
				} while (loopBreakCheck != " ");
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
	return 0;
}
#endif