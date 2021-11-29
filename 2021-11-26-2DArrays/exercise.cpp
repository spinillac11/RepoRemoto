#include <iostream>
#include <cstdlib>
#include <vector>
#include <random>
#include <fstream>

int main(int argc, char **argv)
{
    //Read parameters from comand line
    const int N = std::atoi(argv[1]); //Numero de muestras
    const int SEED = std::atoi(argv[2]);//Inicializar generador aleatoreo
    const double A = std::atof(argv[3]);
    const double B = std::atof(argv[4]);//parametros de la distribucion weilbull
    const int BINS = 15;
    std::vector<double> histo(BINS,0.0);//Tamano BINS y sus elementos se inicializan con 0.0
    //Generate N random numbers with weibull distribution - buscar en cppreference
    //commute them to compute a histogram
    std::mt19937 gen(SEED); //Con la misma semilla los numeros aleatoreos son los miismos
    std::weibull_distribution<double> d(A, B); //Sintaxis de la distribucion weilbull
    const double XMIN = 0;
    const double XMAX = 2;
    const double DX = (XMAX-XMIN)/BINS; //Tamno de intervalo
    for (int isample = 0; isample < N; ++isample) {//Para cada iteracion se crea una nueva muestra aleatorea
        double x = d(gen);//Generador aleatoreo con ditribucion Weilbull
        int boxid = int((x - XMIN)/DX); //Tamano de intervalos truncandose a un entero
        if(0 <= boxid && boxid < BINS)
            histo[boxid]++; //Cajita de histograma
    }
    //copute the histogram into a file
     std::ofstream fout("histo.txt"); //Salida
    for (int ibin = 0; ibin < BINS; ++ibin) {
        double x = XMIN + ibin*DX;
        fout << x << "\t" << histo[ibin] << "\n";
    }
    fout.close();
    return 0;
}
