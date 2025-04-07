#include<iostream>
#include<fstream>
#include<vector>
#include<time.h>
using namespace std;

vector<string> input_file(){
    vector<string> words;
    ifstream infile("harry_full.txt");
    string word;
    while(infile >> word){
        words.push_back(word);
    }

    // 중복 제거 => but, 정렬 시간 측정이 이 문제 목표라서, sort + unique 사용 불가

    return words;
}

void bubble_sort(vector<string> v){
    int n = v.size();

    for(int i = n; i > 0; i--){
        for(int j = i; i < n-1; i++ ){
            
        }
    }
}

void insertion_sort(vector<string> v){
    
}

void merge_sort(vector<string> v){

}

void quick_sort(vector<string> v){

}

void heap_sort(vector<string> v){

}

void stdLibaray_sort(vector<string> v){

}

int main(){
    vector<string> words = input_file();


    return 0;
}