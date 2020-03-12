// Copyright 2019 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#include "tink/python/cc/output_stream_adapter.h"

#include "third_party/pybind11/include/pybind11/pybind11.h"
#include "tink/python/cc/clif/status_casters.h"

namespace crypto {
namespace tink {

PYBIND11_MODULE(output_stream_adapter, m) {
  namespace py = pybind11;

  // TODO(b/146492561): Reduce the number of complicated lambdas.
  py::class_<OutputStreamAdapter>(m, "OutputStreamAdapter")
      .def(
          "write",
          [](OutputStreamAdapter* self,
             const py::bytes& data) -> util::StatusOr<int64_t> {
            return self->Write(std::string(data));
          },
          py::arg("data"))
      .def("close", &OutputStreamAdapter::Close);
}

}  // namespace tink
}  // namespace crypto