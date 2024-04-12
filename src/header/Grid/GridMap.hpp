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

        T value(string k){
            auto it = element.find(k);
            return it->second;
        }

        void add(string k, T val){
            element.insert({k, val});
        }

        auto firstptr(){
            return element.begin();
        }

        auto endptr(){
            return element.end();
        }

        void del(string k){
           auto it = element.find(k);
           element.erase(it);
        }

        int howMuchElement(){
            return this->numOfEl;
        }
};  

#endif