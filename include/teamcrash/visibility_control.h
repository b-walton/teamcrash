#ifndef TEAMCRASH__VISIBILITY_CONTROL_H_
#define TEAMCRASH__VISIBILITY_CONTROL_H_
#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define TEAMCRASH_EXPORT __attribute__ ((dllexport))
    #define TEAMCRASH_IMPORT __attribute__ ((dllimport))
  #else
    #define TEAMCRASH_EXPORT __declspec(dllexport)
    #define TEAMCRASH_IMPORT __declspec(dllimport)
  #endif
  #ifdef TEAMCRASH_BUILDING_LIBRARY
    #define TEAMCRASH_PUBLIC TEAMCRASH_EXPORT
  #else
    #define TEAMCRASH_PUBLIC TEAMCRASH_IMPORT
  #endif
  #define TEAMCRASH_PUBLIC_TYPE TEAMCRASH_PUBLIC
  #define TEAMCRASH_LOCAL
#else
  #define TEAMCRASH_EXPORT __attribute__ ((visibility("default")))
  #define TEAMCRASH_IMPORT
  #if __GNUC__ >= 4
    #define TEAMCRASH_PUBLIC __attribute__ ((visibility("default")))
    #define TEAMCRASH_LOCAL  __attribute__ ((visibility("hidden")))
  #else
    #define TEAMCRASH_PUBLIC
    #define TEAMCRASH_LOCAL
  #endif
  #define TEAMCRASH_PUBLIC_TYPE
#endif
#endif  // TEAMCRASH__VISIBILITY_CONTROL_H_
// Generated 28-Nov-2023 10:53:59
// Copyright 2019-2020 The MathWorks, Inc.
