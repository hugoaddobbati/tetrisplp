#include "gamestate.h"
#include "tetromino.h"

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
        for(int k = 0; k < state.qtdActivePoints; k++){
            if(isEqual(state.currentTetromino.points[i], state.activePoints[k])) return false;
        }
        if((state.currentTetromino.points[i].x) < 0 || (state.currentTetromino.points[i].x >= state.ncolumns)) return false;
        if((state.currentTetromino.points[i].y < 0) || (state.currentTetromino.points[i].y >= state.nlines)) return false;
    }
    return true;
}

GameState moveDown(GameState state){
    GameState cpyActGameState;
    cpyActGameState.nlines = state.nlines;
    cpyActGameState.ncolumns = state.ncolumns;
    cpyActGameState.activePoints = new Point[state.nlines*state.ncolumns];
    for(int i = 0; i < state.qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
    }
    cpyActGameState.qtdActivePoints = state.qtdActivePoints;
    cpyActGameState.currentTetromino = moveDown(state.currentTetromino);
    cpyActGameState.nextTetromino = copyTetro(state.nextTetromino);
    return cpyActGameState;
}

GameState moveLeft(GameState state){
    GameState cpyActGameState;
    cpyActGameState.nlines = state.nlines;
    cpyActGameState.ncolumns = state.ncolumns;
    cpyActGameState.activePoints = new Point[state.nlines*state.ncolumns];
    for(int i = 0; i < state.qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
    }
    cpyActGameState.qtdActivePoints = state.qtdActivePoints;
    cpyActGameState.currentTetromino = moveLeft(state.currentTetromino);
    cpyActGameState.nextTetromino = copyTetro(state.nextTetromino);
    return cpyActGameState;
}

GameState moveRight(GameState state){
    GameState cpyActGameState;
    cpyActGameState.nlines = state.nlines;
    cpyActGameState.ncolumns = state.ncolumns;
    cpyActGameState.activePoints = new Point[state.nlines*state.ncolumns];
    for(int i = 0; i < state.qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
    }
    cpyActGameState.qtdActivePoints = state.qtdActivePoints;
    cpyActGameState.currentTetromino = moveRight(state.currentTetromino);
    cpyActGameState.nextTetromino = copyTetro(state.nextTetromino);
    return cpyActGameState;
}


GameState rotateClockwise(GameState state){
    GameState cpyActGameState;
    cpyActGameState.nlines = state.nlines;
    cpyActGameState.ncolumns = state.ncolumns;
    cpyActGameState.activePoints = new Point[state.nlines*state.ncolumns];
    for(int i = 0; i < state.qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
    }
    cpyActGameState.qtdActivePoints = state.qtdActivePoints;
    cpyActGameState.currentTetromino = rotateClockwise(state.currentTetromino);
    cpyActGameState.nextTetromino = copyTetro(state.nextTetromino);
    return cpyActGameState;
}


GameState rotateAnticlockwise(GameState state){
    GameState cpyActGameState;
    cpyActGameState.nlines = state.nlines;
    cpyActGameState.ncolumns = state.ncolumns;
    cpyActGameState.activePoints = new Point[state.nlines*state.ncolumns];
    for(int i = 0; i < state.qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
    }
    cpyActGameState.qtdActivePoints = state.qtdActivePoints;
    cpyActGameState.currentTetromino = rotateAnticlockwise(state.currentTetromino);
    cpyActGameState.nextTetromino = copyTetro(state.nextTetromino);
    return cpyActGameState;
}


GameState copyGameState(GameState state){
    GameState cpyActGameState;
    cpyActGameState.nlines = state.nlines;
    cpyActGameState.ncolumns = state.ncolumns;
    cpyActGameState.qtdActivePoints = state.qtdActivePoints;
    cpyActGameState.currentTetromino = copyTetro(state.currentTetromino);
    cpyActGameState.nextTetromino = copyTetro(state.nextTetromino);
    cpyActGameState.activePoints = new Point[state.nlines*state.ncolumns];
    for(int i = 0; i < state.qtdActivePoints; i++){
        cpyActGameState.activePoints[i] = state.activePoints[i];
    }
    return cpyActGameState;
}

GameState appendPiece(GameState state){
  GameState newState = copyGameState(state);
  for(int i = 0; i < 4; i++){
    newState.activePoints[newState.qtdActivePoints++] = state.currentTetromino.points[i];
  }
  return newState;
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
            if(state.currentTetromino.points[i].y == state.activePoints[j].y && state.currentTetromino.points[i].x == state.activePoints[j].x){
                isover = true;
                running = false;
                break;
            }
        }
    }
    return isover;
}

GameState simplifyLine(GameState state, int line){
    int k = 0;
    Point * newPoints = new Point[state.nlines*state.ncolumns];
    int qtdActiveTemp = 0;
    for(int j = 0; j < state.qtdActivePoints; j++){
      if(state.activePoints[j].y > line){
        newPoints[qtdActiveTemp] = state.activePoints[j];
        qtdActiveTemp++;
       }
      else if(state.activePoints[j].y < line){
        newPoints[qtdActiveTemp] = state.activePoints[j];
        newPoints[qtdActiveTemp].y += 1;
        qtdActiveTemp++;
      }
    }
    for(int m = 0; m < qtdActiveTemp; m++){
      state.activePoints[m] = newPoints[m];
    }
    state.qtdActivePoints = qtdActiveTemp;
    return state;
}

GameState simplify(GameState state, int &score, int & powerUpBars){
    GameState newState = copyGameState(state);
    int lines = 0;
    int count[state.nlines];
    for(int i = 0; i < state.nlines; i++) count[i] = 0;
    for(int i = 0; i < state.qtdActivePoints; i++){
      count[state.activePoints[i].y]++;
    }
    for(int i = 0; i < state.nlines; i++){
      if(count[i] == state.ncolumns){
        state = simplifyLine(state, i);
        lines += 1;
      }
    }

    // for(int i = 0; i < state.nlines; i++){
    //   if(count[i] == state.ncolumns){
    //     lines += 1;
    //     int j = 0;
    //     for(int k = 0; k < state.qtdActivePoints; k++){
    //       if(state.activePoints[k].y < i){
    //         state.activePoints[k].y++;
    //         newState.activePoints[j++] = state.activePoints[k];
    //       }
    //       else if(state.activePoints[k].y > i){
    //         newState.activePoints[j++] = state.activePoints[k];
    //       }
    //     }
    //     state.qtdActivePoints -= state.ncolumns;
    //   }
    // }
    if(lines == 1) score += 50;
    if(lines == 2) score += 110;
    if(lines == 3) score += 180;
    if(lines == 4) score += 300;
    powerUpBars += lines;
    if(powerUpBars > 5)powerUpBars = 5;
    return state;
}
