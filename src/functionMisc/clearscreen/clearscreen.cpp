/* Saya ambil dari artikel https://cplusplus.com/articles/4z18T05o/
   Sayangnya tidak ada cara yg mudah bagi pemula untuk Clear screen.
   Ada cuman caranya perlu library conio yang sudah outdated atau
   menggunakan system("cls"), tapi orang-orang menyarankan jangan
   pakai itu di lingkungan professional karena itu hanya bekerja di
   1 OS dan function system bekerja lgsg ke sistem komputer kita
   jadi dia ngebypass program AV makanya berbahaya. Saya bisa aja
   menggunakan system("cls"), tapi saya mau coba membiasakan diri
   untuk menggunakan function selain system(). */

#include "../../../include/clearscreen.hpp"
#include <windows.h>

void ClearScreen()
  {
  HANDLE                     hStdOut;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD                      count;
  DWORD                      cellCount;
  COORD                      homeCoords = { 0, 0 };

  hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
  if (hStdOut == INVALID_HANDLE_VALUE) return;

  /* Get the number of cells in the current buffer */
  if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
  cellCount = csbi.dwSize.X *csbi.dwSize.Y;

  /* Fill the entire buffer with spaces */
  if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Fill the entire buffer with the current colors and attributes */
  if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;

  /* Move the cursor home */
  SetConsoleCursorPosition( hStdOut, homeCoords );
  }