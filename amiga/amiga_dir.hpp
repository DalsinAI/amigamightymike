// The AmigaOS side of Mighty Mike for GFOS: its current directory.
// MIT, Copyright (c) 2026 AmiCradle Team.
#ifndef MM_AMIGA_DIR_HPP
#define MM_AMIGA_DIR_HPP

// Makes PROGDIR: (the game's drawer) the current directory, so that the
// game's relative Data/ and User/ paths are found when it is
// started from a Shell anywhere. The Shell's own directory comes back when
// the game exits, however it exits.
void amiga_enter_progdir();

// Makes the drawer's User directory (preferences, saved games) when it is
// missing; call after amiga_enter_progdir.
void amiga_make_user_dir();

#endif  // MM_AMIGA_DIR_HPP
