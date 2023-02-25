#pragma once

#include <SFML/System/Vector2.hpp>

class SquareForm;

class PositionAligner {
public:
    void placeWithMargin(const SquareForm& ref, SquareForm& target, float left, float top) {
        const sf::Vector2f& refPos = ref.getPosition();
        float refOutline = ref.getOutlineSize();

        target.setPosition(sf::Vector2f(refPos.x + refOutline + left, refPos.y + refOutline + top));
    }

    void placeAndSizeWithMargin(const SquareForm& ref, SquareForm& target, float left, float top, float right, float buttom) {
        const sf::Vector2f& refPos = ref.getPosition();
        const sf::Vector2f& refSize = ref.getSize();
        float refOutline = ref.getOutlineSize();

        target.setPosition(sf::Vector2f(refPos.x + refOutline + left, refPos.y + refOutline + top));
        target.setSize(sf::Vector2f(refSize.x - left - right, refSize.y - top - buttom));
    }
};

class SquareForm {
protected:
    SquareForm() = default;

public:
    virtual const sf::Vector2f& getPosition() const = 0;
    virtual const sf::Vector2f& getSize() const = 0;
    virtual float getOutlineSize() const = 0;

    virtual void setPosition(const sf::Vector2f& pos) = 0;
    virtual void setSize(const sf::Vector2f& size) = 0;
    virtual void setOutlineSize(float size) = 0;
};