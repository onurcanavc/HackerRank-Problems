#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


int diagonalDifference(vector<vector<int>> arr) {
    int sum1 = 0, sum2 = 0;
    int j=arr.size()-1;
    for (int i = 0; i < arr.size(); i++) {
        sum1 += arr[i][i];
        sum2 += arr[i][j];
        j--;
    }
    int result = sum2-sum1;
    if(result < 0){
        result = result*-1;
    }
    return result;
}



int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Run the code with the following command: ./diagonal_difference [input_file] [output_file]" << endl;
        return 1;
    }
    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;
    ifstream input(argv[1]);
    ofstream output(argv[2]);


    int n;
    input >> n;
    input.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            input >> arr[i][j];

        }

        input.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);
    output << result;
    cout << result;

    return 0;
}
