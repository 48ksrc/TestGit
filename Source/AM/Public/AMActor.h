// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine\SkeletalMesh.h"
#include "Components\SkeletalMeshComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AMActor.generated.h"

UCLASS()
class AM_API AAMActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAMActor();

	UPROPERTY(Category = SkeletalMeshActor, VisibleAnywhere, BlueprintReadOnly, meta = (ExposeFunctionCategories = "Mesh,Components|SkeletalMesh,Animation,Physics", AllowPrivateAccess = "true"))
		USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditAnywhere, Category = "TCFramesTransform")
		FTransform TCFRamesTransform;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	USkeleton* TheSkeleton;
	TArray<struct FBoneNode> BoneTree;
	TArray<FName> BoneNames;
	int numberOfBones;
	int TCFramesIndex;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
