/** file: test-springmass-graphics.cpp
 ** brief: Tests the spring mass simulation with graphics
 ** author: Andrea Vedaldi
 **/

#include "graphics.h"
#include "springmass.h"

#include <iostream>
#include <sstream>
#include <iomanip>

/* ---------------------------------------------------------------- */
class SpringMassDrawable : public SpringMass, public Drawable
/* ---------------------------------------------------------------- */
{
private:
  Figure figure ;

public:
  SpringMassDrawable()
  : figure("SpringMass")
  {
    figure.addDrawable(this) ;
  }

  void draw() {
    figure.drawLine(x1,y1,x2,y2,thick) ;
    figure.drawCircle(x1,y1,r) ;
    figure.drawCircle(x2,y2,r) ;
  }

  void display() {
    figure.update() ;
  }

} ;

int main(int argc, char** argv)
{
  glutInit(&argc,argv) ;
  const double dt = 1/120.0 ;
  SpringMassDrawable springmass ;
  run(&springmass, dt) ;
  return 0 ;
}
