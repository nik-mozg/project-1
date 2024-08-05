#include "SearchServer.h"
#include "InvertedIndex.h"
#include "ConverterJSON.h"
#include <iostream>

int main() {
    // Читаем документы из конфигурации
    ConverterJSON converter;
    std::vector<std::string> docs = converter.GetTextDocuments();

    // Обновляем базу документов
    InvertedIndex idx;
    idx.UpdateDocumentBase(docs);

    // Получаем лимит ответов из конфигурации
    int responses_limit = converter.GetResponsesLimit();

    // Создаем сервер поиска с ограничением на количество ответов
    SearchServer srv(idx, responses_limit);

    // Читаем запросы
    std::vector<std::string> queries = converter.GetRequests();

    // Выполняем поиск
    std::vector<std::vector<RelativeIndex>> search_results = srv.search(queries);

    // Сохраняем ответы
    converter.putAnswers(search_results);

    return 0;
}
