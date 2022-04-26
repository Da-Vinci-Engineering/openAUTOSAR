The DaVinci/openAUTOSAR project is a fork of openAUTOSAR/classic-platform v2.18.0 by Arctic Core (now part of Vector GmbH)
Its main objective is to provide a learning platform for the development of AUTOSAR modules.

For details about setting the development environment and possibly other development issues please read the INSTALL.txt file.

Please note
As the version number of the released version clearly indicates, this package is currently just a little more than a small refactoring of a lost package from the Internet.
Do NOT consider it suitable for anything. 

Da Vinci's contributions so far:

- v0.1.0.alpha
    - creation of a build system based on CMake, rather than old *nix/GNU Linux makefiles
    - better decoupling of the software modules between the different AUTOSAR blocks and from hardware packages (still a work in progress)

- Currently Known Issues (in the master branch)
    - There is no hardware support. Support for legacy hardware has been dropped. A successful generation of the available modules only indicates the fact the the build system has been correctly configured.
    - AUTOSAR modules not explicitly mentioned are not supported at the moment
    - AUTOSAR modules explicitly mentioned may just have stub implementations
    - A few source code files are still part of old Board Support Packages for boards that are not supported anymore. Some of these files are now only used as examples for the configuration of the AUTOSAR modules. Preprocessor directives in the build system indicate when this happens.
    - The 

