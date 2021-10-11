#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned int uint_t;

struct problem_t {
    size_t num_stock_types;
    size_t num_shelf_types;
    uint_t * stock_lengths;
    uint_t * stock_costs;
    uint_t * shelf_lengths;
    uint_t * shelf_quantities;
};


/**
 * process input file to get the data in the format we want
 *
 * k will be a size_t type
 * m with be a size_t type
 * the stock lengths will be uint_t array (will be later extended to fractional lengths)
 * the costs will be will be uint_t array (in cents)
 * the shelf lengths will be uint_t array (will be later extended to fractional lengths)
 * the demanded quantity of shelves will be uint_t array
 *
 * stores the problem instance in prob_instance
 */
void parse_input(istream & in_stream, problem_t * prob_instance) {

    string line, temp_str; // temp string variables
    uint_t k, m; // vars for number of types

    // get integer k, the num_stock_types
    getline(in_stream, line);
    k = stoul(line);
    prob_instance->num_stock_types = k;

    // get integer m, the num_shelf_types
    getline(in_stream, line);
    m = stoul(line);
    prob_instance->num_shelf_types = m;

    // allocate memory for the arrays
    prob_instance->stock_lengths = (uint_t*) malloc(k * sizeof(uint_t));
    prob_instance->stock_costs = (uint_t*) malloc(k * sizeof(uint_t));
    prob_instance->shelf_lengths = (uint_t*) malloc(m * sizeof(uint_t));
    prob_instance->shelf_quantities = (uint_t*) malloc(m * sizeof(uint_t));

    // loop over the number of stock types and grab their lengths
    getline(in_stream, line);
    for (uint_t i = 0; i < k; ++i) {
        istringstream ss(line);
    }
}

int main(int argc, char** argv) {

    // Expecting one command line argument for the input file
    if (argc != 2) {
        cerr << "Command line argument error!" << endl;
        exit(EXIT_FAILURE);
    }


    ifstream input_file(argv[1]);

    // this will contain the information about our specific
    // instance of the cutting wood optimization problem
    problem_t my_prob_instance;

    parse_input(input_file, &my_prob_instance);

    cout << "k = " << my_prob_instance.num_stock_types << endl;
    cout << "m = " << my_prob_instance.num_shelf_types << endl;

/*
    string line;
    while(getline(input_file, line)) {
        istringstream ss(line);      // create istringstream of current line
        string first, second, third; // helper vars
        getline(ss, first, ',');     // store first column
        getline(ss, second, ',');    // store second column
        getline(ss, third, '\n');    // store third column
    }
*/
    input_file.close();   

}
