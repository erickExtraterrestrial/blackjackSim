#include "Card.hpp"

const Card CARD_FACES[13] = {Card("A", "Spades", 1),  Card("2", "Spades", 2),
                             Card("3", "Spades", 3), Card("4", "Spades", 4),
                             Card("5", "Spades", 5), Card("6", "Spades", 6),
                             Card("7", "Spades", 7), Card("8", "Spades", 8),
                             Card("9", "Spades", 9), Card("10", "Spades", 10),
                             Card("J", "Spades", 10), Card("Q", "Spades", 10),
                             Card("K", "Spades", 10)};

const string SUITS[4] = {"Spades", "Hearts", "Diamonds", "Clubs"};

void initArray(Card cards[], int size);
void checkAce(Card cards[], int counter);
void checkCondition(int points, int d_points);
void checkValue(int points, bool& run);

int main()
{
    srand(time(NULL));

    int size = 52, place = 0, totalValue = 0, dealerTotal = 0;
    bool running = true;
    char choice;
    Card cards[size];
    initArray(cards, size);

    // shuffling
    for (int c = 0; c < size; c++) //lol
    {
        int r = rand() % size;
        cards[c] = cards[r];
        swap(c, r);
    }

    cout << "/// BLACKJACK SIM ///\nYOUR CARDS:\n";

    for (int i = 0; i < 2; i++)
    {
        checkAce(cards, place);
        cards[place].print();
        totalValue += cards[place].getValue();
        place++;
        cout << endl;
    }

    cout << endl << "DEALER'S:\n";

    for (int i = 0; i < 2; i++)
    {
        if (i > 0)
        {
            cards[place].print();
        }
        else
        {
            cout << "??? of ???";
        }
        if (cards[place].getFaceValue() == "A")
        {
            cards[place].setValue(11);
        }
        dealerTotal += cards[place].getValue();
        place++;
        cout << endl;
    }

    cout << endl;

    checkValue(totalValue, running);

    while (running)
    {
        cout << "Hit or Stand? (H/S): ";
        cin >> choice;
        switch(toupper(choice))
        {
            case 'H':
                checkAce(cards, place);
                cards[place].print();
                totalValue += cards[place].getValue();
                place++;
                cout << endl;
                checkValue(totalValue, running);
                break;
            case 'S':
                running = false;
                break;
            default:
                cout << "Invalid selection, try again...\n";
                break;
        }

    }
    cout << "The dealer's total is " << dealerTotal << "...\n";
    cout << "Your total is " << totalValue << ".\n";
    checkCondition(totalValue, dealerTotal);
    return 0;
}

void checkValue(int points, bool& run)
{
    if (points >= 21)
    {
        run = false;
    }
}

void checkCondition(int points, int d_points)
{
    if (points == d_points)
    {
        cout << "TIE!\n";
    }
    else if (points > d_points && points < 21)
    {
        cout << "WINNER!\n";
    }
    else if (points > 21 || d_points > points)
    {
        cout << "You Lost :(\n";
    }
    else if (points == 21)
    {
        cout << "TOP WINNER!!!\n";
    }
}

void checkAce(Card cards[], int counter)
{
    int choice;
    if (cards[counter].getFaceValue() == "A")
    {
        cout << "What value would you like for A? 1 or 11?\n";
        cin >> choice;
        assert(choice == 1 || choice == 11);
        cards[counter].setValue(choice);
    }
}

void initArray(Card cards[], int size)
{
    int counter = 0;
    for(int i = 0; i < size; i++)
    {
        if(i >= 0 && i <= 12)
        {
            cards[i] = CARD_FACES[counter % 13];
        }
        else if(i >= 13 && i <= 25)
        {
            cards[i] = CARD_FACES[counter % 13];
            cards[i].setSuit(SUITS[1]);
        }
        else if(i >= 26 && i <= 38)
        {
            cards[i] = CARD_FACES[counter % 13];
            cards[i].setSuit(SUITS[2]);
        }
        else
        {
            cards[i] = CARD_FACES[counter % 13];
            cards[i].setSuit(SUITS[3]);
        }
        counter++;
    }
}
