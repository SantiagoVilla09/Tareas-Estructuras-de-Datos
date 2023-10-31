#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include "sorting_algorithms.h"


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

    std::vector<int> sample = fill_random(30,99);

    std::cout << "\nInsertionsort: \n";

    std::vector copy_1 = sample;

    auto start = std::chrono::high_resolution_clock::now();
    insertionsort(copy_1);
    auto stop = std::chrono::high_resolution_clock::now();

    toString(copy_1);

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";



    std::cout << "\nSelectionsort: \n";

    std::vector copy_2 = sample;

    start = std::chrono::high_resolution_clock::now();
    selectionsort(copy_2);
    stop = std::chrono::high_resolution_clock::now();

    toString(copy_2);

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";



    std::cout << "\nBubblesort: \n";

    std::vector copy_3 = sample;

    start = std::chrono::high_resolution_clock::now();
    bubblesort(copy_3);
    stop = std::chrono::high_resolution_clock::now();

    toString(copy_3);

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";


    std::cout << "\nQuicksort: \n";

    std::vector copy_4 = sample;

    start = std::chrono::high_resolution_clock::now();
    int end = static_cast<int>(copy_4.size() - 1);
    quicksort(copy_4, 0, end);
    stop = std::chrono::high_resolution_clock::now();

    toString(copy_4);

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";


}