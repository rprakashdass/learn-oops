#include "../../include/print.h"

class DataHandler {
public:
    virtual void read() = 0;
    virtual void write() = 0;
};

class ReaderDevice : DataHandler{
public:
    void read() {
        println("Printer is reading");
    }
};

class WriterDevice : DataHandler{
public:
    void write() {
        println("Printer is writing");
    }
};

int main() {
}