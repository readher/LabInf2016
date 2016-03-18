//Załóżmy, że mamy kilka baz danych, złożonych z imion, nazwisk i zarobków osób, zgodnych z tymi typami:
  //#define MAX_DL_IM 11
  //#define MAX_DL_NA 17
  //#define DUZO ...
  //typedef  struct {
    //char imie[MAX_DL_IM];
    //char nazwisko[MAX_DL_NA];
    //int pensja;
//}  osoba;
  //osoba tabl[DUZO];
//(nie wiadomo z góry, ile osób jest w danej bazie). Proszę napisać program   porzadkuj.c , którego wywołanie np. takie
    //./porzadkuj jedna_z_baz wynik_porzadkowania
//posortuje wskazaną bazę   jedna_z_baz   (alfabetycznie wg nazwisk, a dla równych nazwisk wg imion) i zapisze wynik sortowania na nowo utworzony plik   wynik_porzadkowania .
//Postarać się o dobre rozbicie programu na funkcje. Na przykład program główny mógłby mieć taki kształt:
  //int main (int arg_num, char* arg[]) {
    //if (arg_num == 3) {
    //int  ile = czytanie(arg[1]);
      //if (ile > 0) {
        //sortowanie(0, ile);
        //pisanie(arg[2], ile);
      //}
    //}
    //else
      //printf("\n Poprawne wywolanie: './porzadkuj dane wynik'\n\n");
    //return 0;
  //}
//a   czytanie ,   sortowanie   i   pisanie  mogłyby być osobno zdefiniowanymi funkcjami (czytanie   oddaje liczbę osób, znalezionych w bazie danych).
