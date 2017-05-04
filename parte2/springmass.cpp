/** file: springmass.cpp
 ** brief: SpringMass simulation implementation
 ** author: Andrea Vedaldi
 **/

#include "springmass.h"

#include <iostream>
#include <cmath>

/* ---------------------------------------------------------------- */
// class Mass
/* ---------------------------------------------------------------- */

Mass::Mass()
: position(), velocity(), force(), mass(1), radius(1)
{ }

Mass::Mass(Vector2 position, Vector2 velocity, double mass, double radius)
: position(position), velocity(velocity), force(), mass(mass), radius(radius),
xmin(-1),xmax(1),ymin(-1),ymax(1)
{ }

void Mass::setForce(Vector2 f)
{
  force = f ;
}

void Mass::addForce(Vector2 f)
{
  force = force + f ;
}

Vector2 Mass::getForce() const
{
  return force ;
}

Vector2 Mass::getPosition() const
{
  return position ;
}

Vector2 Mass::getVelocity() const
{
  return velocity ;
}

double Mass::getRadius() const
{
  return radius ;
}

double Mass::getMass() const
{
  return mass ;
}

double Mass::getEnergy(double gravity) const
{
  double energy =  (getMass()*((getVelocity().y)*(getVelocity().y))/2)
                      + (getPosition().x * gravity * getMass());

  return energy ;
}

void Mass::step(double dt)
{
  Vector2 newPosition;
  newPosition.x = getPosition().x + (getVelocity().x * dt);
  newPosition.y = getPosition().y + (getVelocity().y * dt) - (0.5 * getForce().y/getMass() * dt * dt);

  if (xmin + getRadius() <= newPosition.x && newPosition.x <= xmax - getRadius()) {
    position.x = newPosition.x;
  } else {
    position.x = -newPosition.x;
  }

  if (ymin + getRadius() <= newPosition.y && newPosition.y <= ymax - getRadius()) {
    position.y = newPosition.y;
  } else {
    position.y = -newPosition.y;
  }
}

/* ---------------------------------------------------------------- */
// class Spring
/* ---------------------------------------------------------------- */

Spring::Spring(Mass * mass1, Mass * mass2, double naturalLength, double stiffness, double damping)
: mass1(mass1), mass2(mass2),
naturalLength(naturalLength), stiffness(stiffness), damping(damping)
{ }

Mass * Spring::getMass1() const
{
  return mass1 ;
}

Mass * Spring::getMass2() const
{
  return mass2 ;
}

Vector2 Spring::getForce() const
{
  Vector2 F ;
  F.x = - stiffness * abs((mass1.getPosition().x - mass2.getPosition().x)) - damping * abs((mass1.getVelocity().x - mass2.getVelocity().x));
  F.y = - stiffness * abs((mass1.getPosition().y - mass2.getPosition().y)) - damping * abs((mass1.getVelocity().y - mass2.getVelocity().y));

  return F;

}

double Spring::getLength() const
{
  Vector2 u = mass2->getPosition() - mass1->getPosition() ;
  return u.norm() ;
}

double Spring::getEnergy() const {
  double length = getLength() ;
  double dl = length - naturalLength;
  return 0.5 * stiffness * dl * dl ;
}

std::ostream& operator << (std::ostream& os, const Mass& m)
{
  os<<"("
  <<m.getPosition().x<<","
  <<m.getPosition().y<<")" ;
  return os ;
}

std::ostream& operator << (std::ostream& os, const Spring& s)
{
  return os<<"$"<<s.getLength() ;
}

/* ---------------------------------------------------------------- */
// class SpringMass : public Simulation
/* ---------------------------------------------------------------- */

SpringMass::SpringMass(Mass * mass1, Mass * mass2, Spring * spring double gravity)
: mass1(mass1), mass2(mass2), spring(spring), gravity(gravity)
{ }

void SpringMass::display()
{

/* INCOMPLETE: TYPE YOUR CODE HERE */

}

double SpringMass::getEnergy() const
{
  double energy = 0 ;

/* INCOMPLETE: TYPE YOUR CODE HERE */

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity) ;

/* INCOMPLETE: TYPE YOUR CODE HERE */

}


/* INCOMPLETE: TYPE YOUR CODE HERE */
