#include <iostream>
#include <vector>

using namespace std;

struct inputs{
    int gifts_number;
    vector<vector<int>> desired_gifts;
    int gen_numbers;
    vector<string> genes;
}typedef inputs;

inputs getting_inputs(){
    inputs my_inputs;
    cin >> my_inputs.gifts_number;
    vector<vector<int>> gifts(my_inputs.gifts_number, vector<int>(my_inputs.gifts_number));
    for(int i = 0; i < my_inputs.gifts_number; i++){
        for(int j = 0; j < my_inputs.gifts_number; j++){
            cin >> gifts[i][j];
        }
    }
    cin >> my_inputs.gen_numbers;
    vector<string> genes(my_inputs.gen_numbers);
    for(int i = 0; i < genes.size(); i++){
        cin >> genes[i];
    }
    my_inputs.desired_gifts = gifts;
    my_inputs.genes = genes;
    return my_inputs;
}

int main(){
    inputs my_inputs = getting_inputs();
    return 0;
}