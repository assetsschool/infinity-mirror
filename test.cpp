#include <iostream>

#define BITSHIFT 8


using namespace std;

int main() {

	// uint32_t color = 0xFF0000;
	
	// do {
	// 	cout << "\n" << color << "\n";
	// } while ((color >>= BITSHIFT) >= 255);


	const int step = 8; // Select this to be a power of two if you want the maximum brightness to be reachable
	for( int red = 0x00; red <= 0xFF; red += step ) {
		for( int green = 0x00; green <= 0xFF; green += step ) {
			for( int blue = 0x00; blue <= 0xFF; blue += step ) {
				const int color = blue << 16 + green << 8 + red;
					cout << "\n" << color << "\n";
			}
		}
	} 
}