#include <iostream>
#include <vector>
#include <chrono>

// Selectionsort(Data: values[])
void selectionsort(std::vector<int>& data){

    for(int i=0; i<data.size(); ++i){
        //Find the item that belongs in position i.
        int value = data.at(i);
        //<Find the smallest item with index j >= i.>
        int min = i;
        for(int j=i; j<data.size(); ++j){
            if(data.at(j) < data.at(min)){
                min = j;
            }
        }

        //<Swap values[i] and values[j].>
        data.at(i) = data.at(min);
        data.at(min) = value;
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
    std::vector<int> example = fill_random(30,999);
    toString(example);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\nSelectionsort: \n";
    selectionsort(example);
    toString(example);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << "Total time: " << total_time << "\n";

}










