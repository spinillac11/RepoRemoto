#include<iostream>

struct Vector3D
{
    double x, y, z;

    Vector3D(){
         x = 0.0;
         y = 0.0;
         z = 0.0;
    }

    void print(){
        std::cout << "(" << x << ", " << y << ", " << z << ")" << "\n";
    }

    Vector3D operator+(const Vector3D &v){
        Vector3D sum;
            sum.x = x + v.x;
            sum.y = y + v.y;
            sum.z = z + v.z;
            return sum;
    }

    Vector3D operator*(const Vector3D &v){
        Vector3D dot;
        dot.x = x*v.x;
        dot.y = y*v.y;
        dot.z = z*v.z;
        return dot;
    }

};

int main()
{
    Vector3D R1, R2, R3;
    R1.x = 1.0; R1.y = 2.0; R1.z = 3.0; 
    R2.x = 4.0; R2.y = 5.0; R2.z = 6.0; 

    R3 = R1 + R2;
    R1.print(); R2.print(); R3.print();

    R3 = R1*R2;
    std::cout << R3.x + R3.y + R3.z << std::endl;

    return 0;
}
