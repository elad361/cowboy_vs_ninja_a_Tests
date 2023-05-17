#pragma once
/**
* @author: Elad Shoham, 205439649
*/

#include <iostream>
#include <string>
#include <cmath>
#include "Point.hpp"

// Defines for cowboy
#define COWBOY_START_HIT_POINTS 110
#define COWBOY_START_BULLETS 6
#define RELOAD 6
#define SHOOT_POINTS 10

// Defines for ninja
#define YUONG_SPEED 14
#define YOUNG_HIT_POINTS 100
#define TRAINED_SPEED 12
#define TRAINED_HIT_POINTS 120
#define OLD_SPEED 8
#define OLD_HIT_POINTS 150
#define SLASH_POINTS 40

using namespace std;


//Describes a charcter in the game
class Character {
private:
    Point location;
    int hitPoints;
    std::string name;
public:
    // Constructor 
    Character(string charName, const Point& startLocation, int startPoints) : name(charName), location(startLocation),  hitPoints(startPoints) {}
    Character(string charName, const Point& startLocation) : name(charName), location(startLocation),  hitPoints(0) {}
    Character(const Character& other) : name(other.getName()), location(other.location), hitPoints(other.hitPoints) {}

    // Destractur
    ~Character() {}

    //Get
    int getHitPoints() const {return hitPoints;} /**/
    string getName() const {return name;}
    Point getLocation() const {return location;}



    // Subtract points from hitPoints
    void hit(int points) {hitPoints -= points;}

    //

    bool isAlive() const {return hitPoints > 0;}

    //Distance from the given Character
    double distance(const Character& other) const {return location.distance(other.location);}

    /*
    * Format:
    * Name of the character (the name will start with: N for ninja, C for cowboy). if not alive the fornat will be: "N/C (name)"
    * Number of hitting points (only if hitPoints > 0)
    * Location
    */
    virtual string print() = 0;

    virtual int attack(Character*) = 0;
}


// Describes a charcter of type cowboy
class Cowboy : public Character{
private:
    int bullets;
public:
    // Constructor 
    Cowboy(string charName, const Point& startLocation) : Character(charName, startLocation, COWBOY_START_HIT_POINTS), bullets(COWBOY_START_BULLETS) {}
    Cowboy(const Cowboy& other) : Character(other.getName(), other.getLocation(), other.getHitPoints()), bullets(other.bullets) {}

    // Destractur
    ~Cowboy() {}

    // Shoot other and subtract 10 points from him
    void shoot(Character& other);

    bool hasbullets() {return bullets > 0;}

    // Reload bullets
    bool reload() {bullets += RELOAD;}

    string print();

    virtual int attack(Character* enemy); 
}


// Describes a charcter of type ninja
class Ninja : public Character{
protected:
    int speed;

public:
    // Constructor 
    Ninja(string charName, const Point& startLocation, int startHitPoints, int speed) : Character(charName, startLocation, startHitPoints), speed(speed) {}
    Ninja(const Ninja& other) : Character(other), speed(other.speed) {}

    // Destructur
    ~Ninja() {}

    void move(const Character&);

    // slash another character (only if distance <= 1)
    void slash(const Character&);

    string print();

    int attack(Character*);
}
class y {

}

class YoungNinja : public Ninja {
public:
    YoungNinja(string charName, const Point& startLocation) : Ninja(charName, startLocation, YOUNG_HIT_POINTS, YUONG_SPEED) {}
    YoungNinja(const YoungNinja& other) : Ninja(other) {}
    ~YoungNinja() {}
}

class TrainedNinja : public Ninja {
public:
    TrainedNinja(string charName, const Point& startLocation) : Ninja(charName, startLocation, TRAINED_HIT_POINTS, TRAINED_SPEED) {}
    TrainedNinja(const TrainedNinja& other) : Ninja(other) {}
    ~TrainedNinja() {}
}

class OldNinja : public Ninja {
public:
    OldNinja(string charName, const Point& startLocation) : Ninja(charName, startLocation, OLD_HIT_POINTS, OLD_SPEED) {}
    OldNinja(const OldNinja& other) : Ninja(other) {}
    ~OldNinja() {}
}