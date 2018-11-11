#include "Dictionary.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <vector>

std::vector<std::string> input_build(std::string input);
Dictionary dictionary_build(std::string dict);

int main(){

  //std::cout << "Please enter the name of a text file to spell check:" << std::endl;
  //std::cin >> in_file_name;
  std::string in_file_name = "inputSmall.txt";
  std::string out_file_name;
  std::string dictionary_name = "dictSmall.txt";
  std::ofstream out_s;

  std::vector<std::string> input = input_build(in_file_name);
  Dictionary avl_dict = dictionary_build(dictionary_name);

  std::cout << "Please enter the name of a file to output to:" << endl;
  std::cin >> out_file_name;
  out_s.open(out_file_name);

  while(out_s.fail()){

    out_s.clear();
    std::cout << "Output file opening failed, please retry output file name." << std::endl;
    std::cin >> out_file_name;
    out_s.open(out_file_name.c_str());
}

  for(int i = 0; i < input.size(); i++){

    if(avl_dict.FindEntry(input.at(i)) == true){

      std::cout << input.at(i) << " is spelled correctly." << endl;
    }else{

      out_s << input.at(i) << endl;
    }
  }

  return 0;
}

//Building input text file I/O
std::vector<std::string> input_build(std::string input){

  std::vector<std::string> check;
  std::string str;
  std::ifstream in_s;
  std::locale loc;


  in_s.open(input);

  //If input file name is invalid, re-prompt the user to enter a correct one
  while(in_s.fail()){

    in_s.clear();
    std::cout << "Input file opening failed, please retry input file name." << std::endl;
    std::cin >> input;
    in_s.open(input.c_str());
  }

  while(std::getline(in_s, str)){

    for(std::string::size_type i = 0; i < str.length(); i++){

      str[i] = std::tolower(str[i], loc);
    }

    check.push_back(str);
  }

  in_s.close();

  return check;
}

//Building dictionary AVL tree with file I/O
Dictionary dictionary_build(std::string dict){

  Dictionary dictionary;
  std::string str;
  std::ifstream in_s;

  in_s.open(dict);

  while(in_s.fail()){

    in_s.clear();
    std::cout << "Dictionary file opening failed, please check file name." << std::endl;
    std::exit(1);
  }

  while(std::getline(in_s, str)){

    dictionary.AddEntry(str);
  }

  in_s.close();

  return dictionary;
}
