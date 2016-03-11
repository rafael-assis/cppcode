//
//  main.cpp
//  MergeSort
//
//  Created by Rafael Amaral de Assis on 2/23/16.
//  Copyright © 2016 Rafael Amaral de Assis. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> vector;
    
    vector.push_back(5);
    
    for(auto &&current : vector)
    {
        cout << "#" << current << endl;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
