#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
//Denica Slavcheva KN 81275 1gr 1potok
void readFile(ifstream & file, vector<string> & words)
{
    if(file.is_open())
    {
        string word;
        while(getline(file, word))
        {
            words.push_back(word);
        }
    }
}

void upToLow(vector<string> & words)
{
    for(int i=0; i<words.size(); i++)
    {
        transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
    }
}

void sortWords(vector<string> & words)
{
    for(int i=0; i<words.size(); i++)
    {
        sort(words[i].begin(), words[i].end());
    }
}

map<string, int> mapAnagrams(vector<string> & words)
{
    map<string, int> anagrams;

    for(int i=0; i<words.size(); i++)
    {
        if(anagrams.count(words[i]) > 0)
        {
            anagrams[words[i]]++;
        }
        else
        {
            anagrams.insert(pair<string, int>(words[i], 0));
        }
    }

    return anagrams;
}

int countAnagrams(map<string, int> & anagrams)
{
    int counter = 0;

    for(map<string, int>::iterator word=anagrams.begin(); word!=anagrams.end(); ++word)
    {
        if(word->second > 1) counter++;
    }

    return counter;
}

int main()
{
    ifstream file("input.txt");
    vector<string> words;
    readFile(file, words);
    upToLow(words);
    sortWords(words);
    map<string,int> anagrams = mapAnagrams(words);
    int anagrams_count = countAnagrams(anagrams);
    cout<<anagrams_count<<endl;

    return 0;
}
