//===- ImageScaler.h --------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_IR_COMPUTE_OPERATOR_IMAGESCALER_H
#define ONNC_IR_COMPUTE_OPERATOR_IMAGESCALER_H
#include <onnc/IR/ComputeOperator.h>
#include <onnc/IR/ComputeVisitor.h>
#include <onnc/IR/Compute/Attributes.h>
#include <onnc/Support/IOStream.h>

namespace onnc {

class ImageScaler : public ComputeOperator
{
public:
  enum IOConst {
    kInput = 0,
    kOutput = 0
  };

public:
  ImageScaler();

  ImageScaler(const FloatsAttr& pBias,
              const FloatAttr& pScale);

  ~ImageScaler() { }

  const FloatsAttr& getBias() const { return m_Bias; }

  const FloatAttr& getScale() const { return m_Scale; }

  Tensor* getInput(unsigned int pIdx) override { return static_cast<Tensor*>(m_Inputs[pIdx]); }

  const Tensor* getInput(unsigned int pIdx) const override { return static_cast<Tensor*>(m_Inputs[pIdx]); }

  Tensor* getOutput(unsigned int pIdx) override { return static_cast<Tensor*>(m_Outputs[pIdx]); }

  const Tensor* getOutput(unsigned int pIdx) const override { return static_cast<Tensor*>(m_Outputs[pIdx]); }

  Tensor* getInput() { return getInput(kInput); }

  Tensor* getOutput() { return getOutput(kOutput); }

  void setInput(Tensor& pTensor) { m_Inputs[kInput] = &pTensor; }

  void setOutput(Tensor& pTensor) { m_Outputs[kOutput] = &pTensor; }

  void print(std::ostream& pOS) const override;

  void dump() const { print(errs()); }

  void accept(ComputeVisitor& pVisitor) { pVisitor.visit(*this); }

private:
  FloatsAttr m_Bias;
  FloatAttr m_Scale;
};

} // namespace of onnc

#endif
