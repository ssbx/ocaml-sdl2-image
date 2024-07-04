.PHONY: build test t clean


build:
	dune build

clean:
	dune clean

t: test
test:
	dune runtest -f

def_install:
	opan install --working-dir ./osdl2-image.opam
