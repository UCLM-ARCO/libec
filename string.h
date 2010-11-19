// -*- mode:c++ -*-

#ifndef __EASY_STRING_H__
#define __EASY_STRING_H__


#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <istream>
#include <sstream>

#include "exceptions.h"


namespace ec {

	class string {
	public:

		static const std::string hexdigits;
		static const std::string whitespace;

		static bool contains(const std::string& str, const std::string& substr);
		static bool endswith(const std::string& str, const std::string& suffix);
		static bool isspace(const std::string& str);
		static std::string join(const std::string& str, const std::vector<std::string>& fields);

		/*
		 * string::lower("HellO1\n") produces "hello1\n"
		 */
		static std::string lower(const std::string& str);

		/*
		 * string::replace("__pa_par_apat_", "pa", "MO") produces "__MO_MOr_aMOt_"
		 */
		static std::string replace(const std::string& str, const std::string& old,
															 const std::string& new_, std::string::size_type count = 0);

		/*
		 * string::split("::") produces ["foo", "bar"]
		 */
		static std::vector<std::string> split(const std::string& str, const std::string& sep=whitespace, int maxsplit=-1);

		static bool startswith(const std::string& str, const std::string& prefix);

		static std::string lstrip(const std::string& str, const std::string& remove = whitespace);
		static std::string rstrip(const std::string& str, const std::string& remove = whitespace);
		static std::string strip(const std::string& str, const std::string& remove = whitespace);

		// adaptor for STL algorithms
		inline static std::string strip_(const std::string& str) {
			return strip(str);
		}

		//static std::string title(const std::string& line);
		static std::string upper(const std::string& line);

		static std::string itoa(int n);

		friend std::ostream& ec::operator<<(std::ostream& os, const ec::string& p);
	};

};


//std stream inserters

namespace std {
	ostream& operator<<(ostream& os, const std::vector<std::string>& p);
	ostream& operator<<(ostream& os, const std::vector<int>& p);
	ostream& operator<<(ostream& os, const std::pair<std::string,std::string>& p);
};


#endif
