#!/usr/bin/env bash
set -e
case "$1" in
    *.hpp) ${CXX:-g++} ${CXXFLAGS:--std=c++20 -Isrc} -fsyntax-only "$1" ;;
    *) exit 1 ;;
esac
