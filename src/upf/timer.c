/*
 * Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "timer.h"
#include "event.h"
#include "context.h"

static upf_timer_cfg_t g_upf_timer_cfg[MAX_NUM_OF_UPF_TIMER] = {
    [UPF_TIMER_CONNECT_TO_UPF] = 
        { .duration = ogs_time_from_sec(12) },
};

upf_timer_cfg_t *upf_timer_cfg(upf_timer_e id)
{
    ogs_assert(id < MAX_NUM_OF_UPF_TIMER);
    return &g_upf_timer_cfg[id];
}

const char *upf_timer_get_name(upf_timer_e id)
{
    switch (id) {
    case UPF_TIMER_CONNECT_TO_UPF:
        return "UPF_TIMER_CONNECT_TO_UPF";
    default: 
       break;
    }

    return "UNKNOWN_TIMER";
}

void upf_timer_connect_to_upf(void *data)
{
    int rv;
    upf_event_t *e = NULL;
    ogs_assert(data);

    e = upf_event_new(UPF_EVT_N4_TIMER);
    e->timer_id = UPF_TIMER_CONNECT_TO_UPF;
    e->pnode = data;

    rv = ogs_queue_push(upf_self()->queue, e);
    if (rv != OGS_OK) {
        ogs_warn("ogs_queue_push() failed:%d", (int)rv);
        upf_event_free(e);
    }
}