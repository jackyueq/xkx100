// Room: /d/tiezhang/hclu2.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "�Ĳ�·");
	set("long", @LONG
������һ�����ߵ�С·�ϣ����ԻĲ���ϥ��������أ��ƺ�������
����ɽʯ������������գ�����ȫ�ޣ�����������һƬ����֮�У�ʹ��
�￴�������������ľ���
LONG	);
	set("exits", ([ /* sizeof() == 2 */
		"southdown" : __DIR__"hclu1",
		"northwest" : __DIR__"hclu3",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2050);
	set("coor/y", -1890);
	set("coor/z", 60);
	setup();
}
int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") == "���ư�") return 1;
	if ((dir != "northwest") && (dir != "southdown"));
	if (dir == "northwest")
	{
		me->receive_damage("qi", 5);       
		write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
	}
	if (dir == "southdown")
	{
		me->receive_damage("qi", 5);       
		write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
	}
	return 1;
}
