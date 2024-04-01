/**
 * \file PresentationQosPolicy.hh
 * \brief Contains the definition of the \c PresentationQosPolicyProxy class.
 * \author Rolando J. Nieves <rolando.j.nieves@nasa.gov>
 * \date 2024-01-23 12:16:45
 */

#ifndef _DDSJS_DDSJS_PRESENTATIONQOSPOLICY_HH_
#define _DDSJS_DDSJS_PRESENTATIONQOSPOLICY_HH_

#include <napi.h>

#include <DdsJs/ConstructorRegistry.hh>
#include <DdsJs/PresentationQosPolicyAccessScopeKind.hh>
#include <DdsJs/Primitives.hh>

#include <DdsJs/dds_provider.hh>


namespace DdsJs {

class PresentationQosPolicyProxy : public Napi::ObjectWrap< PresentationQosPolicyProxy >
{
public:
    struct AccessScopeField
    {
        using Proxy = PresentationQosPolicyAccessScopeKindProxy;
        static const char *NAME;
    };

    struct CoherentAccessField
    {
        using Proxy = BooleanPrimitive;
        static const char *NAME;
    };

    struct OrderedAccessField
    {
        using Proxy = BooleanPrimitive;
        static const char *NAME;
    };

    using CppEntity = DDS::PresentationQosPolicy;
    using NapiContainer = Napi::Object;

    static const char *MODNAME;

    static const char *NAME;

    static Napi::Object Init(Napi::Env env, Napi::Object exports, ConstructorRegistry *ctorReg);

    static NapiContainer NewInstance(Napi::Env env);

    static NapiContainer NewInstance(Napi::Env env, CppEntity const& cppInstance);

    static void FromCpp(Napi::Env env, CppEntity const& cppVal, NapiContainer& jsValOut);

    static void FromJs(Napi::Env env, NapiContainer const& jsVal, CppEntity& cppValOut);

    PresentationQosPolicyProxy(Napi::CallbackInfo const& info);

    virtual ~PresentationQosPolicyProxy() = default;
};

} // end namespace DdsJs

#endif /* !_DDSJS_DDSJS_PRESENTATIONQOSPOLICY_HH_ */

// vim: set ts=4 sw=4 expandtab:
