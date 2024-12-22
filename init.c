void main()
{
	//INIT ECONOMY--------------------------------------
	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	//DATE RESET AFTER ECONOMY INIT-------------------------
	int year, month, day, hour, minute;
	int reset_month = 2, reset_day = 1;
	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

	if ((month == reset_month) && (day < reset_day))
	{
		GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
	}
	else
	{
		if ((month == reset_month + 1) && (day > reset_day))
		{
			GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
		}
		else
		{
			if ((month < reset_month) || (month > reset_month + 1))
			{
				GetGame().GetWorld().SetDate(year, reset_month, reset_day, hour, minute);
			}
		}
	}
}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.25, 0.65 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}
	
	void SetLowHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomFloat( 0.15, 0.35 );
			itemEnt.SetHealth01( "", "", rndHlt );
		}
	}
	
	void SetQuantity(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			float rndHlt = Math.RandomInt( 1, 5 );
			itemEnt.SetQuantity(rndHlt);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer( identity, characterName, pos, 0, "NONE" );
		Class.CastTo( m_player, playerEnt );

		GetGame().SelectPlayer( identity, m_player );

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemClothing;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;
		player.RemoveAllItems();
				
		int throwDice = 3; //Math.RandomInt(0, 2);  
		// WYLOSUJ CZY MA BYĆ US CZY RUS
		if (throwDice == 0) 	// ZRÓB AMERYKAŃCA
		{	
			itemEnt = player.GetInventory().CreateInInventory("PlateCarrierVest");	
			itemEnt = player.GetInventory().CreateInInventory("PlateCarrierPouches");					
			itemEnt = player.GetInventory().CreateInInventory("M67Grenade");
			player.SetQuickBarEntityShortcut(itemEnt, 3);
			itemBs = ItemBase.Cast(itemEnt);
			itemEnt = player.GetInventory().CreateInInventory("M67Grenade");
			player.SetQuickBarEntityShortcut(itemEnt, 4);
			itemBs = ItemBase.Cast(itemEnt);
			itemEnt = player.GetInventory().CreateInInventory("USMCJacket_Woodland");
			itemEnt = player.GetInventory().CreateInInventory("USMCPants_Woodland");
			itemEnt = player.GetInventory().CreateInInventory("Mich2001Helmet");
			itemEnt = player.GetInventory().CreateInInventory("PetrolLighter");
			itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Green");														
			itemEnt = player.GetInventory().CreateInInventory("Armband_Blue");
			itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Beige");
			itemEnt = player.GetInventory().CreateInInventory("MilitaryBelt");
			itemEnt = player.GetInventory().CreateInInventory("Canteen");
			itemEnt = player.GetInventory().CreateInInventory("Shemag_Brown");
			itemEnt = player.GetInventory().CreateInInventory("Battery9V");
			itemEnt = player.GetInventory().CreateInInventory("Battery9V");
			itemEnt = player.GetInventory().CreateInInventory("Heatpack");
			itemEnt = player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			itemEnt = player.GetInventory().CreateInInventory( "BandageDressing" );
			player.SetQuickBarEntityShortcut(itemEnt, 2);
			itemEnt = player.GetInventory().CreateInInventory( "HuntingKnife" );
			player.SetQuickBarEntityShortcut(itemEnt, 1);
			itemEnt = player.GetInventory().CreateInInventory( "Flag_LivoniaArmy" );

			int throwDiceAgain = Math.RandomInt(0, 2); 	// WYLOSUJ MU BROŃ 
			if (throwDiceAgain == 0)
			{
				EntityAI gun1 = player.GetHumanInventory().CreateInHands("M4A1");

				gun1.GetInventory().CreateAttachment("M4_RISHndgrd_Black");
				gun1.GetInventory().CreateAttachment("M4_MPBttstck_Black");
				gun1.GetInventory().CreateAttachment("ACOGOptic_6x");
				gun1.GetInventory().CreateAttachment("Mag_STANAG_30Rnd");
				gun1.GetInventory().CreateAttachment("UniversalLight");	
				gun1.GetInventory().CreateAttachment("M9A1_Bayonet");
				itemEnt = player.GetInventory().CreateInInventory("Battery9V");				
				itemEnt = player.GetInventory().CreateInInventory("Battery9V");
				player.SetQuickBarEntityShortcut(gun1, 0);
				itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
		
			}
			if (throwDiceAgain == 1)
			{
				EntityAI gun2 = player.GetHumanInventory().CreateInHands("AugShort");
				player.SetQuickBarEntityShortcut(gun2, 0);
				gun2.GetInventory().CreateAttachment("Mag_Aug_30Rnd");
				gun2.GetInventory().CreateAttachment("UniversalLight");	
				itemEnt = player.GetInventory().CreateInInventory("Battery9V");
				itemEnt = player.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_Aug_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
			}
			
		}
		if (throwDice == 1) 	// ZRÓB RUSKIEGO
		{			

			// A TAK POZA TYM TO DAJ MU JESZCZE: 
			
			itemEnt = player.GetInventory().CreateInInventory("PlateCarrierVest_Green");
			itemEnt = player.GetInventory().CreateInInventory("PlateCarrierPouches_Green");	
			itemEnt = player.GetInventory().CreateInInventory("RGD5Grenade");
			player.SetQuickBarEntityShortcut(itemEnt, 3);
			itemBs = ItemBase.Cast(itemEnt);
			itemEnt = player.GetInventory().CreateInInventory("RGD5Grenade");
			player.SetQuickBarEntityShortcut(itemEnt, 4);
			itemBs = ItemBase.Cast(itemEnt);
			itemEnt = player.GetInventory().CreateInInventory("Heatpack");
			itemEnt = player.GetInventory().CreateInInventory("GorkaHelmet");
			itemEnt = player.GetInventory().CreateInInventory("GorkaPants_Winter");
			itemEnt = player.GetInventory().CreateInInventory("GorkaEJacket_Winter");
			itemEnt = player.GetInventory().CreateInInventory("PetrolLighter");
			itemEnt = player.GetInventory().CreateInInventory("TacticalGloves_Black");
			itemEnt = player.GetInventory().CreateInInventory("Armband_Red");
			itemEnt = player.GetInventory().CreateInInventory("CombatBoots_Black");
			itemEnt = player.GetInventory().CreateInInventory("Shemag_Green");	
			itemEnt = player.GetInventory().CreateInInventory("MilitaryBelt");
			itemEnt = player.GetInventory().CreateInInventory("AssaultBag_Green");
			itemEnt = player.GetInventory().CreateInInventory("Canteen");
			itemEnt = player.GetInventory().CreateInInventory("Battery9V");
			itemEnt = player.GetInventory().CreateInInventory("Battery9V");
			itemEnt = player.GetInventory().CreateInInventory("Glock19");
			itemEnt = player.GetInventory().CreateInInventory("Mag_Glock_15Rnd");
			itemEnt = player.GetInventory().CreateInInventory("TacticalBaconCan_Opened");
			itemEnt = player.GetInventory().CreateInInventory( "BandageDressing" );
			player.SetQuickBarEntityShortcut(itemEnt, 2);
			itemEnt = player.GetInventory().CreateInInventory( "HuntingKnife" );
			player.SetQuickBarEntityShortcut(itemEnt, 1);
			itemEnt = player.GetInventory().CreateInInventory( "Flag_Bear" );
			
						
			int throwDiceAgain2 = Math.RandomInt(0, 1); // WYLOSUJ MU BROŃ 
			if (throwDiceAgain2 == 0)
			{
				EntityAI gun3 = player.GetHumanInventory().CreateInHands("AK74");
				player.SetQuickBarEntityShortcut(gun3, 0);
				gun3.GetInventory().CreateAttachment("AK_RailHndgrd");
				gun3.GetInventory().CreateAttachment("AKS74U_Bttstck");
				gun3.GetInventory().CreateAttachment("KobraOptic");	
				gun3.GetInventory().CreateAttachment("AK_Bayonet");	
				gun3.GetInventory().CreateAttachment("Mag_AK74_30Rnd");
				gun3.GetInventory().CreateAttachment("UniversalLight");	
				itemEnt = player.GetInventory().CreateInInventory("Battery9V");
				itemEnt = player.GetInventory().CreateInInventory("Battery9V");
				itemEnt = player.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_AK74_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
	
			}
			if (throwDiceAgain2 == 1)
			{				
				EntityAI gun4 = player.GetHumanInventory().CreateInHands("AKM");
				player.SetQuickBarEntityShortcut(gun4, 0);
				gun4.GetInventory().CreateAttachment("AK_RailHndgrd");
				gun4.GetInventory().CreateAttachment("AKS74U_Bttstck");
				gun4.GetInventory().CreateAttachment("KobraOptic");	
				gun4.GetInventory().CreateAttachment("AK_Bayonet");	
				gun4.GetInventory().CreateAttachment("Mag_AKM_30Rnd");
				gun4.GetInventory().CreateAttachment("UniversalLight");
				itemEnt = player.GetInventory().CreateInInventory("Battery9V");
				itemEnt = player.GetInventory().CreateInInventory("Battery9V");
				itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
				itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
			
			}
			
			
		}
		if (throwDice == 2) 			// STWÓRZ BANDYTĘ
		{
		// UBIERZ BANDYTĘ
		
		itemEnt = player.GetInventory().CreateInInventory("PoliceVest");
		itemEnt = player.GetInventory().CreateInInventory("Balaclava3Holes_Black");	
		itemEnt = player.GetInventory().CreateInInventory("WorkingBoots_Brown");
		itemEnt = player.GetInventory().CreateInInventory("TrackSuitJacket_Black");
		itemEnt = player.GetInventory().CreateInInventory("TrackSuitPants_Black");
		itemEnt = player.GetInventory().CreateInInventory("WoolGlovesFingerless_Black");
		itemEnt = player.GetInventory().CreateInInventory("FlatCap_BlackCheck");
		itemEnt = player.GetInventory().CreateInInventory("Slingbag_Black");
		itemEnt = player.GetInventory().CreateInInventory("WorkingBoots_Brown");
		itemEnt = player.GetInventory().CreateInInventory("Flag_Pirates");
		itemEnt = player.GetInventory().CreateInInventory( "BandageDressing" );
		player.SetQuickBarEntityShortcut(itemEnt, 2);
		itemEnt = player.GetInventory().CreateInInventory( "HuntingKnife" );
		player.SetQuickBarEntityShortcut(itemEnt, 1);
		
		
		}
		
		if (throwDice == 3) 					// STWÓRZ RYCERZA
		
		{
		itemEnt = player.GetInventory().CreateInInventory("MedievalBoots");
		itemEnt = player.GetInventory().CreateInInventory("Chainmail_Leggings");	
		itemEnt = player.GetInventory().CreateInInventory("Chainmail");
		itemEnt = player.GetInventory().CreateInInventory("Chainmail_Coif");
		itemEnt = player.GetInventory().CreateInInventory("Leather");
		itemEnt = player.GetInventory().CreateInInventory("Gloves_Natural");
		itemEnt = player.GetInventory().CreateInInventory("LeatherStorageVest_Natural");
		itemEnt = player.GetInventory().CreateInInventory("ImprovisedBag");
		itemEnt = player.GetInventory().CreateInInventory("Sword");
		itemEnt = player.GetInventory().CreateInInventory("Mace");
		EntityAI gun5 = player.GetHumanInventory().CreateInHands("Crossbow_Wood");
		gun5.GetInventory().CreateAttachment("Ammo_HuntingBolt");
		itemEnt = player.GetInventory().CreateInInventory( "BandageDressing" );
		player.SetQuickBarEntityShortcut(itemEnt, 2);
		itemEnt = player.GetInventory().CreateInInventory( "HuntingKnife" );
		player.SetQuickBarEntityShortcut(itemEnt, 1);
		}
		
		if (throwDice == 99) 			// STWÓRZ WORKERA

		{		
			itemEnt = player.GetHumanInventory().CreateInHands("Barrel_Green");
			itemEnt = player.GetInventory().CreateInInventory("Headtorch_Black");
			itemEnt = player.GetInventory().CreateInInventory("WorkingBoots_Yellow");
			itemEnt = player.GetInventory().CreateInInventory("WorkingGloves_Yellow");
			itemEnt = player.GetInventory().CreateInInventory("CargoPants_Grey");
			itemEnt = player.GetInventory().CreateInInventory("ConstructionHelmet_Yellow");
			itemEnt = player.GetInventory().CreateInInventory("TacticalShirt_Grey");
			itemEnt = player.GetInventory().CreateInInventory("ReflexVest");
			itemEnt = player.GetInventory().CreateInInventory("AliceBag_Black");
			itemEnt = player.GetInventory().CreateInInventory("PetrolLighter");
			itemEnt = player.GetInventory().CreateInInventory("Hatchet");
			itemEnt = player.GetInventory().CreateInInventory("Hatchet");
			itemEnt = player.GetInventory().CreateInInventory("SpaghettiCan_Opened");
			itemEnt = player.GetInventory().CreateInInventory("SpaghettiCan_Opened");
			itemEnt = player.GetInventory().CreateInInventory("WaterBottle");
			itemEnt = player.GetInventory().CreateInInventory("Whetstone");
			itemEnt = player.GetInventory().CreateInInventory("Whetstone");
			itemEnt = player.GetInventory().CreateInInventory("Whetstone");
			itemEnt = player.GetInventory().CreateInInventory("NailBox");
			itemEnt = player.GetInventory().CreateInInventory("NailBox");
			itemEnt = player.GetInventory().CreateInInventory("NailBox");
			itemEnt = player.GetInventory().CreateInInventory("NailBox");
			itemEnt = player.GetInventory().CreateInInventory("NailBox");
			itemEnt = player.GetInventory().CreateInInventory("NailBox");
			itemEnt = player.GetInventory().CreateInInventory("NailBox");
			itemEnt = player.GetInventory().CreateInInventory("Pickaxe");
			itemEnt = player.GetInventory().CreateInInventory("SledgeHammer");
			itemEnt = player.GetInventory().CreateInInventory("Rope");
			itemEnt = player.GetInventory().CreateInInventory("Pliers");
			itemEnt = player.GetInventory().CreateInInventory("Shovel");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");	
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");	
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");	
			itemEnt = player.GetInventory().CreateInInventory("WoodenPlank");			
			itemEnt = player.GetInventory().CreateInInventory("Battery9V");
		}
//END CUSTOM
		
		itemClothing = player.FindAttachmentBySlotName( "Legs" );
		player.GetStatWater().Set( 1000 );
		player.GetStatEnergy().Set( 1000 );
		player.SetTemporaryResistanceToAgent(eAgents.INFLUENZA, 1200);
		
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
