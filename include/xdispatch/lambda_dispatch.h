/*
* Copyright (c) 2008-2009 Apple Inc. All rights reserved.
* Copyright (c) 2011 MLBA. All rights reserved.
*
* @MLBA_OPEN_LICENSE_HEADER_START@
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
*     http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
* @MLBA_OPEN_LICENSE_HEADER_END@
*/


/* When building on 10.6 with gcc 4.5.1 we can bypass
    Apple's lambda functions implementation in C++ as we have lambdas.
	This prevents a lot of errors from occuring
	*/

#ifndef XDISPATCH_LAMBDA_DISPATCH_H_
#define XDISPATCH_LAMBDA_DISPATCH_H_

#ifndef __XDISPATCH_INDIRECT__
#error "Please #include <xdispatch/dispatch.h> instead of this file directly."
#endif

/// provide block specific libdispatch functions as well

#if defined(XDISPATCH_HAS_BLOCKS) && !defined(__BLOCKS__)

inline void dispatch_async(dispatch_queue_t queue, dispatch_block_t block){
    dispatch_async_f(queue, new xdispatch::block_operation(block), _xdispatch_run_operation);
}

inline void dispatch_after(dispatch_time_t when, dispatch_queue_t queue, dispatch_block_t block){
    dispatch_after_f(when, queue, new xdispatch::block_operation(block), _xdispatch_run_operation);
}

inline void dispatch_sync(dispatch_queue_t queue, dispatch_block_t block){
    dispatch_sync_f(queue, new xdispatch::block_operation(block), _xdispatch_run_operation);
}

inline void dispatch_apply(size_t iterations, dispatch_queue_t queue, dispatch_iteration_block_t block){
    xdispatch::iteration_wrap wrap( new xdispatch::block_iteration_operation(block), iterations );
    dispatch_apply_f(iterations, queue, &wrap, _xdispatch_run_iter_wrap);
}

inline void dispatch_group_async(dispatch_group_t group, dispatch_queue_t queue, dispatch_block_t block){
    dispatch_group_async_f(group, queue, new xdispatch::block_operation(block), _xdispatch_run_operation);
}

inline void dispatch_group_notify(dispatch_group_t group, dispatch_queue_t queue, dispatch_block_t block){
    dispatch_group_notify_f(group,queue, new xdispatch::block_operation(block), _xdispatch_run_operation);
}

XDISPATCH_EXPORT void dispatch_source_set_event_handler(dispatch_source_t source, dispatch_block_t handler);

XDISPATCH_EXPORT void dispatch_source_set_cancel_handler(dispatch_source_t source, dispatch_block_t cancel_handler);

XDISPATCH_EXPORT void dispatch_once(dispatch_once_t *predicate, dispatch_block_t block);

#endif

#endif /* XDISPATCH_LAMBDA_DISPATCH_H_ */