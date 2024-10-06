#include <iostream>
#include "tetris_input.h"
using namespace std;

int main() {
	for (;;) {
		if (rotateR()) {
			cout << "OK\n";
		}
	}
	return 0;
}