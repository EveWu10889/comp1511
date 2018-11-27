#include "Game.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <assert.h>

#define CARD_FIRST 28


struct _node {
    Card card;
    struct _node *next;
};

typedef struct _node *Node;

struct _player {
    Node cards;
    //int discard;
    struct _player *next;
};

typedef struct _player *Player;

static Player newPlayer();

struct _move {
    playerMove move;
    struct _move *next;
};

typedef struct _move *Move;

struct _game{
    Node deck;
    Player players;
    //Player player0;
    //Player player1;
    //Player player2;
    //Player player3;
    Node discard;
    Move moves;
    int Values[16];
    int Colors[5];
    int Suits[5];

    int cardNum;
    int current_Player;
    int current_Turn;
    int num_Turns;
    int current_TurnMoves;
    int getNumberOf_TwoCardsAtTop;
    int get_CurrentColor;
    int get_PreviousTurnPlayer;
    int get_TopDiscardTurnNumber;
    int get_ActiveDrawTwos;
    int hand_CardCount;
    int game_Winner;

};

static int cardInHand (Game game, playerMove move);
//static int playerAction (Game game, playerMove move);
//static int testTwo (Game game, playerMove move);
static int isSameCard (Game game, playerMove move);
static int check_Move (Game game, playerMove move);
static Node reverseCard(Node reverseHead);

// Create a new game engine.
//
// This creates a game with a deck of the given size
// and the value, color, and suit of each card to be taken from
// each of the arrays in order.
//
// Your game will always have 4 players. Each player starts with a hand
// of 7 cards. The first card from the deck is given to player 0, the
// second to player 1, the third to player 2, the fourth to player 3,
// the fifth to player 0, and so on until each player has 7 cards.
Game newGame(int deckSize, value values[], color colors[], suit suits[]) {
    Game game = malloc (sizeof(struct _game));
    game->deck = NULL;
    game->players = NULL;

    for(int k = 0; k < 16; k++) {
    	game->Values[k] = 0;
    }
    
    for (int m = 0; m < 5; m++) {
    	game->Colors[m] = 0;
    	game->Suits[m] = 0;
    }
    

    game->cardNum = deckSize;
    game->current_Player = 0;
    game->current_Turn = 0;
    game->num_Turns = 1;
    game->current_TurnMoves = 0;
    game->getNumberOf_TwoCardsAtTop = 0;
    game->get_CurrentColor = 0;
    game->get_PreviousTurnPlayer = -1;
    game->get_TopDiscardTurnNumber = -1;
    game->get_ActiveDrawTwos = 0;
    game->hand_CardCount = 0;
    game->game_Winner = NOT_FINISHED;


    Player player0 = newPlayer();
    Player player1 = newPlayer();
    Player player2 = newPlayer();
    Player player3 = newPlayer();

    player0->next = player1;
    player1->next = player2;
    player2->next = player3;
    player3->next = NULL;

    game->players = player0;

    //game->player1 = NULL;
    //game->player2 = NULL;
    //game->palyer3 = NULL;
    game->discard = NULL;

    game->deck = malloc(sizeof(struct _node));
    game->deck->card = newCard(values[0], colors[0], suits[0]);

    game->Values[values[0]]++;
    game->Colors[colors[0]]++;
    game->Suits[suits[0]]++;
    //game->player0 = malloc(sizeof(struct _node));
    //game->deck = malloc(sizeof(struct _node));
    //game->deck = malloc(sizeof(struct _node));
    //game->deck = malloc(sizeof(struct _node));
    game->discard = malloc(sizeof(struct _node));

    Node curr0 = game->deck;
    for (int i = 1; i < deckSize; i++) {
        Card new_Card = newCard(values[i], colors[i], suits[i]);
        
        game->Values[values[i]]++;
    	game->Colors[colors[i]]++;
    	game->Suits[suits[i]]++;

        Node temp = malloc (sizeof(struct _node));
        temp->card = new_Card;
        temp->next = NULL;
        curr0->next = temp;
        curr0 = curr0->next;
    }

    Node curr1 = game->deck;
    Player currPlayer = game->players;
    //currPlayer = player0;
    for (int j = 0; j < CARD_FIRST; j++) {
        game->deck = game->deck->next;
        curr1->next = currPlayer->cards;
        currPlayer->cards = curr1;
        curr1 = game->deck;
        currPlayer = currPlayer->next;
        if (currPlayer == NULL ) {
            currPlayer = game->players;
        }
    }

    Node curr2 = game->deck;
    game->deck = game->deck->next;
    curr2->next = NULL;
    game->discard = curr2;

    /*game moves = malloc (sizeof(struct _move));
    assert(moves != NULL);*/


    return game;
}

// Destroy an existing game.
//
// This should free all existing memory used in the game including
// allocations for players and cards.
void destroyGame(Game game) {
    Node tem;
    while (game->discard != NULL) {
        tem = game->discard;
        game->discard = game->discard->next;
        destroyCard(tem->card);
        free(tem);
    }

    while (game->deck != NULL) {
        tem = game->deck;
        game->deck = game->deck->next;
        destroyCard(tem->card);
        free(tem);
    }

    Player tem_Player;
    while (game->players != NULL) {
        tem_Player = game->players;
        game->players = game->players->next;
        while (tem_Player->cards != NULL) {
            Node temp = tem_Player->cards;
            tem_Player->cards = tem_Player->cards->next;
            destroyCard(temp->card);
            free(temp);
        }  
        free(tem_Player);
    }
    
    while (game->discard != NULL) {
        tem = game->discard;
        game->discard = game->discard->next;
        destroyCard(tem->card);
        free(tem);
    }

    destroyCard(tem->card);
    free(tem);
}

// The following functions can be used by players to discover
// information about the state of the game.

// Get the number of cards that were in the initial deck.
int numCards(Game game) {
    return game->cardNum;
}

// Get the number of cards in the initial deck of a particular
// suit.
int numOfSuit(Game game, suit suit) {
    return game->Suits[suit];
}

// Get the number of cards in the initial deck of a particular color.
int numOfColor(Game game, color color) {
	return game->Colors[color];
}

// Get the number of cards in the initial deck of a particular value.
int numOfValue(Game game, value value) {
	return game->Values[value];
}

// Get the number of the player whose turn it is.
int currentPlayer(Game game) {
	return game->current_Player;
}

// Get the current turn number.
//
// The turn number increases after a player ends their turn.
// The turn number should start at 0 once the game has started.
int currentTurn(Game game) {
	return game->current_Turn;
}


// Get the card that is on the top of the discard pile.
Card topDiscard(Game game) {
	return game->discard->card;
}

// This function returns the number of turns that have occurred in the
// game so far including the current turn.
// (i.e. on turn 0 of the game, this should return 1, as there has been
//       1 turn so far including the current turn.)
int numTurns(Game game) {
	return game->num_Turns;
}

// Get the number of moves (actions) that happened on the current turn.
//
// A turn may consist of multiple moves (actions) such as drawing cards,
// playing cards, and ending the turn.
int currentTurnMoves(Game game) {
	return game->current_TurnMoves;
}


// Get the number of consecutive cards with value "2" at the top of the 
// discard pile.
// If the value of the top of the discard pile is not "2", the function will 
// return zero. 
int getNumberOfTwoCardsAtTop(Game game) {
    return game->getNumberOf_TwoCardsAtTop;
}


// If the last player played a card with value "D" and declared a color, 
// the following function returns that declared color as the current color. 
// For all other cases, the function returns the color of the card at 
// the top of the discard pile. 
int getCurrentColor(Game game) {
	return game->get_CurrentColor;
}

// The function returns the player who played the previous turn.
// For example, if player 1 plays "A" in turn 12, player 3 will 
// play next turn 13. During turn 13, the following function will 
// return 1 (for player 1 who played the previous turn 12).
// If the current turn is the first turn (turn 0), the function should 
// return -1.
int getPreviousTurnPlayer(Game game) {
	return game->get_PreviousTurnPlayer;
}


// Get the turn number that played the card that is on the top of 
// the discard pile.
int getTopDiscardTurnNumber(Game game) {
	return game->get_TopDiscardTurnNumber;
}

// Get the number of "active" cards with value "2" at the top of the 
// discard pile. 
// For example, say in turn-5 player-1 plays "2", as a result of this, 
// the function should return 1. Let's say in turn-6 player-2 
// draws two cards and is unable to play a card. 
// At the start of turn-7, the function should return zero.
// If the value of the top of the discard pile is not "2", the function
// should return zero.
int getActiveDrawTwos(Game game) {
    /*
    Card card_Two = topDiscard(game);
    if (cardValue(card_Two) == DRAW_TWO) {
        if (cardValue(topDiscard(game->discard)) != A && ){
            game->get_ActiveDrawTwos = 1;
        } else {
            game->get_ActiveDrawTwos = 0;
        }
        
    } else {
        game->get_ActiveDrawTwos = 0;
    } */
	return game->get_ActiveDrawTwos;
}


// Get the number of cards in the current player's hand.
int handCardCount(Game game) {
	return game->hand_CardCount;
}

// View a card from the current player's own hand.
//
// The player should not need to free() this card,
// so you should not allocate or clone an existing card
// but give a reference to an existing card.

// If no such card exists, the function returns NULL.
Card handCard(Game game, int card) {
	Player curr_player = game->players;
	int count = 0;
	if (game->current_Player == 0) {
		curr_player = game->players;
	}
	else {
		for (int i = 0; i < game->current_Player; i++) {
			curr_player = curr_player->next;
		}
	}
	
	
	Node curr = curr_player->cards;

	if (card == 0) {
		return curr->card;
	} else {
		for (int j = 0; j < card; j++) {
			if (curr != NULL) {
				curr = curr->next;
				count ++;
			}	
		}
		if (count == card) {
			return curr->card;
		} else {
			return NULL;
		}
	}	
}

// Check if a given move is valid.
//
// If the last player played a 2 (DRAW_TWO),
// the next player must either play a 2
// or draw 2 cards.

// If the last player has NOT played a 2, 
// the player must play a card that is either a ZERO
// or that has the same color, value, or suit as the card on the top
// of the discard pile (adjust color for a case where the 
//   previous player has played a "D").
//
// If the player plays an "A", the next player's turn is skipped.
// If the player plays a "D", they must also state which color
// the next player's discarded card should be.
//
// A player can only play cards from their hand.
// A player may choose to draw a card instead of discarding a card.
// A player must draw a card if they are unable to discard a card.
//
// This check should verify that:
// * If a card is played, that card is from the player's hand, and matches 
//   the top card on the discard pile (adjust color for a case where the 
//   previous player has played a "D"), AND the player has not already
//   played a card during their turn.
// * If a DRAW_TWO was played, the player drew the appropriate number of cards.
// * If the player draws a card, either they have not yet drawn a card
//   during this turn OR a DRAW_TWO was played in the previous turn,
//   AND the player has not yet drawn the required number of cards.
//
// * The player has either played at least one card, or drawn at least
//   one card, before playing the END_TURN action.   

int isValidMove(Game game, playerMove move) {
    //END_TURN
    if (check_Move(game, move) == TRUE) {
       if (move.action == END_TURN) {
            return TRUE;
        } else  {
            return FALSE;
        } 
    } else {
        return FALSE;
    }
}


// ---------------------------------------------------------
// The following functions must NOT be called by a player
// You can use the following functions to test your Game ADT 
// ---------------------------------------------------------

// Play the given action for the current player
//
// If the player makes the END_TURN move, their turn ends,
// and it becomes the turn of the next player.
//
// This should _not_ be called by the player AI.
void playMove(Game game, playerMove move) {
    Player curr_player;
    if (game->current_Player == 0) {
        curr_player = game->players;
    } else {
        for (int i = 0; i < game->current_Player; i++) {
            curr_player = curr_player->next;
        }
    }

    Node countCard = curr_player->cards;
    while (countCard != NULL) {
        game->hand_CardCount ++;
        countCard = countCard->next;
    }


    if (move.action == PLAY_CARD) {
        // find the card in the players hand
        // remove it
        // attach it to discard pile
        Node currCard = curr_player->cards;
        Node prevCard = NULL;
        if (move.card != currCard->card) {
            prevCard = currCard;
            currCard = currCard->next;
        }
        prevCard->next = currCard->next;
        currCard->next = game->discard;
        game->discard = currCard;
        game->current_TurnMoves++;
        game->get_TopDiscardTurnNumber++;

        if (cardValue(move.card) == D) {
            game->get_CurrentColor = move.nextColor;
        }

        if (cardValue(move.card) != A) {
            game->current_Player = (game->current_Player + 2) % 4;
        } else {
            game->current_Player = (game->current_Player + 1) % 4;
        }

        game->moves->move = move;
        game->moves->next = NULL;

        game->hand_CardCount--;

        //check winner
        if (game->hand_CardCount == 0) {
            game->game_Winner = game->current_Player;
        }
        
    } else if (move.action == DRAW_CARD) {
        // take card from top of deck
        // move into players hand
        while (game->deck != NULL) {
            Node currDeckCard = game->deck;
            game->deck = game->deck->next;
            currDeckCard->next = curr_player->cards;
            curr_player->cards = currDeckCard;
        }

        if (game->deck == NULL) {
            game->game_Winner = NO_WINNER;
        }
        
        game->current_Player = (game->current_Player + 1) % 4;

        Move currMove = malloc(sizeof (struct _move));
        currMove->move = move;
        currMove->next = NULL;

        if (game->moves == NULL) {
            game->moves = currMove;
        } else {
            game->moves->next = currMove;
        }

        Move countMove = game->moves;
        while (countMove != NULL) {
            game->current_TurnMoves++;
            countMove = countMove->next;
        }
        
        game->hand_CardCount += game->current_TurnMoves;

        if (game->deck == NULL) {
            if(game->discard->next == NULL) {
                game->game_Winner = NO_WINNER;
            } else {
                game->deck = reverseCard(game->discard->next);
            }
        }
       
    } else if (move.action == END_TURN) {
        game->current_Turn++;
        game->num_Turns++;
        game->current_TurnMoves++;

        Move temMove = game->moves;
        if (temMove->move.action == PLAY_CARD &&
            cardValue(topDiscard(game)) == DRAW_TWO) {
                game->get_ActiveDrawTwos = 1;
        } else if (temMove->move.action == DRAW_CARD){
            if (temMove->next != NULL) {
                game->get_ActiveDrawTwos = 0;
            }
        }

        while (game->moves != NULL) {
            Move clearMove = game->moves;
            game->moves = game->moves->next;
            destroyCard(game->moves->move.card);
            free(clearMove);
        }

        Node currDeck = game->deck; 
        if (cardValue(currDeck->card) == 2) {
            game->getNumberOf_TwoCardsAtTop++;
            currDeck = currDeck->next;
        } 
        if (cardValue(move.card) != D) {
                game->get_CurrentColor = cardColor(game->discard->card);
        }

        if(game->num_Turns == 1) {
            game->get_PreviousTurnPlayer = -1;
        } else {
            if (cardValue(topDiscard(game)) == A){
                game->get_PreviousTurnPlayer = 
                (game->get_PreviousTurnPlayer - 2 + 4) % 4;
            } else {
                game->get_PreviousTurnPlayer = 
                (game->get_PreviousTurnPlayer - 1 + 4) % 4;
            }
        }

    }
    
    
    

    // add move to linked list
    
}

// Check the game winner.
//
// Returns NOT_FINISHED if the game has not yet finished,
// 0-3, representing which player has won the game, or
// NO_WINNER if the game has ended but there was no winner.
int gameWinner(Game game) {
	return game->game_Winner;
}


// Get nth card from the deck, n=0 means top card from deck
// If no such card exists, the function returns NULL.
Card getDeckCard (Game game, int n) {
	Node curr = game->deck;
	int count = 0;

	if (n == 0) {
		return curr->card;
	} 

	for (int i = 0; i < n; i++) {
		if (curr != NULL) {
			curr = curr->next;
			count ++;
		}
	}
	
	if(n == count) {
		return curr->card;
	} else {
		return NULL;
	}
	
}

// Get nth card from the discard pile, n=0 means top card from discard pile
// If no such card exists, the function returns NULL.
Card getDiscardPileCard (Game game, int n) {
	Node curr = game->discard;
	int count = 0;

	if (n == 0) {
		return curr->card;
	} 

	for (int i = 0; i < n; i++) {
		if (curr != NULL) {
			curr = curr->next;
			count ++;
		}
	}
	
	if(n == count) {
		return curr->card;
	} else {
		return NULL;
	}
}

// Get nth card from the hand of a player p.
// If no such card exists, the function returns NULL.
Card getHandCard (Game game, int player, int n) {
	Player curr_player = game->players;
	int count = 0;
	if (player == 0) {
		curr_player = game->players;
	} else {
		for (int i = 0; i < player; i++) {
			curr_player = curr_player->next;
		}
	}

	Node curr = curr_player->cards;

	if (n == 0) {
		return curr->card;
	} else {
		for (int j = 0; j < n; j++) {
			if (curr != NULL) {
				curr = curr->next;
				count ++;
			}	
		}
		if (count == n) {
			return curr->card;
		} else {
			return NULL;
		}
	}		
}

// Get the number of cards in a given player's hand.
int playerCardCount(Game game, int player) {
	Player curr_player = game->players;
	int count = 0;
	if (player == 0) {
		curr_player = game->players;
	} else {
		for (int i = 0; i < player; i++) {
			curr_player = curr_player->next;
		}
	}

	while (curr_player->cards != NULL) {
		count++;
		curr_player->cards = curr_player->cards->next;
	}

	return count;
}

// Get the number of points for a given player.
// Player should be between 0 and 3.
//
// The number of points is always equal to
// the sum of the values for all the cards in a player's hand.
// This should return this number of points at any point in the game.
int playerPoints(Game game, int player) {
	int sum = 0;
	Player curr_player = game->players;
	if (player == 0) {
		curr_player = game->players;
	} else {
		for (int i = 0; i < player; i++) {
			curr_player = curr_player->next;
		}
	}

	while (curr_player->cards != NULL) {
		sum += cardValue(curr_player->cards->card);
		curr_player->cards = curr_player->cards->next;
	}

	return sum;
}

static int cardInHand (Game game, playerMove move) {
    Player curr_player;
    if (game->current_Player == 0) {
        curr_player = game->players;
    } else {
        for (int i = 0; i < game->current_Player; i++) {
            curr_player = curr_player->next;
        }
    }

    Node curr_Card = curr_player->cards;

    while (curr_Card != NULL) {
        if(move.card != curr_Card->card) {
            return FALSE;
        }
        curr_Card = curr_Card->next;
    }
    return TRUE;
}

static int isSameCard (Game game, playerMove move) {
    Card c = topDiscard (game);
    if (cardColor(c) == cardColor(move.card) &&
        cardSuit(c) == cardSuit(move.card) &&
        cardValue(c) == cardValue(move.card)) {
            return TRUE;
    } else {
        return FALSE;
    }
}

static int check_Move (Game game, playerMove move) {
    if (move.action == PLAY_CARD) {
        if (game->get_ActiveDrawTwos == 1) {
            if (cardValue(move.card) == DRAW_TWO &&
                cardInHand(game, move)) {
                return TRUE;
            } else {
                return FALSE;
            }
        } else {
            cardInHand(game, move);
            isSameCard(game, move);
        }
    } else if (move.action == DRAW_CARD) {
        return TRUE;
    }
    return FALSE;
}

static Player newPlayer() {
        Player new = malloc(sizeof(struct _player));
        assert(new != NULL);
        new->cards = NULL;
        //new->discard = FALSE;
        new->next = NULL;
        return new;
}

static Node reverseCard(Node reverseHead) {
    if (reverseHead == NULL || reverseHead->next == NULL) {
        return reverseHead;
    } else {
        Node newTail = reverseHead->next;
        Node newHead = reverseCard(reverseHead->next);
        newTail->next = reverseHead;
        reverseHead->next = NULL;
        return newHead;
    }
}
