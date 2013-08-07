// /quest/quest.h
// Modified by Zeratul Jan 5 2001

mapping quest_name = ([
		"wei"	:	"������Ʒ",
		"book"	:	"�����ؼ�",
		"shan"	:	"����ɱа",
		"helian":	"һƷ��",
		"betrayer":	"նɱ��ͽ",
		"thief"	:	"׽����ϸ",
		"baobiao":	"��������",
		"bt"	:	"���ݲ���",
		"kill" : "������ɱ",
]);

void quest_finished( object who, string quest_type )

{
	string quest = "quest/" + quest_type;
	
	if ( !who->query_temp( quest ) )
		who->set_temp( quest, 1 );
	else
	{
		who->add_temp( quest, 1 );
		if ( who->query_temp( quest ) >= 1 + random(3) )
			for ( int i = 0; i < sizeof(quest_name); i++ )
				if ( who->query( "quest/" + keys(quest_name)[i] + "/lock" ) == quest_type )
				{
					who->delete( "quest/" + keys(quest_name)[i] + "/lock" );
					tell_object( who, "�������ȡ"HIG + values(quest_name)[i] + NOR"�����ˣ�\n"NOR );
					who->set( "quest/" + keys(quest_name)[i] + "/finished", 1 );
				}
	}
	who->set( quest + "/finished", 1 );
}

void quest_failed( object who, string quest_type )
{
	object obj;
	
	who->delete_temp( "quest/" + quest_type );
	who->delete( "quest/" + quest_type + "/finished" );
	if ( objectp( obj = who->query( "quest/" + quest_type + "/obj" ) ) )
		destruct( obj );
}

void lock_quest( object who, string quest_type, string lock_type )
{
	
	quest_failed( who, quest_type );
	who->set( "quest/" + quest_type + "/lock", lock_type );
	who->delete_temp( "quest/" + lock_type );			
}

int islocked( object who, string quest_type )
{
	string lock_quest = who->query( "quest/" + quest_type + "/lock" );
	object me = this_object();
	
	if ( stringp(lock_quest) && lock_quest != "" )
	{
		tell_object( who, "��������"HIY + quest_name[lock_quest] + NOR"������ܼ����������\n" );
		return 1;
	}
	return 0;
}
