# BladeEngine

# Install dependencies
# # SDL
Ubuntu dependencies at : https://github.com/libsdl-org/SDL/blob/main/docs/README-linux.md#build-dependencies

    cd modules/SDL
    cmake -S . -B build
    cmake --build build
    sudo cmake --install build --prefix /usr/local

# # GLM
    cd modules/glm
    cmake -DGLM_BUILD_TESTS=OFF -DBUILD_SHARED_LIBS=OFF -B build .
    cmake --build build -- all
    sudo cmake --build build -- install
