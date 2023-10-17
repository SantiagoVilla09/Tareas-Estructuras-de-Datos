#include <iostream>
#include <vector>

std::vector<int> fill_random(int size, int max_value){

    std::vector<int> data(size);
    std::srand(0);
    for(int i=0; i < data.size(); ++i){
        data.at(i) = std::rand() % max_value;
    }

    return data;
}

//  Insertionsort(Data: values[])
//     For i = 0 To <length of values> - 1
//         // Move item i into position in the sorted part of the array.
//         < Find the first index j where j < i and values[j] > values[i].>
//         <Move the item into position j.>
//   Next i
// End Insertionsort

void Insertionsort(std::vector<int>& data){
    for(i = 0; i < data.size - 1; ++i){
        int min_index = i;
        for(j = i + 1,){

        }

    }
}

int main(){
    std::vector<int> ejemplo = fill_random(100,99);
    for(int i=0; i < ejemplo.size(); ++i){
        std::cout << ejemplo.at(i) << " ";
    }
    std::cout <<"\n";

}