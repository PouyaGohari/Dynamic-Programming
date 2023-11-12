#include <iostream>
#include <vector>

using namespace std;

struct fish_street{
    int number;
    vector<int> fishes;
    vector<int> streets;
}typedef fish_street;

fish_street getting_input(){
    int number;
    cin >> number;
    fish_street my_inputs;
    my_inputs.number = number;  
    for(int i = 0; i < number; i++){
        int temp;
        cin >> temp;
        my_inputs.fishes.push_back(temp);
    }
    for(int i = 0; i < number; i++){
        int temp;
        cin >> temp;
        my_inputs.streets.push_back(temp);
    }
    return my_inputs;
}

int main(){
    fish_street inputs = getting_input();
    return 0;
}