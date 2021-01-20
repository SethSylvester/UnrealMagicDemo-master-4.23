// Fill out your copyright notice in the Description page of Project Settings.


#include "SpellCode.h"

// Sets default values
ASpellCode::ASpellCode()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASpellCode::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASpellCode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Tick down timer
	if (lifeTime > 0.0f) {
		lifeTime -= DeltaTime;
	}
	else {
		//destroy all children
		for (int i = 0; i < this->Children.Num(); i++) {
			this->Children[i]->Destroy();
		}
		//destroy actor
		AActor::Destroy();
	}

}

// Called to bind functionality to input
void ASpellCode::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

