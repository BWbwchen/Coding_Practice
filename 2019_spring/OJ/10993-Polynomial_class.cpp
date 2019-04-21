#define DEBUG
#define MAXN 101
#include <bits/stdc++.h>

using namespace std;


class Polynomial {
private:
    int coefficients[101]; // integer coefficients
    int greatestPower; // integer greatestPower
public:
    Polynomial();
    Polynomial(const int , const int [51]);
    Polynomial add( const Polynomial) const; // add function
    Polynomial subtract( const Polynomial ) const; // subtract function
    Polynomial multiplication( const Polynomial ) const; // multiplication function
    void output() const;
};


int main (int argc, char **argv)
{
    #ifdef DEBUG
    freopen ("text.in", "r", stdin);
    #endif

    int greatestPower1, greatestPower2;
    int coefficient1[51], coefficient2[51];
    Polynomial ans;

    cin>>greatestPower1;
    for(int i = greatestPower1 ; i >= 0; i--)
    {
        cin>>coefficient1[i];
    }
    cin>>greatestPower2;
    for(int i = greatestPower2 ; i >= 0 ; i--)
    {
        cin>>coefficient2[i];
    }
    Polynomial a(greatestPower1, coefficient1),
               b(greatestPower2, coefficient2) ;

    ans = a.add( b );
    ans.output();
    cout << endl;

    ans = a.subtract( b );
    ans.output();
    cout << endl;

    ans = a.multiplication( b );
    ans.output();
    cout << endl;    

    return 0;
}

Polynomial::Polynomial () {
    for (int i = 0; i < MAXN; ++i) coefficients[i] = 0;
    greatestPower = 0;
}
Polynomial::Polynomial(const int great, const int data[51]) {
    for (int i = 0; i <= great; ++i) coefficients[i] = data[i];
    for (int i = great+1; i < MAXN; ++i) coefficients[i] = 0;
    greatestPower = great;
}
Polynomial Polynomial::add( const Polynomial adder) const {
    int A_great = this->greatestPower;
    int B_great = adder.greatestPower;
    int index = max(A_great, B_great);
    Polynomial ans(index, this->coefficients);

    while(A_great >= 0 && B_great >= 0 ) {
        if (A_great > B_great) {
            A_great--;
        }
        else if (A_great < B_great) {
            ans.coefficients[index--] += adder.coefficients[B_great--];
        }
        else if (A_great == B_great) {
            ans.coefficients[index--] += adder.coefficients[B_great--];
            A_great--;
        }
    }
    while (B_great >= 0) {
        ans.coefficients[index--] += adder.coefficients[B_great];
    }

    return ans;
}

Polynomial Polynomial::subtract( const Polynomial sub) const {
    int A_great = this->greatestPower;
    int B_great = sub.greatestPower;
    int index = max(A_great, B_great);
    Polynomial ans(index, this->coefficients);

    while(A_great >= 0 && B_great >= 0) {
        if (A_great > B_great) {
            A_great--;   
        }
        else if (A_great < B_great) {
            ans.coefficients[index--] -= sub.coefficients[B_great--];   
        }
        else if (A_great == B_great) {
            ans.coefficients[index--] -= sub.coefficients[B_great--];
            A_great--;
        }
    }

    while (B_great >= 0) {
        ans.coefficients[index--] -= sub.coefficients[B_great];
    }

    return ans;
} 
Polynomial Polynomial::multiplication( const Polynomial multi) const {
    int A_great = this->greatestPower;
    int B_great = multi.greatestPower;
    int index = A_great + B_great;
    Polynomial ans;
    ans.greatestPower = index;

    for (int A = A_great; A >= 0; --A) {
        for (int B = B_great; B >= 0; --B) {
            ans.coefficients[A+B] += this->coefficients[A] * multi.coefficients[B];
        }
    }

    return ans;
}
void Polynomial::output() const {
    for (int temp = greatestPower; temp >= 0; --temp) {
        cout << coefficients[temp] << (temp!=0?" ":"") ;
    }
}