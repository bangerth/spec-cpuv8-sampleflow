// ---------------------------------------------------------------------
//
// Copyright (C) 2000 - 2020 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of deal.II.
//
// ---------------------------------------------------------------------


#include <deal.II/lac/block_vector.templates.h>

DEAL_II_NAMESPACE_OPEN

#include "block_vector.inst"

#ifndef DOXYGEN
// these functions can't be generated by the preprocessor since
// the template arguments need to be different
template BlockVector<double>::BlockVector(const BlockVector<float> &);
template BlockVector<float>::BlockVector(const BlockVector<double> &);

#  ifdef DEAL_II_WITH_COMPLEX_VALUES
template BlockVector<std::complex<double>>::BlockVector(
  const BlockVector<std::complex<float>> &);
template BlockVector<std::complex<float>>::BlockVector(
  const BlockVector<std::complex<double>> &);
#  endif
#endif

DEAL_II_NAMESPACE_CLOSE