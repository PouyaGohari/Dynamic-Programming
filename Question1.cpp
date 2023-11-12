#include <iostream>
#include <vector>

using namespace std;

struct get_inputs{
    int number;
    vector<int> records;
}typedef inputs;

inputs getting_input(){
    inputs result;
    cin >> result.number;
    for(int i = 0; i < result.number; i++){
        int temp;
        cin >> temp;
        result.records.push_back(temp);
    }
    return result;
}

int main(){
    inputs my_inputs = getting_input();
    return 0;
}