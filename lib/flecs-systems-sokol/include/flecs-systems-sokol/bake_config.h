/*
                                   )
                                  (.)
                                  .|.
                                  | |
                              _.--| |--._
                           .-';  ;`-'& ; `&.
                          \   &  ;    &   &_/
                           |"""---...---"""|
                           \ | | | | | | | /
                            `---.|.|.|.---'

 * This file is generated by bake.lang.c for your convenience. Headers of
 * dependencies will automatically show up in this file. Include bake_config.h
 * in your main project file. Do not edit! */

#ifndef FLECS_SYSTEMS_SOKOL_BAKE_CONFIG_H
#define FLECS_SYSTEMS_SOKOL_BAKE_CONFIG_H

/* Headers of public dependencies */
#include <flecs.h>
#include <flecs_components_gui.h>
#include <flecs_components_transform.h>
#include <flecs_components_geometry.h>
#include <flecs_systems_transform.h>
#include <flecs_systems_sdl2.h>
#include <bake_sdl2.h>

/* Convenience macro for exporting symbols */
#ifndef flecs_systems_sokol_STATIC
#if flecs_systems_sokol_EXPORTS && (defined(_MSC_VER) || defined(__MINGW32__))
  #define FLECS_SYSTEMS_SOKOL_EXPORT __declspec(dllexport)
#elif flecs_systems_sokol_EXPORTS
  #define FLECS_SYSTEMS_SOKOL_EXPORT __attribute__((__visibility__("default")))
#elif defined _MSC_VER
  #define FLECS_SYSTEMS_SOKOL_EXPORT __declspec(dllimport)
#else
  #define FLECS_SYSTEMS_SOKOL_EXPORT
#endif
#else
  #define FLECS_SYSTEMS_SOKOL_EXPORT
#endif

#endif

