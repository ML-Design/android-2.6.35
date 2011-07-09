/*
 *  pm_wakeup.h - Power management wakeup interface
 *
 *  Copyright (C) 2008 Alan Stern
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _LINUX_PM_WAKEUP_H
#define _LINUX_PM_WAKEUP_H

#ifndef _DEVICE_H_
# error "please don't include this file directly"
#endif

#include <linux/types.h>

/* changes to device_may_wakeup take effect on the next pm state change.
 * by default, devices should wakeup if they can.
 */
struct wakeup_source {
       char                    *name;
       struct list_head        entry;
       spinlock_t              lock;
       struct timer_list       timer;
       unsigned long           timer_expires;
       ktime_t total_time;
       ktime_t max_time;
       ktime_t last_time;
       unsigned long           event_count;
       unsigned long           active_count;
       unsigned long           relax_count;
       unsigned long           hit_count;
       unsigned int            active:1;
};

#ifdef CONFIG_PM_SLEEP

/*
 * Changes to device_may_wakeup take effect on the next pm state change.
 */

static inline void device_set_wakeup_capable(struct device *dev, bool capable)
{
       dev->power.can_wakeup = capable;
}

static inline bool device_can_wakeup(struct device *dev)
{
       return dev->power.can_wakeup;
}



static inline bool device_may_wakeup(struct device *dev)
{
	return dev->power.can_wakeup && !!dev->power.wakeup;
}

/* drivers/base/power/wakeup.c */
extern struct wakeup_source *wakeup_source_create(const char *name);
extern void wakeup_source_destroy(struct wakeup_source *ws);
extern void wakeup_source_add(struct wakeup_source *ws);
extern void wakeup_source_remove(struct wakeup_source *ws);
extern struct wakeup_source *wakeup_source_register(const char *name);
extern void wakeup_source_unregister(struct wakeup_source *ws);
extern int device_wakeup_enable(struct device *dev);
extern int device_wakeup_disable(struct device *dev);
extern int device_init_wakeup(struct device *dev, bool val);
extern int device_set_wakeup_enable(struct device *dev, bool enable);
extern void __pm_stay_awake(struct wakeup_source *ws);
extern void pm_stay_awake(struct device *dev);
extern void __pm_relax(struct wakeup_source *ws);
extern void pm_relax(struct device *dev);
extern void __pm_wakeup_event(struct wakeup_source *ws, unsigned int msec);
extern void pm_wakeup_event(struct device *dev, unsigned int msec);

#else /* !CONFIG_PM_SLEEP */

static inline void device_set_wakeup_capable(struct device *dev, bool capable)
{
	dev->power.can_wakeup = capable;
}

static inline bool device_can_wakeup(struct device *dev)
{
	return dev->power.can_wakeup;
}

static inline bool device_may_wakeup(struct device *dev)
{
	return false;
}

static inline struct wakeup_source *wakeup_source_create(const char *name)
{
	return NULL;
}

static inline void wakeup_source_destroy(struct wakeup_source *ws) {}

static inline void wakeup_source_add(struct wakeup_source *ws) {}

static inline void wakeup_source_remove(struct wakeup_source *ws) {}

static inline struct wakeup_source *wakeup_source_register(const char *name)
{
	return NULL;
}

static inline void wakeup_source_unregister(struct wakeup_source *ws) {}

static inline int device_wakeup_enable(struct device *dev)
{
	return -EINVAL;
}

static inline int device_wakeup_disable(struct device *dev)
{
	return 0;
}

static inline int device_init_wakeup(struct device *dev, bool val)
{
       dev->power.can_wakeup = val;
       return val ? -EINVAL : 0;
}

static inline int device_set_wakeup_enable(struct device *dev, bool enable)
{
	return -EINVAL;
}

static inline void __pm_stay_awake(struct wakeup_source *ws) {}

static inline void pm_stay_awake(struct device *dev) {}

static inline void __pm_relax(struct wakeup_source *ws) {}

static inline void pm_relax(struct device *dev) {}

static inline void __pm_wakeup_event(struct wakeup_source *ws, unsigned int msec) {}

static inline void pm_wakeup_event(struct device *dev, unsigned int msec) {}

#endif /* !CONFIG_PM_SLEEP */

#endif /* _LINUX_PM_WAKEUP_H */
