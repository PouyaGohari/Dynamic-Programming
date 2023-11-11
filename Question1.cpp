#include <iostream>
#include <vector>

using namespace std;

vector<int> getting_input(){
    int number;
    cin >> number;
    vector<int> result(number);
    for(int i = 0; i < number; i++){
        cin >> result[i];
    }
    return result;
}

int main(){
    vector<int> inputs = getting_input();
    return 0;
}