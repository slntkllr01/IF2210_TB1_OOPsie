#ifndef _COMMAND_HPP
#define _COMMAND_HPP

#include "../header/Pemain/Pemain.hpp"
#include "../header/Pemain/Pekerja.hpp"
#include "../header/Toko/Toko.hpp"
#include "../header/ListPemain/ListPemain.hpp"

// Tambah Pemain
void addPemain(ListPemain& listPemain, Pemain* p);
bool isWhitespaceString(const string& s);
// Bangun Bangunan
void bangunBangunan(Pemain* p);
int lowest_price(const map<int, BangunanConfig>& bangunanConfigs);
vector<int> getAffordableBuildings(const map<int, BangunanConfig>& bangunanConfigs, const int uang);
// Cetak
void printPeternakan(Pemain* p);
void printLadang(Pemain* p);
void printPenyimpanan(Pemain* p);
// Kasih Makan
void kasihMakan(Pemain* p);
// Makan
void makan(Pemain* p);
// Panen
void panen_petani(Pemain* p);
void panen_peternak(Pemain* p);
// Pungut Pajak
bool comparePajak(const pair<Pekerja*, int>& a, const pair<Pekerja*, int>& b);
void pungutPajak(Pemain* pemain, ListPemain& list_pemain);
// Tanam
void tanam(Pemain* p);
// Ternak
void ternak(Pemain* p);
// Toko (Jual/Beli)
vector<string> getInput(string input);
void beli(Pemain* pemain, Toko toko);
void jual(Pemain* p, Toko toko);


#endif