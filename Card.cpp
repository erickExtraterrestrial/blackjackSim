#include "Card.hpp"

Card::Card()
{
    suit = "Spades";
    faceValue = "A";
    value = 1;
}
Card::Card(string faceValue, string suit, int value)
{
    setSuit(suit);
    setFaceValue(faceValue);
    setValue(value);
}
void Card::setSuit(string suit)
{
    assert(suit == "Spades" || suit == "Hearts" ||
           suit == "Diamonds" || suit == "Clubs");
    this->suit = suit;
}
void Card::setValue(int value)
{
    assert(1 <= value && value <= 11);
    this->value = value;
}
void Card::setFaceValue(string faceValue)
{
    assert(faceValue == "A" || faceValue == "2" ||
           faceValue == "3" || faceValue == "4" ||
           faceValue == "5" || faceValue == "6" ||
           faceValue == "7" || faceValue == "8" ||
           faceValue == "9" || faceValue == "10"||
           faceValue == "J" || faceValue == "Q" ||
           faceValue == "K");

    this->faceValue = faceValue;
}
void Card::print()const
{
    cout << getFaceValue() << " of " << getSuit();
}
