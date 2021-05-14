#include <iostream>
#include <sstream>
using namespace std;

// Solution 1
int countOne(long number) {
//    string numStr = (number);
    char numStr[999];
    sprintf(numStr, "%ld", number);
    cout << numStr << endl;

    int count = 0;
    for (int i = 0; numStr[i] != '\0'; i++) {
        if (numStr[i] == '1') {
            count += 1;
        }
    }

    return count;
}


// Solution 2
int countOne_(long number) {
    stringstream ss;
    ss << number;

    string numStr = ss.str();
    cout << numStr << endl;

    int count = 0;
    for (int i = 0; i < numStr.size(); i++) {
        if (numStr[i] == '1') {
            count += 1;
        }
    }

    return count;
}


// Solution 3
int countOne__(long number) {
    //
    int count = 0;

    long d = number / 10;
    long r = number%10;
    count += r == 1? 1: 0;

    while(d > 0) {
        r = d % 10;
        d /= 10;

        count += r == 1? 1: 0;
    }

    return count;
}


int main() {
    int n;
    cin >> n;

    cout << countOne(n) << endl;
    cout << countOne_(n) << endl;
    cout << countOne__(n) << endl;
}
