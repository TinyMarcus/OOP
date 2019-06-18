#ifndef ERRORS_H
#define ERRORS_H

enum error
{
    OK = 0,
    IncorrectFileData = -1,
    MeshNotLoaded = -2,
    FileNotFound = -3,
    UnknownAction = -4,
    AllocationError = -5
};

#endif // ERRORS_H
