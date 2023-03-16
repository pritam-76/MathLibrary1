#include <iostream>
#include "Vector.h"
using namespace std;

template<class Type>vec<Type>::vec() :x(0.0), y(0.0), z(0.0) {};
template<class Type>vec<Type>::vec(Type x1, Type y1, Type z1) :x(x1), y(y1), z(z1) {}
template<class Type>vec<Type>::vec(const vec<Type>& v) : x(v.x), y(v.y), z(v.z) {}
//magnitude
template<class Type>
float vec<Type> ::magnitude() {
    Type magn = x * x + y * y + z * z;
    magn = sqrt(magn);
    return magn;
}
//addition
template<class Type>
vec<Type> vec<Type>::operator +(const vec& v) {
    return vec(x + v.x, y + v.y, z + v.z);

}
//substraction
template<class Type>
vec<Type>vec<Type>::operator -(const vec& v) {
    return vec(x - v.x, y - v.y, z - v.z);
}

//scalar multiplication
template<class Type>
vec<Type> vec<Type>::operator *(Type scalar) {
    return vec(x * scalar, y * scalar, z * scalar);
}
//multiplication
template<class Type>
vec<Type>vec<Type>::operator *(const vec& v) {
    return vec(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
}
//unit vector
template<class Type>
vec<Type>vec<Type>::normalize() {
    float mag = this->magnitude();
    return vec(x / mag, y / mag, z / mag);
}
//cross product
template<class Type>
vec<Type>vec<Type>::crossproduct(vec& v1, vec& v2) {
    vec ans = v1 * v2;
    return ans;
}
//dot product
template<class Type>
Type vec<Type>::dotproduct(const vec& v1, const vec& v2) {
    Type a = v1.x * v2.x, b = v1.y * v2.y, c = v1.z * v2.z;
    return (a + b + c);
}
template<class Type>
float vec<Type>::sinearc(vec& v1, vec& v2) {
    vec ans = v1 * v2;
    float ans1 = ans.magnitude();
    float scalar = v1.magnitude() * v2.magnitude();
    return ans1 / scalar;
}
template<class Type>
float vec<Type>::coarc(vec& v1, vec& v2) {
    vec temp;
    Type ans = temp.dotproduct(v1, v2);
    return ans / (v1.magnitude() * v2.magnitude());
}
//distance 
template<class Type>
float vec<Type> ::distance(const vec& v1, const vec& v2) {
    Type a = (v1.x - v2.x), b = (v1.y - v2.y), c = (v1.z - v2.z);
    a = a * a, b = b * b, c = c * c;
    return sqrt(a + b + c);
}
template<class Type> void vec<Type>::print() {
    cout << x << "i + " << y << "j + " << z << "k\n";
}

int main()
{
    vec<float> v1(4.2, 6.2, 7.0);
    cout << "v1 is : ";
    v1.print();
    vec<float> v2(3.2, 4.1, 5.0);
    cout << "V2 is: ";
    v2.print();
    cout << "Magnitude of vec1 is : " << v1.magnitude();
    cout << endl;
    cout << "Magnitude of vec2 is: " << v2.magnitude();
    cout << endl;
    cout << "Addtion of v1 and v2 : ";
    vec<float>v3;
    v3 = v1 + v2;
    v3.print();
    cout << "Subtraction of v1 and v2 : ";
    v3 = v1 - v2;
    v3.print();
    cout << "Multiplication of v1 and v2 :";
    v3 = v1 * v2;
    v3.print();
    vec<float>v4 = v1.normalize();
    cout << "Normalized vector value: ";
    v4.print();
    cout << "The dot product of two vector is: " << v3.dotproduct(v2, v1);
    cout << endl;
    cout << "Sine angle is: " << v3.sinearc(v2, v1);
    cout << endl;
    cout << "Cosine angle is: " << v3.coarc(v2, v1);
    cout << endl;
    cout << "Distance between two vector is: " << v3.distance(v2, v1);
    cout << endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
