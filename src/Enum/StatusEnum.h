enum class DriverType{
    None,
    DoubleTurn,
    AlwaysPull,
    SwapPull,
};
enum class SPMode{
    Positive,
    Negative
};
enum class PhaseStatus{
    None,
    BeforeTurn,
    AfterTurn,
    WhileAction
};
enum class SubstatsRerollMode{
    Standard,
    AllCombination, // fix maxsubstats
    AllPossible
};