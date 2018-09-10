#include "gamestate.h"

GameState initialize(int nlines, int ncolumns){
    GameState state;
    state.nlines = nlines;
    state.ncolumns = ncolumns;
    state.activePoints = new Point[nlines*ncolumns];
    state.qtdActivePoints = 0;
    return state;
}

bool isValidState(GameState state){
  for(int i = 0; i < 4; i++){
    for(int k = 0; k < qtdActivePoints; k++){
      if(isEqual(state.nextTetromino.points[i], state.activePoints[k])) return false;
    }
  }
    return true;
}

GameState moveDown(GameState state){
    GameState nextState;

    return nextState;
}

GameState moveLeft(GameState state){
    GameState nextState;

    return nextState;
}
GameState moveRight(GameState state){
    GameState nextState;

    return nextState;
}
GameState rotateClockwise(GameState state){
    GameState nextState;

    return nextState;
}
GameState rotateAnticlockwise(GameState state){
    GameState nextState;

    return nextState;
}

bool isOver(GameState state){
    return true;
}

GameState simplify(GameState state){
    GameState nextState;

    return nextState;
}
