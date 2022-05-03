#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

fstream fout;


bool frecventaCorecta(int frmic[26], int frmare[26])
{
   for (int i = 0; i < 26; ++i)
      if (frmic[i] > frmare[i])
         return false;
   
   return true;
}


void scadeFrecventa(int frmic[26], int frmare[26])
{
   for (int i = 0; i < 26; ++i)
      frmare[i] -= frmic[i];
}


void adunaFrecventa(int frmic[26], int frmare[26])
{
   for (int i = 0; i < 26; ++i)
      frmare[i] += frmic[i];
}


bool frecventaNula(int fr[26])
{
   for (int i = 0; i < 26; ++i)
      if (fr[i] != 0)
         return false;
   
   return true;
}


void back(vector<pair<string, int*>> &cuv, vector<string> &propo, int apQueryMod[26])
{
   bool ok = false;
   for (pair<string, int*> &cuvant : cuv)
   {
      if (frecventaCorecta(cuvant.second, apQueryMod))
      {
         ok = true;

         scadeFrecventa(cuvant.second, apQueryMod);
         propo.push_back(cuvant.first);
         back(cuv, propo, apQueryMod);
         adunaFrecventa(cuvant.second, apQueryMod);
         propo.pop_back();
      }
   }

   if (!ok)
   {
      if (!frecventaNula(apQueryMod))
         return;
      
      for (string &cuvant : propo)
         fout << cuvant << ' ';
      fout << '\n';
   }
}


void afisarePropozitii(vector<pair<string, int*>> &cuv, int apQueryOrig[26])
{
   fout.open("propozitii.txt", ios::out);
   
   int apQueryMod[26];
   copy(apQueryOrig, apQueryOrig + 26, apQueryMod);

   vector<string> propo;
   back(cuv, propo, apQueryMod);

   fout.close();
}