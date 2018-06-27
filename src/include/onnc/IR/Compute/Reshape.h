//===- Reshape.h --------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_IR_COMPUTE_OPERATOR_RESHAPE_H
#define ONNC_IR_COMPUTE_OPERATOR_RESHAPE_H
#include <onnc/IR/ComputeOperator.h>
#include <onnc/IR/ComputeVisitor.h>
#include <onnc/IR/Compute/Attributes.h>
#include <onnc/Support/IOStream.h>

namespace onnc {

class Reshape : public ComputeOperator
{
public:
  enum IOConst {
    kData = 0,
    kShape = 1,
    kReshaped = 0
  };

public:
  Reshape();

  
  ~Reshape() { }

  
  Tensor* getInput(unsigned int pIdx) override { return static_cast<Tensor*>(m_Inputs[pIdx]); }

  const Tensor* getInput(unsigned int pIdx) const override { return static_cast<Tensor*>(m_Inputs[pIdx]); }

  Tensor* getOutput(unsigned int pIdx) override { return static_cast<Tensor*>(m_Outputs[pIdx]); }

  const Tensor* getOutput(unsigned int pIdx) const override { return static_cast<Tensor*>(m_Outputs[pIdx]); }

  Tensor* getData() { return getInput(kData); }

  Tensor* getShape() { return getInput(kShape); }

  Tensor* getReshaped() { return getOutput(kReshaped); }

  void setData(Tensor& pTensor) { m_Inputs[kData] = &pTensor; }

  void setShape(Tensor& pTensor) { m_Inputs[kShape] = &pTensor; }

  void setReshaped(Tensor& pTensor) { m_Outputs[kReshaped] = &pTensor; }

  void print(std::ostream& pOS) const override;

  void accept(ComputeVisitor& pVisitor) override { pVisitor.visit(*this); }
};

} // namespace of onnc

#endif