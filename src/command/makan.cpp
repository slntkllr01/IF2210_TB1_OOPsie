#include "../header/Pemain/Pemain.hpp"
#include "../header/Exception/Exception.hpp"

void makan(Pemain* pemain){
    // Cek apakah di penyimpanan ada makanan
    if (!pemain->getInventory().isThereMakanan()){
        throw NoHumanFood();
    }
    cout << "Pilih makanan dari penyimpanan" << endl;
    // Tamplikan isi penyimpanan
    pemain->getInventory().CetakPenyimpanan();
    // Pilih slot makanan
    string slot;
    bool valid_input = false;
    while (!valid_input){
        cout << "Slot: ";
        cin >> slot;
        // Cek apakah input slot valid
        if (!pemain->getInventory().isLokasiValid(slot)){
            throw InputSlotInvalid();
        }
        // Cek apakah slot kosong
        if (!pemain->getInventory().isPresent(slot)){
            cout << "Kamu mengambil harapan kosong dari penyimpanan." << endl;
            cout << "Silahkan masukan slot yang berisi makanan." << endl;
        } // Cek apakah slot berisi makanan
        else if (!pemain->getInventory().IsMakanan(slot)){
            cout << "Apa yang kamu lakukan??!! Kamu mencoba untuk memakan itu?!!" << endl;
            cout << "Silahkan masukan slot yang berisi makanan." << endl;
        } else {
            valid_input = true;
        }
    }
    // Ambil makanan dari penyimpanan
    Item* makanan = pemain->ambilItem(slot);
    // Makan makanan
    pemain->makan(dynamic_cast<Produk*>(makanan));
    cout << "Dengan lahapnya, kamu memakanan hidangan " << makanan->getName() << endl;
    cout << "Alhasil, berat badan kamu naik menjadi " << pemain->getBeratBadan() << endl;
}