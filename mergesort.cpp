#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

void mergesort(std::vector<int>& data, std::vector<int>& scratch, int start, int end) {
    if (start == end) {
        return;
    }

    int midpoint = (start + end) / 2;
    mergesort(data, scratch, start, midpoint);
    mergesort(data, scratch, midpoint + 1, end);

    int left_index = start;
    int right_index = midpoint + 1;
    int scratch_index = start;

    while (left_index <= midpoint && right_index <= end) {
        if (data[left_index] <= data[right_index]) {
            scratch[scratch_index] = data[left_index];
            left_index++;
        }
        else {
            scratch[scratch_index] = data[right_index];
            right_index++;
        }
        scratch_index++;
    }

    while (left_index <= midpoint) {
        scratch[scratch_index] = data[left_index];
        left_index++;
        scratch_index++;
    }

    while (right_index <= end) {
        scratch[scratch_index] = data[right_index];
        right_index++;
        scratch_index++;
    }

    for (int i = start; i <= end; i++) {
        data[i] = scratch[i];
    }
}

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

int main() {
    std::vector<int> example = fill_random(30, 99);
    std::vector<int> scratch(example.size());
    toString(example);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\nMerge Sort: \n";
    mergesort(example, scratch, 0, example.size() - 1);
    toString(example);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Total time: " << total_time << "\n";

    return 0;
}