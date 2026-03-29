#include "Main.h"
class CharSelect{
    public:
    function<void(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar)> Char;
    int eidolon;
    function<void(CharUnit *ptr)> LC;
    int superimpose;
    function<void(CharUnit *ptr)> Relic;
    function<void(CharUnit *ptr)> Planar;
};
vector<CharSelect> CharSelectList;
void TeamSelector(){
    CharSelect nowSelect;
}
void CharSelector(function<void(int E, function<void(CharUnit *ptr)> LC, function<void(CharUnit *ptr)> Relic, function<void(CharUnit *ptr)> Planar)> &Char) {
    string name;
    bool found = false;

    while (!found) {
        cout << "Please Select Your Character: ";
        cin >> name;
        
        found = true; 

        // --- Abundance ---
        if (name == "Gallagher") 
            Char = Gallagher::Setup;
        else if (name == "Huohuo") 
            Char = Huohuo::Setup;
        else if (name == "Luocha") 
            Char = Luocha::Setup;

        // --- Destruction ---
        else if (name == "Firefly") 
            Char = FireFly::Setup;
        else if (name == "Mydei") 
            Char = Mydei::Setup;
        else if (name == "Phainon") 
            Char = Phainon::Setup;
        else if (name == "Saber") 
            Char = Saber::Setup;

        // --- Elation ---
        else if (name == "Hibana") 
            Char = Hibana::Setup;
        else if (name == "YaoGuang") 
            Char = YaoGuang::Setup;

        // --- Erudition ---
        else if (name == "Anaxa") 
            Char = Anaxa::Setup;
        else if (name == "Jade") 
            Char = Jade::Setup;
        else if (name == "Jingyuan") 
            Char = Jingyuan::Setup;
        else if (name == "Rappa") 
            Char = Rappa::Setup;
        else if (name == "Serval") 
            Char = Serval::Setup;
        else if (name == "TheHerta") 
            Char = TheHerta::Setup;

        // --- Harmony ---
        else if (name == "Bronya") 
            Char = Bronya::Setup;
        else if (name == "Cerydra") 
            Char = Cerydra::Setup;
        else if (name == "Hanabi") 
            Char = Hanabi::Setup;
        else if (name == "HanabiV1") 
            Char = HanabiV1::Setup;
        else if (name == "HarmonyMC") 
            Char = HarmonyMC::Setup;
        else if (name == "Robin") 
            Char = Robin::Setup;
        else if (name == "RuanMei") 
            Char = RuanMei::Setup;
        else if (name == "Sunday") 
            Char = Sunday::Setup;
        else if (name == "Tingyun") 
            Char = Tingyun::Setup;
        else if (name == "Tribbie") 
            Char = Tribbie::Setup;

        // --- Nihility ---
        else if (name == "BS") 
            Char = BSV1::Setup;
        else if (name == "Cipher") 
            Char = Cipher::Setup;
        else if (name == "Guinaifen") 
            Char = Guinaifen::Setup;
        else if (name == "Hysilens") 
            Char = Hysilens::Setup;
        else if (name == "Kafka") 
            Char = Kafka::Setup;
        else if (name == "Luka") 
            Char = Luka::Setup;
        else if (name == "Pela") 
            Char = Pela::Setup;
        else if (name == "SW") 
            Char = SW::Setup;

        // --- Remembrance ---
        else if (name == "Aglaea") 
            Char = Aglaea::Setup;
        else if (name == "Castorice") 
            Char = Castorice::Setup;
        else if (name == "Hyacine") 
            Char = Hyacine::Setup;
        else if (name == "RMC") 
            Char = RMC::Setup;

        // --- The Hunt ---
        else if (name == "Archer") 
            Char = Archer::Setup;

        // --- Not Found Case ---
        else {
            cout << "Character '" << name << "' not found! Please try again." << endl;
            found = false; 
        }
    }
}