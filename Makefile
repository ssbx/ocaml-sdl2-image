.PHONY: build test doc clean fmt install


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
	dune build @doc && $(BROWSER) _build/default/_doc/_html/caml-sdl2-image/CamlSDL2_Image/Img/index.html

install:
	opam install --working-dir ./caml-sdl2-image.opam
