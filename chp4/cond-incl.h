// #if !defined(HDR)
#ifndef HDR 
#define HDR 1
#define QTY 30

#if SYST == MAC
    #define LAPTOP "macbook"
#elif SYST == LIN
    #define LAPTOP "kubuntu"
#elif SYST == WIN
    #define LAPTOP "surfacebook"
#else
    #define LAPTOP "unknown"
#endif
#endif 