#include "player.h"

playerMove decideMove(Game game) {
	playerMove move;
	move.action = END_TURN;
	if(isValidMove(game, move) == FALSE) {
		move.action = PLAY_CARD;
	} else {
		return move;
	}

	int count = handCardCount(game);
	if (count != 0) {
		for(int i = 1; i <= count; i++) {
			Card curr_card = handCard(game, i);
			move.card = curr_card;
			if (isValidMove(game, move)) {
				return move;
			}
		}
	}

	move.action = DRAW_CARD;
	return move;
}


