// Room: /d/tiezhang/hclu3.c
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
		"southeast" : __DIR__"hclu2",
		"northup"   : __DIR__"hclu4",
	]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");
	set("coor/x", -2060);
	set("coor/y", -1880);
	set("coor/z", 60);
	setup();
}
int valid_leave(object me, string dir)
{
	if (me->query("family/family_name") == "���ư�") return 1;
	if ((dir != "northup") && (dir != "southeast"));
	if (dir == "northup")
	{
		me->receive_damage("qi", 5);       
		write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
	}
	if (dir == "southeast")
	{
		me->receive_damage("qi", 5);       
		write("���˫�ȱ��������ƣ���Ѫ���˳�����\n");
	}
	return 1;
}
