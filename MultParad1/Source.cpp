
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
using namespace std;


int main()
{
    ifstream infile;
    infile.open("infile.txt");
    
    string text, word;
    map<string, int> M;

    //Читання з файлу та відокремлення слів
read:
    if (getline(infile, text)) {

        stringstream textstr(text);
    readword:
        if (textstr >> word) {
            cout << endl << word;
            int i = 0;
            int wordsize=word.length();
           lowercaseloop:
            word[i] = tolower(word[i]);
            i++;
            if (i != wordsize)
                goto lowercaseloop;
            if(word!="in"&& word != "on"&& word != "of"&& word != "for"&& word != "the"&& word != "not")
            if (M.find(word) == M.end())
                M.insert(make_pair(word, 1));
            else
                M[word]++;
            

            goto readword;
        }
        goto read;
    }
   
    infile.close();
    ofstream outfile;
    outfile.open("outfile.txt");
    //Вивід
        auto it = M.begin();
        if (M.size() == 0)
            goto end;
        output:
        outfile << (*it).first << " - "
            << (*it).second
            << endl;
        it++;
        if (it != M.end()) {    
            goto output;
        }
    end:
        outfile.close();
        return 0;
    
}
    
