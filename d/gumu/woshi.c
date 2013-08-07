// Room: /d/gumu/woshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIC"����"NOR);
	set("long", @LONG
������С��Ů��ס�����ң����пտն�����������һ�鳤����ʯ��
�� (bed)�����������Ų�ϯ��һ���ײ������������������һ���˸ߵ�
����������У���������һ���ֲ�ľ��(chu)��
LONG	);
	set("item_desc", ([
		"bed" : HIC"һ������ͨ��ʯ�̳ɵĴ��������䴦����һ��ͻ���ʯ�壬�ƿɰ⶯��\n"NOR, 
		"chu" : HIY"һ����֮ͨ���ĳ��ӡ�\n"NOR, 
	]));
	set("exits", ([
		"east" : __DIR__"mudao15",
	]));
	set("chu", 1);
	set("no_clean_up", 0);
	set("coor/x", -3220);
	set("coor/y", -40);
	set("coor/z", 90);
	setup();
}

void init()
{
	add_action("do_tang", "tang");
	add_action("do_ban", "ban");
	add_action("do_open","kai");
	add_action("do_open","open");
	add_action("do_xian","xian");
}

int do_tang(string arg)
{
	object me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( arg == "bed")
	{
		message_vision(HIC"$N������������ʯ�Ƴɵ�ʯ�����档\n"NOR,me);
		me->set_temp("marks/��", 1);
		return 1;
	}
	return notify_fail("��Ҫ���ڵ��ϣ�С������Ŷ��\n");
}  

int do_ban(string arg)
{  
	object me=this_player();

	if (!me->query_temp("marks/��"))
		return notify_fail("��û�ɴ��ϣ������ò������ɣ�\n");	
	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���أ�\n");
	if ( arg == "shiban" || arg == "stone")
	{
		if (me->query("neili") < 500)
			return notify_fail("��ʹ�����̵ľ�������ʯ��ȴ��˿������\n");
		message_vision(HIY "$N�����⶯ͻ���ʯ�壬ֻ�����������죬ʯ���������²�ʯ�ҡ�\n"NOR,me);
		me->add("neili",-200);
		me->delete_temp("marks/��");
		me->move(__DIR__"shishi0");
		write(HIY"�Ҷ�ʯ�����������������ˡ�\n"NOR);
		return 1;
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int do_open(string arg)
{
	object ob, me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( arg=="chu")
	{
		if ( query("chu") == 1 )
		{
			if(!objectp(present("gold key", me)))	
				return notify_fail("��û��Կ�ף���ô������\n");
			message_vision("$N�����ý�Կ�״��˳��š�\n",me);
			ob=new(__DIR__"obj/box");
			ob->move(environment(me));
			write("�㷢�ֳ��ڷ��Ÿ������ε������ӡ�\n");
			set("chu", 0);
			return 1;
		}
		else
		{
			write("�������ˣ��������ڿ����ء�\n");
			return 1;
		}
	}
	return notify_fail("��Ҫ��ʲô��\n");
}

int do_xian(string arg)
{
	object suo, me=this_player();

	if (me->is_busy() || me->is_fighting())
		return notify_fail("����æ���ģ�\n");
	if ( arg =="box" || arg=="da tiehe" || arg =="tiehe")
	{
		if(!(present("da tiehe", environment(me)))) 
			return notify_fail("����������ô��\n");
		if(!objectp( present("silver key", me)))	
			return notify_fail("��û��Կ�ף���ʲô������\n");
		me->delete_temp("marks/����");
		message_vision("$N����Կ�׿������������ƿ������С�\n",me);
		suo=new(__DIR__"obj/yinsuo");
		if(!clonep(suo))
			return notify_fail("�������ˣ������������һ�\n");
		write("�ƿ����У��㷢���������һ�ű�篰�����¡�\n");
		suo->move(me);		
		return 1;
	}
	return notify_fail("��Ҫ�ƿ�ʲô��\n");
}

