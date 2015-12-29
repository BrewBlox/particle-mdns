#include "QuerySet.h"

bool QuerySet::readHeader(Buffer * buffer) {
    bool success = false;

    if (buffer->available() >= 12) {
        id = buffer->readUInt16();
        flags = buffer->readUInt16();
        qdcount = buffer->readUInt16();
        ancount = buffer->readUInt16();
        nscount = buffer->readUInt16();
        arcount = buffer->readUInt16();

        entryCount = 0;
    }

    return success;
}

bool QuerySet::isQuery() {
    return (flags & 0x8000) == 0;
}

uint16_t QuerySet::getId() {
    return id;
}

uint16_t QuerySet::getFlags() {
    return flags;
}

uint16_t QuerySet::getQueryCount() {
    return qdcount;
}

uint16_t QuerySet::getAnswerCount() {
    return ancount;
}

uint16_t QuerySet::getAuthorityCount() {
    return nscount;
}

uint16_t QuerySet::getAdditionalCount() {
    return arcount;
}

uint8_t QuerySet::getEntryCount() {
    return entryCount;
}

void QuerySet::setResponses(uint16_t responses) {
    this->responses = responses;
}

uint16_t QuerySet::getResponses() {
    return responses;
}

void QuerySet::setStatus(String status) {
    this->status = status;
}

String QuerySet::getStatus() {
    return status;
}
