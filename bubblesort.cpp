#include <iostream>
#include <vector>
#include <chrono>

void bubblesort(std::vector<int>& data){
bool not_sorted = true;
    while (not_sorted) {
        not_sorted = false;

for (int i = 1; i < data.size(); ++i)
    if(data[i] < data[i - 1]){
        int key = data[i];
        data[i] = data[i - 1];
        data[i - 1] = key;
        not_sorted = true;
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