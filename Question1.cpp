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


void min_edit_distance(inputs my_inputs){
    vector<int> res(my_inputs.number, my_inputs.number+1);
    vector<vector<vector<int>>> dp(my_inputs.number, vector<vector<int>>(my_inputs.number + 1,
     vector<int>(my_inputs.number, my_inputs.number+1)));

    dp[0][1][0] = (my_inputs.records[0] != 0);
    for(int i = 1; i < my_inputs.number; i++){
        for(int j = 1; j < my_inputs.number+1; j++){
            for(int x = 0; x < my_inputs.number; x++){
                if(x == 0){
                    for(int k =0; k < my_inputs.number; k++){
                        dp[i][j][x] = min(dp[i][j][x], dp[i-1][j-1][k] + (my_inputs.records[i] != 0));
                    }
                }
                else{
                    dp[i][j][x] = min(my_inputs.number+1, dp[i-1][j][x-1] + (my_inputs.records[i] != x));
                }
            }
            if(i == my_inputs.number-1 && j > 0){
                for(int x = 0; x < my_inputs.number; x++){
                    res[j-1] = min(res[j-1], dp[i][j][x]);
                }
            }
        }
    }
    for(auto ans : res){
        cout << ans << endl;
    }
}

int main(){
    inputs my_inputs = getting_input();
    min_edit_distance(my_inputs);
    return 0;
}