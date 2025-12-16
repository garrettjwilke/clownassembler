#include <emscripten/emscripten.h>

// Forward-declare main from frontend_custom.c
int main(int argc, char** argv);

EMSCRIPTEN_KEEPALIVE
int clownassembler_wasm_assemble(const char* input, const char* output) {
    // Fake argv, exactly like CLI usage
    char* argv[] = {
        "clownassembler",
        "-p",
        "-i",
        (char*)input,
        "-o",
        (char*)output,
        NULL
    };

    int argc = 6;
    return main(argc, argv);
}
