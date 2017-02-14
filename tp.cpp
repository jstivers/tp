#include <iostream>   // Basic I/O => cin, cout, etc.
#include "math.h"
#include <iomanip>
#include <cstdlib>
using namespace std;

// Prototype/declaration of a function that returns a
// uniform random number between [0,1]
double rand_uniform();

// Prototype/declaration of a function that will perform a single
// simulation of two rolls of paper and users
// Returns the number of squares left on the non-empty roll
double single_sim (double N, double p);

int main(int argc, char *argv[])
{
    double output = 0;        // the output of the program
    double N;                // initial number of squares on each roll

    double p;             // probability of a big-chooser

    int sims;             // number of trials for our simulation


    // Add your code here
    cout << "\nEnter Number of Squares: ";
    cin >> N;
    cout << "\nEnter Prob. of Big Chooser: ";
    cin >> p;
    cout << "\nEnter Number of Simulations: ";
    cin >> sims;
    cout<<endl;
    for ( int i = 0; i < sims ; i++){
        output += single_sim(N,p);
    }
    output = output/sims;

    cout << setprecision (4) << ( "Average: " ) << output;

    // Be sure you produce an output of the form:
    //    Average: 1.2314
    // where the number is the correct average
    return 0;
}

// return the number of squares on the non-empty roll
//  for this simulation of the problem

double single_sim (double N, double p)
{
    double roll_1 = N;
    double roll_2 = N;
    double big_chooser = p;
    double small_chooser = 1 - p;


    while ( roll_2 != 0.00 && roll_1 != 0.00 ) {

        double random_value = rand_uniform ();

        if ( roll_1 == roll_2 ) {
            roll_1 --;
        }
        if ( random_value == big_chooser == small_chooser ) {
            roll_1 --;
        }
        else if ( random_value > big_chooser ) {
            roll_1 >= roll_2 ? roll_1 -- : roll_2 --;
        }
        else if ( random_value < small_chooser ) {
            roll_1 <= roll_2 ? roll_1 -- : roll_2 --;

        }
    }
    return roll_2 <= 0.00 ? roll_1 : roll_2;


}

// returns a uniformly-distributed number in the range [0,1]
//  The caller can use the return result to then determine
//  if it should treat it as a big- or little-chooser by
//  also using the p parameter.  This code only needs to
//  produce a random number in the range [0,1]
double rand_uniform()
{
    double cast;
    cast = (double) rand () / (double) RAND_MAX;

    return cast;


}