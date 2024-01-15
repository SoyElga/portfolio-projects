// Final project
// Streaming service
// Christian Jesús González Ramírez     A01657929
// Luis Grabriel Martínez Rentería      A01651812
#include <iostream>

using namespace std;

class Video {
    private:
        int length;
    public:
        Video(int length){
            if(length <= 0){
                throw runtime_error("Invalid length");}
            this->length = length;
        }
    int getLength() {return this->length;}

    friend ostream& operator <<(ostream& os, const Video* v) {
        os << " (" << v->length << " min)" << endl;
        return os;
    }
};