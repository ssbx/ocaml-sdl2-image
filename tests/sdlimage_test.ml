open Osdl2
open Osdl2_image

let is_imgs = [
  "ico", Image.is_ico;
  "cur", Image.is_cur;
  "bmp", Image.is_bmp;
  "gif", Image.is_gif;
  "jpg", Image.is_jpg;
  "lbm", Image.is_lbm;
  "pcx", Image.is_pcx;
  "png", Image.is_png;
  "pnm", Image.is_pnm;
  "tif", Image.is_tif;
  "xcf", Image.is_xcf;
  "xpm", Image.is_xpm;
  "xv", Image.is_xv;
  "webp", Image.is_webp;
]

let () =
  let filename = Sys.argv.(1) in
  print_endline filename;
  Image.init [
    `JPG;
    `PNG;
    `TIF;
    `WEBP;
  ];

  let rwo = RWops.from_file ~filename ~mode:"rb" in
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
  Image.quit ();
;;

