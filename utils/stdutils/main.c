#include "main.h"


const time_t getCurrentDateTime(bool isStartTime) {
    const size_t buffer_dim = 30;
    char dateTimeStringBuffer[buffer_dim];
    const time_t now = time(NULL);
    struct tm* restrict time_info = localtime(&(now));
    time_info->tm_hour += 1; 
    strftime(dateTimeStringBuffer, buffer_dim, "%Y-%m-%d %H:%M:%S", time_info);
    wprintf(L"\nGame %ls time = %s\n", isStartTime ? L"start" : L"end", dateTimeStringBuffer);
    return now;
}

void printRow(bool isUp) {
    unsigned short i = 0;
    isUp ? wprintf(L"\n \n \t   ") : wprintf(L"\n \t   ");
    for (; i < N; i++)
        wprintf(L" %i ", i);
    wprintf(L"\n");
}

void printMatrix(wchar_t matrix[N][N]) {
    unsigned short
        i = 0,
        j = 0;
    printRow(true);
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (j == 0)
                wprintf(L"\t%i | %lc ", i, matrix[i][j]);
            else if (j == N - 1)
                wprintf(L" %lc | %i", matrix[i][j], i);
            else
                wprintf(L" %lc ", matrix[i][j]);
            if (j == N - 1 && i < N - 1)
                wprintf(L"\n");
        }
    }
    printRow(false);
    wprintf(L"\n");
}

unsigned short setCoordinate(int x) {
    if(x < 0)
        return 0;
    else if(x > N - 1)
        return N - 1;
    else 
        return x;
}

const double dabs(double value) {
    return value >= 0 ? value : (-1 * value);
}