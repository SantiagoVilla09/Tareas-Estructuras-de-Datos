#include <iostream>
#include <vector>
#include <chrono>



// Countingsort(Integer: values[], Integer: max_value)
// Complexity: O(N)
void countingsort(std::vector<int>& data){

    int max = data.at(0);

    for(int i=0; i<data.size();++i){
        if(data.at(i) > max){
            max = data.at(i);
        }
    }
    ++max;
    // Make an array to hold the counts.
    std::vector<int> counts(max);

    // Count the items with each value.
    for(int i=0; i<data.size(); ++i){
        counts.at(data.at(i)) = counts.at(data.at(i)) + 1;
    }

    // Copy the values back into the array.
    int index = 0;
    for(int i=0; i<max;++i){
        for(int j=0; j<counts.at(i); ++j){
            data.at(index) = i;
            ++index;
        }
    }
}












std::vector<int> fill_random(int size, int max_value){

    std::vector<int> data(size);
    std::srand(0);
    for(int i=0; i < data.size(); ++i){
        data.at(i) = std::rand() % max_value;
    }

    return data;
}

void toString(std::vector<int>& data){
    for(int i=0; i < data.size(); ++i){
        std::cout << data.at(i) << " ";
    }
    std::cout <<"\n";
}

int main(){
    std::vector<int> example = fill_random(100,99);
    toString(example);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\nCountingsort: \n";
    countingsort(example);
    toString(example);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << "Total time: " << total_time << "\n";

}