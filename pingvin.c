#include <stdio.h>
#include <unistd.h>

void cls() { printf("\033[H\033[J"); }

int main() {
    for (int i = 0; i < 20; i++) {
        cls();
        if (i % 2 == 0) {
            // 1. Fázis: Szárnyak lent
            printf("          .---.\n");
            printf("         /      \\\n");
            printf("        /  (o)(o) \\\n" ); // Javítva: \ helyett
            printf("       /  /  VV  \\ \\ \n");
            printf("    __/  /        \\  \\__\n");
            printf("   (____/          \\____)\n");
            printf("        \\__________/\n");
            printf("        /    /\\    \\\n");
            printf("       /____/  \\____\\\n");
        } else {
            // 2. Fázis: Szárnyak fent
            printf("    ____  .---.  ____\n");
            printf("   (    \\/     \\/    )\n");
            printf("    \\__ / (o)(o) \\\\__/\n"); // Javítva: \\\\ az escape miatt
            printf("      \\  /  VV  //  /\n");
            printf("       \\ /         /\n");
            printf("        \\         /\n");
            printf("         \\_______/\n");
            printf("        /    /\\    \\\n");
            printf("       /____/  \\____\\\n");
        }
        fflush(stdout);
        usleep(400000); // 0.4 másodperces várakozás
    }
    return 0;
}
