// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CursorCode.h"
#include "MagicSystem.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAGICSYSTEMDEMO_API UMagicSystem : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMagicSystem();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SubtractMana(int amount) { mana -= amount; }
	void AddMana(int amount) { mana += amount; }
	int GetMana() { return mana; }
	void SetMana(int value) { mana = value; }

	UFUNCTION(BlueprintCallable)
		bool GetCursorShown() { return cursorShown; }

	//Debug Function
	UFUNCTION(BlueprintCallable)
	void SetCursorShown(bool value) { cursorShown = value; }

	UFUNCTION(BlueprintCallable)
	void CastSpell(int cost);

	UFUNCTION(BlueprintCallable)
	FVector GetMousePos();

	UFUNCTION(BlueprintCallable)
	void RayTraceFromMouse();

	UFUNCTION(BlueprintCallable)
	void SpawnSpell(FVector spawnLocation);

	UFUNCTION(BlueprintCallable)
	void SetPlayerController(APlayerController* p) { player = p; }

	UFUNCTION(BlueprintCallable)
	FTransform GetHitTransform();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	int mana = 100;
	bool cursorShown = false;

	float MouseX;
	float MouseY;

	UWorld* world;
	APlayerController* player;
	FVector2D mousePos;
	FVector worldDir;
	FVector worldpos;
	FHitResult hit;
	FVector hitVector;
	FTransform hitTransform;

	//Functions
	FVector GetForwardRotation();
	void ConvertHitToTransform();
	ACursorCode cursor;
};
//UPROPERTY(VisibleAnywhere, BlueprintReadOnly)