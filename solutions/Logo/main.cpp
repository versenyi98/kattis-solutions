#include <iostream>
#include <cmath>

#define PI 3.14159265358979323846

using namespace std;

double currX, currY;
int rotation;
char operation, temp;
int value;

void handleOperation() {

    if (operation == 'l') {
        rotation += value;
        rotation = rotation % 360;
        return;
    }

    if (operation == 'r') {
        rotation -= value;
        while (rotation < 0) rotation += 360;
        rotation = rotation % 360;
        return;
    }

    int m = 1;

    if (operation == 'b') {
        m = -1;
    }

    currY += sin(PI * rotation / 180.0) * m * value;
    currX += cos(PI * rotation / 180.0) * m * value;
}


int main() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {

        currX = 0;
        currY = 0;
        rotation = 0;

        int lines;
        cin >> lines;

        for (int j = 0; j < lines; j++) {
            cin >> operation >> temp >> value;
            handleOperation();
        }
        long dist = round(sqrt(pow(currX, 2) + pow(currY, 2)));
        cout << dist << endl;
    }
}
