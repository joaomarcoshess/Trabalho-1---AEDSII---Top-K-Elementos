#include "Funcoes.hpp"

Funcoes::Funcoes()
{
}

void Funcoes::Welcome() {
  cout << "Bem vindo ao algoritmo de verificacao de recorrencias das principais palavras de um arquivo." << endl;
  cout << "(Para que o programa funcione, os arquivos devem estar nomeados como in1.data, in2.data...)" << endl;
  cout << "Quantos arquivos serao lidos:  ";
  
}

wchar_t* Funcoes::getText(const locale loc, string name)
{
  wifstream txt(name, ios::binary);

  if(!txt.is_open())
  {
    cerr << "Nao foi possível abrir o arquivo " << name << endl;
    exit(1);
  }
  
  txt.imbue(loc);
  txt.seekg(0, ios::end);
  streampos tamanho = txt.tellg();
  txt.seekg(0, ios::beg);
  wchar_t* buffer = new wchar_t[tamanho];
  txt.read(buffer, tamanho);
  txt.close();

  return buffer;
}

unordered_set<wstring> Funcoes::getStopWords(const locale loc)
{
  wstring word;
  unordered_set<wstring> stopwords;
  wifstream file("dataset/stopwords.txt");

  if(!file.is_open())
  {
    cerr << "Não foi possível abrir o arquivo!" << endl;
    exit(1);
  }
  file.imbue(loc);

  while (file >> word)
  {
    stopwords.insert(word);
  }

  file.close();

  return stopwords;
  
}

void Funcoes::printHeap(vector<Aux> heap)
{
  wstring_convert<std::codecvt_utf8<wchar_t>> converter;
  
  for (auto i = 0u; i < heap.size(); i++)
  {
    cout << "Palavra: " << converter.to_bytes(heap[i].getNome()) << " ~ " << "Recorrencia: "<< heap[i].getRecorrencia() << endl;
  }

}
