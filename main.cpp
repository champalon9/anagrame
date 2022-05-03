#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
fstream fin;

vector<string> cuv;

int main()
{
   string query;
   cout << "Inserati propozitia de cautat:\n";
   cin >> query;
   transform(query.begin(), query.end(), query.begin(), ::tolower); // transformam in litere mici

   int apQuery[26], apCuv[26];
   fill(apQuery, apQuery + 26, 0);
   for (char &c : query)
      if (isalpha(c))
         apQuery[c - 'a'] ++;

   // luam cuvintele din fisier care contin macar o litera din query
   // agares = query
   // aaaa = cuvant

   fin.open("cuvinte_ro.txt", ios::in);
   string cuvant;
   while (fin >> cuvant)
   {
      fill(apCuv, apCuv + 26, 0);
      for (char &c : cuvant)
         apCuv[c - 'a'] ++;

      bool pastram = true;
      for (int i = 0; i < 26; ++i)
         if (apCuv[i] > apQuery[i])
         {
            pastram = false;
            break;
         }

      if (pastram)
         cuv.push_back(cuvant);
   }
   
   for (int i = 0; i < 20; ++i)
      cout << cuv[i] << '\n';
}