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
            if(isEqual(state.currentTetromino.points[i], state.activePoints[k])) return false;
        }
        if(currentTetromino.points[i].x < 0 || currentTetromino.points[i].x >= ncolumns) return false;
        if(currentTetromino.points[i].y < 0 || currentTetromino.points[i].x >= nlines) return false;
    }
    return true;
}

GameState moveDown(GameState state){
    GameState nextState;
    nextState.nlines = state.nlines;
    nextState.ncolumns = state.ncolumns;
    for(int i = 0; i < state.nlines * state.ncolumns ; i++){
        nextState.activePoints[i] = state.activePoints[i];
    }
    nextState.qtdActivePoints = state.qtdActivePoints;
    nextState.currentTetromino = moveDown(state.currentTetromino);
    nextState.nextTetromino = copyTetromino(state.nextTetromino);
    return nextState;
}

GameState moveLeft(GameState state){
    GameState nextState;
    nextState.nlines = state.nlines;
    nextState.ncolumns = state.ncolumns;
    for(int i = 0; i < state.nlines * state.ncolumns ; i++){
        nextState.activePoints[i] = state.activePoints[i];
    }
    nextState.qtdActivePoints = state.qtdActivePoints;
    nextState.currentTetromino = moveLeft(state.currentTetromino);
    nextState.nextTetromino = copyTetromino(state.nextTetromino);
    return nextState;
}
GameState moveRight(GameState state){
    GameState nextState;
    nextState.nlines = state.nlines;
    nextState.ncolumns = state.ncolumns;
    for(int i = 0; i < state.nlines * state.ncolumns ; i++){
        nextState.activePoints[i] = state.activePoints[i];
    }
    nextState.qtdActivePoints = state.qtdActivePoints;
    nextState.currentTetromino = moveRight(state.currentTetromino);
    nextState.nextTetromino = copyTetromino(state.nextTetromino);
    return nextState;
}
GameState rotateClockwise(GameState state){
    GameState nextState;
    nextState.nlines = state.nlines;
    nextState.ncolumns = state.ncolumns;
    for(int i = 0; i < state.nlines * state.ncolumns ; i++){
        nextState.activePoints[i] = state.activePoints[i];
    }
    nextState.qtdActivePoints = state.qtdActivePoints;
    nextState.currentTetromino = rotateClockwise(state.currentTetromino);
    nextState.nextTetromino = copyTetromino(state.nextTetromino);
    return nextState;
}
GameState rotateAnticlockwise(GameState state){
    GameState nextState;
    nextState.nlines = state.nlines;
    nextState.ncolumns = state.ncolumns;
    for(int i = 0; i < state.nlines * state.ncolumns ; i++){
        nextState.activePoints[i] = state.activePoints[i];
    }
    nextState.qtdActivePoints = state.qtdActivePoints;
    nextState.currentTetromino = rotateAnticlockwise(state.currentTetromino);
    nextState.nextTetromino = copyTetromino(state.nextTetromino);
    return nextState;
}

bool isOver(GameState state){
    return true;
}

GameState simplify(GameState state){
    GameState nextState;

    return nextState;
}
