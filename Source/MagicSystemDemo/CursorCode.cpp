// Fill out your copyright notice in the Description page of Project Settings.


#include "CursorCode.h"

// Sets default values
ACursorCode::ACursorCode()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACursorCode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACursorCode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACursorCode::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACursorCode::DestroyCursor()
{
	//destroy all children
	for (int i = 0; i < this->Children.Num(); i++) {
		this->Children[i]->Destroy();
	}
	//destroy actor
	AActor::Destroy();
}

