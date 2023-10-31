#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>


std::vector<int> fill_random(int size, int max_value){

    std::vector<int> data(size);
    std::srand(6);
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
    std::vector<int> example = fill_random(40, 99);
    toString(example);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\nstd::sort: \n";
    std::sort(example.begin(), example.end());
    toString(example);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << "Total time: " << total_time << "\n";

    return 0;

}
