#include "Aux.hpp"

Aux::Aux(wstring nome, int recorrencia)
{
  setNome(nome);
  setRecorrencia(recorrencia);
}
Aux::Aux()
{
}

void Aux::setNome(wstring nome)
{
  this->nome = nome;
}
wstring Aux::getNome()
{
  return this->nome;
}

void Aux::setRecorrencia(int recorrencia)
{
  this->recorrencia = recorrencia;
}
int Aux::getRecorrencia()
{
  return this->recorrencia;
}

bool Aux::operator<(const Aux& other) const
{
  return recorrencia > other.recorrencia;
}
