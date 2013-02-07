/* -*- mode: c++; coding: utf-8 -*- */

//
// Copyright (c) 2012 Oscar Aceña. All rights reserved.
//
// This file is part of libec
//
// libec is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// libec is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with libec.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef LIBEC_PYFUNCTIONS_H
#define LIBEC_PYFUNCTIONS_H

#include <iostream>

#include "PyHandle.h"

namespace ec {
namespace py {

    class RuntimeError { };

    PyObjectPtr importModule(std::string name);

    PyObjectPtr getClass(PyObjectPtr module,
			 std::string name);
    PyObjectPtr getMethod(PyObjectPtr classObj,
			  std::string name);
    PyObjectPtr newInstance(PyObjectPtr cls);
    PyObjectPtr newInstance(PyObjectPtr cls,
			    PyObjectPtr args);
    PyObjectPtr callMethod(PyObjectPtr object,
			   std::string name);
    PyObjectPtr callMethod(PyObjectPtr object,
			   std::string name,
			   PyObjectPtr args);

    bool getAsBool(PyObjectPtr value);
    int getAsInteger(PyObjectPtr value);
    std::string getAsString(PyObjectPtr value);

}}

#endif // LIBEC_PYFUNCTIONS_H
