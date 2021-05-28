@echo off 
g++ -std=c++11 %1 -o ram && ram
del ram.exe