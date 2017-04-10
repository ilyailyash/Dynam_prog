#include <iostream>
#include <vector>
#include <iterator>
#include "LCS.h"

using namespace std;
 // dynamics
LCS_din::LCS_din(LCS_din &par):L1(par.L1),L2(par.L2),score(par.score),w(par.w),way(par.way),X(par.X), Y(par.Y) {};
LCS_din::LCS_din(double _w, vector<char> _X,vector<char> _Y):w(_w),X(_X),Y(_Y){
    for(int i=0;i<=X.size();i++){
        vector<int> tmp;
        L1.push_back(tmp);
        L1[i].resize(Y.size()+1,-2);

    }
    for(int i=0;i<=X.size();i++){
        vector<int> tmp;
        L2.push_back(tmp);
        L2[i].resize(Y.size()+1,-2);
    }
    for(int i=0;i<=X.size();i++){
        vector<double> tmp;
        score.push_back(tmp);
        score[i].resize(Y.size()+1,-1);

    }
    for(int i=0;i<=X.size();i++){
        vector<char> tmp;
        way.push_back(tmp);
        way[i].resize(Y.size()+1,'&');
    }
};
void LCS_din::lcsing_din(){
    int i=0,j=0;
    for(i=0;i<score.size();i++){
        score[i][0] = 0;
    }
    for(i=0;i<score[0].size();i++){
        score[0][i] = 0;
    }
    for(i=1;i<score.size();i++){
        for(j=1;j<score[i].size();j++){
            int l1=0,l2=0;
            double s,max;
            char res;

            if(X[i-1] == Y[j-1]){
                if(i != L1[i-1][j-1]+1){
                    l1 = 1;
                }
                if(j != L2[i-1][j-1]+1){
                    l2 = 1;
                }

                s = score[i-1][j-1] + 1 + w * (l1 - l2);

                if (s >= score[i][j-1]){
                    max = s;
                    res = '1';
                    L1[i][j] = i;
                    L2[i][j] = j;
                }
                else{
                    max = score[i][j-1];
                    res = '-';
                    L1[i][j] = L1[i][j-1];
                    L2[i][j] = L2[i][j-1];
                }
                if (max < score[i-1][j]){
                    max = score[i-1][j];
                    res = '|';
                    L1[i][j] = L1[i-1][j];
                    L2[i][j] = L2[i-1][j];
                }
                score[i][j] = max;
                way[i][j] = res;
            }
            else{
                if (score[i][j-1] < score[i-1][j]){
                    score[i][j] = score[i-1][j];
                    way[i][j] = '|';
                    L1[i][j] = L1[i-1][j];
                    L2[i][j] = L2[i-1][j];
                }
                else{
                    score[i][j] = score[i][j-1];
                    way[i][j] = '-';
                    L1[i][j] = L1[i][j-1];
                    L2[i][j] = L2[i][j-1];
                }
            }
        }
    }
};
void LCS_din::print(){

    for(int i=1;i<score.size();i++){
        for(int j=1;j<score[i].size();j++){
            cout << score[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;


    for(int i=1;i<way.size();i++){
        for(int j=1;j<way[i].size();j++){
            cout << way[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    vector<char> result;
    int i=way.size()-1, j=way[0].size()-1;
    while(i>0){
        while(j>0){
            if( way[i][j] == '1'){
                --i;
                --j;
                result.push_back(X[i]);
            }
            else if( way[i][j] == '-'){
                --j;
            }
            else{
                --i;
            }
        }
    }
    copy(result.rbegin(),result.rend(),ostream_iterator<char>(cout," "));

}


// memorise
LCS_mem::LCS_mem(LCS_mem &par):L1(par.L1),L2(par.L2),score(par.score),w(par.w),way(par.way),X(par.X), Y(par.Y) {};
LCS_mem::LCS_mem(double _w, vector<char> _X,vector<char> _Y):w(_w),X(_X),Y(_Y){
    for(int i=0;i<=X.size();i++){
        vector<int> tmp;
        L1.push_back(tmp);
        L1[i].resize(Y.size()+1,-2);

    }
    for(int i=0;i<=X.size();i++){
        vector<int> tmp;
        L2.push_back(tmp);
        L2[i].resize(Y.size()+1,-2);
    }
    for(int i=0;i<=X.size();i++){
        vector<double> tmp;
        score.push_back(tmp);
        score[i].resize(Y.size()+1,-1);
    }
    for(int i=0;i<X.size();i++){
        vector<char> tmp;
        way.push_back(tmp);
        way[i].resize(Y.size(),'&');
    }
};

double LCS_mem::lcsing_mem(int i,int j){

    if( score[i][j] >= 0){
        return score[i][j];

    }


    if ( (i < 1) || (j < 1) ){

       return 0;
    }

    int l1=0,l2=0;
    double s,sx,sy,max;

    sx = lcsing_mem(i-1,j);
    sy = lcsing_mem(i,j-1);

    if(X[i-1] == Y[j-1]){
        if(i != L1[i-1][j-1]+1){
            l1 = 1;
        }
        if(j != L2[i-1][j-1]+1){
            l2 = 1;
        }

        s = lcsing_mem(i-1,j-1) + 1 + w * (l1 - l2);

        if (s >= sy){
            max = s;
            L1[i][j] = i;
            L2[i][j] = j;
        }
        else{
            max = sy;
            L1[i][j] = L1[i][j-1];
            L2[i][j] = L2[i][j-1];
        }
        if (max < sx){
            max = sx;
            L1[i][j] = L1[i-1][j];
            L2[i][j] = L2[i-1][j];
        }
        score[i][j] = max;
        return score[i][j];
    }
    else{
        if (sy < sx){
            score[i][j] = sx;
            L1[i][j] = L1[i-1][j];
            L2[i][j] = L2[i-1][j];
            return score[i][j];
        }
        else{
            score[i][j] = sy;
            L1[i][j] = L1[i][j-1];
            L2[i][j] = L2[i][j-1];
            return score[i][j];
        }
    }
};
double LCS_mem::lcsing_mem(){
    return lcsing_mem(X.size(),Y.size() );
}
void LCS_mem::print(){

    for(int i=1;i<score.size();i++){
        for(int j=1;j<score[i].size();j++){
            cout << score[i][j] << ' ';
        }
        cout << endl;
    }

}



// recursion

LCS_rec::LCS_rec(LCS_rec &par):L1(par.L1),L2(par.L2),w(par.w),X(par.X), Y(par.Y) {};
LCS_rec::LCS_rec(double _w, vector<char> _X,vector<char> _Y):w(_w),X(_X),Y(_Y){
    for(int i=0;i<=X.size();i++){
        vector<int> tmp;
        L1.push_back(tmp);
        L1[i].resize(Y.size()+1,-2);

    }
    for(int i=0;i<=X.size();i++){
        vector<int> tmp;
        L2.push_back(tmp);
        L2[i].resize(Y.size()+1,-2);
    }
//    for(int i=0;i<=X.size();i++){
//        vector<double> tmp;
//        score.push_back(tmp);
//        score[i].resize(Y.size()+1,-1);
//    }
//    for(int i=0;i<X.size();i++){
//        vector<char> tmp;
//        way.push_back(tmp);
//        way[i].resize(Y.size(),'&');
//    }
};

double LCS_rec::lcsing_rec(int i,int j){

//    if( score[i][j] >= 0){
//        return score[i][j];
//
//    }


    if ( (i < 1) || (j < 1) ){

       return 0;
    }

    int l1=0,l2=0;
    double s,sx,sy,max;

    sx = lcsing_rec(i-1,j);
    sy = lcsing_rec(i,j-1);

    if(X[i-1] == Y[j-1]){
        if(i != L1[i-1][j-1]+1){
            l1 = 1;
        }
        if(j != L2[i-1][j-1]+1){
            l2 = 1;
        }

        s = lcsing_rec(i-1,j-1) + 1 + w * (l1 - l2);

        if (s >= sy){
            max = s;
            L1[i][j] = i;
            L2[i][j] = j;
        }
        else{
            max = sy;
            L1[i][j] = L1[i][j-1];
            L2[i][j] = L2[i][j-1];
        }
        if (max < sx){
            max = sx;
            L1[i][j] = L1[i-1][j];
            L2[i][j] = L2[i-1][j];
        }
//        score[i][j] = max;
        return max;
    }
    else{
        if (sy < sx){
//            score[i][j] = sx;
            L1[i][j] = L1[i-1][j];
            L2[i][j] = L2[i-1][j];
            return sx;
        }
        else{
//            score[i][j] = sy;
            L1[i][j] = L1[i][j-1];
            L2[i][j] = L2[i][j-1];
            return sy;
        }
    }
};
double LCS_rec::lcsing_rec(){
    return lcsing_rec(X.size(),Y.size() );
}
