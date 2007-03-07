#include "datasmoother.h"
#include <stdio.h>
#include <iostream>


using namespace std;
using namespace GMapping;

int main(int , char** argv ) {

  //srand(atoi(argv[1]));

  DataSmoother h(0.2);

//   h.add(0.1, 0);
//   h.add(0.2, 0.5);
//   h.add(0.3, 1);
//   h.add(0.4, 1.8);
//   h.add(0.5, 0.0);
//   h.add(0.6, 0);
//   h.add(0.7, 1);
//   h.add(0.8, 0.1);
//   h.add(0.9, 0.0);


//  h.add(0.1, 0.5);
//  h.add(0.12,0.5);
//  h.add(0.2, 1);
//  h.add(0.5, 1);
//    h.add(0.8, 1);
//    h.add(0.85, 0);
//    h.add(0.9, 1);

  h.add(0.1, 0.1);
  
  h.add(0.8, 0.1);


  h.integrate(0.001);


  FILE* fp = fopen("dat1.dat", "w");
  h.gnuplotDumpData(fp);
  fclose(fp);
  fp = fopen("dat2.dat", "w");
  h.gnuplotDumpSmoothedData(fp, 0.0001);
  fclose(fp);


  

  fp = fopen("dat3.dat", "w");

  std::vector<double> samples;
  h.sampleMultiple(samples, 100);
  for (int i=0; i<(int) samples.size(); i++) 
    fprintf(fp, "%f %f\n", samples[i], 0.2);
  fclose(fp);
  
  fp = fopen("dat4.dat", "w");
  for (int i=0; i<100; i++) 
    fprintf(fp, "%f %f\n", h.sample(), 0.1);
  fclose(fp);

//   fp = fopen("dat4.dat", "w");
//   for (double x=-1; x<2; x+= 0.01) 
//     fprintf(fp, "%f %f\n", x, h.integral(0.001, x));
//   fclose(fp);

//   double m=0,s=0;
//   h.approxGauss(0.001, &m, &s);

//   cerr << "CvM  = " << h.cramerVonMisesToGauss(0.01, m, s) << endl;
//   cerr << "KLD  = " << h.kldToGauss(0.01, m, s) << endl;

//   cout << "gaussfactor(s) = (1.0/(sqrt(2.0*pi)*s))" << endl;
//   cout << "gaussexp(x,m,s) = (exp(-0.5 * (x-m)*(x-m)/(s*s)) )" << endl;
//   cout << "gauss(x, m, s) = (gaussfactor(s) * gaussexp(x, m, s))" << endl;
//   cout << "gaussInt(x, m, s) = ( 0.5*(1.0+erf( (x-m)/(s*sqrt(2)))) )" <<endl;
//   cout << "plot [-1:2] \"dat1.dat\" with points,  \"dat2.dat\" with lines, \"dat3.dat\" with points, gauss(x, " << m << ", " << s << "), gaussInt(x, " << m << ", " << s << "),  \"dat4.dat\" with lines\n" << endl;


  cout << "plot [-1:2] \"dat1.dat\" with points,  \"dat2.dat\" with lines, \"dat3.dat\" with points, \"dat4.dat\" with points\n" << endl;

  getchar();
  return 0;
}

