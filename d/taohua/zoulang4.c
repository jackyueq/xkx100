// Room: /d/taohua/zoulang4.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һ�����Ӵ������鷿�Ļ��ȡ������⻨ľ���裬�һ����أ�Զ����
��ɫ�Ĵ󺣺ʹ��̵ĵ���ӳ���ŵ��׷��������续��
LONG
	);
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("exits", ([
		"west" : __DIR__"dating",
		"east" : __DIR__"bookroom",
		"north": __DIR__"tanzhige",
		"south": __DIR__"pikonglang",
	]) );

	set("coor/x", 9020);
	set("coor/y", -3010);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "�һ���") && dir != "west")
		return notify_fail("һλ������ס���㣬�����ƱȻ��ű�ʾ�Ǳ߲���ȥ��\n");

	return ::valid_leave(me, dir);
}