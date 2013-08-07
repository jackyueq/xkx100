// /d/shenlong/dating ����
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>
inherit ROOM;
string* npcs = ({
	__DIR__"npc/boy",
	__DIR__"npc/boy2",
	__DIR__"npc/boy3",
	__DIR__"npc/boy4",
	__DIR__"npc/girl",
});
string look_jia();

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ������֮�У�����˶����������ݵ���ǧ��֮�ڣ�һ
ȺȺ������Ů����ɫվ�ã��ࡢ�ס��ڡ�����ɫ�Ķ������꣬�����ȴ
����Ů�����ϸ����̽���ÿһ��Լ�а��ˡ�ÿ������֮ǰ��վ��һ��ͷ
Ŀ�����������кܶ���ڡ���������һ�ű�����(shelf)��
LONG
	);
	set("exits", ([
		"out"   : __DIR__"tingkou",
		"east"  : __DIR__"shibanlu",
		"north" : __DIR__"zoulang",
	]));
	set("objects", ([
		npcs[random(sizeof(npcs))] : 1,
		npcs[random(sizeof(npcs))] : 1,
		__DIR__"npc/yunsumei": 1,
		CLASS_D("shenlong")+"/wu": 1,
	]));
	set("item_desc", ([
		"shelf": (: look_jia :),
	]));
	set("weapon_count", 10);
	setup();
}

void init()
{
	add_action("do_get", "get");
}

int do_get(string arg)
{
	object weapon, me = this_player();
	string type;

	if(!arg) return 0;
	if( me->is_fighting() || me->is_busy() ) return 0;
	if( sscanf(arg, "%s from shelf", type) != 1) return 0;
	if( time() < me->query("sg/weapontime") + 300 && !wizardp(me))
	{
		tell_object(me, "��̫̰���ˣ����ǵ�һ�������ɡ�\n");
		return 1;
	}
	if(query("weapon_count") < 1)
	{
		tell_object(me, "�����ܿտ���Ҳ��������������ȡ���˰ɡ�\n");
		return 1;
	}
	if( type != "armor" )
	{
		if( (int)me->query_skill(type, 1) < 1 )
		{
			tell_object(me, "�㲻��������������\n");
			return 1;
		}
	}
	switch(type)
	{
		case "sword":   if(me->query("gender") == "����") 
					weapon = new(WEAPON_DIR"treasure/zhen");
				else weapon = new(WEAPON_DIR"sword/changjian");
				break;
		case "blade":   weapon = new(WEAPON_DIR"blade/gangdao");
				break;
		case "stick":   weapon = new(WEAPON_DIR"zhubang");
				break;
		case "staff":   weapon = new(WEAPON_DIR"gangzhang");
				break;
		case "hammer":   weapon = new(WEAPON_DIR"hammer/tongchui");
				break;
		case "whip" :   weapon = new(WEAPON_DIR"changbian");
				break;
		case "hook" :   weapon = new(WEAPON_DIR"hook");
				break;
		case "armor":   weapon = new(ARMOR_DIR"tiejia");
				break;
		default:	tell_object(me, "�Ҳ���"+type+"���ֱ�����\n");
				return 1;
	}
	if( weapon->move(me) )
	{
		message_vision("$N�ӱ�������ȡ��һ"+weapon->query("unit")+weapon->name()+"��\n", me);
		me->set("sg/weapontime", time());
	}
	else
	{
		destruct(weapon);
	}
	add("weapon_count", -1);
	return 1;
}

string look_jia() 
{
	string msg;

	msg ="����һ�������ܣ�ʮ�˰�������Ӧ�о��С�\n";
	msg+="Ŀǰ����н�(sword)����(blade)����(hook)����(stick)����(staff)����(hammer)����(whip)������һЩ����(armor)��\n";
	msg+= "����ָ�get ���� from shelf����ȡ����ֵı�������С�\n";
	return msg;
}

int valid_leave(object me, string dir)
{
	if (dir == "east" &&
		me->query("party/party_name") !=HIY "������" NOR &&
		present("wugen daozhang", environment(me)) &&
		living(present("wugen daozhang", environment(me))))
			return notify_fail("�޸������ȵ��������Ǳ����صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
	else return ::valid_leave(me, dir);

}
