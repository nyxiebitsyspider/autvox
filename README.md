# AutVox

> A terminal-based Alternative and Augmented Communication (AAC) software made by an autistic developer

## Prerequisites

- espeak-ng

## Installation

AutVox is currently in open beta. There is currently only one way to properly install AutVox for guaranteed compatibility: Clone the repo and compile from source.

```
git clone https://github.com/nyxiebitsyspider/autvox.git # clone repo
cd autvox # cd into cloned repo
gcc src/main.c -libespeak-ng -o autvox # compile from source
```


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