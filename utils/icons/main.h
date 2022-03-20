#ifndef __ICONS_H_
#define __ICONS_H_

#define FILLED_SQUARE 0x25A0
#define EMPTY_SQUARE  0x25A1
#define BLACK_QUEEN   0x2654
#define BLACK_KING    0x2655
#define BLACK_TOWER   0x2656
#define BLACK_BISHOP  0x2657
#define BLACK_HORSE   0x2658
#define BLACK_PAWN    0x2659


wchar_t getWhiteIcon(wchar_t black_icon);

bool isPawn(wchar_t icon);

bool isHorse(wchar_t icon);

bool isBishop(wchar_t icon);

bool isTower(wchar_t icon);

bool isKing(wchar_t icon);

bool isQueen(wchar_t icon);

bool isBlack(wchar_t icon);

bool isEqualColor(wchar_t icon1, wchar_t icon2);

void printIconStringName(wchar_t icon);

void pawnTransition(wchar_t chessBoard[N][N], Point* p, bool isBlack);


#endif