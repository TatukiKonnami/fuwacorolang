#ifndef OPTION_HPP
#define OPTION_HPP

#include <string>

class OptionParser
{
private:
  std::string InputFilename;
  std::string OutputFilename;
  int Argc;
  char **Argv;

public:
  OptionParser(int argc, char **argv):Argc(argc), Argv(argv){}
  void printHelp(){
    fprintf(stdout, "Compiler for DummyC\n");
  }
  std::string getInputFileName(){return InputFilename;}
  std::string getOutputFileName(){return OutputFilename;}
  bool parseOption();
};

#endif