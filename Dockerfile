FROM ubuntu

RUN apt-get update

ENV DEBIAN_FRONTEND noninteractive
ENV GCC_VERSION 10
RUN ln -fs /usr/share/zoneinfo/America/New_York /etc/localtime
RUN apt-get install -y gcc-${GCC_VERSION} g++-${GCC_VERSION} cmake
ENV CC gcc-$GCC_VERSION
ENV CXX g++-$GCC_VERSION

ADD ./ /exception_with_location

RUN echo "Test GCC ${GCC_VERSION} for C++20 with #include <source_location> (if has source_location otherwise will use experimental/source_location)"
WORKDIR /exception_with_location/
RUN rm -rf ./build || true 
RUN \
mkdir -p build && \ 
cd build && \
cmake .. -DCMAKE_CXX_STANDARD=20 && \
cmake --build . -j$(nproc) && \
./exception_with_location && \
cd ..

RUN echo "Test GCC ${GCC_VERSION} for C++17 with #include <experimental/source_location>"
WORKDIR /exception_with_location/
RUN rm -rf ./build || true 
RUN \
mkdir -p build && \ 
cd build && \
cmake .. -DCMAKE_CXX_STANDARD=17 && \
cmake --build . -j$(nproc) && \
./exception_with_location && \
cd ..

RUN echo "Test GCC ${GCC_VERSION} for C++17 with implementaition std::source_location from this library"
WORKDIR /exception_with_location/
RUN rm -rf ./build || true 
RUN \
mkdir -p build && \ 
cd build && \
cmake .. -DCMAKE_CXX_STANDARD=17 -DEXCLOC_IGNORE_SYSTEM_HEADERS=ON && \
cmake --build . -j$(nproc) && \
./exception_with_location && \
cd ..

