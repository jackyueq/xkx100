// Npc: /d/nanshaolin/npc/zsseng1.c
// Last Modified by winder on May. 29 2001

inherit NPC;
#include <ansi.h>
string ask_me();
string* names = ({
	"juechan shiren",
	"bichan shiren",
	"kuchan shiren",
	"kongchan shiren",
	"jichan shiren",
	"liaochan shiren",
	"mingchan shiren",
});

void create()
{
	set_name("ִ��ɮ", ({ "zhishi seng", "zhishi","seng" }) );
	set("gender", "����" );
	set("age", 30);
	set("long", "�������Բ������������������Ͷ���\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("inquiry", 
	([
		"������" : (: ask_me :),
		"��������" : (: ask_me :),
	]));
	create_family("��������", 22, "�����õ���");
	setup();
}
string ask_me()
{
	mapping fam, my_fam, skl; 
	object me,fighter,room, monk;
	string *sname;
	int i,j;

	fighter = this_player();
	me = this_object();
	my_fam = fighter->query("family");
	skl = fighter->query_skills();
	sname = keys(skl);
	command("hmm"+fighter->query("id"));
/*
	for(i=0; i<sizeof(skl); i++)
	{
		if (skl[sname[i]] < 120) 
			return (RANK_D->query_respect(fighter) + "�����������������ԡ�");
	} 
*/
	if( fighter->query("pass_xin") && !wizardp(fighter))
		return (RANK_D->query_respect(fighter) + "�������ڸ�ɮ���ɲ�Ҫ�����Ŀ������Ц��");
	if( !mapp(fam = fighter->query("family")) ||
		fam["family_name"] != "��������")
		return (RANK_D->query_respect(fighter) + "�Ǳ��ɵ��ӣ������������С�");
	if( mapp(fam = fighter->query("family")) &&
		fam["family_name"] == "��������" && fam["generation"] > 19 )
		return (RANK_D->query_respect(fighter) + "���ݲ��ϣ������ʸ��������С�");
	if ( (int)fighter->query("guilty") > 0 )
		return (RANK_D->query_respect(fighter) + "���۷����䣬�����������Ȼ�ȥ��ڰɣ�\n");
	say("\nִ��ɮ˵�����ðɣ���������ʯ����أ�������þͻ���Ϊ��(huadi)׼������ɡ�\n");
	me->set("assigned_fighter", fighter->query("id")); 		
	message_vision("\nִ��ɮ�����뿪��\n\n", fighter);
	for(j=1; j<8; j++) 
	{
		if(!( room = find_object("/d/nanshaolin/shiting" + j)) )
		room = load_object("/d/nanshaolin/shiting" + j);
		me->move(room);
		if( !objectp(monk = present(names[j-1], room) ))
		{
			me->move("/d/nanshaolin/xcping");
			message_vision("\nִ��ɮ���˹�����\n\n", fighter);
			return "���ǶԲ���ʯͤ����ʯ�˶��ԣ�û�����д����ˡ�\n"; 
		}
		message("vision", "\nִ��ɮ���˹�������" + monk->query("name") + "�������һ�ơ�\n", room, monk);
		monk->move("/d/nanshaolin/xctang");
		message("vision",monk->query("name") + "����ִ��ɮ�첽���˳�ȥ��\n", room, monk);
	}

	me->move("/d/nanshaolin/xcping");
	call_out("waiting", 1, me);
	return ("�ã���Ҷ������ˡ�\n");
}

void waiting(object me)
{
	object fighter;
	int wait_time;

	if( wait_time == 300 )
	{
		say( "ִ��ɮ˵��������������������ˣ�\n\n");
		call_out("do_back", 0, me);		
	}

	if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
	{
		wait_time++;
		call_out("waiting", 1, me);
	}
	else if(!fighter->query_temp("huadi") )
	{
		if( random(10) == 0 ) 
		say("\nִ��ɮ˵����"+ RANK_D->query_respect(fighter) + "�㻯��Ϊ�����𣿿��ɣ�\n");
		wait_time++;
		call_out("waiting", 1, me);
	}
	else call_out("preparing", 1, me, fighter);

	return;
}

int preparing(object me, object fighter)
{
	object monk, room, ob;

	if(!( room = find_object("/d/nanshaolin/xcping")) )
		room = load_object("/d/nanshaolin/xcping");
//	if(!( room = find_object("/d/nanshaolin/shifang")) )
//		room = load_object("/d/nanshaolin/shifang");

	message("vision", HIY"\nִ��ɮ��������������ʯ�˴���������\n"NOR, room);
	message("vision", "\nֻ��һ��������죬�߸����ޱ����ʯ�˶�ס��ͨ·��\n\n", room);
	room->delete("exits");
	command("chat " + fighter->query("title") + fighter->query("name") + 
	"�ڽ���" + NATURE_D->game_time() + "��ս���������ϴ���\n");
	fighter->delete_temp("baitie");
	fighter->delete_temp("huadi");
	fighter->delete_temp("beat_count");
	fighter->set_temp("fighting", 1);
	call_out("fighting", 8, me, fighter, 0);
	return 1;
}

int fighting(object me, object fighter, int count)
{
	object monk1, monk2, room1, room2;
	if(!( room1 = find_object("/d/nanshaolin/xcping")) )
		room1 = load_object("/d/nanshaolin/xcping");
	if(!( room2 = find_object("/d/nanshaolin/xctang")) )
		room2 = load_object("/d/nanshaolin/xctang");
	if( count < 7 )
	{
		message("vision", "\nʯ�˸�̤�Ź����Է�λ������������\n" NOR, room1);
		monk1 = present(names[count], room2);
		monk1->move(room1);
//		message_vision(HIY+monk1->query("name")+"��$N���˹�����\n"NOR, fighter);
	}
	if( count >= 1 && count <= 7 )
	{
		monk2 = present(names[count-1], room1);
		monk2->move(room2);
	}
	if (!living(fighter) || environment(fighter)!=environment(me))
	{
		if( objectp(fighter))
		{
			fighter->delete_temp("fighting");
			fighter->delete_temp("beat_count");
		}
		monk1->move(room1);
		say("ִ��ɮҡ��ҡͷ��˵������˵�������԰ɣ�\n\n");
		command("sigh");
		command("chat"+ "*"+ "disapp");
		call_out("do_back", 5, me );
	}
	else
	{
		if( count >= 7 )
		{
			if( (int)fighter->query_temp("beat_count") >= 7 )
				call_out("do_recruit", 5, me, fighter);
			else
				call_out("do_back", 5, me );
		}
		else
		{
			count++;
			call_out("fighting", 2, me, fighter, count);
		}
	}
	return 1;
}

int do_recruit(object me, object fighter)
{
	mapping ft_fam, my_fam;

	fighter->delete_temp("beat_count");
	fighter->delete_temp("fighting");
	fighter->add("combat_exp", 30000);
	fighter->set("pass_xin", 1);
	say("\nִ��ɮ˵������ϲ�㴳�������������������ֶ�һ��ɮ��\n");
	command("chat ��ϲ���ɵ���"+fighter->query("name")+"��ֵ�����ã�\n");	
	call_out("do_back", 5, me );
	return 1;
}
int do_back(object me)
{
	object monk, room1, room2;
	int i;
	message("vision", "\nִ��ɮ�������أ�ʯ�����漴����뿪��\n", environment(me) );
	
	if(!( room1 = find_object("/d/nanshaolin/xcping")) )
		room1 = load_object("/d/nanshaolin/xcping");

	for(i=1; i<8; i++) 
	{
		if(!( room2 = find_object("/d/nanshaolin/shiting" + i)) )
		room2 = load_object("/d/nanshaolin/shiting" + i);
		if( objectp( monk = present(names[i-1], room1) ));
			monk->move(room2);
	}
	me->delete("assigned_fighter");
	me->move("/d/nanshaolin/xcping");
	return 1;
} 

