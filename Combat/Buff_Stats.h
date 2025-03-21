#ifndef BUFF_STATS_H
#define BUFF_STATS_H
#include "../Print.h"
using namespace std;
#define endl '\n'
#define F first
#define S second
#define DMG_CAL 12




//check if it is ally uni
void Buff_single_target(Sub_Unit *ptr, string stats_type, string Attack_type, double Value) {  
    ptr->Stats_type[stats_type][Attack_type] += Value;
    if(Attack_type=="None")StatsAdjust(ptr,stats_type);
}
void Buff_single_target(Sub_Unit *ptr, string stats_type, string Attack_type, string Element, double Value) {  
    ptr->Stats_each_element[stats_type][Element][Attack_type] += Value;
}

void Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, double Value) {
    for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
        Buff_single_target(ptr->Sub_Unit_ptr[i].get(), stats_type, Attack_type, Value);
    }
}
void Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, string Element, double Value) {
    for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
        Buff_single_target(ptr->Sub_Unit_ptr[i].get(), stats_type, Attack_type, Element, Value);
    }
}

void Buff_single_with_all_memo_each(Ally *ptr, string stats_type, string Attack_type, double Value, string Buff_name) {
    for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
        if (ptr->Sub_Unit_ptr[i]->Buff_check[Buff_name] == 0) {
            Buff_single_target(ptr->Sub_Unit_ptr[i].get(), stats_type, Attack_type, Value);
            ptr->Sub_Unit_ptr[i]->Buff_check[Buff_name] = 1;
        }
    }
}
void Buff_single_with_all_memo_each(Ally *ptr, string stats_type, string Attack_type, string Element, double Value, string Buff_name) {
    for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
        if (ptr->Sub_Unit_ptr[i]->Buff_check[Buff_name] == 0) {
            Buff_single_target(ptr->Sub_Unit_ptr[i].get(), stats_type, Attack_type, Element, Value);
            ptr->Sub_Unit_ptr[i]->Buff_check[Buff_name] = 1;
        }
    }
}

void Buff_All_Ally(string stats_type, string Attack_type, double Value) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Buff_single_target(Ally_unit[i]->Sub_Unit_ptr[j].get(), stats_type, Attack_type, Value);
        }
    }
}
void Buff_All_Ally(string stats_type, string Attack_type, string Element, double Value) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Buff_single_target(Ally_unit[i]->Sub_Unit_ptr[j].get(), stats_type, Attack_type, Element, Value);
        }
    }
}

void Buff_All_Ally_Each_Ally(string stats_type, string Attack_type, double Value, string Buff_name) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name] == 0) {
                Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name] = 1;
                Buff_single_target(Ally_unit[i]->Sub_Unit_ptr[j].get(), stats_type, Attack_type, Value);
            }
        }
    }
}
void Buff_All_Ally_Each_Ally(string stats_type, string Attack_type, string Element, double Value, string Buff_name) {
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name] == 0) {
                Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name] = 1;
                Buff_single_target(Ally_unit[i]->Sub_Unit_ptr[j].get(), stats_type, Attack_type, Element, Value);
            }
        }
    }
}

void Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, double Value, string Buffer_name) {
    for (int i = 1; i <= Total_ally; i++) {
        if (Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name == Buffer_name) continue;
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Buff_single_target(Ally_unit[i]->Sub_Unit_ptr[j].get(), stats_type, Attack_type, Value);
        }
    }
}
void Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Element, double Value, string Buffer_name) {
    for (int i = 1; i <= Total_ally; i++) {
        if (Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name == Buffer_name) continue;
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Buff_single_target(Ally_unit[i]->Sub_Unit_ptr[j].get(), stats_type, Attack_type, Element, Value);
        }
    }
}

void Buff_All_Ally_Each_Ally_Excluding_Buffer(string stats_type, string Attack_type, double Value, string Buff_name, string Buffer_name) {
    for (int i = 1; i <= Total_ally; i++) {
        if (Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name == Buffer_name) continue;
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name] == 0) {
                Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name] = 1;
                Buff_single_target(Ally_unit[i]->Sub_Unit_ptr[j].get(), stats_type, Attack_type, Value);
            }
        }
    }
}
void Buff_All_Ally_Each_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Element, double Value, string Buff_name, string Buffer_name) {
    for (int i = 1; i <= Total_ally; i++) {
        if (Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name == Buffer_name) continue;
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            if (Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name] == 0) {
                Ally_unit[i]->Sub_Unit_ptr[j]->Buff_check[Buff_name] = 1;
                Buff_single_target(Ally_unit[i]->Sub_Unit_ptr[j].get(), stats_type, Attack_type, Element, Value);
            }
        }
    }
}

//stack buff/debuff
void Stack_Buff_single_target(Sub_Unit *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    if (ptr->Stack[Stack_Name] >= Stack_limit) return;
    if (ptr->Stack[Stack_Name] + Stack_increase > Stack_limit) {
        Stack_increase = Stack_limit - ptr->Stack[Stack_Name];
    }
    Buff_single_target(ptr, stats_type, Attack_type, Stack_increase * Value_per_stack);
    ptr->Stack[Stack_Name] += Stack_increase;
}
void Stack_Buff_single_target(Sub_Unit *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    if (ptr->Stack[Stack_Name] >= Stack_limit) return;
    if (ptr->Stack[Stack_Name] + Stack_increase > Stack_limit) {
        Stack_increase = Stack_limit - ptr->Stack[Stack_Name];
    }
    Buff_single_target(ptr, stats_type, Attack_type, Element, Stack_increase * Value_per_stack);
    ptr->Stack[Stack_Name] += Stack_increase;
}

void Stack_Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    int original_increase = Stack_increase;
    for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
        Sub_Unit *unit = ptr->Sub_Unit_ptr[i].get();
        if (unit->Stack[Stack_Name] < Stack_limit) {
            if (unit->Stack[Stack_Name] + Stack_increase > Stack_limit) {
                Stack_increase = Stack_limit - unit->Stack[Stack_Name];
            }
            Buff_single_target(unit, stats_type, Attack_type, Stack_increase * Value_per_stack);
            unit->Stack[Stack_Name] += Stack_increase;
            Stack_increase = original_increase;
        }
    }
}
void Stack_Buff_single_with_all_memo(Ally *ptr, string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    int original_increase = Stack_increase;
    for (int i = 0; i < ptr->Sub_Unit_ptr.size(); i++) {
        Sub_Unit *unit = ptr->Sub_Unit_ptr[i].get();
        if (unit->Stack[Stack_Name] < Stack_limit) {
            if (unit->Stack[Stack_Name] + Stack_increase > Stack_limit) {
                Stack_increase = Stack_limit - unit->Stack[Stack_Name];
            }
            Buff_single_target(unit, stats_type, Attack_type, Element, Stack_increase * Value_per_stack);
            unit->Stack[Stack_Name] += Stack_increase;
            Stack_increase = original_increase;
        }
    }
}

void Stack_Buff_All_Ally(string stats_type, string Attack_type, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    int original_increase = Stack_increase;
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Sub_Unit *unit = Ally_unit[i]->Sub_Unit_ptr[j].get();
            if (unit->Stack[Stack_Name] < Stack_limit) {
                if (unit->Stack[Stack_Name] + Stack_increase > Stack_limit) {
                    Stack_increase = Stack_limit - unit->Stack[Stack_Name];
                }
                Buff_single_target(unit, stats_type, Attack_type, Stack_increase * Value_per_stack);
                unit->Stack[Stack_Name] += Stack_increase;
                Stack_increase = original_increase;
            }
        }
    }
}
void Stack_Buff_All_Ally(string stats_type, string Attack_type, string Element, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    int original_increase = Stack_increase;
    for (int i = 1; i <= Total_ally; i++) {
        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Sub_Unit *unit = Ally_unit[i]->Sub_Unit_ptr[j].get();
            if (unit->Stack[Stack_Name] < Stack_limit) {
                if (unit->Stack[Stack_Name] + Stack_increase > Stack_limit) {
                    Stack_increase = Stack_limit - unit->Stack[Stack_Name];
                }
                Buff_single_target(unit, stats_type, Attack_type, Element, Stack_increase * Value_per_stack);
                unit->Stack[Stack_Name] += Stack_increase;
                Stack_increase = original_increase;
            }
        }
    }
}

void Stack_Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Buffer_name, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    int original_increase = Stack_increase;

    for (int i = 1; i <= Total_ally; i++) {
        if (Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name == Buffer_name) continue;

        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Sub_Unit* ptr = Ally_unit[i]->Sub_Unit_ptr[j].get();  // ดึง pointer ออกจาก unique_ptr
            
            if (ptr->Stack[Stack_Name] < Stack_limit) {
                if (ptr->Stack[Stack_Name] + Stack_increase > Stack_limit) {
                    Stack_increase = Stack_limit - ptr->Stack[Stack_Name];
                }

                Buff_single_target(ptr, stats_type, Attack_type, Stack_increase * Value_per_stack);
                Stack_increase = original_increase;
            }
        }
    }
}
void Stack_Buff_All_Ally_Excluding_Buffer(string stats_type, string Attack_type, string Element, string Buffer_name, double Value_per_stack, int Stack_increase, int Stack_limit, string Stack_Name) {
    int original_increase = Stack_increase;

    for (int i = 1; i <= Total_ally; i++) {
        if (Ally_unit[i]->Sub_Unit_ptr[0]->Atv_stats->Char_Name == Buffer_name) continue;

        for (int j = 0; j < Ally_unit[i]->Sub_Unit_ptr.size(); j++) {
            Sub_Unit* ptr = Ally_unit[i]->Sub_Unit_ptr[j].get();  // ดึง pointer ออกจาก unique_ptr

            if (ptr->Stack[Stack_Name] < Stack_limit) {
                if (ptr->Stack[Stack_Name] + Stack_increase > Stack_limit) {
                    Stack_increase = Stack_limit - ptr->Stack[Stack_Name];
                }

                Buff_single_target(ptr, stats_type, Attack_type, Element, Stack_increase * Value_per_stack);
                Stack_increase = original_increase;
            }
        }
    }
}


#endif