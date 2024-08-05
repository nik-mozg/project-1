#pragma once
#ifndef INVERTED_INDEX_H
#define INVERTED_INDEX_H

#include <vector>
#include <string>
#include <unordered_map>

/**
 * @struct Entry
 * @brief Структура для хранения информации о частоте слова в документе.
 */
struct Entry {
    size_t doc_id; ///< Идентификатор документа, в котором встречается слово.
    int count;     ///< Количество вхождений слова в документе.
};

/**
 * @class InvertedIndex
 * @brief Класс для реализации обратного индекса, который хранит частоту слов в документах.
 */
class InvertedIndex {
public:
    /**
     * @brief Обновляет базу документов, используя предоставленные текстовые документы.
     * @param input_docs Вектор строк, где каждая строка представляет содержимое одного документа.
     */
    void UpdateDocumentBase(const std::vector<std::string>& input_docs);

    /**
     * @brief Получает список записей (вхождений) для указанного слова.
     * @param word Слово, для которого нужно получить информацию о частоте.
     * @return Вектор структур Entry, где каждая запись представляет частоту слова в документе.
     */
    std::vector<Entry> GetWordCount(const std::string& word) const;

    /**
     * @brief Выполняет поиск информации о частоте указанного слова в документе.
     * @param word Слово для поиска.
     * @return Константная ссылка на вектор записей (вхождений) для указанного слова.
     * @note Возвращает пустой вектор, если слово не найдено.
     */
    const std::vector<Entry>& Lookup(const std::string& word) const;

    /**
     * @brief Получает количество документов в базе.
     * @return Количество документов.
     */
    size_t GetDocumentCount() const;

private:
    std::unordered_map<std::string, std::vector<Entry>> freq_dictionary; ///< Словарь, где ключ - слово, значение - вектор записей (вхождений).
    size_t document_count = 0; ///< Количество документов в базе.
};

#endif // INVERTED_INDEX_H
