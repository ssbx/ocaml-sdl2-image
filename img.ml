(* OCamlSDL2_Image - An OCaml interface to the SDL2_Image library
   Copyright (C) 2013 Florent Monnier

   This software is provided "AS-IS", without any express or implied warranty.
   In no event will the authors be held liable for any damages arising from
   the use of this software.

   Permission is granted to anyone to use this software for any purpose,
   including commercial applications, and to alter it and redistribute it freely.
*)
(* Image loading library *)

open CamlSDL2

type init_flags =
  [ `JPG
  | `PNG
  | `TIF
  | `WEBP
  ]

external init : init_flags list -> unit = "caml_SDL_IMG_Init"
external quit : unit -> unit = "caml_SDL_IMG_Quit"
external get_linked_version : unit -> int * int * int = "caml_SDL_IMG_GetLinkedVersion"

external get_compiled_version
  :  unit
  -> int * int * int
  = "caml_SDL_IMG_GetCompiledVersion"

external is_ico : Sdl.RWops.t -> bool = "caml_SDL_IMG_isICO"
external is_cur : Sdl.RWops.t -> bool = "caml_SDL_IMG_isCUR"
external is_bmp : Sdl.RWops.t -> bool = "caml_SDL_IMG_isBMP"
external is_gif : Sdl.RWops.t -> bool = "caml_SDL_IMG_isGIF"
external is_jpg : Sdl.RWops.t -> bool = "caml_SDL_IMG_isJPG"
external is_lbm : Sdl.RWops.t -> bool = "caml_SDL_IMG_isLBM"
external is_pcx : Sdl.RWops.t -> bool = "caml_SDL_IMG_isPCX"
external is_png : Sdl.RWops.t -> bool = "caml_SDL_IMG_isPNG"
external is_pnm : Sdl.RWops.t -> bool = "caml_SDL_IMG_isPNM"
external is_tif : Sdl.RWops.t -> bool = "caml_SDL_IMG_isTIF"
external is_xcf : Sdl.RWops.t -> bool = "caml_SDL_IMG_isXCF"
external is_xpm : Sdl.RWops.t -> bool = "caml_SDL_IMG_isXPM"
external is_xv : Sdl.RWops.t -> bool = "caml_SDL_IMG_isXV"
external is_webp : Sdl.RWops.t -> bool = "caml_SDL_IMG_isWEBP"
external load_png_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadPNG_RW"
external load_ico_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadICO_RW"
external load_cur_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadCUR_RW"
external load_bmp_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadBMP_RW"
external load_gif_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadGIF_RW"
external load_jpg_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadJPG_RW"
external load_lbm_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadLBM_RW"
external load_pcx_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadPCX_RW"
external load_pnm_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadPNM_RW"
external load_tga_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadTGA_RW"
external load_tif_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadTIF_RW"
external load_xcf_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadXCF_RW"
external load_xpm_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadXPM_RW"
external load_xv_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadXV_RW"
external load_webp_rw : Sdl.RWops.t -> Sdl.Surface.t = "caml_SDL_IMG_LoadWEBP_RW"

external load_texture
  :  Sdl.Renderer.t
  -> filename:string
  -> Sdl.Texture.t
  = "caml_SDL_IMG_LoadTexture"

external save_png : Sdl.Surface.t -> filename:string -> unit = "caml_SDL_IMG_SavePNG"
