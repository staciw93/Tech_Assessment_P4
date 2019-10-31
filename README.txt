The purpose of this program is to format text into a column of specified width. 
This program takes 3 command line arguments. The first is the file to read from,
the second is the file to write to, and the last is the number of characters in
a column.

To build and run this program, I use the Visual Studio Developer Command Prompt
using the cl command to compile. For example, the following would compile and
run this program using the test2.txt file as input, test2results.txt as the
output file, and a column width of 30 characters:
  cl main.cpp
  main.exe test2.txt test2results.txt 30

However, to make the program easier to run on other platforms, I included a
CMakeLists file to create the project.
