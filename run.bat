@echo off
cls

echo ***** Demonstrating Requirement 3 , 4 and 7 Default case *****
echo ***** Command: *****
".\Project1ood\Debug\Project1ood.exe" 

cls
echo ***** Demonstrating Requirement 3 , 4 and 7 With only Path given *****
echo ***** Command: TEST_FOLDER *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" 

cls
echo ***** Demonstrating Requirement 3, 4 and 7 with /s option without pattern *****
echo ***** Command: TEST_FOLDER  /s *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "/s"

cls
echo ***** Demonstrating Requirement 3, 4 and 7 with /s option and patterns*****
echo ***** Command: TEST_FOLDER *.cpp *.h /s *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "*.cpp" "*.h" "/s"

cls
echo ***** Demonstrating Requirement 3 , 4 and 7 without /s option *****
echo ***** Command: TEST_FOLDER *.cpp *.h  *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "*.cpp" "*.h" 

cls
echo ***** Demonstrating Requirement 3 , 4 and 7  without pattern provided *****
echo ***** Command: TEST_FOLDER "/s"  *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "/s"

cls
echo ***** Demonstrating Requirement 3 , 4 and 5 with /s and /d option *****
echo ***** Command: TEST_FOLDER *.cpp *.h /s /d *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "*.cpp" "*.h" "/s" "/d"

cls
echo ***** Demonstrating Requirement 3 , 4 and 5 without /s but /d option *****
echo ***** Command: TEST_FOLDER *.cpp *.h /d *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "*.cpp" "*.h" "/d"

cls
echo ***** Demonstrating Requirement 3 , 4 and 6  /f search text *****
echo ***** Command: TEST_FOLDER *.cpp *.h /s (/f"main") *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "*.cpp" "*.h" "/s" "/f"main""

cls
echo ***** Demonstrating Requirement 7 with no option provided (not /f and not /d) *****
echo ***** Command: TEST_FOLDER *.cpp *.h  *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "*.cpp" "*.h"

cls
echo ***** Demonstrating Requirement 3, 4 , 5 , 6 and 7  *****
echo ***** Command: TEST_FOLDER *.cpp *.h /s /d (/f"main") *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "*.cpp" "*.h" "/s" "/d" "/f"main""

cls
echo ***** Demonstrating Requirement 3, 4 , 5 , 6 and 7  Searching wrong text*****
echo ***** Command: TEST_FOLDER *.cpp *.h /s /d (/f" OOD Project Demonstarting requirement") *****
".\Project1ood\Debug\Project1ood.exe" "..\Projects\TEST_FOLDER" "*.cpp" "*.h" "/s" "/d" "/f" OOD Project Demonstarting requirement""