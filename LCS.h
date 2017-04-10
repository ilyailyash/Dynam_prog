#ifndef LCS_H_INCLUDED
#define LCS_H_INCLUDED

using namespace std;

class LCS_din{
private:
    vector< vector<int> > L1,L2;
    vector< vector<double> > score;
    double w;
    vector< vector<char> > way;
    vector<char> X,Y;
public:
    LCS_din(LCS_din &par);
    LCS_din(double _w, vector<char> _X,vector<char> _Y);
    void lcsing_din();
    void print();
};

class LCS_mem{
private:
    vector< vector<int> > L1,L2;
    vector< vector<double> > score;
    double w;
    vector< vector<char> > way;
    vector<char> X,Y;
public:
    LCS_mem(LCS_mem &par);
    LCS_mem(double _w, vector<char> _X,vector<char> _Y);
    double lcsing_mem(int i, int j);
    double lcsing_mem();
    void print();
};

class LCS_rec{
private:
    vector< vector<int> > L1,L2;
    double w;
    vector<char> X,Y;
public:
    LCS_rec(LCS_rec &par);
    LCS_rec(double _w, vector<char> _X,vector<char> _Y);
    double lcsing_rec(int i, int j);
    double lcsing_rec();
};

#endif // LCS_H_INCLUDED
