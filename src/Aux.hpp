#include <bits/stdc++.h>

#ifndef AUX_HPP
#define AUX_HPP

using namespace std;

class Aux
{
  private:
    wstring nome;
    int recorrencia;

  public:
    Aux(wstring nome, int recorrencia);
    Aux();

    void setNome(wstring nome);
    wstring getNome();
    void setRecorrencia(int recorrencia);
    int getRecorrencia();
    bool operator<(const Aux& other) const;
};
#endif
