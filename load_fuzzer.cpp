#include <cstdint>

#include <fuzzer/FuzzedDataProvider.h>
#include <yaml-cpp/yaml.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size) {
    auto fdp = FuzzedDataProvider(data, size);

    try {
        auto nodes = YAML::LoadAll(fdp.ConsumeRemainingBytesAsString());
    } catch (...) {
    }

    return 0;
}

