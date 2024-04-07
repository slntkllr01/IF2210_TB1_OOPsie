// GridMap.hpp
#ifndef GRID_H
#define GRID_H
#include <map>
#include <iostream>
using namespace std;

template<class T>
class Grid{
    private:
        map<string, T> element;    
        int numOfEl;
    public:
        //Constructor
        Grid(){
            numOfEl = 0;
        } 
        
        //Destructor
        ~Grid(){ 
            //Menghapus seluruh map yang ada
            auto first = element.begin();
            auto end = element.end();
            element.erase(first, end);
        } 

        bool isPresent(string k){
            auto it = element.find(k);
            if(it == element.end()){
                return false;
            }
            else{
                return true;
            }
        }

        void add(string k, T val){
            auto it = element.find(k);
            if(it==element.end()){
                element.insert({k, val});
                cout<<"Kini petak "<<k<<" sudah memiliki isi"<<endl;
                numOfEl ++;
            }
            else{
                cout<<"Sudah ada element di petak "<<k<<endl;
            }
            
        }

        auto firstptr(){
            return element.begin();
        }

        auto endptr(){
            return element.end();
        }

        void del(string k){
           auto it = element.find(k);
           if(it == element.end()){
                cout<<"Tidak ada elemen di petak" << k << endl;
                numOfEl--;
           }
           else{
                element.erase(it);
           }
        }
};  

#endif