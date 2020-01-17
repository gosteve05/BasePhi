//Recent change: All member functions are const. Removed getData() and getNegative().
#include <iostream>
using namespace std;
class BigInt
{
public:
	BigInt();
	BigInt(int x);
	explicit BigInt(string x); //cannot be called implicitly!
	BigInt(const BigInt& arg);

	string getData(){return data;}
	BigInt operator=(const BigInt& arg); //Should be able to build one of these by default, but I ran into an issue
	
	BigInt operator+(const BigInt& right) const;
	BigInt operator-(const BigInt& right) const;
	
	BigInt operator*(const BigInt& right) const;
	BigInt operator&&(const BigInt& right) const;
	BigInt operator/(const BigInt& right) const;
	BigInt operator%(const BigInt& right) const;
	bool operator==(const BigInt& right) const;
	bool operator<(const BigInt& right) const;
	bool operator>(const BigInt& right) const;

	friend BigInt multHelper(BigInt a, BigInt b);
	friend ostream& operator<<(ostream& out, const BigInt& right);
	friend string stringAdder(const BigInt& left, const BigInt& right);
	friend string stringSubtractor(const BigInt& left, const BigInt& right);
	friend int dataComparison(const BigInt& left, const BigInt& right);
	friend BigInt multiplier(BigInt left, BigInt right);
private:
	string data;
	bool isNegative;
};