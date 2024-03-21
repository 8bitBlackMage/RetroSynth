cmake_minimum_required(VERSION 3.22)

project(RetroSynth VERSION 0.0.2)


add_subdirectory(JUCE)


juce_add_plugin(${PROJECT_NAME}
    IS_SYNTH TRUE
    NEEDS_MIDI_INPUT TRUE
    PLUGIN_MANUFACTURER_CODE 8BBM
    PLUGIN_CODE RSS0
    FORMATS AU VST3)


file(GLOB SRC_FILES Source/*.cpp)
target_sources(${PROJECT_NAME}
    PRIVATE
    ${SRC_FILES}
    )

target_compile_definitions(
    ${PROJECT_NAME}
    PUBLIC
    JUCE_WEB_BROWSER=0,
    JUCE_USE_CURL=0
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
    juce::juce_audio_utils
    PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)
