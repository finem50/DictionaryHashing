#include "Dictionary.cpp"
#include <iostream>
#include <fstream>
#include <string>

void input_build(std::string input);
void dictionary_build(std::string dict);

int main(){

  //std::cout << "Please enter the name of a text file to spell check:" << std::endl;
  //std::cin >> in_file_name;
  std::string in_file_name = "inputSmall.txt";
  std::string dictionary_name = "dictSmall.txt";

  input_build(in_file_name);
  dictionary_build(dictionary_name);

  return 0;
}

//Building input text file I/O
void input_build(std::string input){

  Dictionary check;
  std::string out_file_name, str;
  std::ifstream in_s;
  std::ofstream out_s;

  std::cout << "Please enter the name of a file to output to:" << std::endl;
  std::cin >> out_file_name;

  in_s.open(input);

  //If input file name is invalid, re-prompt the user to enter a correct one
  while(in_s.fail()){

    in_s.clear();
    std::cout << "Input file opening failed, please retry input file name." << std::endl;
    std::cin >> input;
    in_s.open(input.c_str());
  }

  out_s.open(out_file_name);

  while(out_s.fail()){

    out_s.clear();
    std::cout << "Output file opening failed, please retry output file name." << std::endl;
    std::cin >> out_file_name;
    in_s.open(out_file_name.c_str());
  }

  while(std::getline(in_s, str)){

    check.AddEntry(str);
  }

  check.PrintSorted(out_s);

  out_s.close();
  in_s.close();
}

//Building dictionary file I/O
void dictionary_build(std::string dict){

  Dictionary dictionary;
  std::string str;
  std::ifstream in_s;
  std::ofstream out_s;

  in_s.open(dict);

  while(in_s.fail()){

    in_s.clear();
    std::cout << "Dictionary file opening failed, please check file name." << std::endl;
    std::exit(1);
  }

  out_s.open("testdict.txt");

  while(out_s.fail()){

    out_s.clear();
    std::cout << "Output file opening failed, please try again." << std::endl;
    std::exit(1);
  }

  while(std::getline(in_s, str)){

    dictionary.AddEntry(str);
  }

  dictionary.PrintSorted(out_s);

  in_s.close();
  out_s.close();
}
