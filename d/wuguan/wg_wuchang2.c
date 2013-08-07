// wg_wuchang2.c

#include <ansi.h>
inherit ROOM;

int do_tiao(string arg);

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
����¶�����䳡���ö�����������������ţ������ڳ��У�û����
��ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ��򣬳��ӵĶ�����һ��ɳ
��(shakeng)��
LONG);
	set("exits", ([
		"east" : __DIR__"wg_wuchang4",
		"north" : __DIR__"wg_lang2",
	]));
	set("objects", ([
		__DIR__"npc/wg_mjbz" : 1,
	]));
	set("item_desc", ([
		"shakeng" : "����һ����ɳ�ӣ�����С������ɳ����������(tiao)Ծ�š�\n",
	]));
	set("outdoors", "wuguan");
	setup();
}

void init()
{
	add_action("do_tiao", "tiao");
	
}
int do_tiao(string arg)
{
	object me;
	int costj, costq,c_exp,c_skill;

	me = this_player();
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר��������\n");
	if ( !living(me)) return notify_fail("�㷢���ˣ�\n");

	if ( !arg || arg != "shakeng" )
		return notify_fail("���ڳ�����ı������˰��죬���˻���Ϊ�㷢�񾭣�\n");
	costj = random((int)me->query("con"))+1;
	costq = random((int)me->query("str"))+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N����һ���������һ������ɳ����ˤ�˸�����ʺ��\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);
	message_vision("$N���ӵ����������ڴ�ɳ���з����������¡�\n", me);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("dodge",1);
	if ( (int)me->query("combat_exp") < 50000)
	{
		if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
			(int)me->query_skill("dodge", 1) < 30 && random(10)>6 )
		{
			write(HIM"�㲻�ϵ���ɳ�������ţ��Լ��Ļ����Ṧ������ߣ�\n"NOR);
			me->improve_skill("dodge", (int)(me->query("int") / 4));
		}
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("dex") / 10)));
	}
	return 1;
}
