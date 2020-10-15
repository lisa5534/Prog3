#include "BoardManager.hpp"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <iostream>

using namespace Prog3::Controller;
using namespace Prog3::Repository;
using namespace Prog3::Model;
using namespace rapidjson;
using namespace std;

BoardManager::BoardManager(RepositoryIf &givenRepository) : repository(givenRepository) {
}

BoardManager::~BoardManager() {
}

std::string BoardManager::getBoard() {
    Board board = repository.getBoard();

    Document document;
    document.SetObject();
    Document::AllocatorType &allocator = document.GetAllocator();

    Value boardTitle(board.getTitle().c_str(), allocator);
    Value columns = getJson(board.getColumns(), allocator);

    document.AddMember("title", boardTitle, allocator);
    document.AddMember("columns", columns, allocator);

    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    document.Accept(writer);

    return buffer.GetString();
}

Value BoardManager::getJson(vector<Column> givenColumns, Document::AllocatorType &allocator) {
    Value columns(kArrayType);
    for (auto column : givenColumns) {
        Value jsonColumn(kObjectType);
        jsonColumn.AddMember("id", column.id, allocator);
        jsonColumn.AddMember("name", Value(column.name.c_str(), allocator), allocator);
        jsonColumn.AddMember("position", column.position, allocator);

        Value items = getJson(column.items, allocator);
        jsonColumn.AddMember("items", items, allocator);

        columns.PushBack(jsonColumn, allocator);
    }

    return columns;
}

Value BoardManager::getJson(vector<string> givenItems, Document::AllocatorType &allocator) {
    Value items(kArrayType);

    for (auto item : givenItems) {
        Value jsonItem(item.c_str(), allocator);
        items.PushBack(jsonItem, allocator);
    }

    return items;
}