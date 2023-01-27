#include <iostream>
using namespace std;
#define N 9

void wypisz(int sudoku[N][N])
{
    cout << "------------------" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int k = 0; k < N; k++)
            cout << sudoku[i][k] << " ";
        cout << endl;
    }
    cout << "------------------" << endl;
}

bool zasady(int sudoku[N][N], int wiersz,
    int kolumna, int numer)
{
    for (int i = 0; i <= 8; i++)
        if (sudoku[wiersz][i] == numer)
            return false;

    for (int i = 0; i <= 8; i++)
        if (sudoku[i][kolumna] == numer)
            return false;

    int startWiersz = wiersz - wiersz % 3,
        startKolumna = kolumna - kolumna % 3;

    for (int i = 0; i < 3; i++)
        for (int k = 0; k < 3; k++)
            if (sudoku[i + startWiersz][k +
                startKolumna] == numer)
                return false;

    return true;
}

bool rozwiazanieSudoku(int sudoku[N][N], int wiersz, int kolumna)
{
    if (wiersz == N - 1 && kolumna == N)
        return true;

    if (kolumna == N) 
    {
        wiersz++;
        kolumna = 0;
    }

    if (sudoku[wiersz][kolumna] > 0)
        return rozwiazanieSudoku(sudoku, wiersz, kolumna + 1);

    for (int numer = 1; numer <= N; numer++)
    {
        if (zasady(sudoku, wiersz, kolumna, numer))
        {
            sudoku[wiersz][kolumna] = numer;
            if (rozwiazanieSudoku(sudoku, wiersz, kolumna + 1))
                return true;
        }
        sudoku[wiersz][kolumna] = 0;
    }
    return false;
}

int main()
{
    int sudoku[N][N] = { 
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9} };

    cout << "Nierozwiazane sudoku:" << endl;
    wypisz(sudoku);

    cout << "Rozwiazane sudkou:" << endl;
    if (rozwiazanieSudoku(sudoku, 0, 0))
        wypisz(sudoku);
    else
        cout << "Rozwiazanie nie istnieje" << endl;

    return 0;
}