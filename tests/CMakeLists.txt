# Устанавливает минимальную требуемую версию CMake
cmake_minimum_required(VERSION 3.10)

# Включает поддержку Google Test
include(GoogleTest)

# Создает исполняемый файл runTests из файла test_main.cpp
add_executable(runTests
    test_main.cpp
)

# Устанавливает пути для поиска заголовочных файлов
target_include_directories(runTests PRIVATE
    ${CMAKE_SOURCE_DIR}/include  # Включает директорию include в корне проекта
    ${nlohmann_json_SOURCE_DIR}/include  # Включает директорию include для библиотеки nlohmann_json
    ${gtest_SOURCE_DIR}/include  # Включает директорию include для библиотеки Google Test
    ${gmock_SOURCE_DIR}/include  # Включает директорию include для библиотеки Google Mock
)

# Связывает исполняемый файл runTests с необходимыми библиотеками
target_link_libraries(runTests
    gtest  # Подключает библиотеку Google Test
    gtest_main  # Подключает основной файл библиотеки Google Test
    gmock  # Подключает библиотеку Google Mock
    gmock_main  # Подключает основной файл библиотеки Google Mock
    SkillboxSearchEngineLib  # Подключает основную библиотеку проекта SkillboxSearchEngineLib
)

# Настраивает автоматическое обнаружение и регистрацию тестов для runTests
gtest_discover_tests(runTests)
