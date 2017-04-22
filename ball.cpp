/** file: ball.cpp
 ** brief: Ball class - implementation
 ** author: Andrea Vedaldi
 **/

#include "ball.h"

#include <iostream>

Ball::Ball()
: r(0.1), x(0), y(0), vx(0.3), vy(-0.1), g(9.8), m(1),
xmin(-1), xmax(1), ymin(-1), ymax(1)
{ }

Ball::Ball(double x0, double y0)
{
  r = 0.1;
  x = x0;
  y = y0;
  vx = 0.3;
  vy = -0.1;
  g = 9.8;
  m = 1;
  xmin = -1;
  xmax = 1;
  ymin = -1;
  ymax = 1;
}

void Ball::step(double dt)
{
  double xp = x + vx * dt ;
  double yp = y + vy * dt - 0.5 * g * dt * dt ;
  if (xmin + r <= xp && xp <= xmax - r) {
    x = xp ;
  } else {
    vx = -vx ;
  }
  if (ymin + r <= yp && yp <= ymax - r) {
    y = yp ;
    vy = vy - g * dt ;
  } else {
    vy = -vy ;
  }
}

//Lembrar de nos próximos exercícios mandar o arquivo
// antes de fazer as mudanças
void Ball::setPosition(double newX, double newY)
{
  x = newX;
  y = newY;
}

void Ball::getPosition()
{
  std::cout<<"X = "<<x<<" Y = "<<y<<std::endl ;
}

void Ball::display()
{
  std::cout<<x<<" "<<y<<std::endl ;
}

void Ball::run(Simulation & s, double dt)
{
  for (int i = 0 ; i < 100000000000 ; ++i)
  {
    s.step(dt);
    s.display();
  }
}
