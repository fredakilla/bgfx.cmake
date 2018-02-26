namespace bgfx
{
    #define SC_TYPE_COMPUTE     0   // c - compute
    #define SC_TYPE_DOMAIN      1   // d - domain
    #define SC_TYPE_FRAGMENT    2   // f - fragment
    #define SC_TYPE_GEOMETRY    3   // g - geometry
    #define SC_TYPE_HULL        4   // h - hull
    #define SC_TYPE_VERTEX      5   // v - vertex

    const bgfx::Memory* compileShader(uint32_t type, const char* filePath, const char* defines = nullptr, const char* varyingPath = nullptr);
}
