// /d/changan/kedian.c

inherit ROOM;

void create()
{
	set("short", "������ջ");
	set("long", @LONG
����һ����¡�Ŀ�ջ���ſڹ��ſ��ң����顰��������������˵��
������ī������С������һ���к����ˣ�һ�ߴ������������Ϳ�ջ��Ԩ
Դ����ɫ��Ϊ���⡣ǽ�Ϲ���һ������(paizi),��������ʲôī����д
������ŤŤ��
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
		"north" : __DIR__"majiu",
		"south" : __DIR__"westroad1",
		"up"    : __DIR__"kedian2",
	]));

	set("coor/x", -5060);
	set("coor/y", 1010);
	set("coor/z", 0);
	setup();
	"/clone/board/kedian10_b"->foo();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "south" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}
