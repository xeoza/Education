#ifndef B_MODIFICATION_H
#define B_MODIFICATION_H

#include "math.h"
#include "matrix.h"

class B_Modification
{

public:

   virtual ~B_Modification(){}
   virtual void setDelta(double d) = 0;
   virtual double getDelta() const = 0;

};

#endif // B_MODIFICATION_H
