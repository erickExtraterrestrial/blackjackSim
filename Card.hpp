#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <cassert>
#include <stdlib.h> // 'rand'
#include <time.h> // 'time'

using namespace std;

class Card
{
    public:
        //Constructors
        Card();
        Card(string suit, string faceValue, int value);
        //Getters
        string getSuit()const{return suit;}
        string getFaceValue()const{return faceValue;}
        int getValue()const{return value;}
        //Setters
        void setSuit(string suit);
        void setFaceValue(string faceValue);
        void setValue(int value);
        //Other methods
        void print()const;

    private:
        string suit, faceValue;
        int value;

};

#endif // CARD_H
