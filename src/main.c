#include <stdio.h>
#include <windows.h>

enum {
    CONSOLE_CODE = 65001
};

void SetupConsoleSettings()
{
    SetConsoleOutputCP(CONSOLE_CODE); 
    SetConsoleCP(CONSOLE_CODE);      
}

struct Point {
    int x;
    int y;
};

struct Point CreatePoint(int x, int y) 
{
    struct Point p;
    p.x = x;
    p.y = y;
    return p;
}

void PrintPoint(struct Point *p) 
{ 

    printf("Coordinates: (%d, %d), Address: %p\n", p->x, p->y, (void*)p);
}

void MovePoint(struct Point p, int dx, int dy) 
{
    printf("\nВнутри MovePoint перед изменением: (%d, %d), Address: %p\n", p.x, p.y, (void*)&p);
    p.x += dx;
    p.y += dy;
    printf("Внутри MovePoint после изменением: (%d, %d), Address: %p\n", p.x, p.y, (void*)&p);
}

int main() 
{
    SetupConsoleSettings();

    struct Point p1 = CreatePoint(10, 20);

    printf("\nПеред сдвигом:\n");
    PrintPoint(&p1);

    MovePoint(p1, 5, 5);

    printf("\nПосле сдвига:\n");
    PrintPoint(&p1);

    return 0;
}
