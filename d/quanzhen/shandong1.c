// shandong.c
// Java Oct.10 1998

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
����Сɽ��(dong)�����һ��ǿ���ˮ���Ե����������γ�һ��
С�������⡣������ٽ�һ������Ļ����͵�Ҫ����ˮ���ˡ������
��С�ӱߡ������ҪǱˮ�ˡ�
LONG
	);
	set("item_desc", ([
		"dong" : "һ�����䡢�İ����ֲ���Сɽ����\n",
	]));
	set("exits", ([
		"out"       : __DIR__"xiaohebian",
		"southdown" : "/d/gumu/anhe2",
	]));

	set("coor/x", -3160);
	set("coor/y", -10);
	set("coor/z", -10);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "southdown" && me->query("family/family_name")!="��Ĺ��")
	{
		return notify_fail("��ô����ˮ����������ȥ��ɱѽ��\n");
	}
	if (dir == "southdown" && me->query("family/family_name")=="��Ĺ��")
	{
		message_vision(HIG "$N����һԾ������ˮ̶֮�С�\n"NOR,me);
		write(HIC"������������ι���������һ�̣�ȴץ�˿ա�ͻȻ����ǰһ����һ�ɰ�������������������һ�����ڡ�\n"NOR);
		return 1;
	}
	return ::valid_leave(me, dir);
}
