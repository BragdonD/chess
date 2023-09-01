target_sources(chess 
    PRIVATE 
        ${CMAKE_CURRENT_SOURCE_DIR}/piece.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/FEN.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/board.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/PieceFactory.cpp
)
add_subdirectory(pieces)