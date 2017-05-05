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
  double kineticEnergy = (getMass()*((getVelocity().y)*(getVelocity().y))/2);
  double potencialEnergy = ((getPosition().y - getRadius()) * gravity * getMass());
  double energy = kineticEnergy + potencialEnergy;

  return energy ;
}

void Mass::step(double dt, double gravity)
{
  Vector2 acceleration;
  acceleration.x = getForce().x/getMass();
  acceleration.y = gravity;

  Vector2 newPosition;
  newPosition.x = getPosition().x + (getVelocity().x * dt) - (0.5 * acceleration.x * dt * dt);
  newPosition.y = getPosition().y + (getVelocity().y * dt) - (0.5 * acceleration.y * dt * dt);

  Vector2 newVelocity;
  newVelocity.x = getVelocity().x + acceleration.x * dt;
  newVelocity.y = getVelocity().y + acceleration.y * dt;

  if (xmin + getRadius() <= newPosition.x && newPosition.x <= xmax - getRadius()) {
    position.x = newPosition.x;
    velocity.x = newVelocity.x;
  } else {
    velocity.x = -velocity.x;
  }

  if (ymin + getRadius() <= newPosition.y && newPosition.y <= ymax - getRadius()) {
    position.y = newPosition.y;
    velocity.y = newVelocity.y;
  } else {
    velocity.y = -velocity.y;
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
  F.x = - stiffness * fabs((mass1->getPosition().x - mass2->getPosition().x)) - damping * fabs((mass1->getVelocity().x - mass2->getVelocity().x));
  F.y = - stiffness * fabs((mass1->getPosition().y - mass2->getPosition().y)) - damping * fabs((mass1->getVelocity().y - mass2->getVelocity().y));

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

SpringMass::SpringMass(Mass * mass1, Mass * mass2, Spring * spring, double gravity)
: mass1(mass1), mass2(mass2), spring(spring), gravity(gravity)
{ }

void SpringMass::display()
{

std::cout<<mass1->getPosition().x<<" "<<mass1->getPosition().y<<" "<<mass2->getPosition().x<<" "<<mass2->getPosition().y<<" "<<std::endl ;

}

double SpringMass::getEnergy() const
{
  double energy = mass1->getEnergy(gravity) + mass2->getEnergy(gravity) + spring->getEnergy() ;

  return energy ;
}

void SpringMass::step(double dt)
{
  Vector2 g(0,-gravity);
  mass1->setForce(g);
  mass2->setForce(g);
  mass1->addForce(spring->getForce());
  mass2->addForce(spring->getForce());
  mass1->step(dt, gravity);
  mass2->step(dt, gravity);

  //std::cout<<mass1->getForce().x<<" "<<mass1->getForce().y<<" "<<mass2->getForce().x<<" "<<mass2->getForce().y<<" "<<spring->getForce().x<<" "<<spring->getForce().y<<std::endl ;
}


/* INCOMPLETE: TYPE YOUR CODE HERE */
