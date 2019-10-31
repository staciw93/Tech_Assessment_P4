#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char const *argv[]) {
  if(argc != 4){
    std::cout << " Input filename, output filename, and column width required.\n";
    return 0;
  }

  int width = std::atoi(argv[3]);
  std::string inFileName = argv[1];
  std::string outFileName = argv[2];

  //open files for reading and writing
  std::ifstream infile;
  infile.open(inFileName);
  std::ofstream outfile;
  outfile.open(outFileName);

  // string variables
  std::string text;
  std::string paddedtext = "";

  //variables to calculate length of string
  int actualTotal = 0;
  int theorTotal = 0;
  int spacesNeeded = 0;

  if( infile.is_open() ){

    //extracts space seperated words
    while( infile >> text ){
      if( text.length() > width){
        std::cout << "Encountered word longer than width of column: " << text << "\n";
        std::cout << "Column width: " << argv[3] << " word length: " << text.length() << "\n";
        break;
      }

      if(paddedtext == ""){
        actualTotal = text.length();
        paddedtext = text;
      }
      else{
        theorTotal = actualTotal + text.length() + 1;
        if(theorTotal <= width){
          paddedtext = paddedtext + " " + text;
          actualTotal = theorTotal;
        }
        else{
          spacesNeeded = width - actualTotal;
          paddedtext = paddedtext + "\n";
          for(int i = 0; i < spacesNeeded/2; i++){
            paddedtext = " " + paddedtext;
          }
          outfile << paddedtext;
          paddedtext = text;
          actualTotal = text.length();
        }
      }
    }
    
    //print last line
    spacesNeeded = width - actualTotal;
    paddedtext = paddedtext + "\n";
    for(int i = 0; i < spacesNeeded/2; i++){
      paddedtext = " " + paddedtext;
    }
    outfile << paddedtext;

    infile.close();
    outfile.close();
  }

  return 0;
}
