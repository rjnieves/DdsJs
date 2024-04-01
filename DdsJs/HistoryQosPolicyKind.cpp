/**
 * \file HistoryQosPolicyKind.cpp
 * \brief Contains the implementation for the \c HistoryQosPolicyKindProxy class.
 * \author Rolando J. Nieves <rolando.j.nieves@nasa.gov>
 * \date 2024-01-31 15:26:11
 */

#include "HistoryQosPolicyKind.hh"


namespace DdsJs {

const char *HistoryQosPolicyKindProxy::NAME = "HistoryQosPolicyKind";


Napi::Object
HistoryQosPolicyKindProxy::Init(Napi::Env env, Napi::Object exports)
{
    Napi::Object enum_obj = Napi::Object::New(env);
    enum_obj.DefineProperties(
        {
            Napi::PropertyDescriptor::Value("KEEP_LAST_HISTORY_QOS", Napi::Number::New(env, DDS::KEEP_LAST_HISTORY_QOS), napi_enumerable),
            Napi::PropertyDescriptor::Value("KEEP_ALL_HISTORY_QOS", Napi::Number::New(env, DDS::KEEP_ALL_HISTORY_QOS), napi_enumerable)
        }
    );

    exports.Set(HistoryQosPolicyKindProxy::NAME, enum_obj);

    return exports;
}


HistoryQosPolicyKindProxy::NapiContainer
HistoryQosPolicyKindProxy::NewInstance(Napi::Env env)
{
    Napi::EscapableHandleScope scope(env);
    Napi::Number result = Napi::Number::New(env, DDS::VOLATILE_DURABILITY_QOS);

    return scope.Escape((napi_value)result).ToNumber();
}


HistoryQosPolicyKindProxy::NapiContainer
HistoryQosPolicyKindProxy::NewInstance(Napi::Env env, CppEntity const& cppInstance)
{
    Napi::EscapableHandleScope scope(env);
    Napi::Number result = Napi::Number::New(env, cppInstance);

    return scope.Escape((napi_value)result).ToNumber();
}


void
HistoryQosPolicyKindProxy::FromCpp(Napi::Env env, CppEntity const& cppVal, NapiContainer& jsValOut)
{
    jsValOut = NewInstance(env, cppVal);
}


void
HistoryQosPolicyKindProxy::FromJs(Napi::Env env, NapiContainer const& jsVal, CppEntity& cppValOut)
{
    cppValOut = static_cast< CppEntity >(jsVal.Int32Value());
}

} // end namespace DdsJs

// vim: set ts=4 sw=4 expandtab:
