#pragma once

#include "BQ.h"
#include "Set.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string.h>
#include <cassert>
#include "../../../Lab02/Lab02/ArraySequence.h"
#include "Person.h"
#include "Complex.h"


int Mapcheck(int a);
float Mapcheck(float a);
string Mapcheck(string a);
Person Mapcheck(Person a);
Complex Mapcheck(Complex a);
int Mapcheck1(int a);
int Mapcheck3(int a);
size_t Map(size_t s);
int ReduceCeck(int a, int b);
float ReduceCeck(float a, float b);
string ReduceCeck(string a, string b);
Person ReduceCeck(Person a, Person b);
Complex ReduceCeck(Complex a, Complex b);
bool Wherecheck(int x);
bool Wherecheck(float x);
bool Wherecheck(string x);
bool Wherecheck(Person x);
bool Wherecheck(Complex x);
string Mch(string c);
Person Perr(Person x, Person y);

void Test();
void Bqtest();

Person Perr(Person x, Person y);

void Perstest();
void intmen();
void domen();
void strimen();
void permen();
void commen();
void TreeMenu();

void intmens();
void domens();
void strimens();
void permens();
void commens();
void SetMenu();

void intmenp();
void domenp();
void strtmenp();
void persmenp();
void complmenp();

void PriorityqueMenu();
void TypeMenu();
