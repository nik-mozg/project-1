#include "ConverterJSON.h"
#include <fstream>
#include <iostream>
#include <sstream>

using json = nlohmann::json;

// Чтение JSON файла и возврат его содержимого в виде объекта json
json ConverterJSON::readJSONFile(const std::string& fileName) {
    std::ifstream file(fileName); // Открытие файла
    if (!file) {
        throw std::runtime_error(fileName + " is missing"); // Исключение, если файл не найден
    }
    json j;
    file >> j; // Чтение содержимого файла в объект json
    return j;
}

// Получение текстовых документов из конфигурационного файла
std::vector<std::string> ConverterJSON::GetTextDocuments() {
    json config = readJSONFile("config.json"); // Чтение конфигурационного файла
    if (config.find("files") == config.end()) {
        throw std::runtime_error("config file is empty or missing 'files'"); // Исключение, если ключ 'files' отсутствует
    }

    std::vector<std::string> documents;
    // Проход по всем файлам, указанным в конфигурационном файле
    for (const auto& file : config["files"]) {
        std::ifstream textFile(file.get<std::string>()); // Открытие текстового файла
        if (textFile) {
            // Чтение содержимого файла в строку
            std::string content((std::istreambuf_iterator<char>(textFile)), std::istreambuf_iterator<char>());
            documents.push_back(content); // Добавление содержимого в вектор документов
        }
    }
    return documents; // Возврат вектора документов
}

// Получение ограничения на количество ответов из конфигурационного файла
int ConverterJSON::GetResponsesLimit() {
    json config = readJSONFile("config.json"); // Чтение конфигурационного файла
    if (config.find("config") == config.end()) {
        throw std::runtime_error("config file is empty or missing 'config'"); // Исключение, если ключ 'config' отсутствует
    }
    // Возврат значения 'max_responses', если ключ отсутствует, используется значение по умолчанию 5
    return config["config"].value("max_responses", 5);
}

// Получение запросов из файла requests.json
std::vector<std::string> ConverterJSON::GetRequests() {
    json requests = readJSONFile("requests.json"); // Чтение файла запросов
    if (requests.find("requests") == requests.end()) {
        throw std::runtime_error("requests file is empty or missing 'requests'"); // Исключение, если ключ 'requests' отсутствует
    }

    std::vector<std::string> requestList;
    // Проход по всем запросам и добавление их в вектор запросов
    for (const auto& request : requests["requests"]) {
        requestList.push_back(request.get<std::string>());
    }
    return requestList; // Возврат вектора запросов
}

// Запись ответов в файл answers.json
void ConverterJSON::putAnswers(const std::vector<std::vector<RelativeIndex>>& answers) {
    json result;
    // Проход по всем ответам
    for (size_t i = 0; i < answers.size(); ++i) {
        json requestResult;
        // Если есть релевантные документы, устанавливаем результат как 'true'
        if (!answers[i].empty()) {
            requestResult["result"] = "true";
            json relevance = json::array();
            // Проход по всем релевантным документам и добавление их в массив relevance
            for (const auto& relIdx : answers[i]) {
                json doc;
                doc["docid"] = relIdx.doc_id;
                doc["rank"] = relIdx.rank;
                relevance.push_back(doc);
            }
            requestResult["relevance"] = relevance;
        } else {
            // Если релевантных документов нет, устанавливаем результат как 'false'
            requestResult["result"] = "false";
        }
        result["request" + std::to_string(i + 1)] = requestResult; // Добавление результата запроса в общий результат
    }

    std::ofstream answersFile("answers.json"); // Открытие файла для записи
    answersFile << result.dump(4);  // Запись результата в файл с форматированием (отступ 4 пробела)
}
