//include headers and libraries
#include "Library.h"
#include <iostream>

using namespace std;
//implement class functions
Library:: Library(){
    for(int i = 0; i < 10; i++){
        books[i] = "";
    }
}

bool Library:: addBook(string bookName){
    for(int i = 0; i < 10; i++){
        if(books[i] == bookName){
            return false;
        }
    }
    for(int i = 0; i < 10; i++){
        if(books[i] == ""){
            books[i] = bookName;
            return true;
        }
    }
    return false;
}

bool Library:: removeBook(string bookName){
    for(int i = 0; i < 10; i++){
        if(books[i] == bookName){
            books[i] = "";
            return true;
        }
    }
    return false;
}

//explicit type is missing ('int' assumed)


void Library:: print(){
    for(int i = 0; i < 10; i++){
        cout << books[i] << endl;
    }
}

//Write a main function that tests your class.
/*You also need to write a program that creates a Library object and prompts for one of the following
commands:
a bookName //add the book named bookName to the library if not already existing and
//if there is availability
r bookName //remove the book bookName if it exists in the library
p //print the library contents
q //quit the program
Your program should show messages if it cannot successfully add or remove a book. You can
assume that the input command is always valid, and the book name always consists of a single
word.*/
int main(){
    Library lib;
    string command;
    string bookName;
    while(true){
        cin >> command;
        if(command == "a"){
            cin >> bookName;
            if(lib.addBook(bookName)){
                cout << "Book added" << endl;
            }
            else{
                cout << "Book already exists or library is full" << endl;
            }
        }
        else if(command == "r"){
            cin >> bookName;
            if(lib.removeBook(bookName)){
                cout << "Book removed" << endl;
            }
            else{
                cout << "Book does not exist" << endl;
            }
        }
        else if(command == "p"){
            lib.print();
        }
        else if(command == "q"){
            break;
        }
    }
    return 0;
}