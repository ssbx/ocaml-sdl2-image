/*
 caml-libsdl-image - Copyright (C) 2024 Sébastien Serre
 OCamlSDL2_Image - Copyright (C) 2013 Florent Monnier

 This software is provided "AS-IS", without any express or implied warranty.
 In no event will the authors be held liable for any damages arising from
 the use of this software.

 Permission is granted to anyone to use this software for any purpose,
 including commercial applications, and to alter it and redistribute it freely.
*/
#define CAML_NAME_SPACE
#include <caml/mlvalues.h>
#include <caml/memory.h>
#include <caml/alloc.h>
#include <caml/fail.h>

#include <SDL_image.h>

#include "camlsdl2/rwops_stub.h"
#include "camlsdl2/surface_stub.h"
#include "camlsdl2/render_stub.h"

static inline IMG_InitFlags
IMG_InitFlag_ml2c(value v)
{
    if (v == caml_hash_variant("JPG"))  return IMG_INIT_JPG;
    if (v == caml_hash_variant("PNG"))  return IMG_INIT_PNG;
    if (v == caml_hash_variant("TIF"))  return IMG_INIT_TIF;
    if (v == caml_hash_variant("WEBP")) return IMG_INIT_WEBP;
    caml_failwith("Sdlimage.init_flags");
}

static inline IMG_InitFlags
IMG_InitFlags_val(value flag_list)
{
    IMG_InitFlags c_mask = 0;
    while (flag_list != Val_emptylist)
    {
        value head = Field(flag_list, 0);
        flag_list = Field(flag_list, 1);
        c_mask |= IMG_InitFlag_ml2c(head);
    }
    return c_mask;
}

CAMLprim value
caml_SDL_IMG_Init(value flags)
{
    CAMLparam1(flags);
    IMG_InitFlags c_flags = IMG_InitFlags_val(flags);
    int si = IMG_Init(c_flags);
    if (si == 0) caml_failwith("Sdlimage.init");
    //if (si != c_flags) caml_failwith("Sdlimage.init: "
    //    "uncomplete initialisation");
    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_IMG_Quit(value unit)
{
    CAMLparam1(unit);
    IMG_Quit();
    CAMLreturn(Val_unit);
}

/* Functions to detect a file type, given a seekable source */

CAMLprim value caml_SDL_IMG_isICO(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isICO(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isCUR(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isCUR(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isBMP(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isBMP(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isGIF(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isGIF(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isJPG(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isJPG(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isLBM(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isLBM(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isPCX(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isPCX(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isPNG(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isPNG(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isPNM(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isPNM(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isTIF(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isTIF(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isXCF(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isXCF(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isXPM(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isXPM(SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isXV (value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isXV (SDL_RWops_val(img))));
}
CAMLprim value caml_SDL_IMG_isWEBP(value img) {
    CAMLparam1(img);
    CAMLreturn(Val_bool(IMG_isWEBP(SDL_RWops_val(img))));
}

CAMLprim value
caml_SDL_IMG_GetCompiledVersion(value unit)
{
    CAMLparam0();
    CAMLlocal1(ret);

    SDL_version img_version;
    SDL_IMAGE_VERSION(&img_version);

    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_int(img_version.major));
    Store_field(ret, 1, Val_int(img_version.minor));
    Store_field(ret, 2, Val_int(img_version.patch));
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_IMG_GetLinkedVersion(value unit)
{
    CAMLparam0();
    CAMLlocal1(ret);

    const SDL_version *img_version;
    img_version = IMG_Linked_Version();

    ret = caml_alloc(3, 0);
    Store_field(ret, 0, Val_int(img_version->major));
    Store_field(ret, 1, Val_int(img_version->minor));
    Store_field(ret, 2, Val_int(img_version->patch));
    CAMLreturn(ret);
}

CAMLprim value
caml_SDL_IMG_LoadPNG_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf =IMG_LoadPNG_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_png_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadICO_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadICO_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_ico_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadTGA_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadTGA_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_tga_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadTIF_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadTIF_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_tif_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadXCF_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadXCF_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_xcf_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadXPM_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadXPM_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_xpm_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadXV_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadXV_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_xv_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadWEBP_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadWEBP_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_webp_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadPNM_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadPNM_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_pnm_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadPCX_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadPCX_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_pcx_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadLBM_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadLBM_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_lbm_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadJPG_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadJPG_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_jpg_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadGIF_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadGIF_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_gif_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadBMP_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadBMP_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_bmp_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_LoadCUR_RW(value img)
{
    CAMLparam1(img);
    SDL_Surface *surf = IMG_LoadCUR_RW(SDL_RWops_val(img));
    if (!surf)
        caml_failwith("Sdlimage.load_cur_rw");

    CAMLreturn(Val_SDL_Surface(surf));
}

CAMLprim value
caml_SDL_IMG_SavePNG(value surf, value filename)
{
    CAMLparam2(surf, filename);
    int r =
        IMG_SavePNG(
            SDL_Surface_val(surf),
            String_val(filename));

    if (r) caml_failwith("Sdlimage.save_png");

    CAMLreturn(Val_unit);
}

CAMLprim value
caml_SDL_IMG_LoadTexture(value renderer, value filename)
{
    CAMLparam2(renderer, filename);
    SDL_Texture *texture =
        IMG_LoadTexture(
            SDL_Renderer_val(renderer),
            String_val(filename));

    if (!texture) caml_failwith("Sdlimage.load_texture");

    CAMLreturn(Val_SDL_Texture(texture));
}

/* vim: set ts=4 sw=4 et: */
