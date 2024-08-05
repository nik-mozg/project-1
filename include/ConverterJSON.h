#pragma once
#ifndef CONVERTER_JSON_H
#define CONVERTER_JSON_H

#include <vector>
#include <string>
#include <nlohmann/json.hpp>
#include "RelativeIndex.h"

/**
 * @class ConverterJSON
 * @brief Класс для работы с JSON файлами, содержащими конфигурацию, запросы и ответы.
 */
class ConverterJSON {
public:
    /**
     * @brief Читает текстовые документы, указанные в конфигурационном файле.
     * @return Вектор строк, где каждая строка представляет содержимое одного документа.
     * @throws std::runtime_error, если конфигурационный файл отсутствует или не содержит ключ 'files'.
     */
    std::vector<std::string> GetTextDocuments();

    /**
     * @brief Получает ограничение на количество ответов из конфигурационного файла.
     * @return Целое число, указывающее максимальное количество ответов.
     * @throws std::runtime_error, если конфигурационный файл отсутствует или не содержит ключ 'config'.
     */
    int GetResponsesLimit();

    /**
     * @brief Читает запросы из файла requests.json.
     * @return Вектор строк, где каждая строка представляет один запрос.
     * @throws std::runtime_error, если файл запросов отсутствует или не содержит ключ 'requests'.
     */
    std::vector<std::string> GetRequests();

    /**
     * @brief Записывает ответы в файл answers.json.
     * @param answers Вектор векторов объектов RelativeIndex, представляющих результаты поиска для каждого запроса.
     */
    void putAnswers(const std::vector<std::vector<RelativeIndex>>& answers);

private:
    /**
     * @brief Читает содержимое JSON файла.
     * @param fileName Имя файла для чтения.
     * @return Объект json, представляющий содержимое файла.
     * @throws std::runtime_error, если файл не может быть открыт.
     */
    nlohmann::json readJSONFile(const std::string& fileName);
};

#endif // CONVERTER_JSON_H
