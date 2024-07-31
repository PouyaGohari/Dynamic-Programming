#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> gift_of_index;
vector<string> my_genes;
vector<int> decoded;
vector<vector<int>> dp;
int all_mask;

struct inputs{
    int gifts_number;
    int gen_numbers;
}typedef inputs;

inputs getting_inputs(){
    inputs my_inputs; 
    cin >> my_inputs.gifts_number;
    gift_of_index.assign(my_inputs.gifts_number, vector<int>(my_inputs.gifts_number));
    for(int i = 0; i < my_inputs.gifts_number; i++){
        for(int j = 0; j < my_inputs.gifts_number; j++){
            cin >> gift_of_index[i][j];
        }
    }
    cin >> my_inputs.gen_numbers;
    my_genes.assign(my_inputs.gen_numbers, "");
    decoded.assign(my_inputs.gen_numbers, 0);
    for(int i = 0; i < my_inputs.gen_numbers; i++){
        cin >> my_genes[i];
        for(int j = 0; j < my_genes[i].size(); j++){
            int bit = my_genes[i][j] - 'G';
            decoded[i] = decoded[i] << 1;
            decoded[i] = decoded[i] | bit;
        }
    }
    return my_inputs;
}


int way_counting(int i, const inputs my_inputs) {
    dp[all_mask][my_inputs.gifts_number] = 1;
    for(int mask = all_mask; mask >= 0; mask--){
        for(int index = my_inputs.gifts_number; index > 0; index--){
            for(int j = 0; j < my_inputs.gifts_number; j++){
                if(my_genes[i][gift_of_index[index-1][j]-1] == my_genes[i][index-1]){
                    dp[mask ^ (1 << gift_of_index[index-1][j]-1)][index-1] += dp[mask][index];
                }
                if(gift_of_index[index-1][j] == index){
                    break;
                }
            }
        }
    }
    return dp[0][0];
}

int main(){
    inputs my_inputs = getting_inputs();
    all_mask = (1 << my_inputs.gifts_number) -1;
    vector<int> result(all_mask + 1, -1);
    for(int i = 0; i < my_inputs.gen_numbers; i++){
        if(result[all_mask ^ decoded[i]] != -1) {
            cout << result[all_mask ^ decoded[i]] << endl;
        }
        else{
            dp.assign(all_mask + 1, vector<int>(my_inputs.gifts_number+1, 0));
            result[decoded[i]] = way_counting(i, my_inputs);
            cout << result[decoded[i]] << endl;
        }
    }
    return 0;
}