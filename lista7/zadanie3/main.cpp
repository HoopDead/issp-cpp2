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

auto soft_img(int width, int height, int depth, Kolor ** tab) {
    Kolor* soften_img = new Kolor[height];
    unsigned char r, g, b;
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < width; j++) {
            if(i == 0) {
                r = (tab[j][i+1].red + tab[j][i].red/2);
                g = (tab[j][i+1].green + tab[j][i].green/2);
                b = (tab[j][i+1].blue + tab[j][i].blue/2);
            }
            else if(i == width-1) {
                r = (tab[j][i-1].red + tab[j][i].red)/2;
                g = (tab[j][i-1].green + tab[j][i].green)/2;
                b = (tab[j][i-1].blue + tab[j][i].blue)/2;
            }
            else {
                r = (tab[j][i-1].red + tab[j][i].red + tab[j][i+1].red)/3;
                g = (tab[j][i-1].green + tab[j][i].green + tab[j][i+1].green)/3;
                b = (tab[j][i-1].blue + tab[j][i].blue + tab[j][i+1].blue)/3;
            }
            soften_img[i] = {r,g,b};
        }
    }
    return tab;
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
    Kolor ** softened_img = soft_img(result.w, result.h, result.d, result.t);
    save_to_pgm("wynik.pgm", result.w, result.h, result.d, softened_img);
    cout << result.w;
    return 0;
}