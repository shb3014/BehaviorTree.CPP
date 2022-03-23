//
// Created by sungaoran on 2022/3/20.
//

#include "behaviortree_cpp_v3/decorators/DecoratorEvent.h"
#include "behaviortree_cpp_v3/decorators/PropReenter.h"


namespace BT {
    NodeStatus DecoratorEvent::tick() {
        if (!m_initialized) {
            m_initialized = true;
            on_init();
        }
        return child()->executeTick();
    }

    int DecoratorEvent::get_priority() {
        Optional<int> ret = getInput<int>(DECORATOR_PRIORITY_NAME);
        if (ret) {
            return ret.value();
        } else {
            return 0;
        }
    }

    int DecoratorEvent::get_index() {
        Optional<int> ret = getInput<int>(DECORATOR_INDEX_NAME);
        if (ret) {
            return ret.value();
        } else {
            return 0;
        }
    }

    NodeStatus DecoratorEvent::on_init() {
        if (auto prop = dynamic_cast<PropReenter *>(child())) {
            m_reenter = true;
        }
        return NodeStatus::SUCCESS;
    }
}
