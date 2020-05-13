//
// Created by mkask on 02/05/2020.
//

#ifndef CHEATERS_HASHTABLE_H
#define CHEATERS_HASHTABLE_H


#include <list>
#include <string>
#include <vector>

class HashTable {
private:
    int size;

    std::list<int> *table;
public:
    HashTable();

    HashTable(int size);

    void insert(std::string const &key, int filenumber);

    void display();

    long long hashFunction(std::string const &key);

    unsigned long int hash_djb2(std::string const &str);

    void findSame(int dim, int threshold, std::vector<std::string> const &filename);

    ~HashTable();

};


#endif //CHEATERS_HASHTABLE_H
