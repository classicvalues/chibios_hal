# README

The files `board.h`, `board.c`, and `board.mk` are auto-generated from the configuration file `cfg/board.chcfg`. However, `board.mk` must then be edited by hand to correct the paths specific to this project layout.

## Auto-generation

The board configuration is defined by the XML file `cfg/board.chcfg`. Any changes to the configuration should be made there.

The board files are auto-generated using FMPP, which can be installed by following the instructions [here](http://fmpp.sourceforge.net/installing.html). To generate the files, from inside the `cfg` directory run `fmpp -C board.fmpp`.

## Editing `board.mk`

The auto-generation will produce a `board.mk` file that uses the paths for the default ChibiOS file structure. Since we are creating our board file outside that directory structure, we need to edit the paths. After auto-generating the files, edit `board.mk` so it looks like

```mk
# List of all the board related files.
BOARDSRC = $(BOARDDIR)/board.c

# Required include directories
BOARDINC = $(BOARDDIR)

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
```

Alternatively, just do a `git checkout -- board.mk` to recover the version that was there before auto-generating.

Note that the `BOARDDIR` variable needs to be set by the calling Makefile.