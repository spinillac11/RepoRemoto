#include <iostream>
#include <vector>
#include <random>

int main(int argc, char **argv)
{
    //Read parameters from comand line
    const int N = std::atoi(argv[1]);
    const int seed = std::atoi(argv[2]);
    const double A = std::atof(argv[3]);
    const double B = std::atof(argv[4]);
    const int BINS = 15;
    std::vector<double> histo(BINS,0.0);
    //Generate N random numbers with weibull distribution - buscar en cppreference
    //commute them to compute a histogram
    //copute the histogram into a file
}
