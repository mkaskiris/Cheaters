#include "HashTable.h"
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include<list>
#include <array>

HashTable::HashTable() {//default constructor
    this->size = 1e6 + 3;
    table = new std::list<int>[size];
}

HashTable::HashTable(int size) {//custom size table
    this->size = size;
    table = new std::list<int>[size];
}

void HashTable::insert(std::string const &key, int filenumber) {
    //long long index = hashFunction(key);
    unsigned  long long index = hash_djb2(key);
    if(table[index].front() == NULL)
        table[index].push_front(filenumber);
    else if(table[index].front() != NULL && table[index].back() != filenumber)
        table[index].push_front(filenumber);

}

void HashTable::display() {
    for (int i = 0; i < size; i++) {
        std::cout << i;
        for (auto x : table[i])
            std::cout << " --> " << x;
        std::cout << std::endl;
    }
}

//tested 2 different hash functions, they perform about the same
long long HashTable::hashFunction(std::string const &key){

    const int p = 31;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : key) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % size;
        p_pow = (p_pow * p) % size;
    }
    return std::abs(hash_value);
}

unsigned long int HashTable::hash_djb2(std::string const &str)
{
    unsigned long int hash;
    int c;

    hash = 5381;
    for (auto x: str)
    {
        c = x;
        hash = ((hash << 5) + hash) + c;
        /* hash * 33 + c */
    }
    return (hash % this->size);
}

void HashTable::findSame(int dim, int threshold, std::vector<std::string> const &filename) {

    int **array = new int *[dim]; //array to hold similarity counter b/w files

    for(int i =0;i<dim;i++){
        array[i] = new int [dim];
        for(int j=0;j<dim;j++){
            array[i][j] = 0;
        }
    }

    for(int i=0;i<size;i++){
        for(int x : table[i]){//first number
            int first = x;
            for(int y : table[i]){//second number
                int second = y;
                if(first == second || first > second){
                }
                else {
                    array[first][second]++;
                }

            }
        }
    }

    for(int i = 0;i<dim;i++){
        for(int j=0;j<dim;j++){
            if(j>i){
                if(array[i][j] > threshold)
                    std::cout<<"file: "<<filename[i]<<", file "<<filename[j]<<" similarity counter: "<<array[i][j]<<std::endl;
            }
        }
    }
    for (int i = 0; i < dim; i++) {
        delete[] array[i]; // delete sub array
    }
    delete [] array; //delete outer array
    array = NULL;
}

HashTable::~HashTable() {
	delete [] table;
}
