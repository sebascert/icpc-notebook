src_dir := src
sources := $(shell find $(src_dir) -name '*.cpp')
headers := $(shell find $(src_dir) -name "*.hpp")

CXXFLAGS += -std=c++20 -Isrc
export CXXFLAGS
LATEXCMD = pdflatex -shell-escape -output-directory build/
export TEXINPUTS=.:content/latex/:
export max_print_line = 1048576

help:
	@echo "This makefile builds KACTL (KTH Algorithm Competition Template Library)"
	@echo ""
	@echo "Available commands are:"
	@echo "	make fast		- to build KACTL, quickly (only runs LaTeX once)"
	@echo "	make kactl		- to build KACTL"
	@echo "	make clean		- to clean up the build process"
	@echo "	make veryclean		- to clean up and remove notebook.pdf"
	@echo "	make test		- to run all the stress tests in stress_tests/"
	@echo "	make test_compiles	- to check algorithm syntax"
	@echo "	make format		- to format headers in src/"
	@echo "	make help		- to show this information"
	@echo "	make showexcluded	- to show files that are not included in the doc"
	@echo ""
	@echo "For more information see readme.md"

format: $(sources) $(headers)
	@clang-format -i $^

fast: format | build
	$(LATEXCMD) content/kactl.tex </dev/null
	mv -f build/kactl.pdf notebook.pdf

kactl: format test_session.pdf | build
	$(LATEXCMD) content/kactl.tex && $(LATEXCMD) content/kactl.tex
	mv -f build/kactl.pdf notebook.pdf

clean:
	cd build && rm -f kactl.aux kactl.log kactl.tmp kactl.toc notebook.pdf kactl.ptc

veryclean: clean
	rm -f notebook.pdf test_session.pdf

.PHONY: help format fast kactl clean veryclean test test_compiles showexcluded

build:
	mkdir -p build/

test:
	./scripts/run_all.sh .

test_compiles:
	./scripts/compile_all.sh .

test_session.pdf: format content/test_session/test_session.tex content/test_session/chapter.tex | build
	$(LATEXCMD) content/test_session/test_session.tex
	mv -f build/test_session.pdf test_session.pdf

showexcluded:
	python3 scripts/find_unreferenced_files.py
