// PA12: Pointer Tracker
// Uses one pointer to adjust two expedition gauges: first oxygen,
// then fuel, and finally no gauge at all (null).

#include <iostream>

// Prints the current gauge values with a label for the stage.
void printGauges(const char* label, int oxygen, int fuel)
{
    std::cout << label << ": oxygen=" << oxygen << " fuel=" << fuel << '\n';
}

// Adjusts whichever gauge the pointer refers to.
// Returns true if a change was made, false if no gauge was selected.
bool adjustGauge(int* gauge, int amount)
{
    if (gauge == nullptr)
    {
        return false; // nothing selected, so nothing is changed
    }

    *gauge += amount; // change the gauge through the pointer
    return true;
}

int main()
{
    int oxygen = 80;
    int fuel = 45;

    // Step 1: point at oxygen and decrease it by 10.
    int* activeGauge = &oxygen;
    adjustGauge(activeGauge, -10);
    printGauges("After oxygen adjustment", oxygen, fuel);

    // Step 2: reassign the same pointer to fuel and increase it by 5.
    activeGauge = &fuel;
    adjustGauge(activeGauge, 5);
    printGauges("After fuel adjustment", oxygen, fuel);

    // Step 3: select no gauge, then check before trying to use the pointer.
    activeGauge = nullptr;
    if (!adjustGauge(activeGauge, 5))
    {
        std::cout << "No active gauge\n";
    }

    printGauges("Final", oxygen, fuel);

    return 0;
}