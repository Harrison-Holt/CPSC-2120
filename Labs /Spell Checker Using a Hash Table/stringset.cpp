
/*
 * Name: Harrrison Holt
 * Date Submitted: March 6, 2023
 * Lab Section: 005
 * Assignment Name: Lab 5 
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
return size;
}

void Stringset::insert(string word)
{
//check to see if the word isn't in the string set already
if (!find(word)) { 
  int loc;
  string Word1;
  std::hash<std::string> strHash;

//check if the size has been exceeded
if (num_elems >= size) { 
size = size * 2;
vector<list<string>> newTable(size);

//looping thorugh the current table and the list's in each value and re-hash them in the new table
for (int i = 0; i < size / 2; i++) {
  
  for(list<string>::const_iterator it = table[i].begin(); it != table[i].end(); ++it) {
     
     Word1 = *it;
     loc = strHash(Word1) % size;
     newTable[loc].push_back(Word1);
     table[i].remove(word);
}
}
     table = newTable; //set the old table to the new table
}
    loc = strHash(word) % size;
    table[loc].push_back(word);
    num_elems++;
}
}

bool Stringset::find(string word) const {

   std::hash<std::string> str_hash;
   int loc = str_hash(word) % size;
  
  //looping through all the values in the list
for(list<string>::const_iterator it = table[loc].begin(); it != table[loc].end(); ++it) {
   
   if (*it == word) //check if the word is there return true
     
     return true;
}
     return false;
}

void Stringset::remove(string word)
{
//check if the word is in the list remove it from it's hash location's list using .remove()
if (find(word)) { 
    
    std::hash<std::string> str_hash;
    int loc = str_hash(word) % size;
    table[loc].remove(word);
    num_elems--;
}
}
