#include "document.h"
#include <string>

Document::Document() = default;
Document::Document(int id, double relevance, int rating)
    : id(id)
    , relevance(relevance)
    , rating(rating) {
    }
