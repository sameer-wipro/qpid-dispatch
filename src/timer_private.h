#ifndef __timer_private_h__
#define __timer_private_h__ 1
/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

#include "qpid/dispatch/ctools.h"
#include "qpid/dispatch/threading.h"
#include "qpid/dispatch/timer.h"

struct qd_timer_t {
    DEQ_LINKS(qd_timer_t);
    qd_server_t      *server;
    qd_timer_cb_t     handler;
    void             *context;
    qd_timestamp_t    delta_time;
    bool              scheduled; /* true means on scheduled list, false on idle list */
};

DEQ_DECLARE(qd_timer_t, qd_timer_list_t);

void qd_timer_initialize(sys_mutex_t *server_lock);
void qd_timer_finalize(void);
void qd_timer_visit();

/// For tests only
sys_mutex_t* qd_timer_lock();

#endif
