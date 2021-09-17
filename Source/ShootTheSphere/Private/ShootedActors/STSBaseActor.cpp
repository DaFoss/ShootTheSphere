// Fill out your copyright notice in the Description page of Project Settings.


#include "STSBaseActor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SphereComponent.h"
#include "Materials/Material.h"
#include "STSGameMode.h"
#include "STSExplosionFXComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseActor, All, All)

ASTSBaseActor::ASTSBaseActor()
{
	//no need tick and no spawn if collision get touched during spawn
	PrimaryActorTick.bCanEverTick = false;
	SpawnCollisionHandlingMethod = ESpawnActorCollisionHandlingMethod::DontSpawnIfColliding;

	//create base mesh
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SetRootComponent(Mesh);

	//create spherecomponent to get collisions
	SphereComponent = CreateDefaultSubobject<USphereComponent>("Sphere");
	SphereComponent->InitSphereRadius(55.f);
	SphereComponent->SetupAttachment(Mesh);
	//assigning delegate on hit component
	SphereComponent->OnComponentHit.AddDynamic(this, &ASTSBaseActor::OnComponentHit);
	
	//create material and assign it
	Material = CreateDefaultSubobject<UMaterial>("Material");
	Mesh->SetMaterial(0, Material);

	ExplosionFXComponent = CreateDefaultSubobject<USTSExplosionFXComponent>("ExplosionFXComponent");
}


void ASTSBaseActor::BeginPlay()
{
	Super::BeginPlay();
	
	check(Mesh);
	check(SphereComponent);
	check(Material);
	check(ExplosionFXComponent);

	GameMode = GetSTSGameMode();
}

//when hit the sphere destroy it and decreasing numbers for next wave
void ASTSBaseActor::OnComponentHit(	UPrimitiveComponent* HitComponent, AActor* OtherActor,	UPrimitiveComponent* OtherComp,
	FVector NormalImpulse,	const FHitResult& Hit)
{
	UE_LOG(LogBaseActor, Display, TEXT("Got HIT"));
	GameMode->HitTheSphere();
	ExplosionFXComponent->PlayExplosionFX(this);
	Destroy();
}

//finding gamemode to get acces to spawninghub
ASTSGameMode* ASTSBaseActor::GetSTSGameMode() const
{
	return GetWorld() ? Cast<ASTSGameMode>(GetWorld()->GetAuthGameMode()) : nullptr;
}