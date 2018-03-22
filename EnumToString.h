#pragma once

#include <boost/optional.hpp>
#include <boost/preprocessor.hpp>
#include <boost/utility/string_view.hpp>

template <typename E>
boost::optional<E> toEnum(boost::string_view);

// Used in toString() method
#define ENUM_TO_STR(unused, _, elem)                                                               \
    if (e == elem)                                                                                 \
        return boost::string_view(BOOST_PP_STRINGIZE(elem));

#define STR_TO_ENUM(unused, _, elem)                                                               \
    if (s == BOOST_PP_STRINGIZE(elem))                                                             \
        return elem;

#define ENUM(NAME, SEQ)                                                                            \
    enum NAME { BOOST_PP_SEQ_ENUM(SEQ) };                                                          \
                                                                                                   \
    boost::optional<boost::string_view> toString(NAME e) {                                         \
        BOOST_PP_SEQ_FOR_EACH(ENUM_TO_STR, ~, SEQ)                                                 \
        return boost::none;                                                                        \
    }                                                                                              \
                                                                                                   \
    template <>                                                                                    \
    boost::optional<NAME> toEnum<NAME>(boost::string_view s) {                                     \
        BOOST_PP_SEQ_FOR_EACH(STR_TO_ENUM, ~, SEQ)                                                 \
        return boost::none;                                                                        \
    }
