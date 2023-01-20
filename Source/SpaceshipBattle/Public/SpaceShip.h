// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SpaceShip.generated.h"

class UStaticMeshComponent;
class USphereComponent;
class UCameraComponent;
class USpringArmComponent;
class APlayerController;
class ABullet;
class USoundCue;
class UParticleSystemComponent;
class UParticleSystem;


UCLASS()
class SPACESHIPBATTLE_API ASpaceShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASpaceShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Initialization
	void Init();

	// Look direction when flying
	void LookAtCursor();

	void Move(float DeltaTime);

	// Move up and down
	void MoveForward(float Value);

	// Move left and right
	void MoveRight(float Value);

	// Fire projectiles
	void Fire();

	void StartFire();

	void EndFire();

	void RestartLevel();

	void OnDeath();

protected:
	
	// Expose to BluePrintClass and Instances
	UPROPERTY(VisibleAnywhere, Category = "Component")
		USceneComponent *RootSceneComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		USphereComponent *CollisionComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		UStaticMeshComponent *ShipSM;

	// Prevent camera from rotating with pawn
	UPROPERTY(VisibleAnywhere, Category = "Component")
		USpringArmComponent *SpringComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		UCameraComponent *CameraComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		USceneComponent *SpawnPoint;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		UParticleSystemComponent *ThrusterParticleComp;

	// Particle after blown up
	UPROPERTY(EditAnywhere, Category = "Particle")
		UParticleSystem* ExplosionParticle;

	APlayerController *PC;

	FTimerHandle TimerHandle_BetweenShot;

	FTimerHandle TimerHandle_Restart;

	bool bDead;

	bool bForwardMove;

	bool bRightMove;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	bool GetBDead() { return bDead; };

public:

	UPROPERTY(EditAnywhere, Category = "Default")
		float Speed;

	UPROPERTY(EditAnywhere, Category = "Default")
		TSubclassOf<ABullet> Bullet;

	UPROPERTY(EditAnywhere, Category = "Default")
		float BetweenShot;

	// sounds
	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundCue *GameOverCue;

	UPROPERTY(EditAnywhere, Category = "Sound")
		USoundCue *ShootCue;

};
