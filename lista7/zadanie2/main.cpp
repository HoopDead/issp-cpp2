#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>

using namespace std;
    
struct Kolor{unsigned char red, green, blue;};


auto load_file(const char filename[]) {
    int width, height, depth;
    ifstream F(filename, ios::binary);
    string s;
    F >> s >> ws;
    F >> width >> height >> depth;
    struct result {int w; int h; int d; Kolor** t;};
    auto tab = new Kolor*[height];
    for(int i = 0; i < height; ++i) {
        tab[i] = new Kolor[width];
        char* adres = reinterpret_cast<char*>(tab[i]);
        F.read(adres, sizeof(Kolor) * width);
    }
    return result{width, height, depth, tab};
}

void save_to_pgm(const char filename[], int width, int height, int depth, Kolor ** tab) {
    ofstream F(filename, ios::binary);
    char* line = new char[width];
    F << "P5\n" << width << " " << height << "\n" << depth << "\n";
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; j++) {
            line[j] = floor((tab[i][j].red + tab[i][j].green + tab[i][j].blue)/3);
        }
        F.write(line, width);
    }
}

int main() {
    auto result = load_file("tree_1.ppm");
    save_to_pgm("wynik.pgm", result.w, result.h, result.d, result.t);
    return 0;
}