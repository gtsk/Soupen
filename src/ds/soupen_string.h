#ifndef YEDIS_STRING_H_
#define YEDIS_STRING_H_
#include "../base/soupen_memory.h"
namespace soupen_datastructures
{
  class SoupenString
  {
  public:
    int init(char *str, int64_t len);
    int init(char *str);
    ~SoupenString();
    YEDIS_MUST_INLINE const char *get_ptr() const
    {
      return data_;
    }
    YEDIS_MUST_INLINE bool is_equal(const char *p) const
    {
      return !strcmp(p, data_);
    }
    YEDIS_MUST_INLINE bool is_equal(const char *p, int64_t len) const
    {
      return !strncmp(p, data_, len < len_ ? len : len_);
    }
    YEDIS_MUST_INLINE bool is_equal(const SoupenString *other) const
    {
      return !strncmp(other->data_, data_, this->length() < other->length() ? this->length() : other->length());
    }
    YEDIS_MUST_INLINE int cmp(const char *p) const
    {
      return strcmp(p, data_);
    }
    YEDIS_MUST_INLINE int cmp(const SoupenString *other) const
    {
      return strcmp(other->data_, data_);
    }
    YEDIS_MUST_INLINE int64_t get_object_size() const
    {
      return len_ < CHAR_LEN_THRESHOLD ? sizeof(SoupenString) + len_ + 1 : sizeof(SoupenString);
    }
    YEDIS_MUST_INLINE int64_t length() const
    {
      return len_;
    }
    YEDIS_MUST_INLINE bool is_empty() const
    {
      return data_ == nullptr || len_ == 0;
    }
    static int factory(const char *p, SoupenString* &yn_str);
  private:
    static const int64_t CHAR_LEN_THRESHOLD = 48;
    int64_t len_;
    char *data_;
    char buffer_data_[0];
  };
}
#endif /*YEDIS_STRING_H_*/