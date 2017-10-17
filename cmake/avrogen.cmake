function (avro_generate_class Schema HeaderName NS Header)
  get_filename_component(SchemaAbs ${Schema} ABSOLUTE)
  set(Hdr "${CMAKE_CURRENT_BINARY_DIR}/${HeaderName}")

  add_custom_command(
    OUTPUT ${Hdr}
    COMMAND ${AVROGENCPP_EXECUTABLE}
    ARGS -i ${SchemaAbs} -o ${Hdr} -n ${NS}
    DEPENDS ${SchemaAbs} ${AVROGENCPP_EXECUTABLE}
    COMMENT "Avro C++ generating ${Schema}"
    VERBATIM)

  set_source_files_properties(${Hdr} PROPERTIES GENERATED TRUE)
  set(${Header} ${Hdr} PARENT_SCOPE)
endfunction()

find_program(AVROGENCPP_EXECUTABLE
  NAMES avrogencpp
  DOC "avro c++ gode generator")
