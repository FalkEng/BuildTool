#pragma once
#include "ObjAction.hpp"

template <class PredT, class SuccT> class GccObj : public Obj<PredT, SuccT> {
  GccObj();
  void update();
};