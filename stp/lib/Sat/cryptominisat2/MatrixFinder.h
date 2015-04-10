/*****************************************************************************
MiniSat -- Copyright (c) 2003-2006, Niklas Een, Niklas Sorensson
CryptoMiniSat -- Copyright (c) 2009 Mate Soos

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
********************************************************************/

#ifndef MATRIXFINDER_H
#define MATRIXFINDER_H

#include <vector>
#include <map>
#ifdef _MSC_VER
#include "msvc/stdint.h"
#else
#include <stdint.h>
#endif //_MSC_VER

#include "Clause.h"
#include "Solver.h"

namespace CMSat2
{
using namespace CMSat2;

class Solver;

using std::map;
using std::vector;
using std::pair;

class MatrixFinder
{

public:
  MatrixFinder(Solver& solver);
  bool findMatrixes();

private:
  unsigned setMatrixes();

  struct mysorter
  {
    bool operator()(const pair<unsigned, unsigned>& left, const pair<unsigned, unsigned>& right)
    {
      return left.second < right.second;
    }
  };

  void findParts(vector<Var>& xorFingerprintInMatrix,
                 vector<XorClause*>& xorsInMatrix);
  inline Var fingerprint(const XorClause& c) const;
  inline bool firstPartOfSecond(const XorClause& c1, const XorClause& c2) const;

  map<unsigned, vector<Var>> reverseTable; // matrix -> vars
  vector<Var> table; // var -> matrix
  unsigned matrix_no;

  Solver& solver;
};

} // NAMESPACE CMSat2

#endif // MATRIXFINDER_H
