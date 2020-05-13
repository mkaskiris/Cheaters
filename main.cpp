#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>

#include "HashTable.h"

using namespace std;


int getdir (string dir, vector<string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

int main(int argc, char *argv[])
{
    time_t start, end;
    time(&start);

    if(argc != 4){
        cout << "wrong number of arguments" << endl;
        return 0;
    }

    int com_len = atoi(argv[2]); //number of consecutive words to be checked
    int threshold = atoi(argv[3]); //minimum number of similarity to flag pair

    string dir = string(argv[1]);
    vector<string> files = vector<string>();

    getdir(dir,files);

    files.erase(files.begin()); //erase .(current directory)
    files.erase(files.begin()); //erase .. (previous directory)

    cout << "Number of files: "<<files.size() <<endl;

    //display files in directory
//    for (unsigned int i = 0;i < files.size();i++) {
//        cout << i <<". " << files[i] << endl;
//    }

    HashTable hash; //i have my hashtable

    ifstream inFile;

    vector<string> text = vector<string>(); //text in a single file
    string s; //single word in the file

    string c;//string version of test
    vector<string> test = vector<string>();//text of interest /6words

    for(int i = 0; i < files.size(); i++) {

        string path = dir + files[i];

        inFile.open(path);;
        inFile >> s;

        text.clear();

        while (inFile) {//read each word and remove spaces
            transform(s.begin(), s.end(), s.begin(), ::tolower); //remove punctuation of word before putting in vector
            for (int j = 0, len = s.size(); j < len; j++) {
                // check whether parsing character is punctuation or not
                if (ispunct(s[j])) {
                    s.erase(j--, 1);
                    len = s.size();
                }
            }
            text.push_back(s);
            inFile >> s;
        }
        int first = 0;
        int last = com_len - 1;

        while (last < text.size()) {
            c = "";

            for (int j = first; j < last; j++)
                c.append(text[j]);

            first++;
            last++;

            hash.insert(c, i);
        }

    inFile.close();
    }

    //hash.display(); //print hash table
    hash.findSame(files.size(), threshold, files);

    time(&end);

    double time_taken = double(end - start);
    cout<<"Time taken: "<< time_taken << "sec"<<endl;
    return 0;
}