#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_
#include <string>
using namespace std;

// ABC Exception
class Exception {
    public:
        virtual string what() = 0;
};

// Tidak ada makanan yang cocok/tidak ada makanan untuk hewan pada KASIH PANGAN
class NoAnimalFood : public Exception {
    public:
        string what() override {
            return "Tidak ada makanan yang cocok.";
        }
};

class CannotEat : public Exception {
    public:
        string what() override {
            return "Tidak bisa makan itu, silakan pilih makanan yang lain.";
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
        return "Nama tersebut sudah ada, silakan ulangi masukan.";
    }
};

// Exception nama pemain kosong
class EmptyName : public Exception{
    public:
    string what() override {
        return "Nama tidak boleh string kosong, silakan ulangi masukan.";
    }
};

class OneWalikota : public Exception {
    public:
        string what() override {
            return "Sudah ada walikota di kota ini.";
        }
};

// Exception untuk segala pemilihan opsi
// Exception untuk PANEN, cek petak dan ID
class InvalidInput : public Exception {
    public:
        string what() override {
            return "Masukan tidak valid, silakan ulangi masukan.";
        }
};

class InvalidFileInput : public Exception {
    public:
	string what() override {
            return "File input invalid.";
        }
};

// Add more or edit as you please

#endif