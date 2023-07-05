#include <BuildTool/actions/ObjAction.hpp>

template <class PredT, class SuccT>
bool Obj<PredT, SuccT>::checkDeprecated() const {
  if (file_checker_.checkDeprecated()) {
    propagateDeprecated();
    return true;
  } else {
    status_ = BuildStatus::Built;
    return false;
  }
}

template <class PredT, class SuccT>
void Obj<PredT, SuccT>::propagateDeprecated() {
  if (status_ != BuildStatus::Deprecated) {
    status_ = BuildStatus::Deprecated;
    for (const SuccT *succ : succ_)
      succ->propagateDeprecated();
  }
}

template <class PredT, class SuccT>
BuildStatus &Obj<PredT, SuccT>::getStatus() {
  return status_;
}