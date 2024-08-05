#include "InvertedIndex.h"
#include <sstream>
#include <unordered_map>
#include <vector>
#include <string>

// Метод для обновления базы документов
void InvertedIndex::UpdateDocumentBase(const std::vector<std::string>& input_docs) {
    // Очищаем словарь частотных данных
    freq_dictionary.clear();
    // Обновляем количество документов
    document_count = input_docs.size();

    // Проходим по каждому документу
    for (size_t doc_id = 0; doc_id < input_docs.size(); ++doc_id) {
        std::istringstream stream(input_docs[doc_id]); // Создаем поток для чтения слов из документа
        std::string word;
        // Читаем слова из документа
        while (stream >> word) {
            auto& entries = freq_dictionary[word]; // Получаем или создаем вектор вхождений для слова
            // Если последнее вхождение слова в тот же документ, то увеличиваем счетчик
            if (!entries.empty() && entries.back().doc_id == doc_id) {
                ++entries.back().count;
            } else {
                // Иначе добавляем новое вхождение слова с count = 1
                entries.push_back({doc_id, 1});
            }
        }
    }
}

// Метод для получения частоты слова в документах
std::vector<Entry> InvertedIndex::GetWordCount(const std::string& word) const {
    auto it = freq_dictionary.find(word); // Ищем слово в словаре частот
    // Если слово найдено, возвращаем его вхождения, иначе возвращаем пустой вектор
    if (it != freq_dictionary.end()) {
        return it->second;
    } else {
        return {};
    }
}

// Метод для поиска слова в словаре с возвращением ссылки на вектор вхождений
const std::vector<Entry>& InvertedIndex::Lookup(const std::string& word) const {
    static const std::vector<Entry> empty; // Пустой вектор для возвращения, если слово не найдено
    auto it = freq_dictionary.find(word); // Ищем слово в словаре частот
    // Если слово найдено, возвращаем его вхождения, иначе возвращаем пустой вектор
    if (it != freq_dictionary.end()) {
        return it->second;
    } else {
        return empty;
    }
}
