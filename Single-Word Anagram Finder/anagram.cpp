/*
 * Name: Harrison Holt
 * Date Submitted: 3-16-23
 * Assignment Name: 
 */
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);
vector<string> anagram(string word, vector<string> wordlist);

 /*int main()
{
vector<string> words;
vector<string> anagrams;
string inputWord;
words=loadWordlist("wordlist.txt");
cout << "Find single-word anagrams for the following word: ";
cin >> inputWord;
anagrams = anagram(inputWord,words);
cout << anagrams.size() << endl; 
for (int i=0; i<anagrams.size();i++ ){
cout << anagrams[i] << endl;
}
return 0;
}
*/
vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}



vector<string> anagram(string word, vector<string> wordlist)
{   //a variable to store one item from wordlist
    string item;
    
    // a vector to store all the found anagrams
    vector<string> anagrams_vector;
        
    //looping through all the items in wordlist
    for(int k=0;k<wordlist.size(); k++){
        //take out one item from wordlist
        item = wordlist[k];
        
        int l1 = word.length();
        int l2 = item.length();  
        
        //initializing unordered map , so that we can match the number of characters in both strings
        unordered_map<char,int> m;
        if(l1!=l2){
            //if different lenght, they can't be anagram
            continue;
        }
        
        for(int i=0;i<l1;i++){
            //increasing key-values for those characters, which are in word(user input)
            m[word[i]]++;
        }
        
        for(int i=0;i<l2;i++){
            if(m.find(item[i])==m.end()){
                //if any character, that was in word, not found in the item, then they are not anagram
                break;
            }
            else{
                //decreasing the corresponding values of no. of characters, which are found in item 
                m[item[i]]--;
                if(m[item[i]]==0){
                    //if all characters will be zero, then whole map will become empty.
                    m.erase(item[i]);
                }
            }
        }
        //if map is empty, it means 'word' and 'item' are anagram.
        if(m.size()==0){
            anagrams_vector.push_back(item);
        }    
    } 

  return anagrams_vector;
}
