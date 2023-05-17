#pragma once
/**
* @author: Elad Shoham, 205439649
*/

#include <iostream>
#include <string>
#include <cmath>
#include "Character.hpp"

using namespace std;

class Team {
private:
    Cowboy** cowboys;
    Ninja** ninjas;
    int numOfMembers; //including the leader
    int numOfNinjas;
    int alive;
    Character* leader;
public:
    Team(Character* lead) : leader(lead), numOfMembers(1), numOfNinjas(0), alive(0) {
        cowboys = new Cowboy*[10];
        ninjas = new Ninja*[10];
    }

    ~Team() {
        delete leader;

        for (int i = 0; i < (numOfMembers - numOfNinjas - 1); i++) {
            delete cowboys[i];
        }
        delete[] cowboys;

        for (int i = 0; i < numOfNinjas; i++) {
            delete ninjas[i];
        }
        delete[] ninjas;
    }

    virtual void add(Character* cha);

    // return 1 if the other tream is still alive, 0 otherwize
    virtual void attack(Team* enemy);

    string print() const;

    int stillAlive() {return numOfMembers;}

protected:
    int getNOM() const {return numOfMembers;} // get Num Of Members
    int getNON() const {return numOfNinjas;}  // get Num Of Ninjas
    Character* getLeader() {return leader;}  // get Leader
    Cowboy** getCowboys() {return cowboys;}  // get Cowboys
    Ninja** getNinjas() {return ninjas;}  // get Ninjas
}



class Team2 : public Team {
private:
    char order[];  // To kep track of the order

public:
    Team2(Character* leader) : Team(leader) {};
    virtual void add(Character*);
    virtual void attack(Character*);

    ~Team2() {delete[] order;}

protected:
    char[] getOrder() {return order;}
}

class Team3 : public Team2 {

private:
    /* data */
public:

}
