#pragma once
#include "ObjAction.hpp"
#include <variant>

template <class PredT, class SuccT> class ArLink : Obj<PredT, SuccT> {
  ArLink();
  void update();
};