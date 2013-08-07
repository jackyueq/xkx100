// Room: /d/gumu/houting.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
����Ҳ�ǿյ�����ûʲô���裬��ǰ��д��һ�д��֣�zi��������
���ڶ�����һ���������� (westpic)�Ļ���������Ů�ɣ����ǹ�Ĺ�ɵ�
ʦ���ֳ�Ӣ��ʦ�����ŵ�Ф�񣬶��� (eastpic)������ȴ��һ����ʿ�� 
    ������Կ�����һ�Ȱ���(door)��
LONG	);

	set("exits", ([
		"east"  : __DIR__"mudao18",
//		"west"  : __DIR__"mudao06",
		"north" : __DIR__"mudao07",
		"south" : __DIR__"mudao19",
	]));
	set("count", 1);
	set("item_desc", ([
		"door" : "һ�Ⱥ��ص�ʯ�ţ��������ȫû�а��֡������濴�˿��������űߵ�ʯ�����ƺ���ʲô��ť(niu)���Կ��š�\n",
		"westpic" : HIM"�����������һ����ʮ�����꣬���ڶԾ���ױ�����о���ӳ��Ů����ò��������ü���ޣ��۽�ȴ��������һ��ɱ�������ǹ�Ĺ��ʦ���ֳ�Ӣ����һ����ʮ�������Ѿ�ߣ��ֳ����裬�����ź򣬺�̬���䣬�������������������С��Ů
��ʦ����\n"NOR,
		"eastpic" : HIC"���е���������ߣ���������������ʳָָ�Ŷ����ǣ�ֻ�Ǳ������⣬��òȴ��������\n"NOR,
		"zi" : HIR"\t���ҹ�Ĺ�����������������񹦣�������ʦ��\n"NOR,
	]));
	set("coor/x", -3180);
	set("coor/y", 10);
	set("coor/z", 90);
	setup();
}

void init()
{ 
	add_action("do_ketou", "ketou"); 
	add_action("do_tuo", "tuo");
	add_action("do_an", "press");
	add_action("do_an", "an");
}
 
int do_ketou(string arg)
{
	mapping fam;
	object me = this_player();

	if ((!arg) || (arg != "westpic")) return 0;
		message_vision("$N�����򵹣�˫ϥ���أ�������������ʦ���ŵĻ������һ����ͷ��\n", me);
	me->add_temp("marks/ketou", 1);
	me->receive_damage("qi", 5);
	if(me->query_temp("marks/tuo") == 2 &&
		me->query_temp("marks/ketou") == 4 &&
		(!(fam = me->query("family")) ||
		fam["family_name"] != "��Ĺ��") &&
		me->query("combat_exp") < 10000)
	{
		me->set("family_name", "��Ĺ��");
		me->set("title", HIW"��Ĺ����"NOR);
		me->create_family("��Ĺ��", 5, "����");
		me->set("class","swordsman");
		write(HIR"��ϲ����Ը��Ϊһ����Ĺ���ӡ�\n"NOR);
		me->delete_temp("marks/tuo");
		me->delete_temp("marks/ketou");
		return 1;
	}
	if (me->query_temp("marks/ketou") == 15 )
	{
		me->delete_temp("marks/ketou");
		if (query("count") == 0)
			return notify_fail("����¶��һ��С�ף�������տ���Ҳ������������������ˡ� \n");
		message_vision(HIY "$N��ǰ��ʯ��ͻȻ�³���¶��һ�ѽ�Կ�ף�$N��������������\n"NOR, me);
		set("count", 0);
		new(__DIR__"obj/goldkey")->move(me);
	}
	return 1;
}

int do_tuo(string arg)
{
	object me = this_player();

	me->receive_damage("qi", 5);
	if (me->query_temp("marks/tuo") == 2)
		return notify_fail("���ٹ���û�У�\n");
	if ( arg=="eastpic")
	{
		message_vision("$N���������Ļ���ݺ�����һ�ڡ�\n", me);
		me->add_temp("marks/tuo", 1);
		return 1;
	}
	return notify_fail("�㲻Ҫ������ٿ�ˮ����\n");
}

int do_an(string arg)
{
	object room, me = this_player();

	if( !arg || arg != "niu" )
	{
		message_vision("����ʯ�����Ұ�һ��������һ�ֻң�ɶҲû���š�\n", me);
		return 1;
	}
	if( query("exits/west"))
	{
		return notify_fail("ʯ���Ѿ��ǿ��ŵģ��㻹����ɶ��\n");
	}
	if( me->query_skill("yunv-xinfa", 1) > 10)
	{
		message_vision("$Nվ��ʯ��ǰ��Ҳ��֪�����ﰴ��һ�£�ʯ��֨֨���ţ��������ˡ�\n", me);
		if( !(room = find_object(__DIR__"mudao06")) )
			room = load_object(__DIR__"mudao06");
		set("exits/west", __DIR__"mudao06");
		room->set("exits/east", __DIR__"houting");
		tell_room(room,"ֻ����ʯ����֨֨���б������򿪡�\n");
		remove_call_out("close");
		call_out("close", 5, me);
	}
	else
		message_vision("$N������ʯ���ϰ�����ȥ������ʯ����˿������ֻ�ð��ˡ�\n", me);
	return 1;
}

void close(object me)
{
	object room;

	tell_room(this_object(), "ʯ�Ż����ع��ϣ��ָ���ԭ״��\n");
	delete("exits/west");
	if( !(room = find_object(__DIR__"mudao06")) )
		room = load_object(__DIR__"mudao06");
	room->delete("exits/east");
	tell_room(room,"��ǽ�İ��Ż����ع����ˡ�\n");
}
