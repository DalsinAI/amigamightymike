Mighty Mike for GFOS
====================

A port of Mighty Mike (Power Pete), Pangea Software's 1995 top-down
action game, as updated by Iliyas Jorio, from
https://github.com/jorio/MightyMike at commit
10c049e12ade1244b4addf0824553b2049f450d0 (version 3.0.2, the last on
SDL 2), for GFOS: AmigaOS 3.2 with GFOpenUp, on a 68040 or 68060 with an
FPU, on GFOpenUp's SDL 2.

Mike is a toy-store action figure come to life: fight through five toy
worlds (Prehistoric Plaza, Candy Cane Lane, Clowning Around, Fairy Tale
Trail and the Games Gallery) to rescue the kids.

Status: see the pull request (stove build and lab).


What you need
-------------

- GFOS: AmigaOS 3.2 with GFOpenUp, which installs
  LIBS:GFOpenGPU/SDL2.module.
- A 68040 or 68060 with an FPU (not an LC040 or EC040), an RTG screen of
  640 x 480 or more (or the AmiCradle lab), and about 24 MB of free
  memory.
- About 20 MB on the disk.


How to play
-----------

Run Install-MightyMike (or copy the MightyMike drawer where you want it),
then double-click MightyMike, or start it from a Shell from anywhere: the
game makes its own drawer its current directory while it runs. The keys
are in the drawer's Controls file. Your settings, high scores and saved
games are kept in the drawer's User drawer (User/MightyMike);
Install-MightyMike keeps it when it updates the game.


Building
--------

    make -f amiga/Makefile.amigaos -j4 STOVE=/path/to/os32-gcc16-open6

or, in Cradle, stove_build with the os32-gcc16-open6 stove and target
package (package/build-amiga.sh), which also packs
MightyMike-VERSION-68040.lha.

    tests/host/run.sh

runs the host tests of the port's change to Pomme (no SDL needed).


What was changed
----------------

- The game draws through SDL's 2D renderer (upstream's SDLRender, its
  build without GLRENDER) and runs one thread (no render threads, as
  upstream's build for PowerPC Macs).
- __BIG_ENDIAN__ is defined, so Pomme and the game read the Mac data
  without byte swapping, as on a PowerPC Mac.
- src/Main.cpp: the Amiga build makes PROGDIR: its current directory
  first and makes User/ there when missing (amiga/amiga_dir.cpp), then
  finds Data/ in it.
- extern/Pomme/src/Files/Files.cpp: on AmigaOS the preferences folder
  is the drawer's User directory. tests/host/test_prefs.cpp checks it
  with the calls the game makes.
- amiga/fs_space.cpp: the statvfs() that libstdc++'s std::filesystem
  needs to link (libnix has none; the game never asks for free space).
- amiga/amiga_start.cpp: a 512 KB stack and the $VER string.

Designed, tested and delivered by The AmiCradle Team.
