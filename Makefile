.PHONY: build test doc clean fmt dev_update


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

dev_update:
	opam install --working-dir ./caml-libsdl2-image.opam
