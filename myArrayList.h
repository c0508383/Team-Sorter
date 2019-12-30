#ifndef MY_ARRAY_LIST
#define MY_ARRAY_LIST
#include <string>
#include <iostream>
using namespace std;

template<typename type> class myArrayList{
    private:
        int numElements;
        int size;
        type* arr = nullptr;
    public:
        myArrayList(){
            size = 10;
            numElements = 0;
            arr = new type[getSize()];
        };
        myArrayList(int size){
            this->size = size;
            numElements = 0;
            arr = new type[getSize()];
        };
        ~myArrayList(){delete[] arr;};

        int getNumElements()const{return numElements;};
        int getSize()const{return size;};
        
        void addElement(type element){
            if(numElements >= size)
                throw runtime_error("List already full!");
            else if(searchElement(element))
                throw runtime_error("Element exists already!");
            else{
                arr[numElements] = element;
                numElements++;
            }
        };
        void deleteElement(type element){
            if(searchElement(element)){
                int index = 0;
                for(int a = 0; a < getNumElements(); a++){
                    if(arr[a] == element){
                        index = a;
                    }
                }
                for(int a = index; a < getNumElements()-1; a++){
                    arr[a] = arr[a+1];
                }
                numElements--;
            }
        };

        bool searchElement(type element){
            for(int a = 0; a < getNumElements(); a++){
                if(arr[a] == element){
                    return true;
                }
            }
            
            return false;
        };
        void sort(){     
            type temp = arr[0];

            for(int a = 0; a < getNumElements()-1; a++){
                for(int b = 0; b < getNumElements()-1-a; b++){
                    if(arr[b+1] < arr[b]){
                        temp = arr[b+1];
                        arr[b+1] = arr[b];
                        arr[b] = temp;
                    }
                }
            }
        };
        void print(){
            for(int a = 0; a  < getNumElements(); a++){
                cout << arr[a] << endl;
            }
        };
};

#endif