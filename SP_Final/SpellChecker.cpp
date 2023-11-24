/*----------------------------------------------------------
 * Project: Spell Checker
 *
 * Date: 29-Nov-2023
 * Authors:
 *           A01746396 Santiago Villazón Ponce de León
 *           A01799815 César Antonio Espinosa Madrid
 *----------------------------------------------------------*/

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <regex>
#include <algorithm>


struct word {
    std::string text;
    int line;
    int column;
};

// Returns input string in all lowercase letters.
// Complexity O(N)
std::string lowercase(std::string input_string){
    std::string output_string;
    for(char c : input_string){
        output_string += std::tolower(c);
    }
    return output_string;
}


// Creates a vector with words from input text.
// Complexity: O(N)
bool read_words(const std::string input_file_name, std::vector<word>& words)
{
    std::ifstream input_file(input_file_name);
    if (input_file.fail()) {
        return false;
    }
    std::regex reg_exp("[a-zA-Z]+");
    std::smatch match;
    std::string text;
    int line = 0;
    int column = 0;
    while (std::getline(input_file, text)) {
        ++line;
        column = 1;
        while (std::regex_search(text, match, reg_exp)) {
            column += match.position();
            words.push_back({match.str(), line, column});
            column += match.length();
            text = match.suffix().str();
        }
    }
    return true;
}

// Creates an hash table with words from dictionary.
// Complexity O(N)
bool read_dictionary(const std::string input_file_name, std::vector<std::string>& wordset)
{
    std::ifstream input_file(input_file_name);
    if (input_file.fail()) {
        return false;
    }

    std::string text;
    while (std::getline(input_file, text)) {
        wordset.push_back(text);
    }
    return true;
}


// Returns Soundex key of the argument
// Complexity: O(N)
std::string soundex(std::string word) {

    std::string soundex;

    soundex += std::tolower(word[0]);

    for(int i=1; i<word.size(); ++i){
        switch(std::tolower(word[i])){
            case 'b':
            case 'f':
            case 'p':
            case 'v': soundex += '1';
            break;
            case 'c':
            case 'g':
            case 'j':
            case 'k':
            case 'q':
            case 's':
            case 'x':
            case 'z': soundex += '2';
            break;
            case 'd':
            case 't': soundex += '3';
            break;
            case 'l': soundex += '4';
            break;
            case 'm':
            case 'n': soundex += '5';
            break;
            case 'r': soundex += '6';
            break;
            default:
            break;
        }
    }

    if(soundex.size()<7){
        int padding = 7 - soundex.size();
        for(int i=0; i<padding ;++i){
            soundex += '0';
        }
    }

    while(soundex.size()>7){
        soundex.pop_back();
    }

    return soundex;
}


// Sorting criteria for words.
// Complexity: O(1)
bool first(const word& a, const word& b){
    if(a.line != b.line){
        return a.line < b.line;
    } else {
        return a.column < b.column;
    }
}



int main(int argc, char* argv[]){
    if(argc != 2){
        std::cerr << "Please specify an input file.\n";
        std::exit(1);
    }
    std::string file_name = argv[1];

    std::vector<word> words;
    read_words(file_name, words);


    std::vector<std::string> wordset;
    read_dictionary("words.txt", wordset);

    // Create dictionary, each key is a unique soundex and the value is a vector of the words with the same soundex.
    std::unordered_map<std::string, std::vector<std::string>> dictionary;
    std::string s;
    for(std::string w : wordset){
        s = soundex(w);
        dictionary.insert({s,{}});
    }

    // Add words to the dictionary.
    for (std::string w : wordset){
        s = soundex(w);
        dictionary.at(s).push_back(w);
    }

    // Creates a hash table with words not found in dictionary (avoid duplicates).
    std::unordered_map<std::string, word> misspelled;
    bool found;
    for(word w: words){
        found = false;
        if(dictionary.find(soundex(w.text)) != dictionary.end()){
            for(std::string w1: dictionary.at(soundex(w.text))){
                if(lowercase(w.text) == w1){
                    found = true;
                }
            }
        }
        if(not found){
            misspelled.insert({lowercase(w.text),w});
        }
    }

    // Creates and sorts a vector with misspelled words
    std::vector<word> un_words;
    for(auto ms : misspelled){
        un_words.push_back(ms.second);
    }
    std::sort(un_words.begin(), un_words.end(), first);


    // Prints misspelled words and suggestions based on soundex, if any.
    word unrecognized;
    for(word w: un_words){

        std::cout << "Unrecognized word: \"" << w.text
                  << "\". First found at line " << w.line
                  << ", column " << w.column << ".\n";

        if(dictionary.find(soundex(w.text)) == dictionary.end()){
            std::cout << "No suggestions \n\n";
        } else {
            std::cout << "Suggestions: ";
            std::cout << dictionary.at(soundex(w.text)).at(0);
            for(int j=1; j < dictionary.at(soundex(w.text)).size(); ++j){
                std::cout <<", "<< dictionary.at(soundex(w.text)).at(j);
            }
            std::cout << "\n\n";
        }
    }


    return 0;
}