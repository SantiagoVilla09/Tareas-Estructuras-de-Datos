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

std::vector<int> fill_ascending(int size, int max_value){

    std::vector<int> data(size);
    std::srand(0);
    int n;
    int ac = 0;
    std::vector<int> sub;
    while(ac<size){
        n = std::rand()%(size-ac+1);
        if(ac+n <= size){
            sub.push_back(n);
            ac = ac + n;
        }
    }

    int index = 0;
    for(int i=0; i<sub.size(); ++i){
        for(int j=0; j<sub.at(i); ++j){
            data.at(index) = i;
            ++index;
        }
    }

    return data;
}

std::vector<int> fill_descending(int size, int max_value){

    std::vector<int> data(size);
    std::srand(0);
    int n;
    int ac = 0;
    std::vector<int> sub;
    while(ac<size){
        n = std::rand()%(size-ac+1);
        if(ac+n <= size){
            sub.push_back(n);
            ac = ac + n;
        }
    }

    int index = 0;
    for(int i=0; i<sub.size(); ++i){
        for(int j=0; j<sub.at(i); ++j){
            data.at(index) = max_value-i;
            ++index;
        }
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

    int size = 1000000;
    int max = 99;

    // std::cout << "size: " << "\n";
    // std::cin >> size;
    // std::cout << "max: " << "\n";
    // std::cin >> max;
    // std::cout << "\n\n";

    std::vector<int> sample = fill_random(size,max);
    // std::vector<int> sample = fill_ascending(size, max);
    // std::vector<int> sample = fill_descending(size, max);


    // toString(sample);


    std::cout << "\nstd::sort: \n";

    std::vector copy_1 = sample;

    auto start = std::chrono::high_resolution_clock::now();
    std::sort(copy_1.begin(), copy_1.end());
    auto stop = std::chrono::high_resolution_clock::now();

    // toString(copy_1);

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";


    std::cout << "\nInsertionsort: \n";

    std::vector copy_2 = sample;

    start = std::chrono::high_resolution_clock::now();
    insertionsort(copy_2);
    stop = std::chrono::high_resolution_clock::now();

    // toString(copy_2);

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";



    std::cout << "\nSelectionsort: \n";

    std::vector copy_3 = sample;

    start = std::chrono::high_resolution_clock::now();
    selectionsort(copy_3);
    stop = std::chrono::high_resolution_clock::now();

    // toString(copy_3);

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";



    std::cout << "\nBubblesort: \n";

    std::vector copy_4 = sample;

    start = std::chrono::high_resolution_clock::now();
    bubblesort(copy_4);
    stop = std::chrono::high_resolution_clock::now();

    // toString(copy_4);

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";


    std::cout << "\nQuicksort: \n";

    std::vector copy_5 = sample;

    start = std::chrono::high_resolution_clock::now();
    quicksort(copy_5, 0, copy_5.size() - 1);
    stop = std::chrono::high_resolution_clock::now();

    // toString(copy_5);

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";



    std::cout << "\nMergesort: \n";

    std::vector copy_6 = sample;

    start = std::chrono::high_resolution_clock::now();

    std::vector<int> scratch(copy_6.size());
    mergesort(copy_6, scratch, 0, copy_6.size() - 1);
    stop = std::chrono::high_resolution_clock::now();

    // toString(copy_6);

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";



    std::cout << "\nCountingsort: \n";

    std::vector copy_7 = sample;

    start = std::chrono::high_resolution_clock::now();
    countingsort(copy_7);
    stop = std::chrono::high_resolution_clock::now();

    // toString(copy_7);

    duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";


}