.PHONY: build test t clean dev_install fmt


build:
	dune build

clean:
	dune clean

test:
	dune runtest -f

fmt:
	dune build @fmt
	@echo 'run "dune promote" to update files'

doc:
	dune build @doc && $(BROWSER) _build/default/_doc/_html/caml-libsdl2-image/Sdl_image/index.html

dev_install:
	opam install --working-dir ./caml-libsdl2-image.opam
