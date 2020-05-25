#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>

using namespace std;

auto load_file(const char filename[]) {
    int width, height, depth;
    ifstream F(filename, ios::binary);
    string s;
    F >> s >> ws;
    F >> width >> height >> depth;
    struct result {int w; int h; int d;};
    return result{width, height, depth};
}

int main() {
    auto result = load_file("tree_1.ppm");
    cout << result.w;
    return 0;
}