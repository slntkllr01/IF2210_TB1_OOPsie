#include "../../header/Hewan/Hewan.hpp"
#include "../../header/Tanaman/Tanaman.hpp"
#include "../../header/Hewan/Karnivora.hpp"
#include "../../header/Hewan/Herbivora.hpp"
#include "../../header/Hewan/Omnivora.hpp"
#include "../../header/Tanaman/Fruit.hpp"
// #include "../../header/Tanaman/Material.hpp"
#include <iostream>
using namespace std;
int main(){
    ConfigLoader& loader = ConfigLoader::getInstance();
    loader.initConfig("../../../config/plant.txt","../../../config/animal.txt","../../../config/product.txt","../../../config/recipe.txt","../../../config/misc.txt");
    produkHewan* p1 = new produkHewan(17);
    cout << "Tes 1" << endl;
    
    Herbivora sapi = Herbivora(1);
    cout << "Tes 2" << endl;
    Herbivora sheep = Herbivora(2);
    cout << "Tes 3" << endl;
    Herbivora horse = Herbivora(3);
    cout << "Tes 4" << endl;
    Herbivora rabbit = Herbivora(3);
    cout << "Tes 5" << endl;
    Karnivora snake = Karnivora(5);
    cout << "Tes 6" << endl;
    Omnivora chicken = Omnivora(6);
    cout << "Tes 7" << endl;
    Omnivora duck = Omnivora(7);
    cout << "Tes 8" << endl;
    cout << sapi.get_harvestweight() << endl;
    cout << sapi.get_type() << endl;
    cout << sapi.getPrice() << endl;
    cout << "Bisa makan" << endl;
    cout << snake.CanEat(p1)<< endl;
    snake.set_actualweight(1202);
    cout << "Bisa panen" << endl;
    cout << snake.siapPanen();

}
// g++ -o test testHewan.cpp Hewan.cpp Omnivora.cpp Karnivora.cpp Herbivora.cpp ../Item/Item.cpp ../Produk/Produk.cpp ../Tanaman/Tanaman.cpp