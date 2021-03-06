//
// Created by Jeongho on 2019-11-03.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

void make_set_tree(vector<int> sets,vector<int> subsets,int n,int depth,priority_queue<string> &answer_arr);

int main(){
    vector<int> numbers;
    for(auto i : {6, 10, 2}) numbers.push_back(i);
//    for(auto i : {0,0,0,0}) numbers.push_back(i);

    string answer = "";

    // ---
    priority_queue<string> answer_arr;
    vector<int> empty_vec;

    int num_max = *max_element(numbers.begin(),numbers.end());
    if(num_max == 0)
        answer = "0";
    else{
        make_set_tree(empty_vec,numbers,0,numbers.size(),answer_arr);
        answer = answer_arr.top();
    }

    // ---

    cout<<answer;

}

void make_set_tree(vector<int> sets,vector<int> subsets,int n,int depth,priority_queue<string> &answer_arr){
    if( n == depth-1 ){
        sets.push_back(subsets[0]);
        // make string
        string answer_temp;

        for(auto i: sets){
            answer_temp+=to_string(i);
        }

        answer_arr.push(answer_temp);
    }else {
        for(auto it = subsets.begin(); it!=subsets.end(); it++){
            int index = distance(subsets.begin(),it);
            vector<int> temp = subsets;
            vector<int> temp_set = sets;
            temp_set.push_back(*it);
            temp.erase(temp.begin()+index);

            make_set_tree(temp_set,temp,n+1,depth,answer_arr);
        }
    }
}

