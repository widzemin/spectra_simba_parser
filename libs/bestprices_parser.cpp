#include "../utils/utils.h"
#include "bestprices_parser.h" 

#include <iostream>

int BestPricesParser::GetParsedLength() const
{
    return parsed_length_;
}

void BestPricesParser::Parse(std::ifstream& file)
{
    uint16_t block_length = Parse16bit(file, order_);
    uint8_t group_size = Parse8bit(file, order_);
    parsed_length_ += ProtocolLength::best_prices_header_length;
    SkipBytes(file, block_length * group_size);
    parsed_length_ += block_length * group_size;
}

void BestPricesParser::PrintInfo() const 
{
    return;
}