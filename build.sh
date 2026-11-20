#!/usr/bin/env bash
set -e

project_dir="$(cd "$(dirname "$0")" && pwd)"
project_parent="$(dirname "$project_dir")"

docker build -f "$project_dir/dockerfile" -t reference-env "$project_dir"
docker run --rm \
	-v "$project_dir":/workspace/notebook \
	-v "$project_parent/main.cpp":/workspace/main.cpp:ro \
	-v "$project_parent/.clang-format":/workspace/.clang-format:ro \
	-w /workspace/notebook \
	reference-env make kactl
