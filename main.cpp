#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "functii.hpp"
using namespace std;
fstream fin;

vector<pair<string, int*>> cuv; // <"cuvant", [aparitii cuvant]>

int main()
{
   string query;
   cout << "Inserati propozitia de cautat:\n";
   getline(cin, query);
   transform(query.begin(), query.end(), query.begin(), ::tolower); // transformam in litere mici

   int apQuery[26];
   fill(apQuery, apQuery + 26, 0);
   for (char &c : query)
      if (isalpha(c))
         apQuery[c - 'a'] ++;

   // luam cuvintele din fisier care contin toate literele in query pentru care frecventa unei litere in cuvant este mai mare sau egala decat frecventa literei in query
   fin.open("cuvinte_ro.txt", ios::in);
   string cuvant;
   while (fin >> cuvant)
   {
      int *apCuv = new int[26];
      fill(apCuv, apCuv + 26, 0);

      for (char &c : cuvant)
         apCuv[c - 'a'] ++;

      if (frecventaCorecta(apCuv, apQuery))
         cuv.push_back({cuvant, apCuv});
   }
   fin.close();
   
   afisarePropozitii(cuv, apQuery);
   
   return 0;
}