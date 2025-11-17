// Copyright Yanna. All rights reserved.

#include "VRPornPawn.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"


// Sets default values
AVRPornPawn::AVRPornPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	VRRoot = CreateDefaultSubobject<USceneComponent>(TEXT("VRRoot"));
	SetRootComponent(VRRoot);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(VRRoot);

	LeftController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("LeftController"));
	LeftController->SetupAttachment(VRRoot);
	LeftController->SetTrackingSource(EControllerHand::Left);

	RightController = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("RightController"));
	RightController->SetupAttachment(VRRoot);
	RightController->SetTrackingSource(EControllerHand::Right);
}

// Called when the game starts or when spawned
void AVRPornPawn::BeginPlay()
{
	Super::BeginPlay();

	// Important for positional tracking in VR
	UHeadMountedDisplayFunctionLibrary::SetTrackingOrigin(EHMDTrackingOrigin::Floor);
	
}

// Called every frame
void AVRPornPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AVRPornPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    // Bind grab actions
    PlayerInputComponent->BindAction("GrabLeft", IE_Pressed, this, &AVRPornPawn::GrabLeft);
    PlayerInputComponent->BindAction("GrabLeft", IE_Released, this, &AVRPornPawn::ReleaseLeft);
    PlayerInputComponent->BindAction("GrabRight", IE_Pressed, this, &AVRPornPawn::GrabRight);
    PlayerInputComponent->BindAction("GrabRight", IE_Released, this, &AVRPornPawn::ReleaseRight);
}

void AVRPornPawn::GrabLeft()
{
    // Implementation for grabbing with the left hand will go here
    // This will involve sphere traces, identifying grabbable objects, and attaching them via physics handles.
}

void AVRPornPawn::ReleaseLeft()
{
    // Implementation for releasing with the left hand
}

void AVRPornPawn::GrabRight()
{
    // Implementation for grabbing with the right hand
}

void AVRPornPawn::ReleaseRight()
{
    // Implementation for releasing with the right hand
}
