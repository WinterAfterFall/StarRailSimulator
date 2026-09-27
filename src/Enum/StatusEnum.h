enum class DriverType{
    NONE,
    DOUBLE_TURN,
    ALWAYS_PULL,
    SWAP_PULL,
    DOT_TRIGGER,
};
enum class SPMode{
    POSITIVE,
    NEGATIVE
};
enum class PhaseStatus{
    NONE,
    BEFORE_TURN,
    AFTER_TURN,
    WHILE_ACTION,
    DOT_BEFORE_TURN,
};
enum class SubstatsRerollMode{
    STANDARD,
    // AllCombination, // fix maxsubstats   ปิดไว้ก่อน — ดู Substats_Reset.h
    // AllPossible
};