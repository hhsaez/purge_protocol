# Checkout
  git clone <REPO_URL> --recursive

# Project setup (Makefile)
  cmake .

# Building (Makefile)
All: 
  make clean all test -j4
Just the game:
  make
Running:
  ./PurgeProtocol

# Project setup (Xcode)
  cmake . -G Xcode

# Project setup (Visual Studio)
  cmake . -G "Visual Studio 2014"

# Config
Edit file assets/scripts/config.lua

# Updating code
git pull origin devel
git submodule update --recursive
cmake .
make # Makefile only

