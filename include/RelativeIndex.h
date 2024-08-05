#pragma once
#ifndef RELATIVE_INDEX_H
#define RELATIVE_INDEX_H

#include <cmath> // Для std::abs
#include <cstddef> // Для size_t

/**
 * @struct RelativeIndex
 * @brief Структура для хранения относительного индекса документа.
 *
 * Данная структура используется для хранения идентификатора документа и его
 * ранга, который представляет собой относительную релевантность документа 
 * по сравнению с другими документами в результатах поиска.
 */
struct RelativeIndex {
    size_t doc_id; ///< Идентификатор документа
    float rank; ///< Релевантность документа

    /**
     * @brief Оператор сравнения.
     *
     * Сравнивает текущий объект RelativeIndex с другим объектом на равенство.
     * Два объекта считаются равными, если их идентификаторы документов равны,
     * а разница в рангах меньше 0.0001.
     *
     * @param other Другой объект RelativeIndex для сравнения.
     * @return true, если объекты равны, иначе false.
     */
    bool operator==(const RelativeIndex& other) const {
        return doc_id == other.doc_id && std::abs(rank - other.rank) < 0.0001f;
    }
};

#endif 
