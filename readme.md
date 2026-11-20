# ICPC notebook

This notebook combines the algorithms from `cp-env/lib/` with additions and
substantive algorithm changes from [HDP-KACTL](https://github.com/imanolgzz/hdp-kactl).
The `src/` implementations take precedence. Loop-macro renames and moves into the
old archive do not qualify an algorithm for retention.

Algorithm headers are in `src/`, include with `-Isrc`, and LaTeX chapters and styles are in `content/`; filenames and directories use lowercase
snake_case. Each chapter lists the algorithms included in `notebook.pdf`.
The notebook's contest template comes from the project-root `main.cpp`; algorithm headers use `src/template.hpp` internally. Each algorithm declares external inputs before its selected source range. Dependency includes are listed in the PDF (excluding the shared template); snippet hashes cover algorithm code and omit `extern` declarations.

Build the PDF with `make kactl`, or use `bash build.sh` for the Docker build. Both run the `format` target over the headers found under `src/` before compiling.
Run regression tests with `make test` and syntax checks with `make test_compiles`.
Syntax checks compile `.hpp` algorithm headers without linking them.
Several imported snippets require problem-specific sizes, types, or operations;
some HDP snippets also retain type conflicts and compilation errors.
The regression suite does not establish correctness for every algorithm.

To add an algorithm, add a matching `\kactlimport` to its `chapter.tex`.
Use `[-l rawcpp]` for snippets without KACTL metadata.
Use `Lines: [start,end]` in a snippet metadata comment to select 1-based, inclusive source lines; omit it to use the whole file. The selected lines are used for PDF output and, when a hash is generated, hashing.

Source files retain their original attribution and license comments. See the
original [KACTL repository](https://github.com/kth-competitive-programming/kactl)
for the template's history and licensing notes.
