#include <bits/stdc++.h>
// Welcome to my array class
// Developed by Mazen Wael Hussien
// V1.2
// Last Modified : 1/16/24
using namespace std;
class OutOfRangeException{};
template<typename T,int N>
class Array{
    private:
    T* data; // pointer to any type array
    public:

        Array(){
            data = new T[N]; // allocate a new T array of  elements of size N
        }
        int getlength() const{
            return N;
        }
        ~Array(){ // Destructor
            delete[] data; // to avoid any memory leaks
        }
        T& operator[](int i) const{ // Overloading the array operator
            if(i >= getlength() || i < 0){
             throw OutOfRangeException()   ; // throw an error in case index is out of range
            }
            else{
               return data[i];
            }

        }

        friend ostream& operator<<(ostream& COUT,const Array& arr){ // Overloading output operator
            for(int i = 0; i<arr.getlength(); i++){
                COUT << arr.data[i] << " ";
            }
            return COUT;
        }

        Array operator=(const Array& a){ // Copy assignment operator, for example a2 =a1 this means that rhs(right hand side) is a1 and  a2 is 'this' pointer
            Array b(a.getlength()); // same size as rhs
            for(int i =0; i<a.getlength(); i++){
                data[i] = a.data[i];
            }
            return b;
        }

        Array operator+(const Array& a1){ // Overloading adding + operator
            int i= 0,j=0;
            Array b(getlength()+a1.getlength());
            for(i =0; i<getlength(); i++){
                b[i] = this->data[i];
            }
             for(j =0; j<a1.getlength(); i++,j++){
                b[i] = a1.data[j];
            }
            return b;
        }



};
int main()
{
    try{
    Array<string,5> arr;
    for(int i =0; i<arr.getlength(); i++){
        arr[i] = "abc";
    }
    cout << arr[4];
    }
    catch(OutOfRangeException& e){
        cout << "Out Of Bounds! " << endl;
    }
    catch(InvalidSizeException& e){
        cout << "Invalid: Cannot input negative size. " << endl;
    }

}
