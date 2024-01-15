// Final project
// Streaming service
// Christian Jesús González Ramírez     A01657929
// Luis Grabriel Martínez Rentería      A01651812#include <iostream>
#include <string>

using namespace std;

class CatalogElement {  
    private:
        int id;
        string title, genre;
    public:
        void setId(int id) { this->id = id; }
        void setTitle(string title) { this->title = title; }
        void setGenre(string genre) { this->genre = genre; }
        
        string getTitle() { return this->title; }
        string getGenre() { return this->genre; }
        int getId() { return this->id; }

        virtual int getLength() = 0;
        virtual int getRating() = 0;
        virtual void displayInformation() = 0;
        virtual string saveInformation() = 0;
};