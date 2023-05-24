#include <BuildTool/build_params.hpp>

BuildParams::BuildParams(char **begin, char **end) {
  while (begin != end) {
    if (*begin[0] == '-') {
      if (!strcmp(*begin, "--build") || !strcmp(*begin, "-b")) {
        begin++;
        if ((begin != end) && (*begin[0] != '-'))
          build_dir_ = std::filesystem::path(*begin);
        else
          throw std::invalid_argument("Argument parsing failed for argument " +
                                      **std::prev(begin));
      } else if (!strcmp(*begin, "--test") || !strcmp(*begin, "-t")) {
        test_ = true;
      }
    } else {
      target_ = *begin;
    }
    begin++;
  }
}