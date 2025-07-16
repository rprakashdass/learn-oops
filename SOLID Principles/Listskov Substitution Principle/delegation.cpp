#include <iostream>

void printText(const std::string& body) {
    std::cout << body << std::endl;
}

class Printer {
public:
    void print(const std::string& text) {
        std::cout << ("[Printer] Started printing..\n") << text << std::endl;
    }
};

class ReportGenerator {
    private:
        Printer printer; // we are delegating printers task to report generator
    public:
        const std::string report = "This is the report";
        void generateReport() {
            printer.print(report);
        }
};

int main() {
    ReportGenerator reportGenerator;
    reportGenerator.generateReport();
}