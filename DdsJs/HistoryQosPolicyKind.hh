/**
 * \file HistoryQosPolicyKind.hh
 * \brief Contains the definition of the \c HistoryQosPolicyKindProxy class.
 * \author Rolando J. Nieves <rolando.j.nieves@nasa.gov>
 * \date 2024-01-31 15:23:02
 */

#ifndef _DDSJS_DDSJS_HISTORYQOSPOLICYKIND_HH_
#define _DDSJS_DDSJS_HISTORYQOSPOLICYKIND_HH_

#include <napi.h>

#include <DdsJs/dds_provider.hh>


namespace DdsJs {

class HistoryQosPolicyKindProxy
{
public:
    using CppEntity = DDS::HistoryQosPolicyKind;
    using NapiContainer = Napi::Number;

    static const char *NAME;

    static Napi::Object Init(Napi::Env env, Napi::Object exports);

    static NapiContainer NewInstance(Napi::Env env);

    static NapiContainer NewInstance(Napi::Env env, CppEntity const& cppInstance);

    static void FromCpp(Napi::Env env, CppEntity const& cppVal, NapiContainer& jsValOut);

    static void FromJs(Napi::Env env, NapiContainer const& jsVal, CppEntity& cppValOut);
};

} // end namespace DdsJs

#endif /* !_DDSJS_DDSJS_HISTORYQOSPOLICYKIND_HH_ */

// vim: set ts=4 sw=4 expandtab:
