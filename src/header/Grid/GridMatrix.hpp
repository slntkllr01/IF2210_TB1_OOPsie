// Grid versi pakai matrix (vector of vector), tapi setelah bbrp pertimbangan, bagusan make map kayaknya
#ifndef GRID_H
#define GRID_H
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

template<class T>
class Grid{
    private:
        int baris;
        int kolom;
        int nElement;
        vector<vector<T>> element;

    public:
        Grid(int b, int k){ //Constructor
            this->baris = b;
            this->kolom = k;
            element.resize(baris);
        
            for(int i = 0; i<this->baris; i++){
                element[i].resize(this->kolom);
            }

            this->nElement = 0;

            }
        
        ~Grid(){
            this->element.clear();
        } //Destructor

        T operator()(int i, int j){
            return this->element[i][j];
        }
        
        void operator()(int i, int j, T object){
            this->element[i][j] = object;
        }

        int getBaris(){
            return this->baris;
        }
        int getKolom(){
            return this->kolom;
        }
        int getNElement(){
            return this->nElement;
        }
        void printGrid(){
            for(int i =0; i<this->baris; i++){
                for(int j = 0; j<this->kolom; j++){
                    cout<<element[i][j];
                    
                    
                }
            }
        }
};

#endif