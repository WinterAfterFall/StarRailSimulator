#include "../include.h"
namespace CharCmd {

    void printUltStart(std::string name);
    void printUltEnd(std::string name);
    void printText(std::string text);

    CharUnit* findAllyName(std::string name);

    void Set_Technique(CharUnit* ptr, int tech);
    void Set_Tune_Speed(CharUnit* ptr, double value);
    void Set_Reroll_check(CharUnit* ptr, bool Bool);
    void Timing_print(CharUnit* ptr);
    bool Using_Skill(CharUnit* ptr);
    void Set_Other_buff(CharUnit* ptr, bool Bool);
}
