#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class VonNeumannMachine {
private:
    vector<int> memory;
    int accumulator;
    int programCounter;
    int instructionRegister;
    bool isRunning;

public:
    VonNeumannMachine() : memory(100, 0), accumulator(0), programCounter(0), instructionRegister(0), isRunning(true) {}

    void loadProgram(const vector<int>& program) {
        for (size_t i = 0; i < program.size() && i < memory.size(); ++i) {
            memory[i] = program[i];
        }
    }

    void fetch() {
        instructionRegister = memory[programCounter];
        programCounter++;
    }

    void execute() {
        int opcode = instructionRegister / 100;
        int operand = instructionRegister % 100;

        switch (opcode) {
            case 0: 
                isRunning = false; 
                break;
            case 1: 
                accumulator += memory[operand]; 
                break;
            case 2: 
                accumulator -= memory[operand]; 
                break;
            case 3: 
                memory[operand] = accumulator; 
                break;
            case 5: 
                accumulator = memory[operand]; 
                break;
            case 9:
                if (operand == 1) {
                    cout << "IN: ";
                    cin >> accumulator;
                } else if (operand == 2) {
                    cout << "OUT: " << accumulator << endl;
                }
                break;
            default:
                isRunning = false;
                break;
        }
    }

    void run() {
        while (isRunning && programCounter < 100) {
            fetch();
            execute();
        }
    }
};

int main() {
    VonNeumannMachine cpu;
    
    vector<int> program = {
        901, 
        399, 
        901, 
        199, 
        902, 
        000  
    };
    
    cout << "=== SIMULADOR VON NEUMANN ===" << endl;
    cpu.loadProgram(program);
    cpu.run();
    
    return 0;
}
