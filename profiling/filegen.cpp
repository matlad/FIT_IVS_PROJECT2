#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>

int main(int argc, char* argv[]) {

    if (argc != 3){
        fprintf(stderr, "Chyba pozadovany 2 argumenty pro spravny prubeh \n "
                "Prvni = pocet cislic \n Druhy = nazev vysledneho souboru \n");
    }

    std::ofstream outfile (argv[2]);

    outfile << std::stoi(argv[1]) << std::endl;

    /**
     * @brief Gnerate random number from interval (1;x) where x = value of argv[1]
     * and write it to file(name of file = value of argv[2])
     */
    for (int i = 1; i <= std::stoi(argv[1]) ; i++) {

       /* int high = std::stoi(argv[1]) + 1;
        int random = rand() % (high - 1) + 1;
        outfile << random << std::endl; */
        outfile << i << std::endl;
    }

    outfile.close();

    return 0;
}