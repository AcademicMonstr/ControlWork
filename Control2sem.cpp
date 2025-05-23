#include <iostream>
#include <cstring>
#include <cstdlib>

struct Strings {
    char name[50];
    int value;
};

int main() {
    const int MAX_ITEMS = 100;
    Strings arr[MAX_ITEMS];
    int amount;
 

    std::cout << "Input amount of string: ";
    std::cin >> amount;
    std::cin.ignore();


    for (int i = 0; i < amount; ++i) {
        char input[100];
        std::cout << "Input string: ";
        std::cin.getline(input, 100);

        char name[50];
        int value;
        
        int j = 0;
        while (input[j] != ' ' && input[j] != '\0') {
            name[j] = input[j];
            j++;
        }
        name[j] = '\0';
        j++;


        value = atoi(&input[j]);

        arr[i] = {0};
        strcpy(arr[i].name, name);
        arr[i].value = value;
    }


    for (int i = 0; i < amount - 1; ++i) {
        for (int j = 0; j < amount - i - 1; ++j) {
            if (arr[j].value > arr[j + 1].value) {
                Strings temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    std::cout << "\nStrings:\n";

    for (int i = 0; i < amount; ++i) {
        std::cout << arr[i].name << " " << arr[i].value << "\n";
    }

    return 0;
}