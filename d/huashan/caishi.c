// caishi.c
// Last Modified by winder on Aug. 1 2002

#include <ansi.h>;
inherit ROOM;

int do_cai(string arg);

void create()
{
	set("short", "��ʯ��");
	set("long", @LONG
������λ�ڻ�ɽ���µĲ�ʯ����һȺȺ�˲�ͣ�����ش���æµ�ţ�
�۵���ͷ�󺹣�Զ���и����̨��һ���ϰ�ģ����������̨ǰ����ϸ��
�������̸��˽��ʣ����Χ��һЩ�ˡ�
LONG);
	set("exits", ([
		"north" : __DIR__"path1",
	]));
	set("objects",([
		__DIR__"npc/zhanggui":1,
	]));
	set("coor/x", -920);
	set("coor/y", 260);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_cai","cai");
}

int do_cai(string arg)
{
	int i;
	object weapon,me = this_player();
	if (!arg || (arg != "stone" && arg != "ʯͷ"))
		return notify_fail("��Ҫ��ʲô��\n");
	if (!objectp(weapon = me->query_temp("weapon")) ||
		weapon->query("name") != "����")
		return notify_fail(RED"���ֶ�ĥ���ˣ�ȴʲôҲû���ɡ�\n"NOR);
	if (me->query_temp("caishi/count")<1)
		return notify_fail("���ﲻ������£�������Զ��ɣ�\n");
	if (me->query_temp("caishi/count")>4) 
	{
		me->set_temp("caishi/finish",1);
		return notify_fail("���Ѿ��ɵò���ˣ������ϰ彻���ˣ�\n");
	}
	if (me->query("qi")<30)
		return notify_fail("���֧�ֲ�ס�ˣ���Ъ����ɣ�\n");
	if (me->is_busy()) return notify_fail ("�����ϸ�������û��ɣ����ܽ�����һ����������\n");
	me->add("qi",-15);
	me->add_temp("caishi/count",1);
	i=random(4);
	message_vision(YEL"$N������������׼ʯͷ�ݺݵ�������ȥ��\n"NOR,me);
	if (i<1)
		tell_object(me,"���������ͣ���û��ڷ��飬��Щˤ��һ����\n");
	else if (i==2) tell_object(me, "��ݺ�һ���������ڵ����˼��������ûվ�ȡ�\n");
	else tell_object(me, "������һ�����£���������Ӧ������һ��ʯͷ����\n");
	me->start_busy(1);
	return 1;
}
