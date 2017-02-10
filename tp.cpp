#include <iostream>   // Basic I/O => cin, cout, etc.
#include <cstdlib>    // Other helpful functions => rand(), RANDMAX

using namespace std;

// Prototype/declaration of a function that returns a
// uniform random number between [0,1]
double rand_uniform();

// Prototype/declaration of a function that will perform a single
// simulation of two rolls of paper and users
// Returns the number of squares left on the non-empty roll
int single_sim(int N, double p);

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

    cout << ("Average: ") << output;

    // Be sure you produce an output of the form:
    //    Average: 1.2314
    // where the number is the correct average
    return 0;
}

// return the number of squares on the non-empty roll
//  for this simulation of the problem
int single_sim(int N, double p)
{
    int big_roll = N;
    int small_roll = N;
    double prob = 1 - p;

    while(small_roll > 0 && big_roll > 0) {
        double random_value = rand_uniform ();
        if ( prob < random_value ) {
            small_roll --;
        }
        else {
            big_roll --;
        }
    }
    if(small_roll <= 0){
        return big_roll;
    }else{
        return small_roll;
    }



}

// returns a uniformly-distributed number in the range [0,1]
//  The caller can use the return result to then determine
//  if it should treat it as a big- or little-chooser by
//  also using the p parameter.  This code only needs to
//  produce a random number in the range [0,1]
double rand_uniform()
{
    double cast = (double)rand() / ((double)RAND_MAX);

    return cast;


}