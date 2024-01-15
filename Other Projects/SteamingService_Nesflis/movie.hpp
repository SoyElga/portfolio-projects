// Final project
// Streaming service
// Christian Jesús González Ramírez     A01657929
// Luis Grabriel Martínez Rentería      A01651812
#include <iostream>

using namespace std;

class Movie : public CatalogElement{
    private:
        Video* video;
        int rating;
    public:
        void setVideo(Video* v){this->video = v;}
        void setRating(int rating){
            if (rating < 0 || rating > 5) throw runtime_error("Invalid input");
            this->rating = rating;
            }

        int getLength() {return this->video->getLength();}
        int getRating() {return this->rating;}

        void displayInformation(){
            cout << this;
        }

        string saveInformation(){
            string info = "";
            info += "-Movie-";
            info += "\n";
            info += this->getTitle();
            info += "\n";
            info += this->getGenre();
            info += "\n";
            info += to_string(this->getLength());
            info += "\n";
            info += to_string(this->rating);
            info += "\n";
            return info;
        }

        friend ostream& operator << (ostream& os, Movie* m){
            string stars = "";
            for(int i = 0; i < m->rating; i++){
                stars += "*";
            }
           
                os << "Movie: " << m->getTitle() << m->video << "Rating: " << stars << "\nGenre: " << m->getGenre() << endl;
            
        
        return os;
        }
};