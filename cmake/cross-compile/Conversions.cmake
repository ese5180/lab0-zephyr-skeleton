####################################
# Conversions module               #
####################################
# Convert ELF output files to .hex or .bin files respectively

function(convert_elf_to_hex target rel_path)
    add_custom_command(
            TARGET ${target}
            COMMAND ${OBJCOPY} -O binary ${CMAKE_BINARY_DIR}/${rel_path}/${target} ${CMAKE_BINARY_DIR}/${rel_path}/${target}.bin
    )
endfunction()

function(convert_elf_to_bin target rel_path)
    add_custom_command(
            TARGET ${target}
            COMMAND ${OBJCOPY} -O ihex ${CMAKE_BINARY_DIR}/${rel_path}/${target} ${CMAKE_BINARY_DIR}/${rel_path}/${target}.hex
    )
endfunction()