#include <stdio.h>
#include <string.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);      

    char name[100];
    printf("Здарова епта, имя назови свое?\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Здарова епта, %s!\n", name);

    return 0;
}