#include "pch.h"
#include <iostream>

#include "The-Celestial-Alignment-of-Lumoria.h"
#include "The-Chamber-of-Echoes.h"
#include "The-Clockwork-Town-of-Tempora.h"
#include "The-Gridlock-Arena-of-Mythos.h"
#include "The-Legendary-Duel-of-Stonevale.h"
#include "The-Magical-Forest-of-Algora.h"
#include "The-Scrolls-Of-Eldoria.h"




// Forward declarations of the Run functions for each adventure
void RunAlgora();
void RunChamberOfEchoes();
void RunEldoria();
void RunLumoria();
void RunMythos();
void RunStoneVale();
void RunTempora();



int main(int argc, char* argv[]) 
{
    std::string adventure;

    if (argc > 1) {
        adventure = std::string(argv[1]);
        std::transform(adventure.begin(), adventure.end(), adventure.begin(), ::tolower);
    }
    else {
        std::cout << "Please specify which logic to run: Sample names include: algora, chamberofechoes, elodoria, lumoria, mythos, stonevale, tempora." << std::endl;
        std::getline(std::cin, adventure);
    }

    if (adventure == "algora") {
        RunAlgora();
    }
    else if (adventure == "chamberofechoes") {
        RunChamberOfEchoes();
    }
    else if (adventure == "eldoria") {
        RunEldoria();
    }
    else if (adventure == "lumoria") {
        RunLumoria();
    }
    else if (adventure == "mythos") {
        RunMythos();
    }
    else if (adventure == "stonevale") {
        RunStoneVale();
    }
    else if (adventure == "tempora") {
        RunTempora();
    }
    else {
        std::cout << "Unknown option: " << adventure << std::endl;
    }

    return 0;
}

// Implementations or forward declarations of Run functions
void RunAlgora() {  Algora::Run(); }
void RunChamberOfEchoes() {  ChamberOfEchoes::Run();  }
void RunEldoria() {  /*Eldoria::Run();*/  }
void RunLumoria() {  Lumoria::Run();  }
void RunMythos() {  /*Mythos::Run();*/  }
void RunStoneVale() {  StoneVale::Run();  }
void RunTempora() {  Tempora::Run();  }
