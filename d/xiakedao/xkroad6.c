// Room: /d/xiakedao/xkroad6.c
// Modified by Java on Feb.14.1998
inherit ROOM;

void create()
{
	set("short", "���С��");
	set("long", @LONG
С�������С��ʮ�ּ�ª������ûʲô�ҵ������Ϲ��������þ�
�˵���ߡ���Ŵ��˶������ˣ�ֻ��һ��С����������������һ
�����̡�
LONG );
        set("outdoors", "xiakedao");
	set("exits", ([
		"south"   : __DIR__"xkroad5",
	]));
	set("objects", ([
		__DIR__"npc/kid": 1,
	]));
	set("coor/x", -1390);
	set("coor/y", -8990);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}