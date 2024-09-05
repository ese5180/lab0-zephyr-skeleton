# --platform=linux/amd64 makes this work for Apple silicon, does it break for Windows or Linux?
FROM --platform=linux/amd64 ubuntu:jammy AS build-env

# Get dependencies from package manager
RUN apt-get update && apt-get install build-essential wget neofetch clang ninja-build git -y

# Pull Lab 0 Template Repository - Token
ARG GITHUB_TOKEN
RUN cd /home && \
    git clone https://$GITHUB_TOKEN@github.com/upenn-embedded/ESE5180_lab_0_template.git

# # Pull Lab 0 Template Repository - SSH flag forward
# RUN cd /home && \
#     git clone git@github.com:upenn-embedded/ESE5180_lab_0_template.git

# # Pull Lab 0 Template Repository - https://javorszky.co.uk/2023/11/02/use-your-ssh-key-with-a-passphrase-inside-a-docker-container/
# RUN cd /home && \
#     git clone git@github.com:upenn-embedded/ESE5180_lab_0_template.git

# Get latest version of CMake
ENV version=3.30.2
RUN cd /tmp && \
    mkdir /opt/cmake && \
    wget https://github.com/Kitware/CMake/releases/download/v$version/cmake-$version-Linux-x86_64.sh && \
    chmod a+x ./cmake-$version-Linux-x86_64.sh && \
    ./cmake-$version-Linux-x86_64.sh --prefix=/opt/cmake --skip-license && \
    rm cmake-$version-Linux-x86_64.sh
ENV PATH="/opt/cmake/bin:${PATH}"

# Install arm-gnu-toolchain 13.3
RUN cd /opt && \
    wget "https://developer.arm.com/-/media/Files/downloads/gnu/13.3.rel1/binrel/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi.tar.xz" -P /opt/ && \
    tar -xf /opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi.tar.xz && \
    rm /opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi.tar.xz && \
    ln -s /opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-gcc /usr/bin/arm-none-eabi-gcc && \
    ln -s /opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-g++ /usr/bin/arm-none-eabi-g++ && \
    ln -s /opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-gdb /usr/bin/arm-none-eabi-gdb && \
    ln -s /opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-size /usr/bin/arm-none-eabi-size && \
    ln -s /opt/arm-gnu-toolchain-13.3.rel1-x86_64-arm-none-eabi/bin/arm-none-eabi-objcopy /usr/bin/arm-none-eabi-objcopy 
