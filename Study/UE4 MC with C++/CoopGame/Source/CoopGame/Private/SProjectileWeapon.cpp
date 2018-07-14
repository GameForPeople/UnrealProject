// Fill out your copyright notice in the Description page of Project Settings.

#include "SProjectileWeapon.h"
#include "Engine/World.h"

void ASProjectileWeapon::fire()
{
	AActor* MyOwner = GetOwner();

	if (MyOwner && ProjectileClass)
	{
		FVector EyeLocation;
		FRotator EyeRotation;

		MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation); // Eye Location, Eye Rotation

		FVector MuzzleLocation = MeshComp->GetSocketLocation(MuzzleSocketName);
		//FRotator MuzzleRotation = MeshComp->GetSocketRotation(MuzzleSocketName);

		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GetWorld()->SpawnActor<AActor>(ProjectileClass, MuzzleLocation, EyeRotation, SpawnParams);
	}
}



