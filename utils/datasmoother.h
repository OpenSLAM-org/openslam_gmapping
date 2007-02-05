#ifndef DATASMOOTHER_H
#define DATASMOOTHER_H

#include <list>
#include <stdio.h>
#include <math.h>
#include <values.h>
#include "stat.h"

class DataSmoother {
 public: 
  struct DataPoint {
    DataPoint(double _x=0.0, double _y=0.0) { x=_x;y=_y;}
    double x;
    double y;
  };
  
  typedef std::list<DataPoint> Data;

  DataSmoother(double parzenWindow) {
    m_int=-1; 
    m_parzenWindow = parzenWindow;
    m_from = MAXDOUBLE;
    m_to = -MAXDOUBLE;
  };

  double sqr(double x) {
    return x*x;
  }

  void add(double x, double p) {
    m_data.push_back(DataPoint(x,p));
    m_int=-1;
    
    if (x-3.0*m_parzenWindow < m_from)
      m_from = x - 3.0*m_parzenWindow;

    if (x+3.0*m_parzenWindow > m_to)
      m_to = x + 3.0*m_parzenWindow;

  }
   
  void integrate(double step) {
    m_lastStep = step;
    double sum=0;
    for (double x=m_from; x<=m_to; x+=step)
      sum += smoothedData(x)*step;
    m_int = sum;
  }


  double smoothedData(double x) {
    double p=0;
    double sum_y=0;
    for (Data::const_iterator it = m_data.begin(); it != m_data.end(); it++) {
      const DataPoint& d = *it;
      p +=  d.y * exp( -0.5 * sqr ( (x - d.x)/m_parzenWindow ) );
      sum_y += d.y;
    }
    double denom = sqrt(2.0 * M_PI) * (sum_y) * m_parzenWindow;
    p *= 1./denom; 
    
    return p;
  }

  double sample(double step) {

    if (m_int <0 || step != m_lastStep)
      integrate(step);
    
    double r = sampleUniformDouble(0.0, m_int);
    double sum2=0;
    for (double x=m_from; x<=m_to; x+=step) {
      sum2 += smoothedData(x)*step;
      if (sum2 > r)
	return x-0.5*step;
    }
    return m_to;
  }
  
  void gnuplotDumpData(FILE* fp) {
    for (Data::const_iterator it = m_data.begin(); it != m_data.end(); it++) {
      const DataPoint& d = *it;
      fprintf(fp, "%f %f\n", d.x, d.y);
    }
  }

  void gnuplotDumpSmootheData(FILE* fp, double step) {
    for (double x=m_from; x<=m_to; x+=step)
      fprintf(fp, "%f %f\n", x, smoothedData(x));
  }

 protected:
  Data m_data;
  double m_int;
  double m_lastStep;

  double m_parzenWindow;
  double m_from;
  double m_to;
};

#endif
