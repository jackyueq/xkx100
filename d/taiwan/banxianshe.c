// Room: /d/taiwan/banxianshe.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������λ��̨������ƽԭ�жΣ�Ϊƽ��������֮�ء���֣ʱ������
���˾۾ӣ�����������أ�����������̶��ɣ��ƿ�̨�������жΣ���
�زŽ�����ʢ������
LONG );
	set("exits", ([
		"northeast" : __DIR__"maolishe",
		"west"      : __DIR__"lugang",
		"southwest" : __DIR__"taiwanfu",
		"southeast" : __DIR__"riyuetan",
	]));
	set("objects", ([
		__DIR__"npc/nongfu": 2,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

