#include "arithmetic.h"

#include "booleans.h"

bool nodes::IsValid::update(Node &) {
    set_value(to_bool(value_->get_value().has_value()));

    return true;
}

std::optional<std::string> nodes::Length::unary_update(
    const std::string &input) {
    return std::to_string(input.length());
}

std::optional<std::string> nodes::Equal::binary_update(
    const std::string &left, const std::string &right) {
    return to_bool(left == right);
}

std::optional<std::string> nodes::NotEqual::binary_update(
    const std::string &left, const std::string &right) {
    return to_bool(left != right);
}

std::optional<std::string> nodes::Greater::binary_update(
    const std::string &left, const std::string &right) {
    return to_bool(std::stod(left) > std::stod(right));
}

std::optional<std::string> nodes::Less::binary_update(
    const std::string &left, const std::string &right) {
    return to_bool(std::stod(left) < std::stod(right));
}

std::optional<std::string> nodes::GreaterOrEqual::binary_update(
    const std::string &left, const std::string &right) {
    return to_bool(std::stod(left) >= std::stod(right));
}

std::optional<std::string> nodes::LessOrEqual::binary_update(
    const std::string &left, const std::string &right) {
    return to_bool(std::stod(left) <= std::stod(right));
}

std::optional<std::string> nodes::Negative::unary_update(
    const std::string &input) {
    return std::to_string(-std::stod(input));
}

std::optional<std::string> nodes::Absolute::unary_update(
    const std::string &input) {
    return std::to_string(std::abs(std::stod(input)));
}

static double sign(double value) {
    return value > 0 ? 1.0 : (value < 0 ? -1.0 : 0.0);
}

std::optional<std::string> nodes::Sign::unary_update(const std::string &input) {
    return std::to_string(sign(std::stod(input)));
}

std::optional<std::string> nodes::Sin::unary_update(const std::string &input) {
    return std::to_string(std::sin(std::stod(input)));
}

std::optional<std::string> nodes::Cos::unary_update(const std::string &input) {
    return std::to_string(std::cos(std::stod(input)));
}

std::optional<std::string> nodes::LogE::unary_update(const std::string &input) {
    return std::to_string(std::log(std::stod(input)));
}

std::optional<std::string> nodes::Log2::unary_update(const std::string &input) {
    return std::to_string(std::log2(std::stod(input)));
}

std::optional<std::string> nodes::Log10::unary_update(
    const std::string &input) {
    return std::to_string(std::log10(std::stod(input)));
}
