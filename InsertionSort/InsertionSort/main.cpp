//
//  main.cpp
//  InsertionSort
//
//  Created by Rafael Amaral de Assis on 3/10/16.
//  Copyright © 2016 Rafael Amaral de Assis. All rights reserved.
//

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

void PopulateVector(unsigned int maxValue, size_t initialSize, vector<unsigned int> &vector)
{
    vector.clear();
    
    cout << "\nPopulating a vector of " << initialSize << " element(s) in the range of 0 to " << maxValue << endl;
    
    // Initialize random seed:
    srand(time(nullptr));
    
    // Adding random numbers to vector
    for (unsigned int i=0; i<initialSize; i++)
    {
        unsigned int newElement = rand() % maxValue;
        vector.push_back(newElement);
    }
}

void PrintVector(vector<unsigned int> &vector, string msg)
{
    cout << msg << endl;
    
    for (auto current = vector.begin(); current!=vector.end(); ++current)
    {
        std::cout << "#" << *current << endl;
    }
}

void InsertionSort(vector<unsigned int> &vector, bool nonIncreasing = false)
{
    cout << "\nSorting vector using Insertion Sort in non" << (nonIncreasing ? "increasing" : "-decreasing") << " order..."<< endl;
    
    if (vector.size() < 2)
        return;
    
    for (size_t i = 1; i < vector.size(); ++i)
    {
        unsigned int curValue = vector[i];
        size_t j = i;
        
        while ((j>0) &&
               (nonIncreasing ? (curValue > vector[j-1]) : (curValue < vector[j-1])))
        {
            vector[j] = vector[j-1];
            --j;
        }
        vector[j] = curValue;
    }
}

int main(int argc, const char * argv[]) {

    vector<unsigned int> intVector;
    
    // Test case 1: empty vector
    PrintVector(intVector, "Printing unsorted vector:");
    InsertionSort(intVector);
    PrintVector(intVector, "\nPrinting sorted vector:");

    
    // Test case 2: one-element vector
    PopulateVector(100, 1, intVector);
    PrintVector(intVector, "\nPrinting unsorted vector:");
    InsertionSort(intVector);
    PrintVector(intVector, "\nPrinting sorted vector:");
    
    // Test case 3: ten-element vector
    PopulateVector(100, 10, intVector);
    PrintVector(intVector, "\nPrinting unsorted vector:");
    InsertionSort(intVector);
    PrintVector(intVector, "\nPrinting sorted vector:");

    // Test case 4: nonincreasing sort vector
    PopulateVector(100, 10, intVector);
    PrintVector(intVector, "\nPrinting unsorted vector:");
    InsertionSort(intVector, true);
    PrintVector(intVector, "\nPrinting sorted vector:");

    return 0;
}
