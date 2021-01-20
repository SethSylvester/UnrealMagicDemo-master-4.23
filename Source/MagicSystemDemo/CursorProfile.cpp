// Fill out your copyright notice in the Description page of Project Settings.


#include "CursorProfile.h"

// Sets default values
ACursorProfile::ACursorProfile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ACursorProfile::test()
{
}

// Called when the game starts or when spawned
void ACursorProfile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACursorProfile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACursorProfile::SetPosition(float x, float y)
{
	FVector newPosition = FVector(x, y, 0);
	AActor::SetActorLocation(newPosition);
}

