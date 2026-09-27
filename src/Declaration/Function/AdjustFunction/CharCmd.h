#include "../include.h"
namespace CharCmd {

    void printUltStart(std::string name);
    void printUltEnd(std::string name);
    void printText(std::string text);

    CharUnit* findAllyName(std::string name);

    void setTechnique(CharUnit* ptr, int tech);
    void setTuneSpeed(CharUnit* ptr, double value);
    void setRerollCheck(CharUnit* ptr, bool flag);
    void timingPrint(CharUnit* ptr);
    bool usingSkill(CharUnit* ptr);
}
