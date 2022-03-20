#include "../stdutils/main.h"
#include "../positions/main.h"
#include "../icons/main.h"
#include "main.h"


bool isBlackPawnDiaogonalMovement(wchar_t chessBoard[N][N], Point* p1, Point* p2) {
    return !isFreePosition(chessBoard[p2->row][p2->col]) && (p1->row + p1->col - 2 == p2->row + p2->col || p1->row + p1->col == p2->row + p2->col) && (p1->row != p2->row && p1->col != p2->col);
}

bool isWhitePawnDiaogonalMovement(wchar_t chessBoard[N][N], Point* p1, Point* p2) {
    return !isFreePosition(chessBoard[p2->row][p2->col]) && (p1->row + p1->col + 2 == p2->row + p2->col || p1->row + p1->col == p2->row + p2->col) && (p1->row != p2->row && p1->col != p2->col);
}

bool isHorseMovement(Point* p1, Point* p2) {
    return 
        (p1->row == p2->row + 1 && p1->col == p2->col + 2) || 
        (p1->row == p2->row + 2 && p1->col == p2->col + 1) ||
        (p1->row == p2->row - 1 && p1->col == p2->col - 2) || 
        (p1->row == p2->row - 2 && p1->col == p2->col - 1) ||
        (p1->row == p2->row - 1 && p1->col == p2->col + 2) ||
        (p1->row == p2->row + 1 && p1->col == p2->col - 2) ||
        (p1->row == p2->row + 2 && p1->col == p2->col - 1) ||
        (p1->row == p2->row - 2 && p1->col == p2->col + 1);
};

bool isBishopMovement(Point* p1, Point* p2) {
    return ((p1->row + p1->col  - p2->row + p2->col) % 2 == 0) && (p1->row != p2->row && p1->col != p2->col);
}

bool isTowerMovement(Point* p1, Point* p2) {
    return 
        (p2->row > p1->row && p1->col == p2->col) ||
        (p1->row == p2->row && p1->col > p2->col) ||
        (p2->row < p1->row && p1->col == p2->col) ||
        (p1->row == p2->row && p1->col < p2->col);
}

bool isKingMovement(Point* p1, Point* p2) {
    return 
        isBishopMovement(p1, p2) ||
        isTowerMovement(p1, p2);
}

bool isQueenMovement(Point* p1, Point* p2) {
    return 
        (p1->row == p2->row - 1 && p1->col == p2->col) ||
        (p1->row == p2->row + 1 && p1->col == p2->col) ||
        (p1->row == p2->row && p1->col == p2->col - 1) ||
        (p1->row == p2->row && p1->col == p2->col + 1) ||
        (p1->row + p1->col - 2 == p2->row + p2->col && p1->row != p2->row && p1->col != p2->col) ||
        (p1->row + p1->col + 2 == p2->row + p2->col && p1->row != p2->row && p1->col != p2->col) ||
        (p1->row + p1->col == p2->row + p2->col && p1->row != p2->row && p1->col != p2->col);
}

bool move(wchar_t chessBoard[N][N], Point* p1, Point* p2) {
    const wchar_t 
		icon1 = chessBoard[p1->row][p1->col],	
		icon2 = chessBoard[p2->row][p2->col];
    if(!isFreePosition(icon2)) {
        wprintf(L"\nHai mangiato un %lc  %ls/a dell'avversario ! ; ", icon2, isBlack(chessBoard[p2->row][p2->col]) ? L"nero" : L"bianco");
        printIconStringName(icon2);
    }
    chessBoard[p2->row][p2->col] = icon1;
    chessBoard[p1->row][p1->col] = isEmptySquarePosition(p1) ? EMPTY_SQUARE : FILLED_SQUARE;
	if(isPawn(icon1)) {
		if(isBlack(icon1) && p2->row == 0) 
			pawnTransition(chessBoard, p2, true);
		else if(!isBlack(icon1) && p2->row == N - 1) 
			pawnTransition(chessBoard, p2, false);
	}
    return isQueen(icon2);
}

void castling(wchar_t chessBoard[N][N], Point* p1, Point* p2) {
	// arrocco regina - torre
}