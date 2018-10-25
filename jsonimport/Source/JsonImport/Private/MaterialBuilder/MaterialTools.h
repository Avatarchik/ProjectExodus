#pragma once

#include "JsonTypes.h"

class UMaterialExpression;
class UMaterialExpressionParameter;
class UMaterialExpressionVectorParameter;
class UMaterialExpressionConstant;
class UMaterialExpressionTextureSample;
class UTexture;
class UMaterial;

namespace MaterialTools{
	UMaterialExpression* createMaterialInput(UMaterial *material, UTexture *texture, 
		const FLinearColor *matColor, FExpressionInput &matInput, bool normalMap, const TCHAR* paramName, UMaterialExpressionTextureSample ** outTexNode = 0,
		UMaterialExpressionVectorParameter **outVecParameter = 0);

	UMaterialExpression* createMaterialInputMultiply(UMaterial *material, UTexture *texture, 
		const FLinearColor *matColor, FExpressionInput &matInput, 
		const TCHAR* texParamName, const TCHAR* vecParamName,
		UMaterialExpressionTextureSample ** outTexNode = 0,
		UMaterialExpressionVectorParameter **outVecParameter = 0);

	UMaterialExpression* createMaterialSingleInput(UMaterial *material, float value, FExpressionInput &matInput, const TCHAR* inputName);
	UMaterialExpressionTextureSample *createTextureExpression(UMaterial *material, UTexture *texture, const TCHAR* inputName, bool normalMap = false);
	UMaterialExpressionVectorParameter *createVectorExpression(UMaterial *material, FLinearColor color, const TCHAR* inputName);
	UMaterialExpressionConstant* createConstantExpression(UMaterial *material, float value, const TCHAR* constantName);
	template<typename Exp> Exp* createExpression(UMaterial *material){
		Exp* result = NewObject<Exp>(material);
		material->Expressions.Add(result);
		return result;
	}
}
