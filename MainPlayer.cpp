// Fill out your copyright notice in the Description page of Project Settings.

#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"
#include "Containers/UnrealString.h"
#include "Engine/World.h"
#include "MainPlayer.h"

// Sets default values
AMainPlayer::AMainPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMainPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Passing Values to the TwoPressed and ThreePressed functions 
	DECLARE_DELEGATE_OneParam(FAnotherCustomInputDelegate, const int32);
    	InputComponent->BindAction<FAnotherCustomInputDelegate>("Two", IE_Pressed, this, &AMainPlayer::TwoPressed,1);

	DECLARE_DELEGATE_OneParam(FCustomInputDelegate, int32);
	InputComponent->BindAction<FCustomInputDelegate>("Three", IE_Pressed, this, &AMainPlayer::ThreePressed, 2);

	//On release both values are 0 
	DECLARE_DELEGATE_OneParam(FCustomInputDelegate, int32);
	InputComponent->BindAction<FCustomInputDelegate>("Three", IE_Released, this, &AMainPlayer::ThreePressed, 0);

	DECLARE_DELEGATE_OneParam(FAnotherCustomInputDelegate, const int32);
    	InputComponent->BindAction<FAnotherCustomInputDelegate>("Two", IE_Released, this, &AMainPlayer::TwoPressed,0);
	

}

// if both pressed do cerrain actions
void AMainPlayer::BothKeyPressed() {

	if(k1==1 && k2 == 2){
		UE_LOG(LogTemp,Warning,TEXT("Both key pressed "));		
	}
	// here if two ket pressed together you can do any actions you want 

}
// if Key two pressed do cerrain actions
void AMainPlayer::TwoPressed(int val){
	
	k1 = val;
	UE_LOG(LogTemp, Warning, TEXT("Value = %d"), k1);
	BothKeyPressed();
}
//if Key 3 pressed do certain actions 
void AMainPlayer::ThreePressed(int val){
	k2= val;
	UE_LOG(LogTemp, Warning, TEXT("Value = %d"), k2);
	BothKeyPressed();
}
