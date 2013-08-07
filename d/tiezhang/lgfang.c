// Room: /d/tiezhang/lgfang.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>

inherit ROOM;
//void init();
//int do_chazhi();

void create()
{
        set("short",HIC"������"NOR);
	set("long", @LONG
����һ���û��������ɵ�ʯ�ݡ�����һֻ��¯��ȼ�˺�̿��������
�����ڵ�һ��(huo )������������������Сͯ��һ��ʹ���������䣬��
һ����������������֮�����ɳɳ֮����������������ɳ����������
���ӱ�Ŀ��ϥ���ڹ�ǰ����������ϵ��������ţ����ָ�����п�����
LONG
	);
        set("exits", ([ 
		"east" : __DIR__"guangchang",
	]));
	set("objects",([
		__DIR__"npc/heiyi" : 1,
	]));
	set("item_desc", ([
		"huo" : "����һ�ھ޴������������ʢ����ɳ������ȼ��̿��\n",
	]));
	set("coor/x", -2050);
	set("coor/y", -1970);
	set("coor/z", 20);
	setup();
}

void init()
{
	add_action("do_chazhi", "chazhi");
}


int do_chazhi(string arg)
{       
        mapping fam;
	object me;
        me = this_player();

	if (!living(me)) return 0;
	if ( !living(this_player()) || arg != "huo" )
	{
		write("�������Ķ���ѽ��\n");
		return 1;
	}
	if (!(fam = me->query("family")) || fam["family_name"] != "���ư�")
		return notify_fail("��Ǳ�����ӣ������ڴ�������\n");

	if ( (int)me->query_skill("strike", 1) > 100)
		return notify_fail("�㽫˫�ֲ������У�������ɳ���¶ȶ�����˵̫�ͣ��Ѻ��������ˡ�\n");
 
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write("�����һ������ֱ�������������ѵ���\n");
		me->unconcious();
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("strike", me->query("int"));
	message_vision("$N��˫�ֲ�����е���ɳ�\n", me);
	write("���ȵ���ɳ�����˫���̵�ͨ�죬�����˫�ֱ��ǿ׳������\n");
	return 1;
}
