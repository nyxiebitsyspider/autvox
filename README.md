# AutVox

> A terminal-based Alternative and Augmented Communication (AAC) software made by an autistic developer

## ***DISCLAIMER:***

_AutVox is primarily intended for use by autistic individuals without co-occurring intellectual disability or folks who struggle with mutism or a severe stutter or speech impediment. It requires functional literacy to use, and is not intended to be an individual's sole method of communication. It is meant as a supplementary tool for those who struggle with verbalizing but are able to write. AutVox is first and foremost a personal passion project made to fill a need for the developer, and is shared in the hope that someone else may benefit from it._

_I am not a medical or speech-language professional and this software is not intended as a replacement for medical devices like professional AAC tablets. This software is made by a hobbyist with no formal training in software development or computer science. This software is not designed to be used by someone unfamiliar with command-line-based applications. The developer disclaims responsibility for any ill effects resulting from using the software outside its intended use cases._

## About AutVox

This is the first piece of software I have ever made publicly available. It is not finished, but I want to share it as I work on it because it is something I had a need for, and figure someone else out there might as well. I haven't added the binaries yet (the binary I use is not officialy supported but it's here if you want to try it), or created makefiles, or figured out how to implement all the planned features. There's no options menu yet, no way to change the voice without editing the source code, and it currently doesn't accept command-line arguments. It uses an extremely barebones voice synthesis, so it sounds very robotic. But the compiled binary is small and should remain so with all planned features implemented, which was important for me since it's going to be a permanent fixture on my ancient IBM Thinkpad.

My special interest is computers, so I'm entirely self-taught. This is also only the third program I have ever written in C. Honestly, if the espeak-ng library wasn't so well-documented, this project would never have reached a usable state. I'm just an autistic nerd who needed something like this and had the ability to make it myself, if only barely. Basically, don't expect this to come without a few bugs at first. I've compiled and run the program on every acrchitecture I have access to and ensured it works flawlessly in its current state before pushing to main, but I only have access to 64-bit ARM right now, have zero access to a Mac, and only own one Windows PC which runs 32-bit XP as she is a little old lady. If anyone needs the binary for 32-bit Windows, let me know.

## Compatibility

AutVox currently has my personal binary available for convenience, but the plan is to release binaries for all architectures I am able to test on. 64-bit Linux on both ARM and x86 are the extent of planned releases. Eventually there may be a flatpak version if there's interest. No official support for MacOS or Windows is planned, though if anyone wants to fork the project and maintin it for those architectures, you have my blessing.

## Prerequisites

- [espeak-ng](https://github.com/espeak-ng/espeak-ng/blob/master/docs/guide.md#installation) and its prerequisites (can be installed through your distro's package manager such as apt-get, yum, pacman, etc)
- A C compiler (gcc, clang, etc.)

## Installation

AutVox is currently available from source code in open alpha. Though my personal binary is provided for convenience, there is only one supported way to properly install AutVox at this time: Clone the repo and compile from source.

```
git clone https://github.com/nyxiebitsyspider/autvox.git # clone repo
cd autvox # cd into cloned repo
gcc src/main.c -libespeak-ng -o autvox # compile from source
```

Binary for 64-bit x86 and ARM Linux is planned for release of v0.1.0, which will be the first fully-featured CLI build and mark the transition to open beta.


## Usage

Simply run the executable in your terminal. Currently no arguments are supported.

```
cd autvox # cd into parent directory of executable
./autvox # execute autvox
```

## Roadmap for Development

### Short-Term

- options menu with voice selection
- config file affected by options menu
- command line arguments
- makefiles for easier install on alternative architectures building from source
- binary for 64-bit ARM and x86 architectures

### Long-Term

- TUI using ncurses
- ability to import custom voice from file
- binary for 32-bit ARM and x86 architectures (full release)