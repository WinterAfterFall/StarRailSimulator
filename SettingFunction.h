#include "Main.h"
bool askYesNo() {
    std::string input;
    
    while (true) {
        std::getline(std::cin, input);

        // 1. ถ้ากด Enter (ค่าว่าง) ให้ return true
        if (input.empty()) {
            return true;
        }

        // แปลง input ให้เป็นตัวพิมพ์เล็กทั้งหมด เพื่อให้พิมพ์ Yes, yes, YES ก็ได้เหมือนกัน
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        // 2. เช็กค่า yes
        if (input == "yes" || input == "y") {
            return true;
        }
        
        // 3. เช็กค่า no
        if (input == "no" || input == "n") {
            return false;
        }

        // 4. ถ้าไม่ใช่ทั้งคู่ ให้ลูปรับค่าใหม่
        std::cout << "ขออภัย กรุณาพิมพ์ yes หรือ no เท่านั้น\n";
    }
}
bool askNoYes() {
    std::string input;
    
    while (true) {
        std::getline(std::cin, input);

        // 1. ถ้ากด Enter (ค่าว่าง) ให้ return true
        if (input.empty()) {
            return true;
        }

        // แปลง input ให้เป็นตัวพิมพ์เล็กทั้งหมด เพื่อให้พิมพ์ Yes, yes, YES ก็ได้เหมือนกัน
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);

        // 2. เช็กค่า yes
        if (input == "yes" || input == "y") {
            return false;
        }
        
        // 3. เช็กค่า no
        if (input == "no" || input == "n") {
            return true;
        }

        // 4. ถ้าไม่ใช่ทั้งคู่ ให้ลูปรับค่าใหม่
        std::cout << "ขออภัย กรุณาพิมพ์ yes หรือ no เท่านั้น\n";
    }
}
class CharSelect{
    public:
    function<void(int E,function<void(CharUnit *ptr)> LC,function<void(CharUnit *ptr)> Relic,function<void(CharUnit *ptr)> Planar)> Char;
    int eidolon;
    function<void(CharUnit *ptr)> LC;
    function<void(CharUnit *ptr)> Relic;
    function<void(CharUnit *ptr)> Planar;
};

void CharSelector(function<void(int E, function<void(CharUnit *ptr)> LC, function<void(CharUnit *ptr)> Relic, function<void(CharUnit *ptr)> Planar)> &Char,int eidolon) {
    string name;
    bool found = false;

    while (!found) {
        cout << "Please Select Your Character: ";
        std::getline(std::cin >> std::ws, name);
        
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

    cout<<"Choose Eidolon Value"<<endl;
    cin>>eidolon;
}
void LightConeSelector(function<void(CharUnit *ptr)> &LC){
    string name;
    int superimpose;
    bool found = false;
    function<function<void(CharUnit *ptr)>(int superimpose)> lightConeFunction;
    while (!found) {
        cout << "Please Select Your Light Cone: ";
        std::getline(std::cin >> std::ws, name);


        found = true; 

        // --- Abundance ---
        if (name == "Multiplication") 
            lightConeFunction = Abundance_Lightcone::Multiplication;

        // --- Destruction ---
        else if(name == "Blade LC")
            lightConeFunction = Destruction_Lightcone::Blade_LC;
        else if(name == "Bygone Blood")
            lightConeFunction = Destruction_Lightcone::BP2;
        else if(name == "Clara LC")
            lightConeFunction = Destruction_Lightcone::Clara_LC;
        else if(name == "DHIL LC")
            lightConeFunction = Destruction_Lightcone::Danheng_LC;
        else if(name == "Firefly LC")
            lightConeFunction = Destruction_Lightcone::FireFly_LC;            
        else if(name == "Fall of an Aeon")
            lightConeFunction = Destruction_Lightcone::Hertashop;
        else if(name == "Jingliu LC")
            lightConeFunction = Destruction_Lightcone::Jingliu_LC;
        else if(name == "Mydei LC")
            lightConeFunction = Destruction_Lightcone::Mydei_LC;
        else if(name == "Ninja Record")
            lightConeFunction = Destruction_Lightcone::Ninja_Record;            
        else if(name == "Phainon LC")
            lightConeFunction = Destruction_Lightcone::Phainon_LC;
        else if(name == "Saber LC")
            lightConeFunction = Destruction_Lightcone::Saber_LC;
        else if(name == "Secret Vow"){
            cout<<"Is buff 100% Uptime : "<<endl;
            if(askYesNo())
                lightConeFunction = Destruction_Lightcone::Secret_Vow;
            else 
                lightConeFunction = Destruction_Lightcone::Secret_Vow_NoBuff; 
        }
        else if(name == "The Moles")
            lightConeFunction = Destruction_Lightcone::The_Moles;


        // --- Elation ---
        else if(name == "Hibana LC" || name == "Sparxie LC")
            lightConeFunction = Elation_Lightcone::Hibana_LC;
        else if(name == "Mushy Shroomy")
            lightConeFunction = Elation_Lightcone::MushyShroomy;
        else if(name == "Today Good Luck" || name == "TDGL")
            lightConeFunction = Elation_Lightcone::TodayGoodLuck;
        else if(name == "YaoGuang LC")
            lightConeFunction = Elation_Lightcone::YaoGuang_LC;

        // --- Erudition ---
        else if(name == "Anaxa LC")
            lightConeFunction = Erudition_Lightcone::Anaxa_LC;
        else if(name == "Jingyuan LC")
            lightConeFunction = Erudition_Lightcone::Before_Dawn;
        else if(name == "Peaceful Day")
            lightConeFunction = Erudition_Lightcone::BP_Erudition;
        else if(name == "Calculus")
            lightConeFunction = Erudition_Lightcone::Calculus;
        else if(name == "Cosmos Fell")
            lightConeFunction = Erudition_Lightcone::Cosmos_Fell;
        else if(name == "Great Cosmic")
            lightConeFunction = Erudition_Lightcone::GreatCosmic;
        else if(name == "Himeko LC")
            lightConeFunction = Erudition_Lightcone::Himeko_LC;
        else if(name == "Passkey")
            lightConeFunction = Erudition_Lightcone::Passkey;
        else if(name == "Rappa LC")
            lightConeFunction = Erudition_Lightcone::Rappa_LC;
        else if(name == "THerta LC")
            lightConeFunction = Erudition_Lightcone::The_Herta_LC;  
            
        // --- Harmony ---
        else if(name == "Bronya LC")
            lightConeFunction = Harmony_Lightcone::Bronya_LC;
        else if(name == "Cerydra LC")
            lightConeFunction = Harmony_Lightcone::Cerydra_LC;
        else if(name == "DDD")
            lightConeFunction = Harmony_Lightcone::DDD;
        else if(name == "For Tomorrow Journey")
            lightConeFunction = Harmony_Lightcone::For_Tomorrow_Journey;
        else if(name == "The Forever Victual")
            lightConeFunction = Harmony_Lightcone::ForeverVictual;
        else if(name == "MOTP" || name == "Memories of the Past")
            lightConeFunction = Harmony_Lightcone::Memories_of_the_Past;
        else if(name == "Meshing Cogs")
            lightConeFunction = Harmony_Lightcone::Meshing_Cogs;
        else if(name == "Robin LC")
            lightConeFunction = Harmony_Lightcone::Robin_LC; 
        else if(name == "Sunday LC")
            lightConeFunction = Harmony_Lightcone::Sunday_LC;
        else if(name == "Tribbie LC")
            lightConeFunction = Harmony_Lightcone::Tribbie_LC;

        // --- Nihility ---
        else if(name == "Before The Tutorial")
            lightConeFunction = Nihility_Lightcone::Before_the_Tutorial;
        else if(name == "Black Swan LC" || name == "BS LC")
            lightConeFunction = Nihility_Lightcone::BlackSwan_LC;
        else if(name == "Holiday Thermae")
            lightConeFunction = Nihility_Lightcone::BP2;
        else if(name == "Cipher LC")
            lightConeFunction = Nihility_Lightcone::Cipher_LC;
        else if(name == "Eyes Of The Prey" || name == "EOTP")
            lightConeFunction = Nihility_Lightcone::EyesOfThePrey;
        else if(name == "Fermata")
            lightConeFunction = Nihility_Lightcone::Fermata;
        else if(name == "Fugue LC")
            lightConeFunction = Nihility_Lightcone::Fugue_LC;
        else if(name == "GNSW")
            lightConeFunction = Nihility_Lightcone::GNSW;
        else if(name == "Solitary Healing")
            lightConeFunction = Nihility_Lightcone::HertaShop;            
        else if(name == "Hysilens LC")
            lightConeFunction = Nihility_Lightcone::Hysilens_LC;
        else if(name == "Jiaoqiu LC"){
            cout<<"Select superimpose value : "<<endl;
            cin>>superimpose;
            cout<<"Is Dot 100% Uptime : "<<endl;
            LC = Nihility_Lightcone::Jiaoqiu_LC(superimpose,askYesNo());
            return;
        }
        else if(name == "Kafka LC")
            lightConeFunction = Nihility_Lightcone::Kafka_LC;
        else if(name == "Resolution")
            lightConeFunction = Nihility_Lightcone::Resolution;
        else if(name == "ShowTime")
            lightConeFunction = Nihility_Lightcone::ShowTime;

        // --- Remembrance ---
        else if(name == "Aglaea LC")
            lightConeFunction = Remembrance_Lightcone::Aglaea_LC;
        else if(name == "Castorice LC")
            lightConeFunction = Remembrance_Lightcone::Castorice_LC;
        else if(name == "Geniuses Greetings")
            lightConeFunction = Remembrance_Lightcone::Geniuses_Greetings;
        else if(name == "Hyacnine LC")
            lightConeFunction = Remembrance_Lightcone::Hyacnine_LC;
        else if(name == "Curtain Never Falls")
            lightConeFunction = Remembrance_Lightcone::RemembranceHertaShop;
        else if(name == "Reminiscence")
            lightConeFunction = Remembrance_Lightcone::Reminiscence;
        else if(name == "Sweat Now Cry Less" || name == "SNCL")
            lightConeFunction = Remembrance_Lightcone::SweatNowCryLess;
        else if(name == "Victory In Blink" || name == "VIB")
            lightConeFunction = Remembrance_Lightcone::Victory_In_Blink;


        else {
            cout << "Light Cone '" << name << "' not found! Please try again." << endl;
            found = false; 
        }
    }
    cout<<"Select superimpose value : "<<endl;
    cin>>superimpose;

    LC = lightConeFunction(superimpose);
}
void RelicSelector(function<void(CharUnit *ptr)> &Relic){
    string name;
    bool found = false;
    while (!found) {
        cout << "Please Select Your Relic: ";
        std::getline(std::cin >> std::ws, name);
        found = true; 

        if (name == "Wavestrider Captain") 
            Relic = Relic::Captain;
        else if (name == "Diviner Of Distant"){
            cout<<"Is your character'speed more than 200 : ";
            Relic = Relic::DivinerOfDistant(askYesNo());
        }
        else if (name == "Eagle") 
            Relic = Relic::Eagle_Beaked_Helmet;
        else if (name == "Genius Brilliant") 
            Relic = Relic::GeniusBrilliant;
        else if (name == "Sun and Thunder") 
            Relic = Relic::Goddess_of_Sun_and_Thunder;
        else if (name == "Grand Duke") 
            Relic = Relic::Grand_Duke;
        else if (name == "Hero Wreath") 
            Relic = Relic::Hero_Wreath;
        else if (name == "Iron Cavalry") 
            Relic = Relic::Iron_Cavalry;
        else if (name == "Knight") 
            Relic = Relic::Knight;
        else if (name == "Magical Girl") 
            Relic = Relic::MagicalGirl;
        else if (name == "Pair Set"){
            string firstStats,secondStats;
            cout<<"choose your first set";
            cin>>firstStats;
            cout<<"choose your second set";
            cin>>secondStats;
            Relic = Relic::PairSet(transString(firstStats),transString(secondStats));
        }
        else if (name == "Poet Dill") 
            Relic = Relic::Poet_Dill;
        else if (name == "Prisoner") 
            Relic = Relic::Prisoner;
        else if (name == "Sacerdos") 
            Relic = Relic::Sacerdos_Relived_Ordeal;
        else if (name == "Scholar") 
            Relic = Relic::Scholar;

        // --- Not Found Case ---
        else {
            cout << "Relic '" << name << "' not found! Please try again." << endl;
            found = false; 
        }
    }
}
void PlanarSelector(function<void(CharUnit *ptr)> &Planar){
        string name;
    bool found = false;
    while (!found) {
        cout << "Please Select Your Relic: ";
        std::getline(std::cin >> std::ws, name);
        found = true; 

        if (name == "Arcadia") 
            Planar = Planar::Arcadia;
        else if (name == "Bone Collection")
            Planar = Planar::Bone_Collection;
        else if (name == "Broken Keel")
            Planar = Planar::Broken_Keel;
        else if (name == "Firmanent Frontline"){
            cout<<"Is your character'speed more than 160 : ";
            Planar = Planar::FirmanentFrontline(askYesNo());
        }
        else if (name == "Giant Tree"){
            cout<<"Is your character'speed more than 180 : ";
            Planar = Planar::GiantTree(askYesNo());
        }
        else if (name == "Inert")
            Planar = Planar::Inert;
        else if (name == "Izumo") 
            Planar = Planar::Izumo;
        else if (name == "Kalpagni Lantern")
            Planar = Planar::Kalpagni_Lantern;
        else if (name == "Lushaka")
            Planar = Planar::Lushaka;
        else if (name == "Revelry") 
            Planar = Planar::Revelry;
        else if (name == "Rutilant")
            Planar = Planar::Rutilant;
        else if (name == "SpaceSealing")
            Planar = Planar::SpaceSealing;
        else if (name == "Talia") 
            Planar = Planar::Talia;
        else if (name == "Tengoku Livestream")
            Planar = Planar::TengokuLivestream;
        else if (name == "BananAmusement Park")
            Planar = Planar::The_Wondrous_BananAmusement_Park;
            
        // --- Not Found Case ---
        else {
            cout << "Planar '" << name << "' not found! Please try again." << endl;
            found = false; 
        }
    }
}
void EnemySelector(){
    int Tenemy;
    cout<<"How much enemy do you want : "<<endl;
    cin>>Tenemy;
    cout<<"Do you want to configure enemy status by yourself? : "<<endl;
    if(askNoYes()){
        SetupEnemy(158,160,{10,15},{200,300},{4,6},2,EnemyType::Main);
        SetupEnemy(158,160,{10,10},{200,300},{4,6},2,EnemyType::Adjacent);
    }
}
vector<CharSelect> CharSelectList;
void BuildSelector(){
    CharSelect nowSelect;
    CharSelector(nowSelect.Char,nowSelect.eidolon);
    LightConeSelector(nowSelect.LC);
    RelicSelector(nowSelect.Relic);
    PlanarSelector(nowSelect.Planar);
    CharSelectList.push_back(nowSelect);
}