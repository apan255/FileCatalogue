@echo off
cls

echo ***** Building the Solution *****
cd Project1ood
devenv Project1ood.sln /rebuild debug
cd ..