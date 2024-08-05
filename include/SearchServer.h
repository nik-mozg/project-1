#pragma once
#ifndef SEARCH_SERVER_H
#define SEARCH_SERVER_H

#include "InvertedIndex.h"
#include "RelativeIndex.h"
#include "ConverterJSON.h"
#include <vector>
#include <string>

/**
 * @class SearchServer
 * @brief Класс для выполнения поиска по запросам в текстовых документах, используя обратный индекс.
 */
class SearchServer {
public:
    /**
     * @brief Конструктор класса SearchServer.
     * @param idx Ссылка на объект InvertedIndex, который содержит данные об индексах документов.
     * @param responses_limit Ограничение на количество возвращаемых результатов для каждого запроса.
     */
    SearchServer(InvertedIndex& idx, int responses_limit);

    /**
     * @brief Выполняет поиск по вектору запросов и возвращает результаты.
     * @param queries_input Вектор строк, каждая из которых представляет собой запрос.
     * @return Вектор векторов объектов RelativeIndex, где каждый внутренний вектор представляет собой результаты поиска по одному запросу.
     */
    std::vector<std::vector<RelativeIndex>> search(const std::vector<std::string>& queries_input) const;

private:
    InvertedIndex& _index; ///< Ссылка на объект InvertedIndex, используемый для поиска.
    int _responses_limit;  ///< Максимальное количество результатов, возвращаемых для каждого запроса.
};

#endif // SEARCH_SERVER_H
