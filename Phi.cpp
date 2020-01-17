#include<string>
#include<iostream>
#include<cmath>
#include<vector>
#include "BigInt.h"
using namespace std;

const int DIM = 2;


class Matrix
{
    private:
        BigInt entry[DIM][DIM];
    public:
        Matrix();
        Matrix operator*(Matrix& right);
        Matrix operator*(int right);
        Matrix operator+(Matrix& right);
        friend BigInt fibSlowMatrix(int x);
        friend BigInt fibFastMatrix(int x);
};
class PhiNum
{
    private:
        vector<int> data;
        int cheat;
    public:
        PhiNum();
        PhiNum(int x);
        PhiNum operator+(PhiNum& right);
        PhiNum operator*(PhiNum& right);
        vector<int> getData(){return data;}
        int getCheat(){return cheat;}
        BigInt toBigInt();
};
BigInt fibFastMatrix(int x); //PhiNum needs to know this exists

PhiNum::PhiNum()
{
    cheat = 0;
}
PhiNum::PhiNum(int x)
{
    cout << "JUST ENTERED INTEGER CONSTRUCTOR";
    cheat = x;
    int i;
    for(i = 0 ; fibFastMatrix(i) < BigInt(x) || fibFastMatrix(i) == BigInt(x) ; i++){}
    int maxBit = i;
    for(int j = 0 ; j < maxBit ; j++)
    {
        data.push_back(0);
    }
    while(x != 0)
    {
        for(int i = maxBit ; fibFastMatrix(i) > BigInt(x) ; i--){}
        data[i] = 1;
        x = stoi((BigInt(x) - fibFastMatrix(i)).getData());
        cout << "POTATO" << endl;
        /*{
            data[i] = 1; //stores it forwards.
            cout << "x before is: " << x << endl;
            x = stoi( (BigInt(x)-fibFastMatrix(i)).getData()); //string to integer
            cout << "x after is: " << x << endl;
        }*/
    }
    if(data[0] = 1)
    {
        cout << "A horrible error has occurred!" << endl;
    }
}

PhiNum PhiNum::operator+(PhiNum& right)
{
    PhiNum ret = 0;
    ret.cheat = cheat + right.cheat;
    //Whenever two numbers have the same digit, 2*F(n)=F(n)+F(n)=F(n)+F(n-1)+F(n-2)
    bool sizeCheck = data.size() > right.data.size();
    PhiNum longer = sizeCheck ? *this : right;
    PhiNum shorter = sizeCheck ? right : *this;
    int maxSize = longer.data.size();
    int minSize = shorter.data.size();
    

    return ret;
}
PhiNum PhiNum::operator*(PhiNum& right)
{
    PhiNum ret = 0;
    ret.cheat = cheat * right.cheat;




    return ret;
}

BigInt PhiNum::toBigInt()
{
    BigInt ret;
    for(int i = 0 ; i <= data.size() ; i++)
    {
        if(data[i])
        {
            ret = ret + fibFastMatrix(i);
        }
    }
    return ret;
}


Matrix::Matrix()
{
    entry[0][0] = 1;
    entry[0][1] = 1;
    entry[1][0] = 1;
    entry[1][1] = 0;
}
Matrix Matrix::operator*(Matrix& right) //slow matrix multiplication. works for a 2x2 only!
{
    Matrix ret;
    ret.entry[0][0] = entry[0][0]*right.entry[0][0] + entry[0][1]*right.entry[1][0];
    ret.entry[0][1] = entry[0][0] * right.entry[0][1] + entry[0][1] * right.entry[1][1];
    ret.entry[1][0] = entry[1][0] * right.entry[0][0] + entry[1][1]*right.entry[1][0];
    ret.entry[1][1] = entry[1][0] * right.entry[0][1] + entry[1][1]*right.entry[1][1];
    return ret;
}
Matrix Matrix::operator*(int right)
{
    Matrix ret;
    for(int i = 0 ; i < DIM ; i++)
    {
        for(int j = 0 ; j < DIM ; j++)
        {
            ret.entry[i][j] = BigInt(right)*entry[i][j];
        }
    }
    return ret;
}
Matrix Matrix::operator+(Matrix& right) //works for any size matrix
{
    Matrix ret;
    for(int i = 0 ; i < DIM ; i++)
        for(int j = 0 ; j < DIM ; j++)
        {
            ret.entry[i][j] = entry[i][j] + right.entry[i][j];
        }
    return ret;
}

const double PHI = (1+sqrt(5.f))/2;//1.618033988;

BigInt fibRecursive(int n) //slows to a crawl at 43
{
	if(n < 0)
        exit(1);
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibRecursive(n-1)+fibRecursive(n-2);
}
int fibBinet(int n) //gives wrong numbers after 33
{
	if(n < 0)
		exit(1);
	return sqrt(5.f)*(pow(PHI,n)-pow(-PHI,-n)) /5.f;
}

BigInt fibIter(int n) //Relatively fast
{
    n++;
    BigInt first = 1;
    BigInt second = 1;
    for(int i = 1 ; i < n/2 ; i++)
    {
        first = first + second;
        second = first + second;
    }
    return n%2 ? second : first;
}

BigInt fibSlowMatrix(int n) //Slows down at around 180
{
	Matrix m;
    Matrix base;
    for(int i = 0 ; i < n ; i++)
    {
        m = m * base;
    }
    return m.entry[1][0];
}
BigInt fibFastMatrix(int n) //Slows down at around 600. Takes 34 seconds to compute just F_8192.
{
    cout << "Called with n is: " << n << endl;
    Matrix ret;
    ret.entry[1][0] = 0;
    ret.entry[0][1] = 0;
    ret.entry[1][1] = 1;
    Matrix base;
    while(n)
    {
        //cout << "n is: " << n << endl;
        if(n%2) //should only be 1 or 0
        {
            ret = ret * base;
        }
        n/=2;
        base = base * base;
    }
    return ret.entry[1][0];
}

int main()
{
    PhiNum x(45);
}