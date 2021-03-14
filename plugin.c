// Copyright 2020 Valentin Vanelslande
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common_types.h"

#ifdef _WIN32
#define VVCTRE_PLUGIN_EXPORT __declspec(dllexport)
#else
#define VVCTRE_PLUGIN_EXPORT
#endif

static const char* required_function_names[] = {
    "vvctre_settings_set_region_value",
    "vvctre_settings_set_custom_cpu_ticks",
    "vvctre_settings_set_audio_volume",
    "vvctre_settings_set_resolution",
    "vvctre_settings_set_nickname",
};

typedef void (*vvctre_settings_set_region_value_t)(int value);
static vvctre_settings_set_region_value_t vvctre_settings_set_region_value;
typedef void (*vvctre_settings_set_custom_cpu_ticks_t)(u64 value);
static vvctre_settings_set_custom_cpu_ticks_t vvctre_settings_set_custom_cpu_ticks;
typedef void (*vvctre_settings_set_audio_volume_t)(float value);
static vvctre_settings_set_audio_volume_t vvctre_settings_set_audio_volume;
typedef void (*vvctre_settings_set_resolution_t)(u16 value);
static vvctre_settings_set_resolution_t vvctre_settings_set_resolution;
typedef void (*vvctre_settings_set_nickname_t)(const char* value);
static vvctre_settings_set_nickname_t vvctre_settings_set_nickname;

VVCTRE_PLUGIN_EXPORT int GetRequiredFunctionCount() {
    return 5;
}

VVCTRE_PLUGIN_EXPORT const char** GetRequiredFunctionNames() {
    return required_function_names;
}
      
VVCTRE_PLUGIN_EXPORT void PluginLoaded(void* core, void* plugin_manager, void* required_functions[]) {
    vvctre_settings_set_region_value = (vvctre_settings_set_region_value_t)required_functions[0];
    vvctre_settings_set_custom_cpu_ticks = (vvctre_settings_set_custom_cpu_ticks_t)required_functions[1];
    vvctre_settings_set_audio_volume = (vvctre_settings_set_audio_volume_t)required_functions[2];
    vvctre_settings_set_resolution = (vvctre_settings_set_resolution_t)required_functions[3];
    vvctre_settings_set_nickname = (vvctre_settings_set_nickname_t)required_functions[4];
}

VVCTRE_PLUGIN_EXPORT void InitialSettingsOpening() {
    vvctre_settings_set_region_value(0);
    vvctre_settings_set_custom_cpu_ticks(16000);
    vvctre_settings_set_audio_volume(0.8f);
    vvctre_settings_set_resolution(0);
    vvctre_settings_set_nickname("HOLiC");
}
