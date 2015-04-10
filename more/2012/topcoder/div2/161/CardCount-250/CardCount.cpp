#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CardCount{
public:
  vector<string> dealHands(int numPlayers, string deck){
    int aprox = deck.size()/numPlayers;
    vector<string> players(numPlayers, "");
    
    for( int i = 0; i < aprox*numPlayers; ++i )
      players[i%numPlayers] += deck[i];
      
    return players;
  }
};