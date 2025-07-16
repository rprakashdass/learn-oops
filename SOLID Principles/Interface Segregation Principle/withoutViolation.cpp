#include "../../include/print.h"

class ReadableDevice {
public:
    virtual void read() = 0;
};

class WritableDevice {
    public:
        virtual void write() = 0;
};

class ReaderDevice : ReadableDevice{
public:
    void read() {
        println("[ReaderDevice] is reading");
    }
};

class WriterDevice : WritableDevice{
public:
    void write() {
        println("[WriterDevice] is writing");
    }
};

int main() {
    ReaderDevice reader;
    reader.read();

    WriterDevice writer;
    writer.write();
}