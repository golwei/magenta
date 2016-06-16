// Copyright 2016 The Fuchsia Authors
//
// Use of this source code is governed by a MIT-style
// license that can be found in the LICENSE file or at
// https://opensource.org/licenses/MIT

#pragma once

#include <err.h>
#include <stdint.h>

#include <kernel/event.h>

#include <magenta/handle.h>
#include <magenta/magenta.h>
#include <magenta/types.h>

#include <utils/ref_counted.h>
#include <utils/ref_ptr.h>

class HandleList;
class Waiter;

// The Kernel Objects. Keep this list sorted.
class EventDispatcher;
class InterruptDispatcher;
class LogDispatcher;
class MessagePipeDispatcher;
class PciInterruptDispatcher;
class PciDeviceDispatcher;
class ProcessOwnerDispatcher;
class ThreadDispatcher;
class VmObjectDispatcher;
class IoMappingDispatcher;


class Dispatcher : public utils::RefCounted<Dispatcher> {
public:
    virtual ~Dispatcher() {}

    virtual void Close(Handle* handle) = 0;

    virtual mx_obj_type_t GetType() const = 0;

    virtual status_t UserSignal(uint32_t set_mask, uint32_t clear_mask) {
        return ERR_NOT_SUPPORTED;
    }

    virtual Waiter* BeginWait(event_t* event, Handle* handle, mx_signals_t signals) {
        return nullptr;
    }

    virtual EventDispatcher* get_event_dispatcher() {
        return nullptr;
    }

    virtual InterruptDispatcher* get_interrupt_dispatcher() {
        return nullptr;
    }

    virtual MessagePipeDispatcher* get_message_pipe_dispatcher() {
        return nullptr;
    }

    virtual ProcessOwnerDispatcher* get_process_owner_dispatcher() {
        return nullptr;
    }

    virtual ThreadDispatcher* get_thread_dispatcher() {
        return nullptr;
    }

    virtual VmObjectDispatcher* get_vm_object_dispatcher() {
        return nullptr;
    }

    virtual PciDeviceDispatcher* get_pci_device_dispatcher() {
        return nullptr;
    }

    virtual PciInterruptDispatcher* get_pci_interrupt_dispatcher() {
        return nullptr;
    }

    virtual IoMappingDispatcher* get_io_mapping_dispatcher() {
        return nullptr;
    }

    virtual LogDispatcher* get_log_dispatcher() {
        return nullptr;
    }
};