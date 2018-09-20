#include "gamestate.h"

GameState initialize(int nlines, int ncolumns){
    GameState state;
    state.nlines = nlines;
    state.ncolumns = ncolumns;
    state.activePoints = new Point[nlines*ncolumns];
    state.qtdActivePoints = 0;
    state.currentTetromino = getRandomTetromino();
    state.nextTetromino = getRandomTetromino();
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
    cpyActGameState.activePoints = new Point[nlines*ncolumns];
    for(int i = 0; i < qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
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
    cpyActGameState.activePoints = new Point[nlines*ncolumns];
    for(int i = 0; i < qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
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
    cpyActGameState.activePoints = new Point[nlines*ncolumns];
    for(int i = 0; i < qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
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
    cpyActGameState.activePoints = new Point[nlines*ncolumns];
    for(int i = 0; i < qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
    }
    nextState.qtdActivePoints = state.qtdActivePoints;
    nextState.currentTetromino = rotateClockwise(state.currentTetromino);
    nextState.nextTetromino = copyTetromino(state.nextTetromino);
    return nextState;
}
}

GameState rotateAnticlockwise(GameState state){
    GameState nextState;
    nextState.nlines = state.nlines;
    nextState.ncolumns = state.ncolumns;
    cpyActGameState.activePoints = new Point[nlines*ncolumns];
    for(int i = 0; i < qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
    }
    nextState.qtdActivePoints = state.qtdActivePoints;
    nextState.currentTetromino = rotateAnticlockwise(state.currentTetromino);
    nextState.nextTetromino = copyTetromino(state.nextTetromino);
    return nextState;
}


GameState copyGameState(GameState state){
    GameState cpyActGameState;
    cpyActGameState.nlines = state.nlines;
    cpyActGameState.ncolumns = state.ncolumns;
    cpyActGameState.qtdActivePoints = state.qtdActivePoints;
    cpyActGameState.currentTetromino = copyTetromino(state.currentTetromino);
    cpyActGameState.nextTetromino = copyTetromino(state.nextTetromino);
    cpyActGameState.activePoints = new Point[nlines*ncolumns];
    for(int i = 0; i < qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
    }
    return cpyActGameState;
}

bool isOver(GameState state){
    bool isover = false;
    bool running = 1;
    for(int i = 0; i < 4 && running; i++){
        if(state.currentTetromino.points[i].y == state.nlines){
            isover = true;
            break;
        }
        for(int j = 0; j < state.qtdActivePoints; j++){
            if(state.currentTetromino.points[i].y == state.activePoints[j].y){
                isover = true;
                running = false;
                break;
            }
        }
    }
    return isover;
}

GameState simplify(GameState state){
    GameState newState;
    return newState;
}
