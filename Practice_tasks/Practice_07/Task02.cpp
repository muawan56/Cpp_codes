#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Enum for card suits
enum Suit
{
    HEARTS,
    DIAMONDS,
    CLUBS,
    SPADES
};

// Class representing a playing card
class PlayingCard
{
public:
    PlayingCard(int value, Suit suit) : value(value), suit(suit) {}

    // Function to get string representation of the card
    std::string toString() const
    {
        std::string valueString;
        if (value >= 2 && value <= 10)
        {
            valueString = std::to_string(value);
        }
        else if (value == 11)
        {
            valueString = "Jack";
        }
        else if (value == 12)
        {
            valueString = "Queen";
        }
        else if (value == 13)
        {
            valueString = "King";
        }
        else if (value == 14)
        {
            valueString = "Ace";
        }

        std::string suitString;
        switch (suit)
        {
        case HEARTS:
            suitString = "Hearts";
            break;
        case DIAMONDS:
            suitString = "Diamonds";
            break;
        case CLUBS:
            suitString = "Clubs";
            break;
        case SPADES:
            suitString = "Spades";
            break;
        }

        return valueString + " of " + suitString;
    }

    // Function to check if two cards are equal
    bool operator==(const PlayingCard &other) const
    {
        return value == other.value && suit == other.suit;
    }

private:
    int value;
    Suit suit;
};

// Class representing a hand of playing cards
class Hand
{
public:
    Hand()
    {
        // Initialize random seed
        std::srand(std::time(0));

        // Fill the hand with random cards
        for (int i = 0; i < 5; ++i)
        {
            int value = rand() % 13 + 2; // Values 2 to 14 (Ace)
            Suit suit = static_cast<Suit>(rand() % 4);
            PlayingCard card(value, suit);

            // Check for duplicates
            while (findCard(card))
            {
                value = rand() % 13 + 2;
                suit = static_cast<Suit>(rand() % 4);
                card = PlayingCard(value, suit);
            }

            cards[i] = card;
        }
    }

    // Function to display the hand's values
    void display() const
    {
        for (int i = 0; i < 5; ++i)
        {
            std::cout << cards[i].toString() << std::endl;
        }
    }

private:
    PlayingCard cards[5];

    // Function to check if a card already exists in the hand
    bool findCard(const PlayingCard &card) const
    {
        for (int i = 0; i < 5; ++i)
        {
            if (cards[i] == card)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    // Declare a hand and display its values
    Hand hand;
    hand.display();

    return 0;
}
