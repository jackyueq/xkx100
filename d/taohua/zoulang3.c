// Room: /d/taohua/zoulang3.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����Ӵ��������䳡�Ļ��ȡ������⻨ľ���裬�һ����أ�Զ��
����ɫ�Ĵ󺣺ʹ��̵ĵ���ӳ���ŵ��׷��������续��
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("exits", ([
		"west" : __DIR__"lianwuchang",
		"east" : __DIR__"zoulang1",
		"north": __DIR__"daojufang",
		"south": __DIR__"bingqi",
	]) );

	set("coor/x", 8990);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir != "east" && me->query("family/family_name") != "�һ���")
		return notify_fail("һλ������ס���㣬�����ƱȻ��ű�ʾ�Ǳ߲���ȥ��\n");
	
	return ::valid_leave(me, dir);
}