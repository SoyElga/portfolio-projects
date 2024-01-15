// Final project
// Streaming service
// Christian Jesús González Ramírez     A01657929
// Luis Grabriel Martínez Rentería      A01651812
#include <iostream>
#include <string>

using namespace std;

class Episode{
    private:
        Video* video;
        string name;
        int rating;
    public:
        void setVideo(Video* video){this->video = video;}
        void setName(string name){this->name = name;}
        void setRating(int rate){
            if (rate < 0 || rate > 5) throw runtime_error("Invalid rating");
            this->rating = rate;
            }
        
        Video* getVideo(){return this->video;}
        string getName(){return this->name;}
        int getRating(){return this->rating;}
};