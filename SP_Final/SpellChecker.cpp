#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <regex>


struct word {
    std::string text;
    int line;
    int column;
};

struct s_key {
    std::string soundex;
    std::vector<std::string> s_vector;
};


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



std::string soundex(std::string word) {

    std::string soundex;

    soundex += std::tolower(word[0]);

    for(char c : word){
        switch(c){
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

int main(){

    std::vector<std::string> wordset;
    read_dictionary("words.txt", wordset);

    std::vector<word> words;
    read_words("tooinkle.txt", words);


    std::vector<s_key> dictionary;

    for(std::string w : wordset){
        std::string s = soundex(w);
        for (s_key d : dictionary){
            if(s == d.soundex){
                d.s_vector.push_back(w);
            } else{
                dictionary.push_back({s, {s}});
            }
        }
    }

    // std::string soundex_test = soundex("aabbccdd");

    std::cout << dictionary.size();





    return 0;
}