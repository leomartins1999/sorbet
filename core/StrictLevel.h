#ifndef SORBET_CORE_STRICT_LEVEL_H
#define SORBET_CORE_STRICT_LEVEL_H

namespace sorbet::core {
enum class StrictLevel {
    // Internal Sorbet errors. There is no syntax to make those errors ignored.
    // This error should _always_ be lower than any other level so that there's no way to silence internal errors.
    Internal = 0,

    // No user errors are at this level.
    None = 1,

    // Don't even parse this file.
    Ignore = 2,

    // Only errors related to syntax, constant resolution and correctness of sigs are reported.
    False = 3,

    // Things that would normally be called "type errors" are reported.
    // This includes calling a non-existent method, calling a method with mismatched
    // argument counts, using variables inconsistently with their types, etc.
    True = 4,

    // Everything must be declared.
    Strict = 5,

    // Nothing can be T.untyped in the file. Basically Java.
    Strong = 6,

    // No errors are at this level.
    Max = 7,

    // Custom levels which mirror another level with some tweaks.

    // Identical to Strict except allow constants to be undefined. Useful for
    // .rbi files that are written by scripts but you don't require people
    // update them when they delete a class.
    Autogenerated = 10,
};
} // namespace sorbet::core

#endif
