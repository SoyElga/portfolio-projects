// Final project
// Streaming service
// Christian Jesús González Ramírez     A01657929
// Luis Grabriel Martínez Rentería      A01651812
#include <iostream>
#include <fstream>
#include <string>

#include "catalogElement.hpp"

using namespace std;

class Catalog {
    private:
        CatalogElement* elements[100];
        int counter;
    public:
        Catalog() {
            counter = 0;
        }
        void addCatalogElement(CatalogElement* e) {
            e->setId(counter);
            elements[counter] = e;
            counter++;
        }

        void deleteCatalogElement() {
            int choice;
            do{
            cout << "Choose an element to delete: " << endl;
            for(int i = 0; i < counter; i++){
                cout << i + 1 << ". " << elements[i]->getTitle() << endl;
            }
            cout << "\tChoice: ";
            cin >> choice;
            }while(choice < 1 || choice > counter);
            elements[choice - 1] = elements[counter - 1];
            counter--;
        }

        int getCounter() {return counter;}

        void displayElements() {
            for (int i=0; i<counter; i++) {
                elements[i]->displayInformation();
                cout << "\n";
            }
        }
        void saveElements(){
            ofstream file;
            file.open("catalog.txt");
            for(int i = 0; i < counter; i++){
            file << elements[i]->saveInformation();
            }
            file.close();
        }
        /*
        friend ostream& operator <<(ostream& os, const Catalog* c) {
            os << "Total elements in catalog: " << c->counter;
            return os;
        }
*/
};