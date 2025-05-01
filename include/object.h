#pragma once

#include <iostream>
#include <memory>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <stdexcept>

// Classe base para todos os componentes
class Component {
public:
    virtual ~Component() = default;

    bool selectable = true;

    virtual void start() {}
    virtual void update() {}
    virtual void render() {}
};

// Object que gerencia componentes
class Object {
private:
    std::unordered_map<std::type_index, std::shared_ptr<Component>> components;

public:
    bool selectable = true;

    template<typename T, typename... Args>
    T* addComponent(Args&&... args) {
        auto type = std::type_index(typeid(T));
        if (components.count(type)) {
            throw std::runtime_error("Component already exists!");
        }
        auto comp = std::make_shared<T>(std::forward<Args>(args)...);
        T* ptr = comp.get();
        components[type] = comp;
        return ptr;
    }

    template<typename T>
    T* getComponent() {
        auto type = std::type_index(typeid(T));
        auto it = components.find(type);
        if (it != components.end()) {
            return dynamic_cast<T*>(it->second.get());
        }
        return nullptr;
    }

    template<typename T>
    void removeComponent() {
        auto type = std::type_index(typeid(T));
        components.erase(type);
    }

    void startAll() {
        for (auto& pair : components) {
            if (pair.second) {
                pair.second->start();
            }
        }
    }

    void updateAll() {
        for (auto& pair : components) {
            if (pair.second) {
                pair.second->update();
            }
        }
    }

    virtual void render()
    {
        for (auto& pair : components)
        {
            pair.second->selectable = selectable;
            pair.second->render();
        }
    }
};
