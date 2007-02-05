#include "datasmoother.h"
#include <stdio.h>
#include <iostream>


using namespace std;
using namespace GMapping;

int main(int , char** ) {

  DataSmoother h(0.1);

  h.add(0.1, 0);
  h.add(0.2, 0.5);
  h.add(0.3, 1);
  h.add(0.4, 1.8);
  h.add(0.5, 0.0);
  h.add(0.6, 1);
  h.add(0.7, 1);
  h.add(0.8, 0.1);



  FILE* fp = fopen("dat1.dat", "w");
  h.gnuplotDumpData(fp);
  fclose(fp);
  fp = fopen("dat2.dat", "w");
  h.gnuplotDumpSmootheData(fp, 0.0001);
  fclose(fp);


  fp = fopen("dat3.dat", "w");
  for (int i=0; i<100; i++) 
    fprintf(fp, "%f %f\n", h.sample(0.001), 0.1);
  fclose(fp);

  cout << "plot [-.5:1.5] \"dat1.dat\" with points,  \"dat2.dat\" with lines, \"dat3.dat\" with points\n" << endl;

  getchar();
}
