FROM ubuntu:24.04

RUN apt-get update && apt-get install -y \
    vim \
    git \
    build-essential \
    python3 \
    python3-pip \
    texlive-latex-base \
    texlive-latex-extra \
    texlive-fonts-recommended \
    texlive-fonts-extra \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install --break-system-packages clang-format==23.1.5

WORKDIR /workspace
CMD ["/bin/bash"]
