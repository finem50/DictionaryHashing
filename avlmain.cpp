#include "Dictionary.cpp"
#include <iostream>
#include <fstream>
#include <string>

int main(){

  Dictionary dict;
  std::string in_file_name, out_file_name, str;
  std::ifstream in_s;
  std::ofstream out_s;

  //std::cout << "Please enter the name of a text file to spell check:" << std::endl;
  //std::cin >> in_file_name;
  in_file_name = "inputSmall.txt";

  std::cout << "Please enter the name of a file to output to:" << std::endl;
  std::cin >> out_file_name;

  in_s.open(in_file_name);

  //If input file name is invalid, re-prompt the user to enter a correct one
  while(in_s.fail()){

    in_s.clear();
    std::cout << "Input file opening failed, please retry input file name." << std::endl;
    std::cin >> in_file_name;
    in_s.open(in_file_name.c_str());
  }

  out_s.open(out_file_name);

  while(out_s.fail()){

    out_s.clear();
    std::cout << "Output file opening failed, please retry output file name." << std::endl;
    std::cin >> out_file_name;
    in_s.open(out_file_name.c_str());
  }

  while(std::getline(in_s, str)){

    dict.AddEntry(str);
  }

  dict.PrintSorted(out_s);

  out_s.close();
  in_s.close();
  return 0;
}
