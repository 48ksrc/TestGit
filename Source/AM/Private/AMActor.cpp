// Fill out your copyright notice in the Description page of Project Settings.


#include "AMActor.h"
#include "Engine\Engine.h"
#include "Animation\Skeleton.h"
#include "Components/SkinnedMeshComponent.h"

// Sets default values
AAMActor::AAMActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshReference");
	SetRootComponent(SkeletalMeshComponent);
	TCFramesIndex = -1;

}

// Called when the game starts or when spawned
void AAMActor::BeginPlay()
{
	Super::BeginPlay();

	if (SkeletalMeshComponent)
	{
		//TheSkeleton = SkeletalMeshComponent->SkeletalMesh->Skeleton;
		//BoneTree = TheSkeleton->GetBoneTree();
		SkeletalMeshComponent->GetBoneNames(BoneNames);
		numberOfBones = BoneNames.Num();
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("Number of bones = %d"), numberOfBones));

		for (int i = 0; i != numberOfBones; i++)
		{

			FName Name = BoneNames[i];
			UE_LOG(LogTemp, Warning, TEXT("Found %s component at index: %d"), *Name.ToString(), SkeletalMeshComponent->GetBoneIndex(Name));

			if (FName("root") == BoneNames[i])
			{
				TCFramesIndex = SkeletalMeshComponent->GetBoneIndex(BoneNames[i]);
				if (TCFramesIndex > -1)
				{
					//UE_LOG(LogTemp, Warning, TEXT("Found timecode root component at index: %d"), TCFramesIndex);
					TCFRamesTransform = SkeletalMeshComponent->GetBoneTransform(TCFramesIndex);
					UE_LOG(LogTemp, Warning, TEXT("TCFrames Frames = %d"), TCFRamesTransform.GetTranslation().X);
				}
			}
		}
	}

	
	
}

// Called every frame
void AAMActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//TCFRamesTransform = SkeletalMeshComponent->GetBoneTransform(TCFramesIndex);
}

