#include <bits/stdc++.h>
#include "Funcoes.hpp"
#include "Aux.hpp"

using namespace std;

int main()
{ 
  const int k = 20;
  int numFiles;
  Funcoes f;
  wstring word;
  vector<Aux> minHeap;
  
  setlocale(LC_ALL, "pt_BR.UTF-8");
  // Converte os caracteres para UTF-8, a partir de um objeto
  locale loc(locale(), new codecvt_utf8<wchar_t>);
  unordered_set<wstring> stopwords = f.getStopWords(loc);
  unordered_map <wstring, int> frequenceMap;
  

  cout << "(Todos os arquivos devem ser nomeados como in1.data, in2.data...)" << endl;
  cout << "Insira o número de arquivos a serem lidos: ";
  cin >> numFiles;

  auto start = chrono::high_resolution_clock::now();

  for(int i = 1; i <= numFiles; i++)
  {
    string name = "./dataset/in" + to_string(i) + ".data";
    wchar_t* txt = f.getText(loc, name), *ch = txt;
    while(*ch)
    {
      switch(*ch)
      {
        case L' ': case L'!': case L'?': case L'.': case L'\n': case L',': case L'(': case L')': case L';': case L'/': case L':': case L'—': case L'"': case L'\'':
          if(!word.empty())
          {
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            if(stopwords.find(word) == stopwords.end())
            {
              frequenceMap[word]++;
            }
            word.clear();
          }
          break;
  
        default:
          if(*ch == '-' && word.size() == 0)
          {
            break;
          }
          word += *ch;
          break;
      }
      ch++;
    }
    delete[] txt;
  }

  for (const auto& aux: frequenceMap)
  {
    if(minHeap.size() < k)
    {
      minHeap.push_back(Aux(aux.first, aux.second));
      if(minHeap.size() == k)
      {
        make_heap(minHeap.begin(), minHeap.end());
      }
    }
    else
    {
      if(aux.second > minHeap[0].getFrequencia())
      {
        pop_heap(minHeap.begin(), minHeap.end());
        minHeap.pop_back();
        minHeap.push_back(Aux(aux.first, aux.second));
        push_heap(minHeap.begin(), minHeap.end());
      }
    }
  }

  f.printHeap(minHeap);

  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
  wcout << endl << "Latencia: " << duration.count() << " ms" << endl;

  return 0;
}
