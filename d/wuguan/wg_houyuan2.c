// wg_houyuan2.c

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
������Ȼ�Ǻ�Ժ�����治ʱ������˻�����㿴��ȥ�������Ǹ�����
����������Ҳ�ǳ����ģ������Ǿ�ľͷ��������
LONG);
	set("exits", ([
		"north" : __DIR__"wg_mafang",
		"south" : __DIR__"wg_mufang",
		"west"  : __DIR__"wg_houyuan",
		"east"  : __DIR__"wg_houyuan3",
	]));
	set("objects", ([
		__DIR__"npc/wg_xueshandizi" : 1,
		__DIR__"npc/wg_honghuabangzhong" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 71);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

