let is_imgs =
  [ "ico", Sdl_image.is_ico
  ; "cur", Sdl_image.is_cur
  ; "bmp", Sdl_image.is_bmp
  ; "gif", Sdl_image.is_gif
  ; "jpg", Sdl_image.is_jpg
  ; "lbm", Sdl_image.is_lbm
  ; "pcx", Sdl_image.is_pcx
  ; "png", Sdl_image.is_png
  ; "pnm", Sdl_image.is_pnm
  ; "tif", Sdl_image.is_tif
  ; "xcf", Sdl_image.is_xcf
  ; "xpm", Sdl_image.is_xpm
  ; "xv", Sdl_image.is_xv
  ; "webp", Sdl_image.is_webp
  ]
;;

let () =
  let filename = Sys.argv.(1) in
  print_endline filename;
  Sdl_image.init [ `JPG; `PNG; `TIF; `WEBP ];
  let rwo = Sdl.rw_from_file ~filename ~mode:"rb" in
  let found = ref false in
  List.iter
    (fun (ext, is_img) ->
      if is_img rwo
      then (
        Printf.printf "\"%s\" is %s\n" filename ext;
        found := true))
    is_imgs;
  if not !found then Printf.printf "unknown filetype for \"%s\"\n" filename;
  Sdl_image.quit ()
;;
