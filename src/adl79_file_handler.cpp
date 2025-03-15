#include "adal79/system/adl79_file_handler.hpp"
#include <sstream>
#include <string>

namespace adl
{
file_handler::file_handler(std::string_view filename)
    : m_filename(filename)
{
    adl_debug_constructor(file_handler);

    m_file.open(m_filename);
    check_file_open();
}

file_handler::~file_handler()
{
    m_file.close();
    adl_debug_deconstructor(file_handler);
}

void file_handler::check_file_open()
{
    if (!m_file.is_open())
    {
        throw std::runtime_error(fmt::format("failed to open file [{}]!", m_filename));
    }
}

std::string file_handler::read_all()
{
    check_file_open();

    std::stringstream buf;
    buf << m_file.rdbuf();
    return buf.str();
}

std::vector<std::string> file_handler::read_lines()
{
    check_file_open();

    std::vector<std::string> lines;
    std::string              line;
    while (std::getline(m_file, line))
    {
        lines.push_back(line);
    }
    return lines;
}

} // namespace adl
