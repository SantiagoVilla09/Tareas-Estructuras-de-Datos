#include <iostream>
#include <vector>
#include <chrono>

void selectionsort(std::vector<int>& data){ // Selectionsort(Data: values[])
    for(int i=0; i<data.size(); ++i){       //     For i = 0 To <length of values> - 1
        int value = data.at(i);             //Find the item that belongs in position i.
        int min = i;                        //         <Find the smallest item with index j >= i.>
        for(int j=i; j<data.size(); ++j){
            if(data.at(j) < data.at(min)){
                min = j;
            }
        }
        data.at(i) = data.at(min);          //         <Swap values[i] and values[j].>
        data.at(min) = value;
    }                                       //     Next i
}                                           // End Selectionsort

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
    selectionsort(example);
    toString(example);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << "Total time: " << total_time << "\n";

}










