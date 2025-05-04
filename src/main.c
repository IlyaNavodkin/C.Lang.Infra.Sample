#include <stdio.h>
#include <string.h>
#include <windows.h>

void SetupConsoleSettings()
{
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);      
}

int main() 
{
    SetupConsoleSettings();

    char name[100];
    printf("АЛОО Здарова епта, имя назови свое?\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Здарова епта, %s!\n", name);
    printf("дАВАЙ Бывай");

    return 0;
}