#include <iostream>
#include <vector>
#include <chrono>

void insertionsort(std::vector<int>& data){
    for(int i = 1; i < data.size(); ++i){
        int key = data[i];
        int j = i - 1;
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
        data[j + 1] = key;
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
    std::vector<int> example = fill_random(100,999);
    toString(example);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\nSelectionsort: \n";
    insertionsort(example);
    toString(example);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << "Total time: " << total_time << "\n";

}

// Bubblesort(Data: values[])
    // Repeat until the array is sorted.
    // Boolean: not_sorted = True
    // While (not_sorted)
        // Assume we won't find a pair to swap.
        // not_sorted = False

        // Search the array for adjacent items that are out of order.
        // For i = 0 To <length of values> - 1
            // See if items i and i - 1 are out of order.
            // If (values[i] < values[i - 1]) Then
            //     // Swap them.
            //     Data: temp = values[i]
            //     values[i] = values[i - 1]
            //     values[i - 1] = temp

                // The array isn't sorted after all.
//                 not_sorted = True
//             End If
//         Next i
//     End While
// End Bubblesort