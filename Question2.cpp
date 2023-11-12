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

int max_bridges(fish_street inputs){
    vector<vector<int>> dp(inputs.number+1, vector<int>(inputs.number+1, 0));
    for(int i = 1; i <= inputs.number; i++){
        for(int j = 1; j <= inputs.number; j++){
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            for(int x = 1; x <= i; x++){
                if(abs(inputs.streets[j-1] - inputs.fishes[x-1]) <= 4){
                    dp[i][j] = max(dp[i][j], dp[x-1][j-1]+1);
                }
            }
        }
    }
    return dp[inputs.number][inputs.number];
}

int main(){
    fish_street inputs = getting_input();
    cout << max_bridges(inputs) << endl;
    return 0;
}