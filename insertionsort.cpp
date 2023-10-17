//  Insertionsort(Data: values[])
//     For i = 0 To <length of values> - 1
//         // Move item i into position in the sorted part of the array.
//         < Find the first index j where j < i and values[j] > values[i].>
//         <Move the item into position j.>
//   Next i
// End Insertionsort

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

int main(){
    std::vector<int> ejemplo = fill_random(1000,99);
    for(int i=0; i < ejemplo.size(); ++i){
        std::cout << ejemplo.at(i) << " ";
    }
    std::cout <<"\n";

}