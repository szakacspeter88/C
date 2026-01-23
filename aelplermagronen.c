#include <stdio.h>

int main() {
    int adag;

    // Swiss German Greetings and Question
    printf("=== Älplermagrone-Rächner ===\n");
    printf("Für wie vill Persone wotsch choche? ");
    scanf("%d", &portion);

    printf("\n--- Zuetate für %d Persone ---\n", adag);

    // Apfelmus (Opfelmuas)
    printf("\n[Opfelmuas]\n");
    printf("- %.2f g Öpfel (z.B. Boskoop, gschelt und gschnitte)\n", 150.0 * adag);
    printf("- %.2f dl Öpfelsaft\n", 0.25 * adag);
    printf("- %.2f EL Zucker\n", 0.65 * adag);
    printf("- %.2f Zimtstange\n", 0.25 * adag);

    // Hauptgang (Hauptmollziit)
    printf("\n[Magrone und Härdöpfel]\n");
    printf("- %.2f g Härdöpfel (feschtochig, i 1cm Würfeli)\n", 150.0 * adag);
    printf("- %.2f g Magrone (oder Hörnli)\n", 63.0 * adag);
    printf("- %.2f g Chäs (griibe)\n", 63.0 * adag);
    printf("- %.2f dl Vollrahm\n", 0.25 * adag);
    printf("- Gwürz: Salz, Pfäffer, Muskatnuss\n");

    // Zwiebelschwitze (Zwiebele-Schvitz)
    printf("\n[Zwiebele-Schvitz]\n");
    printf("- %.2f Zwiebele (i Ringe)\n", 0.5 * adag);
    printf("- %.2f EL Mähl\n", 0.35 * adag);
    printf("- Bratbutter zum Aabrote\n");


    // Elkészítés (Zubereitung)
    printf("\n======================================\n");
    printf("        ZUBEREITIG (Schritt für Schritt)\n");
    printf("======================================\n");

    printf("1. Opfelmuas:\n");
    printf("   Alli Zuetate ufchoche. Öpfel zuedeckt 10-15 Minute weich choche.\n\n");

    printf("2. Magrone und Härdöpfel:\n");
    printf("   Härdöpfel und Teigware zäme im Salzwasser gare.\n");
    printf("   Abgiesse és abtropfe loh.\n\n");

    printf("3. Schichte:\n");
    printf("   Lagevys mit em Chäs zrugg id heissi Pfanne geh.\n");
    printf("   De Rahm würze (Salz, Pfäffer, Muskat) und drüberleyre.\n\n");

    printf("4. Zwiebele-Schvitz:\n");
    printf("   Zwiebelringe im Mähl wände. I de heisse Bratbutterchnusprig bache.\n");
    printf("   Über d'Magrone verteile és serviere.\n");

    printf("\n--------------------------------------\n");
    printf("En Guete! Viel Spass bim Choche!\n");

       printf("\n-------------------------------\n");
    printf("En Guete!\n");
}
