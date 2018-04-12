//
//  main.cpp
//  Kaculator whith brackets
//
//  Created by Jan Napolskykh on 06.11.16.
//  Copyright © 2016 Jan Napolskykh. All rights reserved.
//

#include <iostream>

using namespace std;

typedef enum {PlusSm, MinusSm, RazySm, DzielSm, LewyNawSm, PrawyNavSm, LiczbaSm, PustySm } symbole;

const int MAXBUF=101;
struct symv {
    symbole SymbNm;
    double wart;
} symbol;

char buforek[MAXBUF];
int pozBuf=0;
int scan() {
    int wart;
    char znak;
    while ((znak=buforek[pozBuf++])==' ');
    if (isdigit(znak)) {
        symbol.SymbNm=LiczbaSm;
        while (isdigit(znak=buforek[pozBuf])) {
            wart=10*wart+(znak-'0');
            pozBuf++;
        }
        symbol.wart=wart;
    }
    else {
        switch (znak) {
            case '(':
                symbol.SymbNm=LewyNawSm;
                break;
            case ')':
                symbol.SymbNm=PrawyNavSm;
                break;
            case '+':
                symbol.SymbNm=PlusSm;
                break;
            case '-':
                symbol.SymbNm=MinusSm;
                break;
            case '*':
                symbol.SymbNm=RazySm;
                break;
            case '/':
                symbol.SymbNm=DzielSm;
                break;
            case '\0':
                symbol.SymbNm=PustySm;
                break;
                
            default: {
                cout<<"Nieznany znak "<<znak<<endl;
                return -1;
            }
        }
    }
    return 0;
}

double skladnik();
double czynnik();
double wyrazenie() {
    double wart;
    wart=skladnik();
    if (symbol.SymbNm==PlusSm) {
        scan();
        wart += wyrazenie();
    }
    else if (symbol.SymbNm==MinusSm) {
        scan();
        wart -= wyrazenie();
    }
    cout<<"wwwwwwwwwwwwwwwyrazenie = "<<wart<<endl;
    return wart;
}

double skladnik() {
    double wart;
    wart=czynnik();
    if (symbol.SymbNm==RazySm){
        scan();
        wart *= skladnik();
    }
    else if (symbol.SymbNm==DzielSm) {
        scan();
        wart /= skladnik();
    }
    cout<<"ssssssssssssskladnik = "<<wart<<endl;
    return wart;
}

double czynnik() {
    double wart;
    if (symbol.SymbNm==LiczbaSm){
        wart=symbol.wart;
        scan();
    }
    else if (symbol.SymbNm==LewyNawSm) {
        scan();
        wart=wyrazenie();
        if (symbol.SymbNm!=PrawyNavSm){
            cout<<"**** Spodziewany nawias zamykajacy"<<endl;
            wart = 0;
        }
        else scan();
    }
    cout<<"$$$$$ czynnik wart = "<<wart<<endl;
    return wart;
}

int main() {
    int i=0;
    char c;
    cout<<"Podaj wyrazenie"<<endl;
    while ((c=getchar())!='\n')buforek[i++]=c;buforek[i]='\0';
    cout<<"Wczytano "<<buforek<<endl;
    symbol.wart=0;
    scan();
    cout<<" = "<<dec<<wyrazenie()<<endl;
    return 0;
}