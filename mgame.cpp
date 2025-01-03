#include <iostream>
#include <libplatform/libplatform.h>
#include <v8.h>

// Function to initialize V8
void InitializeV8() {
    v8::V8::InitializeICUDefaultLocation("");
    v8::V8::InitializeExternalStartupData("");
    std::unique_ptr<v8::Platform> platform = v8::platform::NewDefaultPlatform();
    v8::V8::InitializePlatform(platform.get());
    v8::V8::Initialize();
}

// Function to run a script
void RunScript(v8::Isolate* isolate, const std::string& script) {
    v8::Isolate::Scope isolate_scope(isolate);
    v8::HandleScope handle_scope(isolate);
    v8::Local<v8::Context> context = v8::Context::New(isolate);
    v8::Context::Scope context_scope(context);

    v8::Local<v8::String> source =
        v8::String::NewFromUtf8(isolate, script.c_str(), v8::NewStringType::kNormal).ToLocalChecked();
    v8::Local<v8::Script> compiled_script = v8::Script::Compile(context, source).ToLocalChecked();
    v8::Local<v8::Value> result = compiled_script->Run(context).ToLocalChecked();

    v8::String::Utf8Value utf8(isolate, result);
    std::cout << *utf8 << std::endl;
}

int main() {
    InitializeV8();

    v8::Isolate::CreateParams create_params;
    create_params.array_buffer_allocator = v8::ArrayBuffer::Allocator::NewDefaultAllocator();
    v8::Isolate* isolate = v8::Isolate::New(create_params);

    {
        v8::Isolate::Scope isolate_scope(isolate);
        v8::HandleScope handle_scope(isolate);
        v8::Local<v8::Context> context = v8::Context::New(isolate);

        v8::Context::Scope context_scope(context);

        
        RunScript(isolate, script)

        
    }

    isolate->Dispose();
    v8::V8::Dispose();
    v8::V8::ShutdownPlatform();
    delete create_params.array_buffer_allocator;

    return 0;
}
