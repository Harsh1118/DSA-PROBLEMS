#include<iostream>
using namespace std;

class Complex
{
    int real;
    int img;

    public : 
    Complex(int real,int img)
    {
        this->real=real;
        this->img = img;
    }

    void Add(Complex &c)
    {
        real+=c.real;
        img+=c.img;

        cout << "The Sum : "<<real << "+ (" << img <<"i)"<<endl;
    }
};

int main () 
{
    Complex C1(3,4);
    Complex C2(1,2);
    C1.Add(C2);
}