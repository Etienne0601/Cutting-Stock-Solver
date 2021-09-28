#include <iostream>
#include <string>
#include <vector>
using namespace std;


// g++ -o solver -Wall -pedantic -O0 -std=c++11 solver.cpp


string vect_to_str(const vector<unsigned int> & to_convert) {
    string output;

    for (auto i : to_convert) {
        output.append(to_string(i) + " ");
    }
    output.pop_back();

    return output;
}

unsigned int dot_product(const vector<unsigned int> & a, const vector<unsigned int> & b) {
    if (a.size() != b.size()) {
        cerr << "Dot Product Error!" << endl;
        exit(EXIT_FAILURE);
    }

    unsigned int output = 0;
    for (unsigned int i = 0; i < a.size(); ++i) {
        output += a[i] * b[i];
    }

    return output;
}

// prints all possible cutting patterns
void cutting_patterns(unsigned int stock_length, const vector<unsigned int> & shelf_lengths) {
    const unsigned int num_lengths = shelf_lengths.size();
    vector<unsigned int> n(num_lengths, 0);

    unsigned int ind = 0;
    unsigned int count = 0;
    unsigned int waste = 0;
    while (ind < num_lengths) {
        waste = stock_length - dot_product(n, shelf_lengths);
        if (waste < 20) {
            cout << "count = " << count << "; n = " << vect_to_str(n) << " Waste: " << waste << "; maximal" << endl;
        }

        ind = 0;
        while (dot_product(n, shelf_lengths) + shelf_lengths[ind] > stock_length) {
            n[ind++] = 0;
            if (ind == num_lengths) {
                return;
            }
        }
        
        n[ind] += 1;
        ++count;
    }
}

// int main(int argc, char** argv) {

int main() {

    vector<unsigned int> shelf_lengths{20, 45, 50, 55, 75};

    cutting_patterns(220, shelf_lengths);

    return 0;
}
