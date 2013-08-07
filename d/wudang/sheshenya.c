//Room: sheshenya.c ������
//Date: Sep 22 1997

#include <combat.h>
#include <ansi.h>
inherit ROOM;

int fall_down(object me, string type, int stage);

string *wudang = ({
	"taiziyan",
	"guangchang",
	"zixiaogate",
	"shijie2",
	"shibapan",
	"shiliang",
	"taizipo",
	"shanlu1",
	"haohanpo",
	"wdbl",
	"yuzhengong",
	"shijie1",
	"xuanyuegate"
});

void create()
{
	set("short","������");
	set("long",@LONG
����һ���վ��������ͱڣ��ഫ������ڴ�����õ����˼������
�ͣ���ľ�Դ䣬�Ͻӱ��������پ��������䵱ɽ��ʮ������������һ����
����������դ������ֹ������ɱ������۵ĺ󳾡�
LONG);
	set("exits",([ /* sizeof() == 1 */
	    "east"     : __DIR__"nanyanfeng",
	]));
	set("outdoors", "wudang");
	set("no_clean_up", 0);
	set("coor/x", -2050);
	set("coor/y", -940);
	set("coor/z", 110);
	setup();
}

void init()
{
	add_action("do_jump", "tiao");
	add_action("do_jump", "jump");
	add_action("do_push", "tui");
	add_action("do_push", "push");
}

int do_jump(string arg)
{
	object me = this_player();

	if( !arg || arg == "" )
		return notify_fail("ʲô��\n");

	if( arg == "cliff" )
	{
		if( me->query_skill("dodge") < 150 )
			return notify_fail("����ߵ���դ������ĵ���ȥ�᣿\n");
		message_vision("$N����Ծ����դ�������̤�գ��������������Ԩ֮�ϣ�������ſ����ȫ����ǰ���ˣ����������£�\n", me);
		me->set_temp("last_damage_from", "Ч���������·�����");
		fall_down(me, "char", 0);
		return 1;
	}
	return 0;
}

int do_push(string who)
{
	object me = this_player();
	object victim, room, weapon;
	string attack_skill, dodge_skill, parry_skill;
	int ap, dp, pp;
	mapping prepare;

	victim = present(who, environment(me));
	if( !who )return notify_fail("������ʲô��\n");
	if( !victim ) return notify_fail("����˲�������ɡ�\n");
	if( victim==me ) return notify_fail("ָ���ʽ��jump cliff\n");
	if( me->is_busy() )
		return notify_fail("�������Թ˶���Ͼ��������˼�����ˣ�\n");
	if( !victim->is_character() || victim->query("id") == "corpse" )
		return notify_fail("Ҫ�ƣ�Ҳֻ��������ȥ������˼����\n");
	if( objectp(weapon = me->query_temp("weapon")) )
		return notify_fail("����"+weapon->name()+"��ô���ˣ�\n");
	message_vision( CYN"\n$Nһ��֮�ʣ����Ƶ�$n���ԣ�ͻȻ����˫�ۣ��͵Ľ�$p���ͱ���ȥ"NOR"��\n", me, victim);
	me->start_busy(1);

	if( !living(victim) )
	{
		message_vision("$n��ɽ����ֱ����ȥ��\n", me, victim);
		victim->set_temp("last_damage_from", "��"+me->name()+"��������ˤ����");
		fall_down(victim, "char", 0);
		victim->revive();
		return 1;
	}

	prepare = me->query_skill_prepare();
	if( !prepare ) prepare = ([]);

	switch( sizeof(prepare) )
	{
		case 0: attack_skill = "unarmed"; break;
		case 1: attack_skill = (keys(prepare))[0]; break;
		case 2: attack_skill = (keys(prepare))[random(2)]; break;
	}

	ap = COMBAT_D->skill_power(me, attack_skill, SKILL_USAGE_ATTACK);
	dp = COMBAT_D->skill_power(victim, "dodge", SKILL_USAGE_DEFENSE);
	if( victim->is_busy() ) dp /= 3;

	if( random(ap + dp) < dp )
	{
		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		message_vision(SKILL_D(dodge_skill)->query_dodge_msg(), me, victim);
		if( random( ap * 2 ) < dp && !random(10) )
		{
			message_vision("$Nȫ��������������һ��֮�ϣ����Ͼ���$n�ܿ�������һ�Σ�̤�˸��գ���������ˤ����ȥ��\n", me, victim);
			me->set_temp("last_damage_from", "�Ӱٳ߸߿յ��£�ˤ��һ������");
			fall_down(me, "char", 0);
			return 1;
		}
		else if( !victim->is_killing(me->query("id")) ) victim->kill_ob(me);
		return 1;
        }
        else
	{
		pp=COMBAT_D->skill_power(victim, "parry", SKILL_USAGE_DEFENSE);
		if( victim->is_busy() ) pp /= 2;
		if( random(ap + pp) < pp )
		{
			parry_skill = victim->query_skill_mapped("parry");
			if( !parry_skill || !SKILL_D(parry_skill)->parry_available() ) 
				parry_skill = "parry";
			message_vision(replace_string(SKILL_D(parry_skill)->query_parry_msg(victim->query_temp("weapon"), 
				victim), "$w", "˫��"), me, victim);
			if( !victim->is_killing(me->query("id")) ) victim->kill_ob(me);
			return 1;
		}
		message_vision("$nһ��ûվ�ȣ�������������ɽ���е�����ȥ��\n", me, victim);
		victim->set_temp("last_damage_from", "��"+me->name()+"��������ˤ����");
		fall_down(victim, "char", 0);
                return 1;
        }
}

int fall_down(object me, string type, int stage)
{
	object *inv; 
	int i, count;
	string dodge_skill;

	if( stage < sizeof(wudang) )
	{
		switch( random(5) )
		{
			case 1 : tell_object(me, "��ֻ�������鸡��ȫ����������ֻ�Ǳ�ֱ�ĵ��䡣\n");
				 break;
			case 2 : tell_object(me, "����Է���������������̼�֮�£�ȴ�������޾�����Զ����û�ꡣ\n");
				 break;
			case 3 : tell_object(me, "�����ڰ�գ�����λΣ�ʵ�����ɼ���ȫ�ް����������\n");
				 break;
			case 4 : tell_object(me, "��ֻ�����Է������������Ӳ�ס������ˤ�䡣\n");
				 break;
			default: tell_object(me, "�㵫�����Է������������֮�䣬�ѵ���");
				 break;
		}
		me->move(__DIR__+wudang[stage]);
		message("vision","����������һ�˴�ɽ����ֱ����£�һʱȴ��������˭��\n", environment(me), me);
		fall_down(me, type, ++stage);
		return 1;
	}

	inv = all_inventory(environment(me));
	for( i = 0; i < sizeof(inv); i++ ) 
		if( inv[i]->is_character() && inv[i] != me )
		{
			if( !random(25) && random(inv[i]->query_kar()) < 15 )
			{
				tell_object(inv[i],"���Ȼ�������˾�������ֱ�����������\n");
				tell_object(me,"�㲻�������ı�ֱ���£�����һ�ˣ���ϡ������"+ inv[i]->name() +"��\n");
				if( random(inv[i]->query_skill("dodge")) > 200 )
				{
					dodge_skill = inv[i]->query_skill_mapped("dodge");
					if( !dodge_skill ) dodge_skill = "dodge";
					message_vision(SKILL_D(dodge_skill)->query_dodge_msg(), me, inv[i]);
				}
				else if( !inv[i]->query_temp("weapon") &&
					random(inv[i]->query_skill("taiji-quan", 1)) > 100 &&
					inv[i]->query_skill_prepared("unarmed") == "taiji-quan" &&
					inv[i]->query_skill_mapped("parry") == "taiji-quan" )
				{
					message_vision(CYN "$N����ʹ��һ�С���ȸβ�����ҽ�ʵ������飬���𡰼����־���ճ��ճ�棬�����Ѵ�ס$n���ᾢ��������$p�¶�֮��תֱΪ�ᣬ��$n�Ƶú�ɳ�ȥ��\n"NOR, inv[i], me);
					tell_object(inv[i], HIR"��ֻ����ʱ֮��ͷ���ۻ�������������\n"NOR);
					inv[i]->set("neili", 0);
				}
				else
				{
					count++;
					message_vision("$nֱ����$N���У���ʱײ��$P���Ƴ��������ڷ�����\n", inv[i], me);
					inv[i]->receive_wound("qi", inv[i]->query("max_qi")+100, "��"+me->name()+"ײ�ø��Ƴ��������ڷ���");
				}
			break;
			}
		}

	if( !count )
	{
		tell_object(me, "��ֱײ��ʯ���ϣ�");
		switch( random(3) )
		{
			case 0 : tell_object(me, "��Ѫ�������������ڰ�ߣ�ȴ���ƿ��˸����̡��̵ģ���ģ����ģ�һ������������\n");
				 break;
			case 1 : tell_object(me, "������ѣ�����ų���Ҳ�ƿ��˸��ʲ��̵ġ�"HIR"��"NOR"�ģ�"BLU"��"NOR"�ģ�"MAG"��"NOR"�ģ�������������\n");
				 break;
			case 2 : tell_object(me, "̫�������ţ�ȴ������һȫ��ˮ½�ĵ������Ͷ�������������һ���졣\n");
				 break;
		}
		message("vision", "ֻ���á��项��һ�����죬" +me->name()+"ײ��ʯ���ϣ�ˤ�÷�����ǣ�����һ���⽬��\n", environment(me), me);
	}

	me->receive_wound("qi", me->query("max_qi")+100, me->query_temp("last_damage_from"));

	inv = all_inventory(me);
	for( i = 0; i < sizeof(inv); i++ )
	{
		if( inv[i]->is_character() )
		inv[i]->receive_wound("qi", inv[i]->query("max_qi")+100, "��"+me->name()+"���۵��÷��������");
	}
	return 1;
}

int visit_room(string room_path, mapping info, mapping mapdb_info, mixed args)
{
	object room;

	if( strsrch(room_path, "/d/wudang/") != 0 ) return 1;
	room = find_object(room_path);
	if( !objectp(room) ) return 0;
	message("info", HIR"��������������ɽͻȻ����һ�������Ĳҽ�����\n"NOR, room, 0);
}

