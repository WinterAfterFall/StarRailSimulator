#include "../include.h"

void extendBuffTimeAllAlly(std::string Buff_name, int Turn_extend);
void extendBuffTimeExcludingBuffer(std::string Buff_name, int Turn_extend, std::string Buffer_name);
void extendBuffTimeExcludingBuffer(std::string Buff_name, int Turn_extend, SubUnit *Buffer);

void buffAllAlly(std::vector<BuffClass> buffSet);
void buffAllAlly(std::vector<BuffElementClass> buffSet);
void buffAllAlly(std::vector<BuffClass> buffSet, std::string Buff_name, int extend);
void buffAllAlly(std::vector<BuffElementClass> buffSet, std::string Buff_name, int extend);
