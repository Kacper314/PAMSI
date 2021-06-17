#define GRA_HH
#ifdef GRA_HH

#define ROZMIAR 3            //Aktualny Rozmiar Tablicy
#define Bot 1                //Zmienne w celu rozróżnienia czyja jest tura
#define Man 2
#define Komp 'O'             //Bot jest reprezentowany przez kółko
#define Czlowiek 'X'         //Człowiek reprezentowany przez krzyzyk

void Start( char tab[ROZMIAR][ROZMIAR]);
void Plansza(char tab[ROZMIAR][ROZMIAR]);
void Wygrany(int Tura);
bool WygranaWiersz(char tab[ROZMIAR][ROZMIAR]);
bool WygranaKol(char tab[ROZMIAR][ROZMIAR]);
bool WygranaPrzek(char tab[ROZMIAR][ROZMIAR]);
bool KoniecGry(char tab[ROZMIAR][ROZMIAR]);
bool Zwyciestwo(char tab[ROZMIAR][ROZMIAR]);
bool PrawyDiagonal(char tab[ROZMIAR][ROZMIAR]);
bool LewyDiagonal(char tab[ROZMIAR][ROZMIAR]);
bool Koniec(char tab[ROZMIAR][ROZMIAR]);
int MiniMax( char tab[ROZMIAR][ROZMIAR] , int glebokosc , bool isMax , int alfa , int beta);
int Ruch(char tab[ROZMIAR][ROZMIAR] , int wykonajruch , int alfa , int beta);
void Graj(int Tura);

#endif