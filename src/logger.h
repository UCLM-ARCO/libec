
#ifndef __EASY_LOGGER_H__
#define __EASY_LOGGER_H__

#include <iostream>

namespace ec{

  class Logger {
  public:
    enum Level {ALL, DEBUG, INFO, WARNING, ERROR, FATAL};
    Level level;
    static Logger root;

    Logger(Level level=ERROR) : level(level) {}
    void set_level(Level new_level) { level = new_level; };
    std::ostream& operator()(Level msg_level);

    std::ostream& debug(void)    { return (*this)(DEBUG); }
    std::ostream& info(void)     { return (*this)(INFO); }
    std::ostream& warn(void)     { return (*this)(WARNING); }
    std::ostream& error(void)    { return (*this)(ERROR); }
    std::ostream& fatal(void)    { return (*this)(FATAL); }

  private:
    std::ofstream* _dev_null;
    std::ofstream& get_null(void);

    friend std::ostream& debug(void);
    friend std::ostream& info(void);
    friend std::ostream& warn(void);
    friend std::ostream& error(void);
    friend std::ostream& fatal(void);
  };

  std::ostream& debug(void);
  std::ostream& info(void);
  std::ostream& warn(void);
  std::ostream& error(void);
  std::ostream& fatal(void);


  /* Class for container logging
   *
   *  vector<string> a;
   *  a.push_back("hola");
   *  a.push_back("adios");
   *  copy(a.begin(), a.end(), Log_iterator<string>(Logger::INFO));
   *
   *  map<string, string> d;
   *  copy(d.begin(), d.end(), Log_iterator<pair<string, string> > (Logger::DEBUG));
   */
  template<typename _Tp>
  class Log_iterator
    : public std::iterator<std::output_iterator_tag, void, void, void, void>
  {
  public:
    //@{
    /// Public typedef
    typedef std::basic_ostream<char, std::char_traits<char> > ostream_type;
    //@}

  private:
    //ostream_type*	_M_stream;
    //const _CharT*	_M_string;
    Logger _logger;
    Logger::Level level;

  public:
    /// Construct from an ostream.
    Log_iterator() :
      _logger(Logger::root),
      level(Logger::ERROR) { }

    Log_iterator(Logger::Level level) :
      _logger(Logger::root),
      level(level)  { }

    Log_iterator(Logger logger, Logger::Level level) :
      _logger(logger),
      level(level)  { }


    /// Copy constructor.
    Log_iterator(const Log_iterator& __obj)
      : _logger(__obj._logger), level(__obj.level)  { }

    Log_iterator&
    operator=(const _Tp& __value)
    {
      //__glibcxx_requires_cond(_M_stream != 0,
      //						_M_message(__gnu_debug::__msg_output_ostream).
      //						_M_iterator(*this));
	//*_M_stream << "[DEBUG2]";
	//*_M_stream << __value;
	//*_M_stream << std::endl;

      _logger(level) << __value << std::endl;
      return *this;
    }

    Log_iterator&
    operator*()
    { return *this; }

    Log_iterator&
    operator++()
    { return *this; }

    Log_iterator&
    operator++(int)
    { return *this; }
  };

}; //namespace

#endif
