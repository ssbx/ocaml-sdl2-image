(lang dune 3.15)

(name caml-sdl2-image)
(version 1.0)

(generate_opam_files true)

(source
 (github ssbx/caml-sdl2-image))

(authors "Seb")

(maintainers "Seb")

(license "BSD Zero Clause License")

(documentation https://github.com/ssbx/caml-sdl2-image)

(use_standard_c_and_cxx_flags true)

;;(formatting (enabled_for ocaml))

(package
 (name caml-sdl2-image)
 (synopsis "Bindings to the SDL2 image library")
 (description "Bindings to the SDL2 image library")
 (depends ocaml dune caml-sdl2)
 (tags
  (topics bindings graphics image loader)))

; See the complete stanza docs at https://dune.readthedocs.io/en/stable/dune-files.html#dune-project
