//Edited by fandog, 02/15/2000
inherit ROOM;

void create()
{
	set("short", "�紨��ջ");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��������
�ţ��������������������صķ������顣��С����������æ������ת��
�Ӵ�����ǻ�����Ŀ��ˡ�ǽ�Ϲ���һ������(paizi)��
LONG );
	set("no_fight", 1);
	set("valid_startroom", 1);
	set("no_sleep_room",1);
//	set("no_clean_up", 0);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ��ʮ��������\n",
	]));
	set("objects", ([
		"/d/city/npc/xiaoer" : 1,
	]));
	set("exits", ([
		"east" : __DIR__"majiu",
		"west" : __DIR__"hzjie4",
		"up"   : __DIR__"kedian2",
	]));

	set("coor/x", -1490);
	set("coor/y", -2130);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian9_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "west" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}