enum class DriverType{
    None,
    DoubleTurn,
    AlwaysPull,
    SwapPull,
    DotTrigger,
};
enum class SPMode{
    Positive,
    Negative
};
enum class PhaseStatus{
    None,
    BeforeTurn,
    AfterTurn,
    WhileAction,
    DotBeforeTurn
};
enum class SubstatsRerollMode{
    Standard,
    AllCombination, // fix maxsubstats
    AllPossible
};