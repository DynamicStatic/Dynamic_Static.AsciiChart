
/*
==========================================
  Copyright (c) 2020 Dynamic_Static
    Patrick Purcell
      Licensed under the MIT license
    http://opensource.org/licenses/MIT
==========================================
*/

#include "ascii-chart.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

/**
+-------------------------+-------------------------+-------------------------+
|{                        |{                        |{                        |
|    "type": "frog",      |    "type": "spider",    |    "type": "human",     |
|    "legs": 4            |    "legs": 8            |    "legs": 2            |
|}                        |}                        |}                        |
|                         |                         |                         |
|                         |                         |                         |
+-------------------------+-------------------------+-------------------------+
|{                        |{                        |
|    "type": "chimpanzee",|    "type": "centipede", |
|    "legs": 2            |    "legs": "too many",  |
|}                        |    "stinger": true      |
|                         |}                        |
|                         |                         |
+-------------------------+-------------------------+-------------------------+
|{                        |{                        |{                        |
|    "type": "bee",       |    "type": "bat",       |    "type": "scorpion",  |
|    "legs": 6,           |    "legs": 2,           |    "legs": 8,           |
|    "wings": 4,          |    "wings": 2           |    "pincers": 2,        |
|    "stinger": true      |}                        |    "stinger": true      |
|}                        |                         |}                        |
+-------------------------+-------------------------+-------------------------+
|{                        |
|    "type": "robin",     |
|    "legs": 2,           |
|    "wings": 2           |
|}                        |
|                         |
+-------------------------+
*/
dst::AsciiChart get_json_ascii_chart()
{
    std::vector<std::string> jsonStrs {
R"({
    "type": "frog",
    "legs": 4
})",
R"({
    "type": "spider",
    "legs": 8
})",
R"({
    "type": "human",
    "legs": 2
})",
R"({
    "type": "chimpanzee",
    "legs": 2
})",
R"({
    "type": "centipede",
    "legs": "too many",
    "stinger": true
})",
R"({
    "type": "bee",
    "legs": 6,
    "wings": 4,
    "stinger": true
})",
R"({
    "type": "bat",
    "legs": 2,
    "wings": 2
})",
R"({
    "type": "scorpion",
    "legs": 8,
    "pincers": 2,
    "stinger": true
})",
R"({
    "type": "robin",
    "legs": 2,
    "wings": 2
})",
    };
    return dst::AsciiChart {
        {
            { jsonStrs[0], jsonStrs[1], jsonStrs[2], },
            { jsonStrs[3], jsonStrs[4], },
            { jsonStrs[5], jsonStrs[6], jsonStrs[7] },
            { jsonStrs[8], },
        },
        dst::AsciiChart::BoldBox
    };
}

/**
+----+
|0   |
| \n |
+----+----+----+----+----+----+----+----+----+----+----+----+
|1   |2   |3   |4   |5   |6   |7   |8   |9   |10  |11  |12  |
|  L |  o |  r |  e |  m |    |  i |  p |  s |  u |  m | \n |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|13  |14  |15  |16  |17  |18  |19  |20  |21  |22  |23  |24  |25  |26  |27  |
|  d |  o |  l |  o |  r |    |  s |  i |  t |    |  a |  m |  e |  t | \n |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|28  |29  |30  |31  |32  |33  |34  |35  |36  |37  |38  |39  |40  |41  |
|  d |  u |  i |  s |    |  s |  i |  t |    |  n |  o |  n |  . | \n |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|42  |
| \n |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|43  |44  |45  |46  |47  |48  |49  |50  |51  |52  |53  |54  |55  |56  |57  |
|  A |  r |  c |  u |    |  n |  u |  n |  c |  . |    |  d |  i |  a | \n |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|58  |59  |60  |61  |62  |63  |64  |65  |66  |67  |68  |69  |70  |71  |72  |
|  t |  o |  r |  t |  o |  r |  , |    |  d |  i |  c |  t |  u |  m | \n |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|73  |74  |75  |76  |77  |78  |79  |80  |81  |82  |83  |84  |85  |86  |87  |
|  p |  r |  i |  m |  i |  s |    |  i |  n |    |  i |  p |  s |  a | \n |
+----+----+----+----+----+----+----+----+----+----+----+----+----+----+----+
|88  |89  |90  |91  |92  |93  |94  |95  |96  |97  |98  |99  |100 |
|  n |  u |  l |  l |  a |    |  p |  r |  o |  i |  n |  . | \n |
+----+----+----+----+----+----+----+----+----+----+----+----+----+
*/
dst::AsciiChart get_lorem_ipsum_ascii_chart()
{
    std::string loremIpsum = R"(
Lorem ipsum
dolor sit amet
duis sit non.

Arcu nunc. dia
tortor, dictum
primis in ipsa
nulla proin.
)";
    dst::AsciiChart asciiChart;
    asciiChart.seperator = dst::AsciiChart::Box;
    size_t lineBegin = 0;
    while (lineBegin < loremIpsum.size()) {
        auto lineEnd = std::min(loremIpsum.find('\n', lineBegin), loremIpsum.size());
        auto lineSize = lineEnd + 1 - lineBegin;
        asciiChart.cells.emplace_back();
        asciiChart.cells.back().reserve(lineSize);
        for (size_t i = lineBegin; i < lineEnd; ++i) {
            asciiChart.cells.back().emplace_back(std::to_string(i) + "\n  " + loremIpsum[i] + ' ');
        }
        asciiChart.cells.back().emplace_back(std::to_string(lineEnd) + "\n \\n ");
        lineBegin = lineEnd + 1;
    }
    return asciiChart;
}

/**
+--------+--------+--------+--------+--------+--------+--------+--------+
|0       |1       |2       |3       |4       |5       |6       |7       |
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
|1       |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
|2       |        |        |        |        ||||||||||        |        |
|        |        |        |        |        |{ 5, 2 }|        |        |
|        |        |        |        |        ||||||||||        |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
|3       ||||||||||        |        |        |        |        |        |
|        |{ 1, 3 }|        |        |        |        |        |        |
|        ||||||||||        |        |        |        |        |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
|4       |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
|5       |        |        ||||||||||        |        |        |        |
|        |        |        |{ 3, 5 }|        |        |        |        |
|        |        |        ||||||||||        |        |        |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
|6       |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
|        |        |        |        |        |        |        |        |
+--------+--------+--------+--------+--------+--------+--------+--------+
|7       |        |        |        |        |        ||||||||||        |
|        |        |        |        |        |        |{ 6, 7 }|        |
|        |        |        |        |        |        ||||||||||        |
+--------+--------+--------+--------+--------+--------+--------+--------+
*/
dst::AsciiChart get_coordinate_ascii_chart()
{
    dst::AsciiChart asciiChart;
    asciiChart.seperator = dst::AsciiChart::BoldBox;
    asciiChart.cells = dst::AsciiChart::Cell::Grid(8, dst::AsciiChart::Cell::Row(8));
    for (size_t row_i = 0; row_i < asciiChart.cells.size(); ++row_i) {
        asciiChart.cells[row_i][0] = std::to_string(row_i);
    }
    for (size_t column_i = 0; column_i < asciiChart.cells[0].size(); ++column_i) {
        asciiChart.cells[0][column_i] = std::to_string(column_i);
    }
    auto setupCell =
    [&asciiChart](size_t row, size_t column)
    {
        auto& cell = asciiChart.cells[row][column];
        cell = "\n{ " + std::to_string(column) + ", " + std::to_string(row) + " }\n";
        cell.fill = '|';
    };
    setupCell(2, 5);
    setupCell(3, 1);
    setupCell(5, 3);
    setupCell(7, 6);
    return asciiChart;
}

void print_ascii_chart(const std::string& name, dst::AsciiChart asciiChart)
{
    std::cout << '\n';
    std::cout << name << '\n';
    std::cout << asciiChart << '\n';
    asciiChart.seperator = dst::AsciiChart::Basic;
    std::ofstream(name + "-ascii-chart.txt") << asciiChart;
}

int main(int argc, const char* argv[])
{
    print_ascii_chart("json", get_json_ascii_chart());
    print_ascii_chart("lorem-ipsum", get_lorem_ipsum_ascii_chart());
    print_ascii_chart("coordinate", get_coordinate_ascii_chart());
    return 0;
}
