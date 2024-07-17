#ifndef __HOSTAPD_AP_UCODE_H
#define __HOSTAPD_AP_UCODE_H

#include "utils/ucode.h"

struct hostapd_data;

struct hostapd_ucode_bss {
#ifdef UCODE_SUPPORT
	int idx;
#endif
};

struct hostapd_ucode_iface {
#ifdef UCODE_SUPPORT
	int idx;
#endif
};

#ifdef UCODE_SUPPORT

int hostapd_ucode_init(struct hapd_interfaces *ifaces);

void hostapd_ucode_free(void);
void hostapd_ucode_free_iface(struct hostapd_iface *iface);
void hostapd_ucode_free_bss(struct hostapd_data *hapd);
void hostapd_ucode_bss_cb(struct hostapd_data *hapd, const char *type);

#else

static inline int hostapd_ucode_init(struct hapd_interfaces *ifaces)
{
	return -EINVAL;
}
static inline void hostapd_ucode_free(void)
{
}
static inline void hostapd_ucode_free_iface(struct hostapd_iface *iface)
{
}
static inline void hostapd_ucode_bss_cb(struct hostapd_data *hapd, const char *type)
{
}
static inline void hostapd_ucode_free_bss(struct hostapd_data *hapd)
{
}

#endif

static inline void hostapd_ucode_create_bss(struct hostapd_data *hapd)
{
	hostapd_ucode_bss_cb(hapd, "bss_create");
}

static inline void hostapd_ucode_add_bss(struct hostapd_data *hapd)
{
	hostapd_ucode_bss_cb(hapd, "bss_add");
}

static inline void hostapd_ucode_reload_bss(struct hostapd_data *hapd)
{
	hostapd_ucode_bss_cb(hapd, "bss_reload");
}

#endif
