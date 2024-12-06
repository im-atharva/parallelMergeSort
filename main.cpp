#include "./sorting/mergeSort.hpp"
#include "./sorting/parallelMergeSort.hpp"
#include<iostream>
#include <chrono>
#include<vector>

int main(int argc, char *argv[]){
    const int SIZE = 10000000;
    std::vector<int> nums(SIZE);
    std::vector<int> nums1(SIZE);

    for(int i=0; i<SIZE; i++){
        nums[i] = rand()%10000000;
        nums1[i] = nums[i];
    }
    

    MergeSort* mergesort = new MergeSort(&nums);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort->sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortDuration = end-start;
    std::cout << "Normal Merge Sort algorithm time taken: " << mergesortDuration.count()<< " seconds" << std::endl;

    delete mergesort;

    std::cout << std::endl;

    ParallelMergeSort* mergesort1 = new ParallelMergeSort(&nums1);
    start = std::chrono::high_resolution_clock::now();
    mergesort1->sort();
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> mergesortDuration1 = end-start;
    std::cout << "Parallel Merge Sort algorithm time taken: " << mergesortDuration1.count()<<" seconds" << std::endl;

    delete mergesort1;


    return 0;
}