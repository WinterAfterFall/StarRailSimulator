#include "../include.h"
namespace CharCmd {

    void printUltStart(std::string name);
    void printUltEnd(std::string name);
    void printText(std::string text);

    Ally* findAllyName(std::string name);

    void Set_Technique(Ally* ptr, int tech);
    void Set_Tune_Speed(Ally* ptr, double value);
    void Set_Reroll_check(Ally* ptr, bool Bool);
    void Timing_print(Ally* ptr);
    bool Using_Skill(Ally* ptr);
    void Set_Other_buff(Ally* ptr, bool Bool);
}
