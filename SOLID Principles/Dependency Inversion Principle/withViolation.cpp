#include "../../include/print.h"

class WiredKeyboard {
    public:
    void connect() {
        println("Wired keyboard is connected");
    }
};

class Computer {
private:
    WiredKeyboard keyboard;
public:
    void start() {
        keyboard.connect();
    }
};

int main() {
    Computer pc;
    pc.start();
}