/* Copyright (c) 2020 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include "common/datatypes/Path.h"

namespace nebula {
void Path::reverse() {
    std::reverse(steps.begin(), steps.end());
    swap(src, steps.front().dst);
    for (size_t i = 0; i < steps.size(); ++i) {
        if (i <= steps.size() - 2) {
            swap(steps[i].dst, steps[i + 1].dst);
        }
        steps[i].type = -steps[i].type;
    }
}

bool Path::append(Path path) {
    if (this->steps.back().dst != path.src) {
        return false;
    }
    this->steps.reserve(path.steps.size());
    this->steps.insert(this->steps.end(),
                       std::make_move_iterator(path.steps.begin()),
                       std::make_move_iterator(path.steps.end()));
    return true;
}
}  // namespace nebula
