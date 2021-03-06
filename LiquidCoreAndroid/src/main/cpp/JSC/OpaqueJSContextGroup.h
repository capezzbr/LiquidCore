//
// OpaqueJSContextGroup.h
//
// LiquidPlayer project
// https://github.com/LiquidPlayer
//
// Created by Eric Lange
//
/*
 Copyright (c) 2014-2018 Eric Lange. All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:

 - Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.

 - Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef LIQUIDCORE_OPAQUEJSCONTEXTGROUP_H
#define LIQUIDCORE_OPAQUEJSCONTEXTGROUP_H

#include "JSC/JSCRetainer.h"

struct OpaqueJSContext;

struct OpaqueJSContextGroup : public ContextGroup {
    public:
        static boost::shared_ptr<OpaqueJSContextGroup> New();
        static boost::shared_ptr<OpaqueJSContextGroup> New(Isolate *isolate, uv_loop_t *event_loop);
        OpaqueJSContextGroup(Isolate *isolate, uv_loop_t *event_loop);
        OpaqueJSContextGroup();
        virtual ~OpaqueJSContextGroup();

        void AssociateContext(const OpaqueJSContext* ctx);
        void DisassociateContext(const OpaqueJSContext* ctx);

        void Retain();
        void Release();

    private:
        int m_jsc_count;
        std::vector<const OpaqueJSContext *> m_associatedContexts;
        std::mutex m_mutex;
    protected:
        boost::atomic_shared_ptr<ContextGroup> m_self;
};

#endif //LIQUIDCORE_OPAQUEJSCONTEXTGROUP_H
