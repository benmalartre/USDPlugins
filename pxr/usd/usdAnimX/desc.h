//
// Copyright 2020 benmalartre
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
#ifndef PXR_USD_USD_ANIMX_DESC_H
#define PXR_USD_USD_ANIMX_DESC_H

#include "pxr/base/tf/token.h"
#include "pxr/base/vt/value.h"
#include <vector>

PXR_NAMESPACE_OPEN_SCOPE

struct UsdAnimXKeyframeDesc {
    double time;
    double data[8];
};

struct UsdAnimXCurveDesc {
    TfToken name;
    TfToken preInfinityType;
    TfToken postInfinityType;
    std::vector<UsdAnimXKeyframeDesc> keyframes;
};

struct UsdAnimXOpDesc {
    TfToken name;
    TfToken target;
    TfToken dataType;
    VtValue defaultValue;
    bool useRotationInterpolation;
    TfToken interpolationMethod;
    std::vector<UsdAnimXCurveDesc> curves;
};

struct UsdAnimXPrimDesc {
    TfToken name;
    std::vector<UsdAnimXPrimDesc> children;
    std::vector<UsdAnimXOpDesc> ops;
    UsdAnimXPrimDesc* parent;
};

struct UsdAnimXDesc {
    std::vector<UsdAnimXPrimDesc> prims;
    double startTimeCode;
    double endTimeCode;
};

PXR_NAMESPACE_CLOSE_SCOPE

#endif // PXR_USD_USD_ANIMX_DESC_H