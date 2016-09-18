//---------------------------------------------------------------------------
/*
ManyDigitNewick, Newick class
Copyright (C) 2011-2015 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/CppManyDigitNewick.htm
//---------------------------------------------------------------------------
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"

#include "manydigitnewick.h"

#include <cassert>
#include <cmath>
#include <boost/test/unit_test.hpp>

#include <iostream>


#include <boost/numeric/conversion/cast.hpp>

#include "newickvector.h"
#include "newick.h"
#include "manydigitnewickindexer.h"
#pragma GCC diagnostic pop


BOOST_AUTO_TEST_CASE(ribi_ManyDigitNewick_all)
{
  const double theta = 10.0;
  ribi::ManyDigitNewick::SetTheta(theta);
  const std::vector<std::string> v = ribi::Newick().CreateValidNewicks();
  for(const std::string& s: v)
  {
    if ( ribi::Newick().CalcComplexity(ribi::Newick().StringToNewick(s))
      >  BigInteger(10000) )
    {
      continue;
    }
    ribi::ManyDigitNewick::CalculateProbability(s,theta);
  }
}
