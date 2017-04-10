#include <iostream>
#include <vector>
#include <ctime>
#include <iterator>
#include <fstream>
#include "LCS.h"

using namespace std;

int main()
{
    vector<char> X,Y;
    int n_x,n_y;
    double w;
    clock_t t;

    // loading data
    if(1){
        ifstream fin("data.txt");
        fin >> w;
        cout << w << endl;
        fin >> n_x;
        for(int i=0;i<n_x;i++){
            char tmp;
            fin >> tmp;
            X.push_back(tmp);
        }
        fin >> n_y;
        for(int i=0;i<n_y;i++){
            char tmp;
            fin >> tmp;
            Y.push_back(tmp);
        }
    }
    else{
        w = 0;
        X={'B','A','B','C','A','D','B','A','C','D'};
        Y={'B','A','C','A','D','C','D','A','A','B'};
    }


    cout << "din" << endl;
    LCS_din first(w,X,Y);
    t = clock();
    first.lcsing_din();
    cout << "working time = " << clock() - t << endl;
    first.print();
    cout << endl;


    cout << "mem" << endl;
    LCS_mem second(w,X,Y);
    t = clock();
    second.lcsing_mem();
    cout << "working time = " << clock() - t << endl;
    second.print();
    cout << endl;


    cout << "rec" << endl;
    LCS_rec third(w,X,Y);
    t = clock();
    double result = third.lcsing_rec();
    cout << "working time = " << clock() - t << endl;
    cout << result << endl;
    cout << endl;

    return 0;
}
