# Cheaters
Plagiarism detection program

Program to detect similarities between .txt files using separate chaining implementation of hash tables.

NOTE: number of similarities might be a bit higher than the actual number due to improper collisions in the hash table due to the hash funciton used.

removes all punctuation from text and converts all letters to lowecase. does not remove special characters.

To use:

type 'make' in the command line program name: ./plagiarismCatcher

supply 3 arguments to the command line

path
lenth of words to be tested each time
minimum threshold for similarity detection
-if you want to print the directory of files just uncomment the appropriate part commented in the code

-if you want to see the hash table uncomment the line hash.display()

Hash tables commmands: -insert inserts values into the hashtable using the hashfunction can choose which hash function to use by commenting out 1 of the first 2 lines in the method -hashfunction 2 different hash functions are supplied with the programm, both perform about the same -display prints the hashtable to the console -findSame using the threshold value provided by the user prints similarities b/w files to the console
