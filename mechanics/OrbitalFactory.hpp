#pragma once

#include "../config.h"

#include <memory>
#include <functional>

#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#include <glm/glm.hpp>

class IOrbitalFactory {
public:
    enum class PositionCallback {
        None,
        Sun,
        Mercury,
        Venus,
        Earth,
        Earth_Moon,
        Mars,
        Mars_Phobos,
        Mars_Demos,
        Saturn,
        Jupiter,
        Uranus,
        Neptune,
        Pluto
    };

    using PositionCallbackFun = std::function<void(double, glm::dvec3&)>;

    MECHANICS_EXPORT static const IOrbitalFactory& instance();

    virtual PositionCallbackFun orbitalSampler(PositionCallback) const = 0;

private:
    static std::unique_ptr<IOrbitalFactory> _instance;
};

class OrbitalFactory : public IOrbitalFactory {
public:
    PositionCallbackFun orbitalSampler( PositionCallback ) const override;
};
