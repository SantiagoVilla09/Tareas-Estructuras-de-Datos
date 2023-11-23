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






int main(){

    std::vector<std::string> wordset;
    read_dictionary("words.txt", wordset);

    std::vector<word> words;
    read_words("tooinkle.txt", words);




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


    std::cout << dictionary.size() << "\n";


    std::string w_ex;
    std::cout << "Enter a word: " << "\n";
    std::cin >> w_ex;

    std::string s_ex = soundex(w_ex);
    std::cout << w_ex << " -> Soundex: " << s_ex << "\n Other words with same Soundex: \n";

    for(std::string i : dictionary.at(s_ex)){
        std::cout << i << " ";
    }
    std::cout <<"\n";

    return 0;
}