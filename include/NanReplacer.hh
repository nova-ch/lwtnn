#ifndef NAN_REPLACER_HH
#define NAN_REPLACER_HH

#include <map>
#include <string>

namespace lwt {
  namespace rep {
    const unsigned nan  = 0x1 << 0;
    const unsigned inf  = 0x1 << 1;
    const unsigned ninf = 0x1 << 2;
    const unsigned all  = nan | inf | ninf;
  }
  class NanReplacer
  {
  public:
    typedef std::map<std::string, double> ValueMap;
    NanReplacer(const ValueMap& defaults, int flags = rep::nan);
    NanReplacer(NanReplacer&) = delete;
    NanReplacer& operator=(NanReplacer&) = delete;
    ValueMap replace(const ValueMap& in) const;
  private:
    ValueMap m_defaults;
    bool m_do_nan;
    bool m_do_inf;
    bool m_do_ninf;
  };
}

#endif
