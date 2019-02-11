#include <iostream>
#include <fstream>
#include "Image.h"
#include "Matrix.h"
#include "processing.h"

using namespace std;



int main(int argc, char* argv[]) {
	ifstream in_f;
	in_f.open(argv[2]);
    if (!in_f.is_open()) {
        cout << "Error opening file: " << argv[2] << endl;
        return 1;
    }
	Image* img = new Image;
	Image_init(img, in_f);
    in_f.close();

	ofstream out_f;
	out_f.open(argv[3]);
    if (!out_f.is_open()) {
        cout << "Error opening file: " << argv[3] << endl;
        return 1;
    }
    int des_height = Image_height(img);
    int des_width = atoi(argv[4]);
    if (argc == 5) {
        des_height = atoi(argv[5]);
    }
    if (!(des_width > 0 && des_width <= Image_width(img)) || !(argc == 4 || argc == 5) || !(des_height > 0 && des_height <= Image_height(img))) {
        cout << "Usage: resize.exe IN_FILENAME OUT_FILENAME WIDTH [HEIGHT]\n"
        << "WIDTH and HEIGHT must be less than or equal to original" << endl;
        return 1;
    }
    seam_carve(img, des_width, des_height);
	Image_print(img, out_f);

    
    return 0;
}



