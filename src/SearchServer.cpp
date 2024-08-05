#include "SearchServer.h"
#include "InvertedIndex.h"
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <sstream>

// Определение конструктора
SearchServer::SearchServer(InvertedIndex& idx, int responses_limit)
    : _index(idx), _responses_limit(responses_limit) {}

// Определение метода search
std::vector<std::vector<RelativeIndex>> SearchServer::search(const std::vector<std::string>& queries_input) const {
    std::vector<std::vector<RelativeIndex>> result;

    for (const auto& query : queries_input) {
        std::istringstream stream(query);
        std::unordered_set<std::string> query_words;
        std::string word;

        // Разбиваем запрос на уникальные слова
        while (stream >> word) {
            query_words.insert(word);
        }

        // Используем unordered_map для хранения абсолютной релевантности документов
        std::unordered_map<size_t, float> doc_relevances;

        // Считаем абсолютную релевантность для каждого документа
        for (const auto& word : query_words) {
            auto entries = _index.Lookup(word);
            for (const auto& entry : entries) {
                doc_relevances[entry.doc_id] += entry.count;
            }
        }

        // Находим максимальную абсолютную релевантность
        float max_relevance = 0;
        for (const auto& [doc_id, relevance] : doc_relevances) {
            if (relevance > max_relevance) {
                max_relevance = relevance;
            }
        }

        // Нормализуем релевантность
        std::vector<RelativeIndex> ranked_results;
        for (const auto& [doc_id, relevance] : doc_relevances) {
            float normalized_relevance = max_relevance > 0 ? relevance / max_relevance : 0;
            ranked_results.push_back({doc_id, normalized_relevance});
        }

        // Сортируем по убыванию релевантности, если ранги равны - по возрастанию doc_id
        std::sort(ranked_results.begin(), ranked_results.end(), [](const RelativeIndex& a, const RelativeIndex& b) {
            if (a.rank == b.rank) {
                return a.doc_id < b.doc_id; // Если ранги равны, сортируем по doc_id
            }
            return a.rank > b.rank; // Иначе сортируем по убыванию ранга
        });

        // Ограничиваем количество результатов, используя _responses_limit
        if (ranked_results.size() > _responses_limit) {
            ranked_results.resize(_responses_limit);
        }

        // Добавляем результат в итоговый результат
        result.push_back(std::move(ranked_results));
    }

    return result;
}
