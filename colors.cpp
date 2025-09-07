#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
using namespace std;

struct Color {
    int r, g, b;
};

int main() {
    vector<Color> colors;

    // RNG setup
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distN(25, 50);
    uniform_int_distribution<int> distRGB(0, 255);

    // choose n
    int n = distN(gen);
    cout << "Generating " << n << " random colors...\n";

    // fill vector
    for (int i = 0; i < n; i++) {
        Color c{distRGB(gen), distRGB(gen), distRGB(gen)};
        colors.push_back(c);
    }

    // print table
    const int wIdx = 8, wCol = 10;
    cout << left
         << setw(wIdx) << "Color#"
         << setw(wCol) << "R value"
         << setw(wCol) << "G value"
         << setw(wCol) << "B value" << "\n";

    cout << setfill('-')
         << setw(wIdx) << "" << setw(wCol) << "" << setw(wCol) << "" << setw(wCol) << "" << "\n"
         << setfill(' ');

    for (int i = 0; i < n; i++) {
        cout << left
             << setw(wIdx) << (i+1)
             << setw(wCol) << colors[i].r
             << setw(wCol) << colors[i].g
             << setw(wCol) << colors[i].b << "\n";
    }

    return 0;
}
