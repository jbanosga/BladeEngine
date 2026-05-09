# BladeEngine

# Install dependencies
# # SDL
    cd modules/SDL
    cmake -S . -B build
    cmake --build build
    sudo cmake --install build --prefix /usr/local

# # GLM
    cd modules/glm
    cmake -DGLM_BUILD_TESTS=OFF -DBUILD_SHARED_LIBS=OFF -B build .
    cmake --build build -- all
    sudo cmake --build build -- install
