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
	Lv1 = "Level1";
	Lv1 = "Level2";
	SwithLvl = true;
	LevelNow = "Level1";
}

// Called when the game starts or when spawned
void AMainPlayer::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp,Warning,TEXT("changed level"));
	
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
	FInputActionBinding& L1 = PlayerInputComponent->BindAction("Level",EInputEvent::IE_Pressed,this,&AMainPlayer::LevelChange);
	L1.bConsumeInput = true;
	FInputActionBinding& One1=PlayerInputComponent->BindAction("One",EInputEvent::IE_Pressed,this,&AMainPlayer::LevelChange);
	One1.bConsumeInput = true;

	DECLARE_DELEGATE_OneParam(FAnotherCustomInputDelegate, const int32);
    InputComponent->BindAction<FAnotherCustomInputDelegate>("Two", IE_Pressed, this, &AMainPlayer::TwoPressed,1);

	DECLARE_DELEGATE_OneParam(FCustomInputDelegate, int32);
	InputComponent->BindAction<FCustomInputDelegate>("Three", IE_Pressed, this, &AMainPlayer::ThreePressed, 2);

	DECLARE_DELEGATE_OneParam(FCustomInputDelegate, int32);
	InputComponent->BindAction<FCustomInputDelegate>("Three", IE_Released, this, &AMainPlayer::ThreePressed, 0);

	DECLARE_DELEGATE_OneParam(FAnotherCustomInputDelegate, const int32);
    InputComponent->BindAction<FAnotherCustomInputDelegate>("Two", IE_Released, this, &AMainPlayer::TwoPressed,0);
	

}

void AMainPlayer::LevelChange(){

UWorld* World = GetWorld();
if(World){
	//FString CurrentLevel = World->GetMapName();
}
	if (LevelNow == "Level1"){
		UGameplayStatics::OpenLevel(World,"Level2");
		UE_LOG(LogTemp,Warning,TEXT(" level 1" ));
		LevelNow = "Level2";
		SwithLvl = false;
	}else if (LevelNow == "Level2"){
		UGameplayStatics::OpenLevel(World,"Level1");
		UE_LOG(LogTemp,Warning,TEXT("Level 2"));
		LevelNow = "Level1";
		SwithLvl = true;
	}
		UE_LOG(LogTemp,Warning,TEXT("changed level"));


}
void AMainPlayer::BothKeyPressed() {

	if(k1==1 && k2 == 2){
		UE_LOG(LogTemp,Warning,TEXT("Both key pressed "));		
	}

}
void AMainPlayer::TwoPressed(int val){
	k1 = val;
	UE_LOG(LogTemp, Warning, TEXT("Value = %d"), k1);
	BothKeyPressed();
}

void AMainPlayer::ThreePressed(int val){
	k2= val;
	UE_LOG(LogTemp, Warning, TEXT("Value = %d"), k2);
	BothKeyPressed();
}