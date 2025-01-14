#ifndef TRANSPORT_H
#define TRANSPORT_H

#define MAX_DESTINATII 100
#define MAX_VEHICULE 100

typedef struct {
    int id;                  // ID-ul vehiculului
    char destinatie[50];     // Destinatia
    float distanta;          // Distanta pana la destinatie
    int defectiuni;          // 1 daca are defecte, 0 altfel
    int in_circulatie;       // 1 daca este in circulatie, 0 daca este retras
} Vehicul;

typedef struct {
    char destinatii[MAX_DESTINATII][50];  // Lista destinatiilor
    int numar_destinatii;                 // Numărul de destinații
    Vehicul autobuze[MAX_VEHICULE];       // Lista autobuzelor
    int numar_autobuze;                   // Numărul de autobuze
    Vehicul trenuri[MAX_VEHICULE];        // Lista trenurilor
    int numar_trenuri;                    // Numărul de trenuri
    Vehicul avioane[MAX_VEHICULE];        // Lista avioanelor
    int numar_avioane;                    // Numărul de avioane
} Companie;

// Functii de gestionare a companiei
void initializare_companie(Companie *companie);

// Adăugare și ștergere destinații
void adauga_destinatie(Companie *companie, const char *destinatie);
void sterge_destinatie(Companie *companie, const char *destinatie);

// Adăugare vehicul
int adauga_vehicul_la_companie(Companie *companie, int tip, Vehicul vehicul);

// Ștergere vehicul
int elimina_vehicul_din_companie(Companie *companie, int tip, int id);

// Atribuire vehicul unei destinații
void atribuie_vehicul(Companie *companie, int tip, int id, const char *destinatie, float distanta);

// Afișare informații vehicul
void afiseaza_informatii_vehicul(Companie *companie, int tip, int id);

// Actualizare defecte vehicul
void actualizeaza_defectiuni(Companie *companie, int tip, int id, int defectiuni);

// Afișare flotă completă
void afiseaza_flota(Companie *companie);

// Afișare destinatii
void afiseaza_destinatii(Companie *companie);

#endif // TRANSPORT_H
