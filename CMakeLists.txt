# Устанавливает минимальную требуемую версию CMake для проекта
cmake_minimum_required(VERSION 3.10)

# Устанавливает имя проекта
project(SkillboxSearchEngine)

# Устанавливает стандарт C++ на C++17 и делает его обязательным
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Устанавливает пути к файлам конфигурации и запросов
set(CONFIG_JSON "${CMAKE_SOURCE_DIR}/config.json")
set(REQUESTS_JSON "${CMAKE_SOURCE_DIR}/requests.json")

# Выводит сообщения о директориях сборки и исходников
message(STATUS "Build directory: ${CMAKE_BINARY_DIR}")
message(STATUS "Source directory: ${CMAKE_SOURCE_DIR}")

# Выводит сообщения о путях к файлам конфигурации и запросов
message(STATUS "Config JSON path: ${CONFIG_JSON}")
message(STATUS "Requests JSON path: ${REQUESTS_JSON}")

# Включает модуль FetchContent для загрузки внешних зависимостей
include(FetchContent)

# Устанавливает политику CMP0135 на NEW, если она поддерживается
if(POLICY CMP0135)
    cmake_policy(SET CMP0135 NEW)
endif()

# Объявляет и загружает библиотеку Google Test
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)

# Объявляет и загружает библиотеку nlohmann_json
FetchContent_Declare(
    nlohmann_json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG v3.10.5
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(nlohmann_json)

# Создает библиотеку SkillboxSearchEngineLib из исходных файлов
add_library(SkillboxSearchEngineLib
    src/ConverterJSON.cpp
    src/InvertedIndex.cpp
    src/SearchServer.cpp
)

# Создает исполняемый файл SkillboxSearchEngine из основного файла main.cpp
add_executable(SkillboxSearchEngine
    src/main.cpp
)

# Устанавливает директории для поиска заголовочных файлов для библиотеки SkillboxSearchEngineLib
target_include_directories(SkillboxSearchEngineLib PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${nlohmann_json_SOURCE_DIR}/include
)

# Связывает библиотеку SkillboxSearchEngineLib с библиотекой nlohmann_json
target_link_libraries(SkillboxSearchEngineLib PUBLIC nlohmann_json::nlohmann_json)

# Устанавливает директории для поиска заголовочных файлов для исполняемого файла SkillboxSearchEngine
target_include_directories(SkillboxSearchEngine PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# Связывает исполняемый файл SkillboxSearchEngine с библиотекой SkillboxSearchEngineLib
target_link_libraries(SkillboxSearchEngine PUBLIC SkillboxSearchEngineLib)

# Добавляет поддиректорию tests, где находится CMakeLists.txt для тестов
add_subdirectory(tests)

# Включает поддержку тестирования
enable_testing()
