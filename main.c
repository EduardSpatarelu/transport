#include <stdio.h>
#include <stdlib.h>
#include "transport.h"

void afiseaza_meniu() {
    printf("\nMeniu:\n");
    printf("1. Vizualizeaza flota\n");
    printf("2. Vizualizeaza destinatii\n");
    printf("3. Adauga destinatie\n");
    printf("4. Sterge destinatie\n");
    printf("5. Adauga vehicul\n");
    printf("6. Elimina vehicul\n");
    printf("7. Atribuie vehicul unei destinatii\n");
    printf("8. Afiseaza informatii vehicul\n");
    printf("9. Actualizeaza defectiuni vehicul\n");
    printf("10. Iesire\n");
}

int main() {
    Companie companie;
    initializare_companie(&companie);

    while (1) {
        int optiune;
        afiseaza_meniu();
        printf("Alege o optiune: ");
        scanf("%d", &optiune);

        if (optiune == 10) break;

        switch (optiune) {
            case 1:
                afiseaza_flota(&companie);
                break;
            case 2:
                afiseaza_destinatii(&companie);
                break;
            case 3: {
                char destinatie[50];
                printf("Introduceti destinatia: ");
                scanf("%s", destinatie);
                adauga_destinatie(&companie, destinatie);
                break;
            }
            case 4: {
                char destinatie[50];
                printf("Introduceti destinatia de sters: ");
                scanf("%s", destinatie);
                sterge_destinatie(&companie, destinatie);
                break;
            }
            case 5: {
                Vehicul vehicul;
                int tip;
                printf("Introduceti tipul vehiculului (1: Autobuz, 2: Tren, 3: Avion): ");
                scanf("%d", &tip);
                printf("Introduceti ID-ul vehiculului: ");
                scanf("%d", &vehicul.id);
                printf("Introduceti distanta: ");
                scanf("%f", &vehicul.distanta);
                vehicul.defectiuni = 0;
                vehicul.in_circulatie = 1;
                adauga_vehicul_la_companie(&companie, tip, vehicul);
                break;
            }
            case 6: {
                int id, tip;
                printf("Introduceti tipul vehiculului de eliminat (1: Autobuz, 2: Tren, 3: Avion): ");
                scanf("%d", &tip);
                printf("Introduceti ID-ul vehiculului de eliminat: ");
                scanf("%d", &id);
                elimina_vehicul_din_companie(&companie, tip, id);
                break;
            }
            case 7: {
                int id, tip;
                char destinatie[50];
                float distanta;
                printf("Introduceti tipul vehiculului (1: Autobuz, 2: Tren, 3: Avion): ");
                scanf("%d", &tip);
                printf("Introduceti ID-ul vehiculului: ");
                scanf("%d", &id);
                printf("Introduceti destinatia: ");
                scanf("%s", destinatie);
                printf("Introduceti distanta: ");
                scanf("%f", &distanta);
                atribuie_vehicul(&companie, tip, id, destinatie, distanta);
                break;
            }
            case 8: {
                int id, tip;
                printf("Introduceti tipul vehiculului (1: Autobuz, 2: Tren, 3: Avion): ");
                scanf("%d", &tip);
                printf("Introduceti ID-ul vehiculului: ");
                scanf("%d", &id);
                afiseaza_informatii_vehicul(&companie, tip, id);
                break;
            }
            case 9: {
                int id, tip, defectiuni;
                printf("Introduceti tipul vehiculului (1: Autobuz, 2: Tren, 3: Avion): ");
                scanf("%d", &tip);
                printf("Introduceti ID-ul vehiculului: ");
                scanf("%d", &id);
                printf("Introduceti starea defectiunilor (1: Da, 0: Nu): ");
                scanf("%d", &defectiuni);
                actualizeaza_defectiuni(&companie, tip, id, defectiuni);
                break;
            }
            default:
                printf("Optiune invalida.\n");
        }
    }

    return 0;
}
