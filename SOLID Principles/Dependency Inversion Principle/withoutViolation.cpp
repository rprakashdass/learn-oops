#include "../../include/print.h"

class Keyboard {
public:
    virtual void connect() = 0;
    virtual ~Keyboard() = default;
};

class WiredKeyboard : public Keyboard {
public:
    void connect() override {
        println("Wired keyboard is connected");
    }
};

class WirelessKeyboard : public Keyboard {
public:
    void connect() override {
        println("Wireless keyboard is connected");
    }
};

class Computer {
private:
    Keyboard* keyboard;
public:
    Computer(Keyboard *keyboard) {
        this->keyboard = keyboard;
    }
    void start() {
        keyboard->connect();
    }
};

int main() {
    // Wired Keyboard
    Keyboard *wired = new WiredKeyboard;
    Computer computer1(wired);
    computer1.start();

    // Wireless Keyboard
    Keyboard *wireless = new WirelessKeyboard;
    Computer computer2(wireless);
    computer2.start();
}