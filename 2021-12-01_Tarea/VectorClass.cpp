#include<iostream>
struct Vector3D
{
    double x, y, z;
    //Constructor
    Vector3D(){
        x = 0.0; y = 0.0; z = 0.0;
    }
    //Print vector
    void print(){
        std::cout << "(" << x << ", " << y << ", " << z << ")" << "\n";
    }
    //Overloading operator +
    Vector3D operator+(const Vector3D &v){
        Vector3D sum;
        sum.x = x + v.x;
        sum.y = y + v.y;
        sum.z = z + v.z;
        return sum;
    }
    //Overloading operator *
    double operator*(const Vector3D &v){
        return (x*v.x) + (y*v.y) + (z*v.z);
    }
    ~Vector3D(){} //Destructor
};

int main()
{
    double dotp = 0.0;
    Vector3D R1, R2, R3;
    R1.x = 1.0; R1.y = 2.0; R1.z = 3.0; 
    R2.x = 4.0; R2.y = 5.0; R2.z = 6.0; 

    R3 = R1 + R2;
    R1.print(); R2.print(); R3.print();

    dotp = R1*R2;
    std::cout << dotp << std::endl;

    return 0;
}