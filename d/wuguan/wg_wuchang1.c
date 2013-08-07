// Last Modified by Sir on 9/17/2001
// wg_wuchang1.c

#include <ansi.h>
inherit ROOM;
int do_da(string arg);

void create()
{
	set("short", "�����䳡");
	set("long", @LONG
���Ǽ���ķ��ӣ�ʮ�ֿ����������������ﺹ��䤱��Ŀ����Ź�
�򣬵�����һЩ�����õĹ��ߣ�ǽ�߰���һ��ľ��׮(muren zhuang)��
LONG);
	set("exits", ([
		"east" : __DIR__"wg_wuchang3",
		"south" : __DIR__"wg_lang1",
	]));
	set("item_desc", ([
		"muren zhuang" : "һ��ľ׮������ľ�˵����ӹ̶��ڵ��ϣ����˻���(da)������\n",
	]));
	set("outdoors", "wuguan"); 
	set("objects", ([
		__DIR__"npc/wg_xxdizi" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_da", "da");
	
}
int do_da(string arg)
{
	object me;
	int costj, costq,c_exp,c_skill;

	me = this_player();
	if (me->is_busy()) return notify_fail("��������æ���أ�\n");
	if (me->is_fighting())
		return notify_fail("������ս���У��޷�ר��������\n");
	if ( !living(me)) return notify_fail("�㷢���ˣ�\n");
	if( objectp( me->query_temp("weapon")) )
		return notify_fail("ֻ�п��ֲ��ܴ�ľ��׮��\n");
	if (!arg || arg != "muren zhuang")
		return notify_fail("��Ҫ��ʲô��������\n");
	costj = random((int)me->query("con"))+1;
	costq = random((int)me->query("str"))+1;

	if ((int)me->query("jing") < costj || (int)me->query("qi") < costq)
	{
		message_vision("$N��һ�ɣ�һ��С���Դ�ײ����ľ��׮�ϣ�\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("jing", costj);
	me->receive_damage("qi", costq);       
	message_vision("$Nվ������������ȭ����ʼ��ľ��׮�Դ�������\n", me);
	c_exp=me->query("combat_exp");
	c_skill=me->query_skill("cuff",1);
	if ( (int)me->query("combat_exp") < 50000)
	{
		if ( ((c_skill*c_skill*c_skill/10)< c_exp) &&
			(int)me->query_skill("cuff", 1) < 30 && random(10)>6 )
		{
			write(HIM"���ں�ľ��׮�ĶԴ��������˲��ٻ���ȭ����\n"NOR);
			me->improve_skill("cuff", (int)(me->query("int") / 5));
		}	
		me->add("potential",random(2));
		me->add("combat_exp",random((int)(me->query("int") / 10)));
	}
	return 1;
}
