FROM ubuntu:kinetic

# Python is needed to run Meson
RUN apt update &&  \
    apt install -y \
    python3 \
    python3-pip \
    python3-setuptools \
    python3-wheel \
    ninja-build \
    libsfml-dev \
    && \
    rm -rf /var/lib/apt/lists/* && \
    apt clean

RUN pip3 install meson

