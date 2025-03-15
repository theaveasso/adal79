#ifndef __ADAL79_SYSTEM_ADL79_FILE_HANDLER_HPP_
#define __ADAL79_SYSTEM_ADL79_FILE_HANDLER_HPP_

namespace adl
{
class file_handler
{
  public:
    explicit file_handler(std::string_view filename);
    ~file_handler();

    std::string              read_all() ;
    std::vector<std::string> read_lines() ;

    void check_file_open();
    [[nodiscard]] inline bool is_open() const { return m_file.is_open(); }

  private:
    std::string   m_filename;
    std::ifstream m_file;
};
} // namespace adl

#endif // __ADAL79_SYSTEM_ADL79_FILE_HANDLER_HPP_
