cmake . -B ./build -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release

cmake --build build

cp ./build/unit_tests ./
./unit_tests