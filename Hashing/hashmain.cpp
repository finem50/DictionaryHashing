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
  std::string in_file_name = "inputBig.txt";
  std::string out_file_name;
  std::string dictionary_name = "dictBig.txt";
  std::ofstream out_s;

  std::vector<std::string> input = input_build(in_file_name);
  Dictionary avl_dict = dictionary_build(dictionary_name);

  //Prompt user for input for the name of an output file
  std::cout << "Please enter the name of a file to output to:" << endl;
  std::cin >> out_file_name;
  out_s.open(out_file_name);

  //If opening the file fails, re-prompt the user for output file name
  while(out_s.fail()){

    out_s.clear();
    std::cout << "Output file opening failed, please retry output file name." << std::endl;
    std::cin >> out_file_name;
    out_s.open(out_file_name.c_str());
}

  out_s << "Incorrectly spelled words from the file: " << in_file_name << endl << endl;

  /**Compare each word from input to each word in dictionary. If the word is
  **found in dictionary, return that the word is spelled correctly. If the word
  **is spelled incorrectly, the word is output to the output file named by the user.
  **/
  for(int i = 0; i < input.size(); i++){

    if(avl_dict.FindEntry(input.at(i)) == true){

      std::cout << input.at(i) << " is spelled correctly." << endl;
    }else{

      out_s << input.at(i) << "\t\tat line " << i + 1 << endl;
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

  /**Convert all characters from the input file to lower-case and
  **push all lower-case words into a vector. This vector will be returned.
  **/
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

  //If input file opening fails, re-prompt user for input file name
  while(in_s.fail()){

    in_s.clear();
    std::cout << "Dictionary file opening failed, please check file name." << std::endl;
    std::exit(1);
  }

  //Add entries into dictionary object by line.
  //Each line is assumed to be a word, and each word is a node in the AVL tree.
  //Do not add duplicate entries into the dictionary
  while(std::getline(in_s, str)){

    if(dictionary.FindEntry(str) == true){

    }else{

      dictionary.AddEntry(str);
    }
  }

  in_s.close();

  return dictionary;
}
