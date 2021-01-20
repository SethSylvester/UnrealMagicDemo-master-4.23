// Fill out your copyright notice in the Description page of Project Settings.


#include "MagicSystem.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerController.h"

#include "Runtime/Engine/Classes/GameFramework/Actor.h"

// Sets default values for this component's properties
UMagicSystem::UMagicSystem()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

//RT From Mouse Point
void UMagicSystem::RayTraceFromMouse()
{
	//Player is null and causes crashes
	player->GetMousePosition(MouseX, MouseY);
	mousePos.X = MouseX;
	mousePos.Y = MouseY;

	world = GetWorld();
	player = world->GetFirstPlayerController();
	mousePos = FVector2D(0, 0);
	worldpos = FVector(mousePos.X, mousePos.Y, 0);
	worldDir = FVector(0, 0, 0);
	player->DeprojectMousePositionToWorld(worldpos, worldDir);

	FVector end = GetForwardRotation() * worldDir;

	//raytrace mouse pos
	GetWorld()->LineTraceSingleByChannel(hit, worldpos, end, ECC_Visibility);
}

FVector UMagicSystem::GetForwardRotation()
{
	FRotator rotation = player->GetControlRotation();

	FVector forwardVector =
		FRotationMatrix(forwardVector.Rotation()).GetScaledAxis(EAxis::X);

	//Remove if needed
	forwardVector = forwardVector + 12000.0f;

	return forwardVector;
}

void UMagicSystem::SpawnSpell(FVector spawnLocation)
{
	FActorSpawnParameters spawnParam;
	spawnParam.Name = NAME_None;
	spawnParam.Owner = NULL;
	spawnParam.Instigator = NULL;
	spawnParam.bNoFail = false;
	//UWorld::SpawnActor<ASpell>(ASpell::StaticClass, hitTransform, player->GetControlRotation(), NULL, NULL);
	//UWorld::SpawnActor<ASpell>(ASpell::StaticClass, hitTransform, spawnParam);
}

void UMagicSystem::ConvertHitToTransform()
{
	hitTransform.SetLocation(hit.ImpactPoint);
}

FTransform UMagicSystem::GetHitTransform()
{
	ConvertHitToTransform();
	return hitTransform;
}

// Called when the game starts
void UMagicSystem::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//If Possible and time permits create widget

	cursorShown = false;
	
}


// Called every frame
void UMagicSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//if cursor is shown
	if (cursorShown) {
		//RT From Mouse Point
		RayTraceFromMouse();


		//set actor location
		
	}

	///F Key
	//Display Menu, likely in BP


	//LMB
	
	//Toggle Mouse Cursor

	//Ray Trace Mous Pos

	//Display Menu

	// ...

	
}

void UMagicSystem::CastSpell(int cost)
{
	//Subtract mana cost
	SubtractMana(cost);

	//Allow cursor
	cursorShown = true;

	////Select Area
	///Spawn cursor profile
	//UWorld::SpawnActor();
	//Move cube to mouse location every update
	//UGameplayStatics::GetPlayerController(GetWorld(), 0)->
	//	GetMousePosition(xSpawnPosition, ySpawnPosition);
	//read for click
	//copy click area
	//destroy actor

	///Spawn Bolt
	//SpawnActor bolt in saved area
}

FVector UMagicSystem::GetMousePos()
{
	return FVector();
}

