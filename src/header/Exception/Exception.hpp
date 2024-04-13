#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_
#include <string>
using namespace std;

// IMPORTANT!!
// EXCEPTION IS ONLY USED WHEN IT'S A COMPLETE DEADEND
// EVERY OTHER INPUT WILL STILL LEAD TO A DEADEND

// ABC Exception
class Exception {
    public:
        virtual string what() = 0;
};

// Tidak ada makanan yang cocok/tidak ada makanan untuk hewan pada KASIH PANGAN
class NoAnimalFood : public Exception {
    public:
        string what() override {
            return "Tidak ada makanan untuk hewan ternak.";
        }
};

class NoMoney : public Exception {
    public:
        string what() override {
            return "Gulden kamu kurang.";
        }
};

class NoInventorySpace : public Exception {
    public:
        string what() override {
            return "Inventorymu penuh.";
        }
};

// Exception duplikasi nama pemain (tidak unik)
class DupeName : public Exception{
    public:
    string what() override {
        return "Nama tersebut sudah ada.";
    }
};

class InvalidRole : public Exception {
    public:
        string what() override {
            return "Peranmu tidak bisa menggunakan command ini.";
        }
};

class LadangFull : public Exception {
    public:
        string what() override {
            return "Ladang kamu penuh, harus kosongkan tempat.";
        }
};

class noTanamaninInv : public Exception {
    public:
        string what() override {
            return "Tidak ada tanaman di inventory untuk ditanam.";
        }
};
// Add more or edit as you please

#endif