//
// Created by LEGION on 2025/12/19.
//

#include "lyricsyl.hpp"

QString LyricSyl::toASS() const {
    const auto dur = static_cast<int64_t>(this->_end/10 - this->_begin/10);
    return QString(R"({\k%1%2}%3)")
            .arg(std::max(dur, 0LL))
            .arg(this->_text.trimmed().isEmpty() ? "" : (this->isText() ? R"(\-T)" : (dur == 0 ? R"(\-Z)" : "")))
            .arg(this->_text);
}
