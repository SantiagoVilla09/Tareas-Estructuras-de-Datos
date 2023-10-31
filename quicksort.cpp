#include <iostream>
#include <vector>
#include <chrono>

// Quicksort(Data: values[], Integer: start, Integer: end)
void quicksort(std::vector<int>& data, int start,int end){

    if(start>=end) return;
//     <Pick a dividing item from the array. Call it divider.>
    int divider = data.at(start);

    int blank = start;
    bool backwards = true;
    bool again = true;
    int i;

//     <Move items < divider to the front of the array.
//     Move items >= divider to the end of the array.
//     Method used: In Place
    while(again){
        again = not again;
        if (backwards){
            i = end;
            while(i>blank){
                if(data.at(i)<divider){
                    data.at(blank) = data.at(i);
                    blank = i;
                    again = true;
                }
                else{
                    --i;
                }
            }
            backwards = not backwards;
        }

        else{
            i = start;
            while(i<blank){
                if(data.at(i)>divider){
                    data.at(blank) = data.at(i);
                    blank = i;
                    again = true;
                }
                else{
                    ++i;
                }
            }
            backwards = not backwards;
        }
    }
    data.at(blank) = divider;

//     Let middle be the index between the pieces where divider is put.>
    int middle = blank;

// Recursively sort the two halves of the array.
//     Quicksort(values, start, middle - 1)
    quicksort(data, start, middle - 1);
//     Quicksort(values, middle + 1, end)
    quicksort(data, middle + 1, end);

// End Quicksort
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

int main(){
    std::vector<int> example = fill_random(100, 99);
    int end = static_cast<int>(example.size() - 1);
    toString(example);

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "\nQuicksort: \n";
    quicksort(example, 0, end);
    toString(example);

    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    double total_time = duration.count() / 1'000'000.0;
    std::cout << "Total time: " << total_time << "\n";

    return 0;

}





