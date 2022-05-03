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

   // luam cuvintele din fisier care contin macar o litera din query
   fin.open("cuvinte_ro.txt", ios::in);
   string cuvant;
   while (fin >> cuvant)
   {
      bool pastram = false; // aa a fa fga
      for (char &c : query)
         if (cuvant.find_first_of(c) != -1)
            pastram = true;

      if (pastram)
         cuv.push_back(cuvant);
   }
      
   cout << cuv.size();
}