#include <bits/stdc++.h>
#include "Aux.hpp"

#ifndef FUNCOES_HPP
#define FUNCOES_HPP

using namespace std;

class Funcoes
{
  public:
    Funcoes();

    void Welcome();
    wchar_t* getText(const locale loc, string name);
    unordered_set<wstring> getStopWords(const locale loc);
    void printHeap(vector<Aux> heap);

};
#endif
