// wg_houyuan.c

inherit ROOM;
void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����Ǻ�Ժ������Щ�ɻ����µĵط��������ȥ���ǲ񷿣�������
һ��ˮ��������ææµµ�Ľ����������Լ��Ļ
LONG);
	set("exits", ([
		"south" : __DIR__"wg_chaifang",
		"north" : __DIR__"wg_shuifang",
		"east" : __DIR__"wg_houyuan2",
		"west" : __DIR__"wg_shilu-3",
	]));
	set("objects", ([		
		__DIR__"npc/wg_hengshannvni" : 1,
		__DIR__"npc/wg_wududizi" : 1,
	]));
	set("outdoors", "wuguan");
	set("coor/x", 61);
	set("coor/y", -20);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

