#include <stdio.h>
#include <string.h>
#include "transport.h"

// Inițializarea companiei
void initializare_companie(Companie *companie) {
    companie->numar_destinatii = 0;
    companie->numar_autobuze = 0;
    companie->numar_trenuri = 0;
    companie->numar_avioane = 0;
}

// Adăugare destinație
void adauga_destinatie(Companie *companie, const char *destinatie) {
    if (companie->numar_destinatii < MAX_DESTINATII) {
        strcpy(companie->destinatii[companie->numar_destinatii], destinatie);
        companie->numar_destinatii++;
    } else {
        printf("Nu se mai pot adăuga destinații.\n");
    }
}

// Ștergere destinație
void sterge_destinatie(Companie *companie, const char *destinatie) {
    int found = 0;
    for (int i = 0; i < companie->numar_destinatii; i++) {
        if (strcmp(companie->destinatii[i], destinatie) == 0) {
            found = 1;
            for (int j = i; j < companie->numar_destinatii - 1; j++) {
                strcpy(companie->destinatii[j], companie->destinatii[j + 1]);
            }
            companie->numar_destinatii--;
            break;
        }
    }
    if (!found) {
        printf("Destinația %s nu a fost găsită.\n", destinatie);
    }
}

// Adăugare vehicul
int adauga_vehicul_la_companie(Companie *companie, int tip, Vehicul vehicul) {
    switch (tip) {
        case 1: // Autobuz
            if (companie->numar_autobuze < MAX_VEHICULE) {
                companie->autobuze[companie->numar_autobuze++] = vehicul;
                return 1;
            }
            break;
        case 2: // Tren
            if (companie->numar_trenuri < MAX_VEHICULE) {
                companie->trenuri[companie->numar_trenuri++] = vehicul;
                return 1;
            }
            break;
        case 3: // Avion
            if (companie->numar_avioane < MAX_VEHICULE) {
                companie->avioane[companie->numar_avioane++] = vehicul;
                return 1;
            }
            break;
        default:
            printf("Tip vehicul invalid.\n");
    }
    return 0;
}

// Ștergere vehicul
int elimina_vehicul_din_companie(Companie *companie, int tip, int id) {
    Vehicul *vehicule;
    int *numar_vehicule;

    switch (tip) {
        case 1: vehicule = companie->autobuze; numar_vehicule = &companie->numar_autobuze; break;
        case 2: vehicule = companie->trenuri; numar_vehicule = &companie->numar_trenuri; break;
        case 3: vehicule = companie->avioane; numar_vehicule = &companie->numar_avioane; break;
        default: printf("Tip vehicul invalid.\n"); return 0;
    }

    for (int i = 0; i < *numar_vehicule; i++) {
        if (vehicule[i].id == id) {
            for (int j = i; j < *numar_vehicule - 1; j++) {
                vehicule[j] = vehicule[j + 1];
            }
            (*numar_vehicule)--;
            return 1;
        }
    }
    printf("Vehiculul cu ID %d nu a fost găsit.\n", id);
    return 0;
}

// Atribuire vehicul
void atribuie_vehicul(Companie *companie, int tip, int id, const char *destinatie, float distanta) {
    Vehicul *vehicule;
    int numar_vehicule;

    switch (tip) {
        case 1: vehicule = companie->autobuze; numar_vehicule = companie->numar_autobuze; break;
        case 2: vehicule = companie->trenuri; numar_vehicule = companie->numar_trenuri; break;
        case 3: vehicule = companie->avioane; numar_vehicule = companie->numar_avioane; break;
        default: printf("Tip vehicul invalid.\n"); return;
    }

    for (int i = 0; i < numar_vehicule; i++) {
        if (vehicule[i].id == id) {
            strcpy(vehicule[i].destinatie, destinatie);
            vehicule[i].distanta = distanta;
            return;
        }
    }
    printf("Vehiculul cu ID %d nu a fost găsit.\n", id);
}

// Afișare informații vehicul
void afiseaza_informatii_vehicul(Companie *companie, int tip, int id) {
    Vehicul *vehicule;
    int numar_vehicule;

    switch (tip) {
        case 1: vehicule = companie->autobuze; numar_vehicule = companie->numar_autobuze; break;
        case 2: vehicule = companie->trenuri; numar_vehicule = companie->numar_trenuri; break;
        case 3: vehicule = companie->avioane; numar_vehicule = companie->numar_avioane; break;
        default: printf("Tip vehicul invalid.\n"); return;
    }

    for (int i = 0; i < numar_vehicule; i++) {
        if (vehicule[i].id == id) {
            printf("ID: %d, Destinatie: %s, Distanta: %.2f km, Defectiuni: %s, In circulatie: %s\n",
                   vehicule[i].id, vehicule[i].destinatie, vehicule[i].distanta,
                   vehicule[i].defectiuni ? "Da" : "Nu",
                   vehicule[i].in_circulatie ? "Da" : "Nu");
            return;
        }
    }
    printf("Vehiculul cu ID %d nu a fost găsit.\n", id);
}

// Actualizare defectiuni
void actualizeaza_defectiuni(Companie *companie, int tip, int id, int defectiuni) {
    Vehicul *vehicule;
    int numar_vehicule;

    switch (tip) {
        case 1: vehicule = companie->autobuze; numar_vehicule = companie->numar_autobuze; break;
        case 2: vehicule = companie->trenuri; numar_vehicule = companie->numar_trenuri; break;
        case 3: vehicule = companie->avioane; numar_vehicule = companie->numar_avioane; break;
        default: printf("Tip vehicul invalid.\n"); return;
    }

    for (int i = 0; i < numar_vehicule; i++) {
        if (vehicule[i].id == id) {
            vehicule[i].defectiuni = defectiuni;
            return;
        }
    }
    printf("Vehiculul cu ID %d nu a fost găsit.\n", id);
}

// Afișare flotă completă
void afiseaza_flota(Companie *companie) {
    printf("\n--- Flota de autobuze ---\n");
    for (int i = 0; i < companie->numar_autobuze; i++) {
        printf("ID: %d\n", companie->autobuze[i].id);
    }
    printf("\n--- Flota de trenuri ---\n");
    for (int i = 0; i < companie->numar_trenuri; i++) {
        printf("ID: %d\n", companie->trenuri[i].id);
    }
    printf("\n--- Flota de avioane ---\n");
    for (int i = 0; i < companie->numar_avioane; i++) {
        printf("ID: %d\n", companie->avioane[i].id);
    }
}

// Afișare destinații
void afiseaza_destinatii(Companie *companie) {
    printf("\n--- Destinatii disponibile ---\n");
    for (int i = 0; i < companie->numar_destinatii; i++) {
        printf("%s\n", companie->destinatii[i]);
    }
}
