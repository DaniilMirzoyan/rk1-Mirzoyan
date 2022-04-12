#include <windows.h>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void rFile1(const char* fileName, unsigned int* buff)
{
    FILE *f1;
    f1 = fopen(fileName, "r");
    if (f1 == nullptr)
    {
        return;
    }
    char i;
    do
    {
        i = fgetc(f1);
        if (i != EOF)
        {
            buff[i]++;
        }
    }while (i != EOF);
    fclose(f1);
}
void wFile(unsigned int* chars)
{
    FILE *f1;
    f1 = fopen("outfile1.txt", "w");
    for (int i = 33; i < 127; i++)
    {
        fprintf(f1, "%c -> %u\n", (char)i, chars[i]);
    }

    fclose(f1);
}
void n1()
{
    unsigned int buff[255] = {0};
    rFile1("inpfile1.txt", buff);
    wFile(buff);
}
void n2(int num)
{
    FILE  *f1;
    f1=fopen("outfile2.txt","w");
    char binNumb[32];
    bool isLeadZero = true;
    int firstNonZero = 0;
    for (int i = 31; i >= 0; i--)
    {
        binNumb[i] = ((num & (1 << i)) >> i) + 0x30;
        if (isLeadZero && (binNumb[i] == 0x31))
        {
            isLeadZero = false;
            firstNonZero = i;
        }
        if (!isLeadZero)
        {
            fprintf(f1,"%c", binNumb[i]);
            cout << binNumb[i];
        }
    }
    cout << endl;
    for (int i = 0; i <= firstNonZero; i++)
    {
        cout << binNumb[i];
    }
    fclose(f1);
}
void n3(char* bin, int length)
{
    int num = 0;
    for (int i = 0; i < length; i++)
    {
        if (bin[i] == 0x31)
        {
            num++;
        }
        if (i != length-1)
        {
            num = num << 1;
        }
    }
    printf("0x%x", num);
}

void vizovn() {
    n1();
    int num;
    cout << "Введите число для перевода в двоичный код:";
    cin >> num;
    cout << "Результат:" << endl;
    n2(num);
    cout << endl;
    char *inpt = "010111010";
    n3(inpt, strlen(inpt));
    cout << endl;
    cout << endl;
}
    int main(int argc, char *argv[])
    {
        SetConsoleOutputCP(CP_UTF8);
        vizovn();
    }