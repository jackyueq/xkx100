// /d/shenlong/wuchang.c
// Last Modified by winder on Aug. 18 2002
 
inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
����һ���������䳡���м�����ִ�̽���������Ů������������
�Ա�վ�ż��ˣ�������Ů����������ʮ���꣬�ϵ���������ʮ�꣬����
ȴ�������С��ϱ���һ�����ȡ�
LONG );
	set("exits", ([
		"south" : __DIR__"zoulang",
	]));
	set("objects", ([
                "/d/shaolin/npc/mu-ren": 5,
	]));
	setup();
	replace_program(ROOM);
}
