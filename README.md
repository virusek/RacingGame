# LAN Racing Game

**Warning: This project is in the early stages of development. It may be incomplete and is subject to significant changes. Use at your own risk.**

## Overview
It's a simple car racing game with built-in map editor. This project is just made to learn and have fun!
You can play solo or with a friend. Solo Mode is used for making new personal records on the track!
You can then export your map to your friends and compete with them for the best time on the same track.
Your Personal Best will be visible on the leaderboard! Have fun racing!

## Table of Contents
 - [Dependencies](#dependencies)
 - [Installation](#installation)
 - [Roadmap](#roadmap)
 - [Contributing](#contributing)
 - [License](#license)

## Dependencies

To build this project, the following dependencies are required:

- **Premake5**: Download it from the [Premake5 website](https://premake.github.io/).
- **Clang**: Install Clang using your package manager:
    - On Ubuntu:
        ```bash
        sudo apt-get install clang
        ```
    - On macOS:
        ```bash
        brew install llvm
        ```
    - On Windows: Download from the [LLVM website](https://llvm.org/).
- **Make**: Ensure Make is installed:
    - On Ubuntu:
        ```bash
        sudo apt-get install build-essential
        ```
    - On macOS:
        ```bash
        xcode-select --install
        ```
    - On Windows: Install through [MSYS2](https://www.msys2.org/) or use the provided Make tools in the [MinGW](http://www.mingw.org/) or [Cygwin](https://www.cygwin.com/) distributions.

## Installation
To install this project, follow these steps:

**Note:** Pre-built binaries will be provided in the future. For now, you will need to build the project yourself.

1. Clone the repository:
    ```bash
    git clone https://github.com/virusek/RacingGame.git
    ```
2. Navigate to the project directiory:
    ```bash
    cd RacingGame
    ```
3. Create Makefiles using *premake5*:
    ```bash
    premake5 gmake2
    ```
    or if building for Visual Studio, change `gmake2` to `vs2022`
4. Build the project using *make*:
    ```bash
    make config=release
    ```
5. Make sure that the assets folder gets copied to the folder containing binaries. If not, copy the whole assets folder to bin/Release/

### Optional Steps 

 - **Generate compile_commands.json for the clang lsp**
    You'll need to add a module `ecc` for the premake5.
    This module could be found on the [Premake5 website](https://premake.github.io/).
    After installing the module, run: 
    ```bash
    premake5 ecc
    ```
    This should generate the `compile_commands.json` in the project directiory.

## Roadmap
 - [ ] Build-in Map Editor: Used to create new race tracks.
 - [ ] Tuning for cars: Your car could be upgraded to be better at certain things but gets worse at others.
 - [ ] Pick-ups on the track: A little boost could be just a little useful.

 Check out the [open issues](https://github.com/virusek/RacingGame/issues) for a full list of proposed features (and known issues).

## Contributing
Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

For more details, please read our [Contributing Guidelines](CONTRIBUTING.md).

## License
Distributed under the "Non-Commercial Use License". See `LICENSE` for more information.
