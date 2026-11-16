// Mighty Mike for GFOS: the program's version string and its stack.
// MIT, Copyright (c) 2026 AmiCradle Team.

// libnix gives the program this much stack when it starts.
extern "C" unsigned long __stack = 512 * 1024;

extern "C" const char mm_amiga_version[] __attribute__((used)) =
    "$VER: MightyMike 3.0.2 (16.11.2026)";
