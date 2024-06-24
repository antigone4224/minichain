#include "wasm3.h"
typedef enum state { ERROR, SUCCESS } state;
typedef struct ResultModule {
    state state;
    union {
        IM3Module m;
        M3Result err;
    } data;
} ResultModule;
typedef struct ResultString {
    state state;
    union {
        const unsigned char *str;
        M3Result err;
    } data;
} ResultString;
ResultModule GetModuleFromBytecode(IM3Environment env,
                                   const unsigned char *bytecode,
                                   size_t bytecodelen);
ResultString RunFunction(IM3Module mod, IM3Runtime rt, IM3Environment env,
                     const char *f, int argc, const char *argv[]);
void AttachToRuntime(IM3Module mod, IM3Runtime rt);
extern int gascnt;