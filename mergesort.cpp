#include <iostream>
#include <vector>
#include <chrono>

void merge(std::vector<int>& values, std::vector<int>& scratch, int start, int midpoint, int end){
    int left_index
    int left_index = start;
    int right_index = midpoint + 1;
    int scratch_index = start;

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
    std::vector<int> example = fill_random(30,99);
    toString(example);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\nSelectionsort: \n";
    bubblesort(example);
    toString(example);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << "Total time: " << total_time << "\n";

}