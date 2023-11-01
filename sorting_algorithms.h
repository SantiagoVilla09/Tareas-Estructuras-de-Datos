#pragma once

#include <vector>


//  Complexity: O(N^2)
void insertionsort(std::vector<int>& data){
    for(int i = 1; i < data.size(); ++i){
//      Move item i into position in the sorted part of the array.
        int key = data[i];
        int j = i - 1;
//      < Find the first index j where j < i and values[j] > values[i].>
        while (j >= 0 && data[j] > key) {
            data[j + 1] = data[j];
            j = j - 1;
        }
//      <Move the item into position j.>
        data[j + 1] = key;
    }
}



// Complexity: O(N^2)
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

void bubblesort(std::vector<int>& data){
    // Repeat until the array is sorted.
    bool not_sorted = true;
    while (not_sorted) {
        // Assume we won't find a pair to swap.
        not_sorted = false;
        // Search the array for adjacent items that are out of order.
        for (int i = 1; i < data.size(); ++i){
            // See if items i and i - 1 are out of order.
            if(data[i] < data[i - 1]){
                // Swap them.
                int key = data[i];
                data[i] = data[i - 1];
                data[i - 1] = key;
                // The array isn't sorted after all.
                not_sorted = true;
            }
        }
    }
}


//Complexity: O(N log N) to O(N^2)
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


//Complexity: O(N log N)
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


// Complexity: O(N)
void countingsort(std::vector<int>& data){

    int max = data.at(0);

    for(int i=0; i<data.size();++i){
        if(data.at(i) > max){
            max = data.at(i);
        }
    }
    ++max;
    // Make an array to hold the counts.
    std::vector<int> counts(max);

    // Count the items with each value.
    for(int i=0; i<data.size(); ++i){
        counts.at(data.at(i)) = counts.at(data.at(i)) + 1;
    }

    // Copy the values back into the array.
    int index = 0;
    for(int i=0; i<max;++i){
        for(int j=0; j<counts.at(i); ++j){
            data.at(index) = i;
            ++index;
        }
    }
}
