open Osdl2
open Osdl2_image

let is_imgs = [
  "ico", SdlImage.is_ico;
  "cur", SdlImage.is_cur;
  "bmp", SdlImage.is_bmp;
  "gif", SdlImage.is_gif;
  "jpg", SdlImage.is_jpg;
  "lbm", SdlImage.is_lbm;
  "pcx", SdlImage.is_pcx;
  "png", SdlImage.is_png;
  "pnm", SdlImage.is_pnm;
  "tif", SdlImage.is_tif;
  "xcf", SdlImage.is_xcf;
  "xpm", SdlImage.is_xpm;
  "xv", SdlImage.is_xv;
  "webp", SdlImage.is_webp;
]

let () =
  let filename = Sys.argv.(1) in
  print_endline filename;
  SdlImage.init [
    `JPG;
    `PNG;
    `TIF;
    `WEBP;
  ];

  let rwo = Sdl.RWops.from_file ~filename ~mode:"rb" in
  let found = ref false in
  List.iter (fun (ext, is_img) ->
    if is_img rwo then
    begin
      Printf.printf "\"%s\" is %s\n" filename ext;
      found := true
    end
  ) is_imgs;
  if not !found then
    Printf.printf "unknown filetype for \"%s\"\n" filename;
  SdlImage.quit ();
;;

