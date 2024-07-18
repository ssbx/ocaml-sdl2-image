open CamlSDL2
open CamlSDL2_Image

let is_imgs =
  [ "ico", Img.is_ico
  ; "cur", Img.is_cur
  ; "bmp", Img.is_bmp
  ; "gif", Img.is_gif
  ; "jpg", Img.is_jpg
  ; "lbm", Img.is_lbm
  ; "pcx", Img.is_pcx
  ; "png", Img.is_png
  ; "pnm", Img.is_pnm
  ; "tif", Img.is_tif
  ; "xcf", Img.is_xcf
  ; "xpm", Img.is_xpm
  ; "xv", Img.is_xv
  ; "webp", Img.is_webp
  ]
;;

let () =
  let filename = Sys.argv.(1) in
  print_endline filename;
  Img.init [ `JPG; `PNG; `TIF; `WEBP ];
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
  Img.quit ()
;;
