#ifndef LIBUDEV_H
#define LIBUDEV_H

#include <sys/types.h> // For dev_t

// Opaque structures
struct udev;
struct udev_device;
struct udev_enumerate;
struct udev_monitor;
struct udev_list_entry;
struct udev_hwdb;

// API functions (ensure all functions in .c are declared here)
struct udev *udev_new(void);
struct udev *udev_ref(struct udev *udev);
struct udev *udev_unref(struct udev *udev);

struct udev_device *udev_device_new_from_syspath(struct udev *udev, const char *syspath);
struct udev_device *udev_device_new_from_devnum(struct udev *udev, char type, dev_t devnum); // Added
struct udev_device *udev_device_new_from_subsystem_sysname(struct udev *udev, const char *subsystem, const char *sysname);
struct udev_device *udev_device_ref(struct udev_device *udev_device);
struct udev_device *udev_device_unref(struct udev_device *udev_device);
const char *udev_device_get_syspath(struct udev_device *udev_device);
const char *udev_device_get_devnode(struct udev_device *udev_device);
const char *udev_device_get_subsystem(struct udev_device *udev_device);
const char *udev_device_get_sysname(struct udev_device *udev_device);
const char *udev_device_get_devtype(struct udev_device *udev_device);
const char *udev_device_get_property_value(struct udev_device *udev_device, const char *key);
const char *udev_device_get_sysattr_value(struct udev_device *udev_device, const char *sysattr);
struct udev_device *udev_device_get_parent_with_subsystem_devtype(struct udev_device *udev_device, const char *subsystem, const char *devtype);
struct udev_list_entry *udev_device_get_properties_list_entry(struct udev_device *udev_device);
struct udev *udev_device_get_udev(struct udev_device *udev_device);
const char *udev_device_get_action(struct udev_device *udev_device);
const char *udev_device_get_devpath(struct udev_device *udev_device);
dev_t udev_device_get_devnum(struct udev_device *udev_device);
int udev_device_get_is_initialized(struct udev_device *udev_device);
struct udev_device *udev_device_get_parent(struct udev_device *udev_device);
struct udev_list_entry *udev_device_get_devlinks_list_entry(struct udev_device *udev_device);
struct udev_list_entry *udev_device_get_sysattr_list_entry(struct udev_device *udev_device);
struct udev_list_entry *udev_device_get_tags_list_entry(struct udev_device *udev_device);


struct udev_enumerate *udev_enumerate_new(struct udev *udev);
struct udev_enumerate *udev_enumerate_ref(struct udev_enumerate *udev_enumerate);
struct udev_enumerate *udev_enumerate_unref(struct udev_enumerate *udev_enumerate);
int udev_enumerate_add_match_subsystem(struct udev_enumerate *udev_enumerate, const char *subsystem);
int udev_enumerate_add_match_sysname(struct udev_enumerate *udev_enumerate, const char *sysname);
int udev_enumerate_add_match_property(struct udev_enumerate *udev_enumerate, const char *property, const char *value);
int udev_enumerate_scan_devices(struct udev_enumerate *udev_enumerate);
struct udev_list_entry *udev_enumerate_get_list_entry(struct udev_enumerate *udev_enumerate);

struct udev_list_entry *udev_list_entry_get_next(struct udev_list_entry *list_entry);
const char *udev_list_entry_get_name(struct udev_list_entry *list_entry);
const char *udev_list_entry_get_value(struct udev_list_entry *list_entry);

struct udev_monitor *udev_monitor_new_from_netlink(struct udev *udev, const char *name);
struct udev_monitor *udev_monitor_ref(struct udev_monitor *udev_monitor);
struct udev_monitor *udev_monitor_unref(struct udev_monitor *udev_monitor);
int udev_monitor_enable_receiving(struct udev_monitor *udev_monitor);
int udev_monitor_get_fd(struct udev_monitor *udev_monitor);
struct udev_device *udev_monitor_receive_device(struct udev_monitor *udev_monitor);
int udev_monitor_filter_add_match_subsystem_devtype(struct udev_monitor *udev_monitor, const char *subsystem, const char *devtype);

struct udev_hwdb *udev_hwdb_new(struct udev *udev);
struct udev_hwdb *udev_hwdb_ref(struct udev_hwdb *udev_hwdb);
struct udev_hwdb *udev_hwdb_unref(struct udev_hwdb *udev_hwdb);
struct udev_list_entry *udev_hwdb_get_properties_list_entry(struct udev_hwdb *hwdb, const char *modalias, unsigned int flags);

#endif // LIBUDEV_H
