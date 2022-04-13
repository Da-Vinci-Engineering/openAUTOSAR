The Watchdog module in the original code from ARCTIC had several inconsistencies
- It was partially written in C++ rather than C language
- It looks as if the system module (WdmG) implemented the interface to several watchdog instances, while the IOhwAbs module (WdgIf) seemed to handle only one instance.

The initial work has refactored the whole module to make it compile again. However, more regression testing is needed to prove the correcteness of the implementation. 