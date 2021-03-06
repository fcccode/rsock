//
// Created by System Administrator on 1/17/18.
//

#ifndef RSOCK_NETINFO_H
#define RSOCK_NETINFO_H


#include <cstdint>
#include <string>
#include <uv.h>

struct EncHead;
struct sockaddr;

struct ConnInfo {
    uint32_t src = 0;
    uint32_t dst = 0;
    uint16_t sp = 0;
    uint16_t dp = 0;
    EncHead *head = nullptr;    // not responsable to free this pointer

    virtual ~ConnInfo() = default;

    virtual bool IsUdp() const { return true; }

    virtual char *Encode(char *buf, int len) const;

    char *EncodeBase(char *buf, int len) const;;

    virtual const char *Decode(const char *buf, int len);

    const char *DecodeBase(const char *buf, int len);

    virtual std::string ToStr() const;

    ConnInfo() = default;

    ConnInfo(const ConnInfo &info) = default;

    ConnInfo &operator=(const ConnInfo &) = default;

    virtual void Reverse();
};

#endif //RSOCK_NETINFO_H