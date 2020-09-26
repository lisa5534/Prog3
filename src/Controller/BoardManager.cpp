#include "BoardManager.hpp"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

using namespace Prog3::Controller;
using namespace Prog3::Repository;
using namespace rapidjson;

BoardManager::BoardManager(RepositoryIf & givenRepository):
    repository(givenRepository)
{
}

BoardManager::~BoardManager()
{
}

std::string BoardManager::getBoard()
{
    Model::Board board = repository.getBoard();

    Document document;
    document.SetObject();
    Document::AllocatorType& allocator = document.GetAllocator();

    Value jsonBoardTitle(board.getTitle().c_str(), allocator);
    Value jsonColumns(kArrayType);
    
    for (auto column : board.getColumns())
    {
        Value singleJsonColumn(kObjectType);
        singleJsonColumn.AddMember("id", column.id, allocator);
        singleJsonColumn.AddMember("name", Value(column.name.c_str(), allocator), allocator);
        singleJsonColumn.AddMember("position", column.position, allocator);

        Value jsonItems(kArrayType);
        for (auto item : column.items)
        {
            Value itemString(item.c_str(), allocator);
            jsonItems.PushBack(itemString, allocator);
        }
        
        singleJsonColumn.AddMember("items", jsonItems, allocator);
        jsonColumns.PushBack(singleJsonColumn, allocator);
    }

    document.AddMember("title", jsonBoardTitle, allocator);
    document.AddMember("columns", jsonColumns, allocator);

    StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	document.Accept(writer);


    return buffer.GetString();
}